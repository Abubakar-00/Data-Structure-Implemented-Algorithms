#include <iostream>
using namespace std;

void merge(int* arr, int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	int k = 0;
	int temp[right - left + 1];
	
	while (i <= mid && j <= right)
	{
		if (arr[i] < arr[j])
		{
	    	temp[k++] = arr[i++];
	    } 
		else
		{
	    	temp[k++] = arr[j++];
	    }
	}
	
	while (i <= mid)
	{
		temp[k++] = arr[i++];
	}
	
	while (j <= right)
	{
		temp[k++] = arr[j++];
	}
	
	for (int l = 0; l < k; l++)
	{
		arr[left + l] = temp[l];
	}
}

void mergeSort(int* arr, int left, int right)
{
	if (left < right)
	{
	    int mid = left + (right - left) / 2; 	// Calculating Mid-Index of array 
	    
		mergeSort(arr, left, mid);			    // For dividing array in 1st portion
	    mergeSort(arr, mid + 1, right);		    // For dividing array in 2nd portion
		merge(arr, left, mid, right);           // Sorting and merging divided portions
  	}
}

int main()
{
	int arr[] = {5, 2, 4, 6, 1, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	mergeSort(arr, 0, n - 1);				// Calling Merge sort Function
	
	for(int i = 0; i < n; i++) 			    // Printing the sorted Array
	{
		cout << arr[i] << " ";
	}
	cout <<endl;
	return 0;
}

