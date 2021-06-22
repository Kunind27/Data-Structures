#include<iostream>
using namespace std;

// Implementing an Open Addressed Hash Table with Linear Probing

class HashTable
{
    int size; // Maximum elements that can be acommodated by the Table
    int* table;
    int hash_func(int key); // Hash Function of the table
    
    public:
    HashTable(int s); // Constructor
    int search(int key); // Returns index at which key is found else -1
    void insert_key(int key); 
    void delete_key(int key); 
    
};

// Constructor
HashTable::HashTable(int s)
{
    size = s;
    table = new int[size]; 
    
    for(int i=0; i < size; i++)
        table[i] = -1; // -1 means that the slot is empty
}

// Hash Function of the Hash Table
int HashTable::hash_func(int key)
{
    return key%size;
}

// Function to Search for the Key in the Hash Table
int HashTable::search(int key)
{
    int index = hash_func(key);
    int index_iter = index;
    
    /* Need to search for the key at every index between initial_index and next 
    free slot Since we have used linear probing. Additional condition applied if 
    all the slots are filled and the key still hasn't been found **/
    
    while(table[index_iter]!=-1)
    {
        if(table[index_iter]==key)
            return index_iter;
        else
        {
            index_iter = (index_iter + 1)%size; // Table is circular
            if(index_iter == index) 
                break;
        }
    }
    return -1;
}

// TO insert a key into the Hash Table
void HashTable::insert_key(int key)
{
    int index = hash_func(key);
    int index_iter = index;
    
    // If initial index is unfilled, it won't enter while loop and go to the next statement
    while(table[index_iter]!=-1)
    {
        index_iter = (index_iter + 1)%size;
        if(index_iter == index)
        {
            cout<<"The Table is Full!"<<endl;
            return;
        }
    }
    /* If at any moment index @ index_iter is free i.e table[index_iter] == -1
    The control jumps out of the for loop and the key is stored at that index**/
    table[index_iter] = key;
    cout<<"Added "<<key<<" to index "<<index_iter<<endl;
}

// To delete a key from the Hash Table
void HashTable::delete_key(int key)
{
    int index = search(key);
    
    if(index==-1)
    {
        cout<<"No such key!"<<endl;
        return;
    }
    else
    {
        table[index] = -2; // Dummy Value so that Search works properly
    }
}

int main()
{
    HashTable my_hash(10); // HashTable of size 10
    
    // Inserting Keys into the Hash Table
    my_hash.insert_key(13);
    my_hash.insert_key(11);
    my_hash.insert_key(16);
    my_hash.insert_key(22);
    
    // Searching for Keys
    cout<<my_hash.search(22)<<endl;
    cout<<my_hash.search(24)<<endl;
    cout<<my_hash.search(11)<<endl;
    
    // Deleting Keys
    my_hash.delete_key(11);
    cout<<my_hash.search(11)<<endl;
    
    return 0;
}
