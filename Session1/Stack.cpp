#include <iostream>

using namespace std;

struct stack_node
{
    int val;
    stack_node* next;
};

class stack
{
    private:
    stack_node* top;
    int size;
    
    public:
    
    // Constructor
    stack()
    {
        size = 0;
        top = nullptr;
    }
    
    // Destructor
    ~stack()
    {
        stack_node* n = top;
        while(n!=nullptr)
        {
            delete n;
            n = n->next;
        }
    }
    
    // Is the Stack Empty
    bool is_empty()
    {
        return (*this).length()>0;
    }
    
    // Return Size of the Stack
    int length()
    {
        return size;
    }
    
    // Printing the entries of the Stack
    void print()
    {
        stack_node *n = top;
        while(n!=nullptr)
        {
            cout<<n->val<<" ";
            n = n->next;
        }
    }
    
    // Pushing a new element onto the stack
    void push(int k)
    {
        // Allocating Memory to the New Stack Node
        stack_node* new_stack_node = new stack_node();
        
        new_stack_node->val = k;
        new_stack_node->next = top;
        top = new_stack_node;
        size++;
    }
    
    // Search for Elements in the Stack
    stack_node* search_value(int k)
    {
        stack_node* n = top;
        while((n!=nullptr)&&(n->val!=k))
        {
            n = n->next;
        }
        
        return n;
    }
    
    // Pop operation on the Stack
    void pop()
    {
        if(top==nullptr)
        {
            cout<<"Stack underflow"<<endl;
            return;
        }
        int pop_val = top->val;
        top = top->next; // Now, the top value is the next element in the array
        
        cout<<pop_val<<" is being popped";
        //return pop_val;
    }
    
    // Just return the last element of the Stack without deleting it
    int peek()
    {
        if(top==nullptr)
            cout<<"Stack underflow"<<endl;
        else
            return top->val;
    }
     
    // Get Last Node of the Stack
    stack_node* last_node()
    {
        stack_node* n = top;
        while((n->next)!=nullptr)
        {
            n = n->next;
        }
        return n;
    }
};


int main()
{
    stack s;
    
    // Pushing Elements onto the Stack
    s.push(31);
    s.push(45);
    s.push(57);
    s.push(24);
    
    // Printing the Stack Elements and its length
    s.print();
    cout<<endl<<s.length()<<endl;
    
    // Searching an element in the Stack
    stack_node* res = s.search_value(45);
    cout<<res->val<<endl;
    
    // Getting the top most element in the stack
    cout<<s.peek()<<endl;
    
    // Pushing More Elements
    s.push(33);
    s.push(83);
    s.push(101);
    cout<<endl;
    
    // Popping the Last element of the Stack
    s.print();
    cout<<endl;
    s.pop();
    cout<<endl;
    s.print();
    
    return 0;
}