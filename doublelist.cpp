#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node * next;
	Node * previous;
	Node(){
		data=0;
		next=previous=NULL;
	}
};

class Dlist{
	Node * head, *tail;
	public:
		Dlist(){
			head=tail=NULL;
		}
		void insert(int x){
			Node * nw = new Node();
			nw->data=x;
			if(head==NULL && tail==NULL){
				head=nw;
				tail=nw;
//				return;
			}
			else{
				Node *temp = head;
				while(temp && temp->next!=NULL){
					temp = temp->next;
				}
					temp->next=nw;
					nw->previous=temp;
			}
		}
		void display(){
			Node *temp=head;
			while(temp && temp->next!=NULL){
				cout << temp->data << "->";
				temp=temp->next;
			}
			cout<<"NULL";
		}
		
		void deletee(int x){
			if(head!=NULL){
				Node *temp = head;
				while(temp && temp->data != x){
					temp= temp->next;
				}
				if(temp->next!=NULL && temp->previous!=NULL){
				temp->previous->next = temp->next;
				temp->next->previous = temp->previous;
				}
				else if(temp->next==NULL)
				temp->previous->next=NULL;
				else{
				temp->next->previous=NULL;
				head=temp->next;
				}
			}
		}
		void swap_node()
		{
			Node*temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			
			Node* temp2 = temp->previous;
			temp->next = head->next;
			head->next->previous=temp;
			temp2->next=head;
			head->previous=temp2;
			head->next=NULL;
			temp->previous=NULL;
		}
};


int main()
{
	Dlist d1;
	d1.insert(1);
	d1.insert(2);
	d1.insert(3);
	d1.insert(4);
	d1.insert(5);
	d1.insert(6);
	d1.insert(7);
	d1.display();
	d1.swap_node();
	d1.display();
	
	
	
	return 0;
}

