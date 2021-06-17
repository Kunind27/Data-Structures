#include <iostream>

using namespace std;

struct node
{
    int val;
    node* next;
};

class sllist
{
    private:
    node* head;
    int size;
    
    public:
    
    // Constructor
    sllist()
    {
        size = 0;
        head = nullptr;
    }
    
    // Destructor
    ~sllist()
    {
        node* n = head;
        while(n!=nullptr)
        {
            delete n;
            n = n->next;
        }
    }
    
    // Return Size of the Linked List
    int length()
    {
        return size;
    }
    
    // Printing the entries of the Linked List
    void print()
    {
        node *n = head;
        while(n!=nullptr)
        {
            cout<<n->val<<" ";
            n = n->next;
        }
    }
    
    // Inserting New Elements in the Linked List
    void add_element(int k)
    {
        // Allocating Memory to the New Node
        node* newnode = new node();
        
        newnode->val = k;
        newnode->next = head;
        head = newnode;
        size++;
    }
    
    // Search for Nodes
    node* search_value(int k)
    {
        node* n = head;
        while((n!=nullptr)&&(n->val!=k))
        {
            n = n->next;
        }
        
        return n;
    }
    
    // Delete Node
    void delete_node(node* p)
    {
        // Search for the Node Before 'p'
        node* n = head;
        
        while((n->next)!=p)
        {
            n = n->next;
        }
        
        // Node before p must point to the Node after p
        n->next = p->next;
        
        //Delete Node 'p' and accordingly change its size
        delete p; 
        size--;
    }
     
    // Get Last Node of the Linked List
    node* last_node()
    {
        node* n = head;
        while((n->next)!=nullptr)
        {
            n = n->next;
        }
        
        return n;
    }
     
    // Sorting a linked List
    void sort()
    {
        node* n1 = head;
        
        // Traversing the list 
        while(n1->next!=nullptr)
        {
            node* n2 = n1->next;
            node* min_node = n1;
            
            // Traversing the unsorted sublist
            while(n2!=nullptr)
            {
                if(n2->val < min_node->val)
                {    
                    min_node = n2;
                }
                n2 = n2->next;
            }
            
            // Swapping the Values
            int temp = n1->val;
            n1->val = min_node->val;
            min_node->val = temp;
            n1 = n1->next;  
        }
    }
};


int main()
{
    sllist ll;
    
    // Adding Elements to the linked list
    ll.add_element(31);
    ll.add_element(45);
    ll.add_element(57);
    ll.add_element(24);
    
    // Printing the List and its length
    ll.print();
    cout<<endl<<ll.length()<<endl;
    
    // Searching an element and Deleting an element of the List
    node* res = ll.search_value(45);
    ll.delete_node(res);
    ll.print();
    
    // Adding More Elements
    ll.add_element(33);
    ll.add_element(83);
    ll.add_element(101);
    cout<<endl;
    ll.print();
    
    // Sorting the list
    ll.sort();
    cout<<endl;
    ll.print();
    
    return 0;
}