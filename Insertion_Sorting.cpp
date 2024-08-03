#include <iostream>
using namespace std;

void insertion_Sort(int [], int );


int main() 
{
  int arr[] = {1,8,4,6,0,3,5,2,7,9};
  int size_ = sizeof(arr) / sizeof(arr[0]);
  
  insertion_Sort(arr, size_);
  
  cout<<"Insertion Sorted array is: "<<endl;

	for(int i=0; i<size_; i++)
	{
		cout<<arr[i]<<" ";
	}
	
	return 0;
}

void insertion_Sort(int ar[], int size)
{
	int key,j;
	
  for (int step = 1; step < size; step++) 
  {
  	
	key = ar[step];
    j = step - 1;

    
	while (key < ar[j] && j >= 0)
	{
    	ar[j + 1] = ar[j];
    	--j;
    }
    
	ar[j + 1] = key;
  }
}
