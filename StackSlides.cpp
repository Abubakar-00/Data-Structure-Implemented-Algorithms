#include<iostream>
using namespace std;

class Stack
{
	int *StackArray;
	int Stacksize;
	int top;
	
	public:
		Stack(int size)
		{
			Stacksize=size;
			StackArray=new int [Stacksize];
			top=-1;
		}
		
		bool isFull()
		{
			if(top==Stacksize-1)
				return true;
			else
				return false;
		}
		
		bool isEmpty()
		{
			if(top==-1)
				return true;
			else
				return false;
		}
		
		void push(int x)
		{
			if(isFull())
				cout<<"The stack is full!!!"<<endl;	
			else
			{
				top++;
				StackArray[top]=x;
			}
		}
		
		void pop(int &x)
		{
			if(isEmpty())
				cout<<"Stack is empty!!!!!"<<endl;
			else
			{
				x = StackArray[top];
				top--;
			}
			
		}
};

int main()
{
	Stack stack(5);
	int catchVar;
	cout << "Pushing 5\n";
	stack.push(5);
	cout << "Pushing 10\n";
	stack.push(10);
	cout << "Pushing 15\n";
	stack.push(15);
	cout << "Pushing 20\n";
	stack.push(20);
	cout << "Pushing 25\n";
	stack.push(25);
	cout << "Popping...\n";
	stack.pop(catchVar);
	cout << catchVar << endl;
	stack.pop(catchVar);
	cout << catchVar << endl;
	stack.pop(catchVar);
	cout << catchVar << endl;
	stack.pop(catchVar);
	cout << catchVar << endl;
	stack.pop(catchVar);
	cout << catchVar << endl;
	return 0;
}

