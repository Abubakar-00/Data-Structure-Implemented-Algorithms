#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node *next;
	Node()
	{
		data=0;
		next=NULL;
	}
};

class DynQueue
{
	private:
		Node *front, *rear;
		int num;
	public:
		DynQueue()
		{
			front=rear=NULL;
			num=0;
		}
		
		bool isEmpty()
		{
			if(num)
				return false;
			else
				return true;
		}
		
		void Enqueue(int x)
		{
			Node *newNode = new Node();
			newNode->data=x;
			
			if(front == NULL)
			{
				front = rear =newNode;
				num++;
			}
			else
			{
				rear->next=newNode;
				rear = newNode;
				num++;
			}
		} 
		
		void Dequeue()
		{
			if(!isEmpty())
			{
				Node* temp = front;
				Node* delNode;
				front = temp->next;
				delNode=temp;
				delete delNode;
				num--;
			}
			else 
				cout<<"List is already empty!!!"<<endl;
		} 
		
		void display()
		{
			if(!isEmpty())
			{
				Node* temp = front;
				while(temp && temp->next != NULL)
				{
					cout<<temp->data<<"->";
					temp = temp->next;
				}
				cout<<"NULL"<<endl;
			}
			else 
				cout<<"List is already empty!!!"<<endl;
		}
};

int main()
{
	DynQueue q1;
	q1.Enqueue(1);
	q1.Enqueue(2);
	q1.Enqueue(3);
	q1.Enqueue(4);
	
	q1.display();
	
	q1.Dequeue();
	
	q1.display();
	
	q1.Enqueue(10);
	q1.Enqueue(2);
	q1.display();
	
	return 0;
}

