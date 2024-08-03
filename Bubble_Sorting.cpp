#include<iostream>
using namespace std;

void Bubble_Sort(int ar[], int);

int main()
{
	int arr[] = {9, 10, 2, 5, 6,8};
	int size_ = sizeof(arr) / sizeof(arr[0]);
	
	Bubble_Sort(arr,size_); // Calling the function
	
	cout<<"Bubble Sorted array is: "<<endl;

	for(int i=0; i<size_; i++)
	{
		cout<<arr[i]<<" ";
	}

	return 0;
}

void Bubble_Sort(int ar[], int size)
{
	int tmp=0;
	int pass=1;
	bool exchanges;
	
	do
	{
		exchanges = false; 
		for(int i=0; i<size-pass; i++)
		{
			if(ar[i] > ar[i+1]) // Condition to swap
			{
				tmp = ar[i];
				ar[i] = ar[i+1]; // Assiging next index number to previous one
				ar[i+1] = tmp; // Assiging previus index number to next one
				exchanges = true;
			}
		}
		pass++;
	}while(exchanges);
}
