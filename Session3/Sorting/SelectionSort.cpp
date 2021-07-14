#include <iostream>
using namespace std;

void selectionSort(int a[], int len)
{
    for(int i=0; i<len; i++)
    {
        int min = a[i];
        int min_pos = i; 
        for(int j=i+1; j<len; j++)
        {
            // Finding out the minimum element
            if(a[j]<min)
            {
                min = a[j];
                min_pos = j;
            }
        }
        // Swapping the minium element with a[i]
        int temp = a[i];
        a[i] = a[min_pos];
        a[min_pos] = temp;
    }
}

int main()
{
    int a[] = {4,6,2,1,3,5,10,9,14};
    int len = sizeof(a)/sizeof(a[0]);
    
    selectionSort(a, len);
    
    // printing all elements of the array
    // Pointer to the first element of the array is passed by value to the function selectionSort
    for(int i=0; i<len; i++)
        cout<<a[i]<<" ";
	return 0;
}
