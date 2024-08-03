#include<iostream>
using namespace std;

int Binary_Search(int [], int ,int );

int main()
{
	int size = 10;
	int arr[size] = {1,22,35,43,52,65,71,83,94,101};


	cout<<"Enter the number you want to find index: ";
	int user;
	cin>>user;
	
	int got;
	got = Binary_Search(arr,size,user); 			// Calling the function

	if(got != (-1))
		cout<<"Entered number found at index: "<<got<<endl;
	else
		cout<<"Entered number not found!!!"<<endl;

	return 0;
}

int Binary_Search(int ar[], int nsize,int num_find) 	// Function for Binary search
{
	int first, last = nsize-1, middle, position = -1;
	bool found = false; 							// flag to end while

	while(!found && first <= last)
	{
		middle = (first+last)/2; 					//mid-point
		
		if(ar[middle] == num_find) 					// matching & assigning number
		{
			found = true;
			position = middle;
		}
		else if(ar[middle] > num_find) 				// condition if middle index number > then required number
		{
			last = middle-1;
		}		
		else  										// condition if middle index number < then required number
		{
			first = middle+1;
		}

	}
	return position;
}

