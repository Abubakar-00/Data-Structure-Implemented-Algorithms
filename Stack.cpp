#include<iostream>
using namespace std;

class Stack
{
	private:
		int top; //to record position index
		int arr[]; 
	
	public:
		Stack(int x) //constructor
		{
			top = -1; 
			for(int i=0; i<x; i++) //removing garbage and set to 0 
			{
				arr[i] = 0;
			}
		}
		
		bool isEmpty() //check empty bool provider
		{
			if(top == -1)
				return true;
			else
				return false;
		}
		
		bool isFull() 
		{
			if(top == 4)
				return true;
			else
				return false;
		}
		
		void push(int val)
		{
			if(isFull())
			{
				cout<<"Stack Overflow"<<endl;
			}
			else
			{
				top++;
				arr[top] = val;
			}
		}
		
		int pop()
		{
			if(isEmpty())
			{
				cout<<"Stack Underflow"<<endl;
				return 0;
			}
			else
			{
				int popValue = arr[top];
				arr[top] = 0;
				top--;
				return popValue;
				
			}
		}
		
		int count()
		{
			return(top+1);
		}
		
		int peek(int pos)
		{
			if(isEmpty())
			{
				cout<<"Stack underflow"<<endl;
				return 0;
			}
			else
			{
				return arr[pos];
			}
		}
		
		void isChange(int pos, int val)
		{
			arr[pos] = val;
			cout<<"Value changed at location "<<pos<<endl;
		}
		
		void Display()
		{
			cout<<"All values in Stack are "<<endl;
			for(int i=4; i>=0; i--)
			{
				cout<<arr[i]<<endl;
			}
			cout<<endl;
		}
};

int main()
{
	int option, position, value, size=0;
	cout<<"Enter the size of Stack: ";
	cin>>size;
	Stack s1(size);
	
	do
	{
		cout<<endl;
		cout<<"What operation do u want to perform? Select option number. Enter 0 to exit."<<endl;
		cout<<"1. Push()"<<endl;
		cout<<"2. Pop()"<<endl;
		cout<<"3. isEmpty()"<<endl;
		cout<<"4. isFull()"<<endl;
		cout<<"5. peek()"<<endl;
		cout<<"6. count()"<<endl;
		cout<<"7. change()"<<endl;
		cout<<"8. display()"<<endl;
		cout<<"9. Clear Screen"<<endl<<endl;
		
		cin>>option;
		switch(option)
		{
			case 0:
				return 0;
			case 1:
				cout<<"Enter an Value to push in the Stack: ";
				cin>>value;
				s1.push(value);
				break;
			case 2: 
				cout<<"Pop function called - Poped Value: "<<s1.pop()<<endl;
				break;
			case 3:
				if(s1.isEmpty())
					cout<<"Stack is empty"<<endl;
				else
					cout<<"Stack is not empty"<<endl;
				break;
			case 4:
				if(s1.isFull())
					cout<<"Stack is Full"<<endl;
				else
					cout<<"Stack is not Full"<<endl;
				break;
			case 5:
				cout<<"Enter the position you want to peek: ";
				cin>>position;
				cout<<"Peek function called - Value at position "<<position<<" is "<<s1.peek(position)<<endl;
				break;
			case 6:
				cout<<"Count Function called - Number of values in Stack are: "<<s1.count()<<endl;
				break;
			case 7:
				cout<<"Change Function called - "<<endl;
				cout<<"Enter the position of value you want to change: ";
				cin>>position;
				cout<<endl;
				cout<<"Enter value of item you want to change: ";
				cin>>value;
				s1.isChange(position,value);
				break;
			case 8:
				cout<<"Display Function Called - "<<endl;
				s1.Display();
				break;
			case 9:
				system("cls");
				break;
			default:
				cout<<"Enter proper option number!!"<<endl;
		}
		
	}while(option != 0);
	
	
	return 0;
}

