#include<iostream>
using namespace std;

class Queue
{
	private:
		int front;
		int rear;
		int arr[5];
	
	public:
		Queue()
		{
			front = -1;
			rear = -1;
			for(int i=0; i<5; i++)
			{
				arr[i]=0;
			}
		}

		bool IsEmpty()
		{
			if(front == -1 && rear == -1)
				return true;
			else
				return false;
		}

		bool IsFull()
		{
			if(rear == 4)
				return true;
			else 
				return false;
		}

		void Enqueue(int val)
		{
			if(IsFull())
			{
				cout<<"Queue if Full"<<endl;
				return;
			}
			else if(IsEmpty())
			{
				rear = front = 0;
				arr[rear] = val;
			}
			else
			{
				rear++;
				arr[rear] = val;
			}
		}

		int Dequeue()
		{
			int x;

			if(IsEmpty())
			{
				cout<<"Queue is Empty"<<endl;
				return 0;
			}
			else if(front == rear)
			{
				x = arr[front];
				arr[front]=0;
				rear = -1;
				front = -1;
				return x;
			}
			else
			{
				x = arr[front];
				arr[front]=0;
				front++;
				return x;
			}
		}

		int Count()
		{
			return (rear-front+1);
		}

		void Display()
		{
			cout<<"All the values in Queue are - "<<endl;
			for(int i=0; i<5; i++)
			{
				cout<<arr[i]<<" ";
			}
		}
};

int main()
{
	Queue q1;
	int option,value;


	do
	{
		cout<<"Select option number. Enter 0 to exit."<<endl;
		cout<<"1. Enqueue()"<<endl;
		cout<<"2. Dequeue()"<<endl;
		cout<<"3. IsEmpty()"<<endl;
		cout<<"4. IsFull()"<<endl;
		cout<<"5. Count()"<<endl;
		cout<<"7. Display()"<<endl;
		cout<<"8. Clear Screen()"<<endl<<endl;

		cin>>option;

		switch(option)
		{
			case 0:
				break;
			case 1:
				cout<<"Enqueue Operation \nEnter an item in the Queue: ";
				cin>>value;
				q1.Enqueue(value);		
				break;
			case 2:
				cout<<"Dequeue Operation \nDequeued Value: "<<q1.Dequeue()<<endl;
				break;
			case 3:
				if(q1.IsEmpty())
					cout<<"Queue is Empty"<<endl;
				else
					cout<<"Queue is not Empty"<<endl;
				break;
			case 4:
				if(q1.IsFull())
					cout<<"Queue is Full"<<endl;
				else
					cout<<"Queue is not Full"<<endl;
				break;
			case 5:
				cout<<"Count Operation \nCount of items in Queue: "<<q1.Count()<<endl;
				break;
			case 6:
				cout<<"Display Function Called -"<<endl;
				q1.Display();
				cout<<endl;
				break;
			case 7:
				system("cls");
				break;
			default:
				cout<<"Enter a proper option."<<endl;
				break;
		}
	}while(option!=0);

	return 0;
}