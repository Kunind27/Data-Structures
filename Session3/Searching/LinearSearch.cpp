#include <iostream>
using namespace std;

int linearSearch(int search_num, int arr[], int len)
{
    for(int i=0; i<len; i++)
    {
        if(arr[i]==search_num)
            return i;
    }
    return -1; // Indicates number not found
}

int main() 
{
	int search_num = 4;
	int a[] = {3,2,1,5,41,7,11,4,9,10};
	
	int pos = linearSearch(search_num, a, sizeof(a)/sizeof(a[0]));
	
	if(pos!=-1)
	    cout<<search_num<<" found at position "<<pos<<endl;
	else
	    cout<<"Element not found in the array"<<endl;
	return 0;
}
