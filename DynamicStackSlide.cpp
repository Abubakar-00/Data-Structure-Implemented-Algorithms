#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node *next;
		Node(int x)
		{
			data = x;
			next = NULL;
		}
};

class DynamicStack
{
	private:
		int items;
		Node *top;
	public:
		DynamicStack()
		{
			items=-1;
			top=NULL;
		}
		
		bool isEmpty()
		{
			if(top==NULL)
				return 1;
			else
				return 0;
		}
		
		void push(int n)
		{
			Node *newNode = new Node(n);
			if(top == NULL)
			{
				top = newNode;
			}
			else
			{
				newNode->next=top;
				top=newNode;
			}
			items++;
		}
		
		void pop(int &n)
		{
			if(isEmpty())
			{
				cout<<"Stack is Empty!!!!"<<endl;
			}
			else
			{
				Node *temp = top;
				n=top->data;
				top=top->next;
				delete temp;
			}
		}
};

int main()
{
	DynamicStack stack;
	int catchVar;
	cout << "Pushing 5\n";
	stack.push(5);
	cout << "Pushing 10\n";
	stack.push(10);
	cout << "Pushing 15\n";
	stack.push(15);
	cout << "Popping...\n";
	stack.pop(catchVar);
	cout << catchVar << endl;
	stack.pop(catchVar);
	cout << catchVar << endl;
	stack.pop(catchVar);
	cout << catchVar << endl;
	cout << "\nAttempting to pop again... ";
	stack.pop(catchVar);
	return 0;
}

