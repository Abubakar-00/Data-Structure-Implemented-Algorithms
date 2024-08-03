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
		
		void Dequeue(int &x)
		{
			if(!isEmpty())
			{
				x = front->data;
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
	
	// BFS IMPLEMENTATION
	
	int node, i=0;
	int visited[7]={0,0,0,0,0,0,0};
	int g[7][7] = {
		{0,1,1,1,0,0,0},
		{1,0,0,1,0,0,0},
		{1,1,0,1,1,0,0},
		{1,0,1,0,1,0,0},
		{0,0,1,1,0,1,1},
		{0,0,0,0,1,0,0},
		{0,0,0,0,1,0,0}
		};
	
	cout<<i<<" ";
	visited[i]=1;
	q1.Enqueue(i); // Enqueue for exploration
	
	while(!q1.isEmpty())
	{
		//node = q1.Dequeue();
		q1.Dequeue(node);
		
		for(int j=0; j<7; j++)
		{
			if(g[node][j] ==1 && !visited[j])
			{
				cout<<j<<" ";
				visited[j]=1;
				q1.Enqueue(j);
			}
		}
	}
	
	return 0;
}

