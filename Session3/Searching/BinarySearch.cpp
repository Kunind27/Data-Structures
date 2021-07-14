#include <iostream>
using namespace std;

int binarySearch(int search_num, int arr[], int len)
{
    int ub = len; // Upper Boundary
    int lb = 0; // Lower Boundary
    
    while(lb<=ub) // Invariant of the Binary Search
    {
        int mid = (lb+ub)/2;
        if(search_num == arr[mid])
        {
            return mid;
        }
        else if(arr[mid]<search_num)
        {
            lb = mid+1
        }
        else
        {
            ub = mid-1
        }
    }
    return -1;
}
int main() 
{
	int search_num = 10;
	// Binary Search Assumes a sorted array - sort your array before putting it into Binary Search
	int a[] = {1,2,3,4,5,7,9,10,11,41};
	
	int pos = binarySearch(search_num, a, sizeof(a)/sizeof(a[0]));
	
	if(pos!=-1)
	    cout<<search_num<<" found at position "<<pos<<endl;
	else
	    cout<<"Element not found in the array"<<endl;
	return 0;
}
