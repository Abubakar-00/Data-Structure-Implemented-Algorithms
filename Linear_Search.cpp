#include<iostream>
using namespace std;

bool Linear_Search(int [],int ,int ,int & ); 

int main()
{
	int size = 10;
	int arr[size] = {1,2,3,4,5,6,7,8,9,10};
	

	cout<<"Enter the number you want to find index: ";
	int user;
	cin>>user;
	
	int catcher=0;
	bool got;

	got = Linear_Search(arr,size,user,catcher); 						// Calling the function

	if(got)
		cout<<"Entered number found at index: "<<catcher<<endl;
	else
		cout<<"Entered number not found!!!"<<endl;

	return 0;
}

bool Linear_Search(int ar[], int nsize, int num_find, int & catcher_) 	// Function for linear search
{
	for(int i=0; i<nsize; i++)
	{
		if(ar[i] == num_find)
		{
			
			catcher_ = i; 			// on finding required number we break(return) for optimization
			return true;
		}
			
	}
	return false;
}
