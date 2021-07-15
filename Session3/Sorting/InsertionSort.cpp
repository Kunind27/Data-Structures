#include <iostream>
using namespace std;
// Implementing Insertion Sort 

void insertionSort(int a[], int len)
{
    // Looping from the firt element to the last element
    for(int i=1; i<len; i++)
    {
        for(int j=i; j>0; j--)
        {
            // Swapping the elements if they are in the wrong order
            if(a[j]<a[j-1])
            {
                // Keep Swapping Elements to keep the first element fixed 
                int temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
            else
                break; // Invariant is that theelements are before a[i] are sorted order so why to do unnecessary operations
        }
        // Printing Each Step in the Iteration
        for(int k=0; k<len; k++)
            cout<<a[k]<<" ";
        cout<<endl;
    }
}

int main()
{
    int a[] = {4,6,2,1,3,5,10,9,14,73,67,22};
    int len = sizeof(a)/sizeof(a[0]);
    
    // Printing original array 
    cout<<"Original Array"<<endl;
    for(int i=0; i<len; i++)
        cout<<a[i]<<" ";
    cout<<endl<<"\n";
    
    // Sorting the Array
    insertionSort(a, len);
    
    // Printing sorted array 
    cout<<"Sorted Array"<<endl;
    for(int i=0; i<len; i++)
        cout<<a[i]<<" ";
	cout<<endl;
	
	return 0;
}
