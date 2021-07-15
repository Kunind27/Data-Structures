#include <iostream>
using namespace std;
// Implementing Heap Sort 

void exchange(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void sink(int a[], int len, int i)
{
    // While the Child Index does not become more than the max. possible array index
    while(2*i+1<=len-1)
    {
        int j = 2*i+1; 
        if((j < len-1) && (a[j] < a[j+1])) // Finding out the largest child node
            j++; 
        
        if(a[i]>=a[j]) // Don't do anything if Parent is Larger than Child node
            break;
        
        // Exchanging Largest Child with Parent if Parent is smaller 
        exchange(a,i,j);
        i = j;
    }
}

void heapSort(int a[], int len)
{
    // Creating a Heap out of the Array using a Bottom Up approach. 
    //'i' corresponds to index of all parent nodes
    for(int i=(len-1)/2; i>=0; i--)
        sink(a, len, i);

    // Extracting the Top Most element
    while(len>1)
    {
        exchange(a,0,len-1); // Exchange Max Element with Bottom Most Element
        len--; // Since we don't considered the max fixed element as part of the heap
        sink(a,len,0); // Sinking Element at the top to create a Heap Again
    }
}

int main()
{
    int a[] = {4,6,1,2,3,5,10,9,14,73,67,22};
    int len = sizeof(a)/sizeof(a[0]);
    
    // Printing original array 
    cout<<"Original Array"<<endl;
    for(int i=0; i<len; i++)
        cout<<a[i]<<" ";
    cout<<endl<<"\n";
    
    // Sort the Array via Heap Sort
    heapSort(a, len);
    
    // Printing sorted array 
    cout<<"Sorted Array"<<endl;
    for(int i=0; i<len; i++)
        cout<<a[i]<<" ";
	cout<<endl;
	
	return 0;
}
