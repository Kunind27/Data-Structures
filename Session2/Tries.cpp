#include<iostream>
using namespace std;

const int alphabet_size = 26;

// Node of a Trie
struct trie_node
{
    trie_node* children[alphabet_size];
    bool isEndOfWord;  // True if the Node marks the end of the word
    
    // Constructor
    trie_node()
    {
        for(int i=0; i< alphabet_size; i++)
            children[i]= nullptr; // Assigns the Children to a Null Pointer
            
        isEndOfWord = false;
    }
};

// Inserts a Word into the Trie Tree
// If word is not present, insert the key
// If key is the prefix of a trie node, just mark the leaf node
void insert(trie_node* root, string key)
{
   trie_node* pCrawl = root;
   
   // Iterating over the Key Letters
   for(int i=0; i < key.length(); i++)
   {
       // Get the Index of Children Array which needs to be initialized to a trie node
       int index = key[i] - 'a';
       // If the Child array index is not initialised, initialize it to a trie node
       if(!pCrawl->children[index])
           pCrawl->children[index] = new trie_node();
           
        pCrawl = pCrawl->children[index]; // To move further into the trie depth
   }
   // Marking last node as the leaf node
   pCrawl->isEndOfWord = true;
}


// Searching for a Key i.e String in a try
bool search(trie_node* root, string key)
{
    trie_node* pCrawl = root;
    
    // Iterating over the Key Characters
    for(int i=0; i<key.length(); i++)
    {
        int index = key[i] -'a';
        // If any one of the key characters doesn't have a node in the try then return false
        if(!pCrawl->children[index])
            return false;
            
        pCrawl = pCrawl->children[index];
    }
    // If you have traversed through the entire key in the trie and the pCrawl which is now the last letter/ node of the key isEndOfWord then return true!
    return (pCrawl!=nullptr && pCrawl->isEndOfWord);
}

int main()
{
    // This is assuming that the key strings contain only lower case letters from
    // a to z
    string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" };
    
    // To get the length of the array;
    int len = sizeof(keys)/sizeof(keys[0]);
    
    trie_node* root = new trie_node();
    
    // Construct trie
    for (int i = 0; i < len; i++)
        insert(root, keys[i]);
  
    // Search for different keys
    search(root, "the")? cout <<"Yes\n" : cout <<"No\n";
    search(root, "these")? cout <<"Yes\n" : cout <<"No\n";
    search(root, "ther")? cout<<"Yes\n" : cout<<"No\n";
    search(root, "thei")? cout<<"Yes\n" : cout<<"No\n";
    search(root, "bye")? cout<<"Yes\n" : cout<<"No\n";
    
    return 0;
}
