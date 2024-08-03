#include<iostream>
using namespace std;

void Selection_sort(int [], int );

int main()
{
	int arr[] = {9, 10, 2, 5, 6,8};
	int size_ = sizeof(arr) / sizeof(arr[0]);
	
	Selection_sort(arr,size_); // Calling the function
	
	cout<<"Selection Sorted array is: "<<endl;

	for(int i=0; i<size_; i++)
	{
		cout<<arr[i]<<" ";
	}

	return 0;
}

void Selection_sort(int ar[], int size)
{
	int tmp, max_index;
	
	for(int rightmost= size-1; rightmost>0; rightmost--)
	{
		max_index = 0;
		for(int current=1; current<=rightmost; current++) // loop for finding max
		{
			if(ar[current] > ar[max_index]) // Condition to find max
				max_index = current;
		}
		
		if(ar[max_index] > ar[rightmost]) // Condition to swap with right most index number
		{
			tmp = ar[max_index];
			ar[max_index] = ar[rightmost];
			ar[rightmost] = tmp;
		}		
	}
}

