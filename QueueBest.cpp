#include<iostream>
using namespace std;

class IntQueue
{
	private:	
		int *queueArray;
		int queueSize;
		int front;
		int rear;
		int numItems;
	public:
		IntQueue(int);
		~IntQueue();
		void enqueue(int);
		int dequeue(int &);
		bool isEmpty();
		bool isFull();
		void clear();
};

IntQueue::IntQueue(int s) //constructor
{	queueArray = new int[s];
	queueSize = s;
	front = -1;
	rear = -1;
	numItems = 0;
}

IntQueue::~IntQueue() //destructor
{
	delete [] queueArray;
}

bool IntQueue::isEmpty(void)
{	
	if (numItems)
		return false;
	else
		return true;
}

bool IntQueue::isFull()
{
	if (numItems < queueSize)
		return false;
	else
		return true;
}

void IntQueue::enqueue(int num)
{
	if (isFull())
		cout << "The queue is full.\n";
	else	
	{
		// Calculate the new rear position		
		rear = (rear + 1) % queueSize;
		// Insert new item
		queueArray[rear] = num;
		// Update item count
		numItems++;
	}
}

int IntQueue::dequeue(int &num)
{
	if (isEmpty())
	{
		cout << "The queue is empty.\n";
		return false;
	}

	// Move front
	front = (front + 1) % queueSize;
	// Retrieve the front item
	num = queueArray[front];
	// Update item count
	numItems--;
	return true;
}

void IntQueue::clear()
{
	front = - 1;
	rear = - 1;
	numItems = 0;
}

int main()
{
	IntQueue iQueue(5);
	cout << "Enqueuing 5 items...\n";
	// Enqueue 5 items.
	for (int x = 0; x < 5; x++)		
		iQueue.enqueue(x);
	
	// Attempt to enqueue a 6th item.
	cout << "Now attempting to enqueue again...\n";
	iQueue.enqueue(5);
	
	// Deqeue and retrieve all items in the queue
	cout << "The values in the queue were:\n";
	while (!iQueue.isEmpty())
	{	int value;
		iQueue.dequeue(value);
		cout << value << endl;
	}
	
	return 0;
}

