#include <iostream>
using namespace std;

struct queue_node
{
    int val;
    queue_node* next;
};

class queue
{
    private:
    queue_node* front;
    queue_node* rear;
    int size;
    
    public:
    // Constructor
    queue()
    {
        size = 0;
        front = nullptr;
        rear = nullptr;
    }
    
    // Destructor
    ~queue()
    {
        queue_node* n = front;
        while(n!=nullptr)
        {
            delete n;
            n = n->next;
        }
    }
    
    // Is the Queue Empty
    bool is_empty()
    {
         return (*this).length()==0;
    }
    
    // Return Size of the Queue
    int length()
    {
        return size;
    }
    
    // Printing the entries of the Queue
    void print()
    {
        queue_node* n = front;
        while(n!=nullptr)
        {
            cout<<n->val<<" ";
            n = n->next;
        }
        cout<<endl;
    }
    
    // Enqueueing a new element into the queue
    void enqueue(int k)
    {
        // Allocating Memory to the New Stack Node
        queue_node* new_queue_node = new queue_node();
        new_queue_node->val = k;
        new_queue_node->next = nullptr;
        
        if(front==nullptr) //Size of the Queue is 0
        {
            front = rear = new_queue_node;
        }
        else
        {
            // The original rear element now points to this new element
            rear->next = new_queue_node;
            // Changing the rear node
            rear = new_queue_node;
        }
        size++;
    }
    
    // Search for an Element in the Queue
    queue_node* search_value(int k)
    {
        queue_node* n = front;
        while((n!=nullptr)&&(n->val!=k))
            n = n->next;
        
        return n;
    }
    
    // Dequeueing the Queue
    void dequeue()
    {
        if(front==nullptr)
        {
            cout<<"Stack underflow"<<endl;
            return;
        }
        int dequeue_val = front->val;
        front = front->next; // Now, the top value is the next element in the array
        
        // Since when size = 1, we put both front and rear as that element
        if(front==nullptr)
        {
            rear = nullptr;
        }
        
        cout<<dequeue_val<<" is being dequeued"<<endl;
        size--;
        //return dequeue_val;
    }
    
    // Just return the Front element of the Queue without dequeueing it
    int peek()
    {
        if(front==nullptr)
            cout<<"Stack underflow"<<endl;
        else
            return front->val;
    }
     
    // Get Rear Node of the Stack
    int last_node()
    {
        return rear->val;
    }
};


int main()
{
    queue q;
    
    // Enqueueing Elements onto the Queue
    q.enqueue(31);
    q.enqueue(45);
    q.enqueue(57);
    q.enqueue(24);
    
    // Printing the Queue Elements and its length
    q.print();
    cout<<q.length()<<endl;
    
    // Searching an element in the Queue
    queue_node* res = q.search_value(45);
    cout<<res<<endl;
    
    // Getting the top most element in the Queue
    cout<<q.peek()<<endl;
    
    // Enqueueing More Elements
    q.enqueue(33);
    q.enqueue(83);
    q.enqueue(101);
    
    // Dequeueing the Queue
    q.print();
    q.dequeue();
    q.print();
    
    // Is the Queue empty
    cout<<q.is_empty()<<endl;
    
    // Get the last node of the Queue
    cout<<q.last_node()<<endl;
    return 0;
}