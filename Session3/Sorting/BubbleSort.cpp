#include <iostream>
using namespace std;
// Implementing Bubble Sort 

void bubbleSort(int a[], int len)
{
    // Looping only until the second last element
    for(int i=0; i<len-1; i++)
    {
        bool swapped = false;
        for(int j=0; j<len-1-i; j++)
        {
            // Swapping the elements if they are in the wrong order
            if(a[j]>a[j+1])
            {
                // Invariant is that the last elements are the largest in the array and get fixed.
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                swapped = true;
            }
        }
        // Automatically break the loop early if there have been no swaps - that means loop is sorted
        if(swapped==false)
            break;
    }
}

int main()
{
    int a[] = {4,6,2,1,3,5,10,9,14,73,67,22};
    int len = sizeof(a)/sizeof(a[0]);
    
    // printing original array 
    cout<<"Original Array"<<endl;
    for(int i=0; i<len; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    
    bubbleSort(a, len);
    
    // printing sorted array 
    cout<<"Sorted Array"<<endl;
    for(int i=0; i<len; i++)
        cout<<a[i]<<" ";
	
	return 0;
}
