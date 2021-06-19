#include <iostream>

using namespace std;

struct Node
{
    int value;
    Node* left;
    Node* right;
    
    // Constructor
    Node(int val)
    {
        value = val;
        left = right = nullptr;
    }
};

class binary_search_tree
{
    public:
    
    // To insert a value at a given node
    void insert(Node* &current_node, int k)
    { // Current Node Pointer is passed by reference
        if(current_node == nullptr) // Add the value to this node
        {
            current_node = new Node(k);
            current_node->left = current_node->right = nullptr;
        }
        else
        {
            if(k == current_node->value) // The value is already present in the tree
            {
                return;
            }
            else if(k < current_node->value)
            {
                insert(current_node->left, k);
            }
            else
            {
                insert(current_node->right, k);
            }
        }
    }
    
    // To search for a given node
    bool search(Node* &current_node, int k)
    {
        // Current node is the node at which we begin searching
        if(current_node == nullptr)
        {
            return false;
        }
        else if(current_node->value == k)
        {
            return true;
        }
        else
        {
            if(k < current_node->value)
            {
                search(current_node->left, k);
            }
            else if(k > current_node->value)
            {
                search(current_node->right, k);
            }
        }
    }
};
int main()
{
   binary_search_tree bst;
   Node* bst_node = nullptr;
   
   // Inserting Values into the BST
   int values[] = {10,12,5,4,20,8,9,11,67};
   
   for(int i=0; i<9; i++)
   {
       bst.insert(bst_node, values[i]);
   }
   //The node bst_node is initialized to the value of the Root Node!
   
   // Searching for Values in the BST
   int search_values[] = {3,5,12,13};
   for(int i=0; i<4; i++)
   {
       if(bst.search(bst_node, search_values[i])) cout<<search_values[i]<<" FOUND"<<endl;
       else cout<<search_values[i]<<" NOT FOUND"<<endl;
   }
   
   return 0;
}
