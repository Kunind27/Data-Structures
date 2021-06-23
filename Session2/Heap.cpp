#include <iostream>
#include<cmath>
using namespace std;

// Implementing Max Heaps/ Priority Queue
class MaxHeap
{
    int N; // Size of the Array/ Queue
    int* arr; // Array to store the keys
    
    bool less(int i, int j)
    {
        return arr[i]<arr[j];
    }
    
    void exchange(int i, int j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    // Restore Heap Order if Child Key > Parent Key
    void swim(int k)
    {
        while(k>0 && less((k-1)/2, k) ) // Parent of node k is at [(k-1)/2]
        {
            exchange((k-1)/2, k);
            k = (k-1)/2;
        }
    }
    
    //Parent's Key becomes lesser than both its children's key. Replace parent's
    // key with the larger child
    void sink(int k)
    {
        while(2*k+1 <= N)
        {
            int j = 2*k+1;
            if(j < N && less(j, j+1)) // To determine the larger child node
                j++;
                
            if(!less(k, j)) // Don't do anything if Parent Node > Child Nodes
                break;
            
            exchange(k, j);
            k = j;
        }
    }
    
    public:
    // Constructor
    MaxHeap(int capacity, int array[], int len_array)
    {
        N = len_array;
        arr = new int[capacity];
        
        for(int i=0; i<N; i++)
            arr[i] = array[i];
            
        // Need to put arr[] in Heap Order
        for(int i = (N-1)/2;  i>=0; i--)
            sink(i);
    }
    
    // Insert a New Node into the array
    void insert(int key)
    {
        arr[N] = key;
        swim(N); // To make sure heap order is maintained
        N++; // Since number of elements in the array have increased
    }
    
    int delete_max()
    {
        int max = arr[0];
        exchange(0, N-1); // Replacing it with the key of last node
        sink(0); // Sinking to restore heap order
        return max;
    }
    
    void print()
    {
        for(int i=0; i< N; i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    
};

int main()
{
   // Defining the Heap
   int capacity = 100;
   int arr[] = {1,2,7,5,13,4,9,8,16};
   MaxHeap h = MaxHeap(capacity, arr, 9);
   
   // Printing out the Heap Ordered Array
   h.print();
   
   // Inserting a New Element into the Heap
   h.insert(10); h.insert(17); h.insert(3);
   h.print();
   
   //Deleting Elements from the Heap;
   cout<<h.delete_max()<<" was deleted from the heap"<<endl;
   h.print();
   return 0;
}
