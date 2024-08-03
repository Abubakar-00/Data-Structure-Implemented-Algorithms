#include <iostream>
using namespace std;

class Node 
{
	public:
		int data;
	  	Node* next;
};

class Stack
{
 	private:
  		Node* top;

 	public:
  		Stack() { top = NULL; }

	  	void push(int value) 
		{
		    Node* new_node = new Node;
		    new_node->data = value;
		    new_node->next = top;
		    top = new_node;
	    }

	  	void pop() 
		{
			if (top == NULL) 
			{
			    cout << "Error: stack is empty" <<endl;
			    return;
			}
			Node* temp = top;
			top = top->next;
		    delete temp;
		}

		int peek()
		{
		    if (top == NULL) 
			{
			    cout << "Error: stack is empty" <<endl;
			    return -1;
		    }
		    return top->data;
		}

  		bool isEmpty() { return top == NULL; }
};

int main()
{
  Stack stack;

  stack.push(1);
  stack.push(2);
  stack.push(3);

  cout << "Top element is: " << stack.peek() <<endl;

  stack.pop();
  cout << "Top element is: " << stack.peek() <<endl;

  stack.pop();
  cout << "Top element is: " << stack.peek() <<endl;

  stack.pop();

  if (stack.isEmpty()) 
    cout << "Stack is empty" <<endl;
  else 
    cout << "Stack is not empty" <<endl;

  return 0;
}

