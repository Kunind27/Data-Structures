#include <iostream>
using namespace std;
// Implementing Merge Sort 

void merge(int a[], int temp[], int low, int mid, int high)
{
    // Storing the Array 'a' in the temporary storage Array
    for(int i=low; i<=high; i++)
        temp[i] = a[i];
        
    // Merging Begins
    int i = low; 
    int j = mid+1;
    for(int k=low; k<=high; k++)
    {
        if(i>mid)
            a[k] = temp[j++];
        else if(j>high)
            a[k] = temp[i++];
        else if(temp[j]<temp[i])
            a[k] = temp[j++];
        else
            a[k] = temp[i++];
    }
}

void mergeSort(int a[], int temp[] ,int low, int high)
{
    // We implement the algorithm using Recursion
    if(high<=low) // Base Case
        return;
    int mid = low+(high-low)/2;
    mergeSort(a, temp, low, mid); // Divide into Halves and Sort those Halves
    mergeSort(a, temp, mid+1, high);
    merge(a, temp, low, mid, high); // Merge the Sorted Halves
}

int main()
{
    // Declaring the Test Array
    int a[] = {4,6,1,2,3,5,10,9,14,73,67,22};
    int len = sizeof(a)/sizeof(a[0]);
    
    // Temporary Array to store array elements
    int temp[len];
    
    // Printing original unsorted array 
    cout<<"Original Array"<<endl;
    for(int i=0; i<len; i++)
        cout<<a[i]<<" ";
    cout<<endl<<"\n";
    
    // Sort the Array via Merge Sort
    mergeSort(a, temp, 0, len-1);
    
    // Printing sorted array 
    cout<<"Sorted Array"<<endl;
    for(int i=0; i<len; i++)
        cout<<a[i]<<" ";
	cout<<endl;
	
	return 0;
}
