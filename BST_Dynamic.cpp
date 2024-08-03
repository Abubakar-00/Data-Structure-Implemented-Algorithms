#include<iostream>
#define SPACE 10
using namespace std;

class TreeNode
{	
	public:
		int value;
		TreeNode *right;
		TreeNode *left;
		
		TreeNode(){value=0; right=left=NULL;} // Default constructor
		TreeNode(int x){value=x; right=left=NULL;} // for inserting value in node !!
};

class BST
{
	public:
		TreeNode *root;
		
		bool isEmpty(){return (root==NULL);} // empty function
		
		void insertNode(TreeNode *newNode) // Insertion function
		{
			if(root == NULL)
			{
				root = newNode;
				cout<<"Value Inserted as root node!!"<<endl;
			}
			else
			{
				TreeNode *tmp = root;
				while(tmp != NULL)
				{
					if(newNode->value == tmp->value) // To tackle alredy exisiting case
					{
						cout<<"Value Already exist!! Insert Another Value!!"<<endl;
						return;
					}
					else if((newNode->value < tmp->value) && (tmp->left==NULL)) // assign to left
					{
						tmp->left=newNode;
						cout<<"Value Inserted on LEFT!"<<endl;
						break;
					}
					else if(newNode->value < tmp->value) //if alredy have left then Traverse tmp to left
						tmp = tmp->left;
					
					else if((newNode->value > tmp->value) && (tmp->right==NULL)) // assign to right
					{
						tmp->right=newNode;
						cout<<"Value Inserted on RIGHT!"<<endl;
						break;
					}
					else if(newNode->value < tmp->value) //if alredy have right then Traverse tmp to right
						tmp = tmp->right; 
				}
			}
		}
		
		TreeNode *insertNodeRecusively(TreeNode *root, TreeNode *new_node) // Insertion-Recursive function 
		{
			if(root == NULL) // NULL Case
			{
				root = new_node;
				return root;
			}
			
			if(new_node->value < root->value) // left-subtree traversal
				root->left =  insertNodeRecusively(root->left,new_node);
				
			else if(new_node->value > root->value) // Right-subtree traversal
				root->right =  insertNodeRecusively(root->right,new_node);
				
			else // Duplication of VALUE case
			{
				cout<<"No Duplication of Values Allowed!!"<<endl;
				return root;
			}
			return root;
		}
		
		void print_2D(TreeNode *r, int space)
		{
			if (r == NULL) // Base case  1
      			return;
    
			space += SPACE; // Increase distance between levels   2
    
			print_2D(r -> right, space); // Process right child first 3 
    		cout << endl;
    
			for (int i = SPACE; i < space; i++) // 5 
      		cout << " "; // 5.1  
    		cout << r -> value << "\n"; // 6
    
			print_2D(r -> left, space); // Process left child  7
		}
		
		void printPreorder(TreeNode *r) // node-left-right NLR (Pre-NLR)
		{
			if(r==NULL) //Base case 
				return; 
				
			cout<<r->value<<" ";
			printPreorder(r->left);
			printPreorder(r->right);
		}
		
		void printInorder(TreeNode *r) // left-node-right LNR (IN-LNR)
		{
			if(r==NULL) //Base case
				return;
				 
			printInorder(r->left);
			cout<<r->value<<" ";
			printInorder(r->right);
		}
		
		void printPostorder(TreeNode *r) // left-right-node LRN (Pos-LRN)
		{
			if(r==NULL) //Base case
				return; 
			printPostorder(r->left);
			printPostorder(r->right);
			cout<<r->value<<" ";
		}
		
		TreeNode *itreativeSearch(int x) // simple search no recursion !!
		{
			if(root == NULL) return root;
			else
			{
				TreeNode* tmp = root;
				while(tmp != NULL)
				{
					if(tmp->value == x) // founding condition
						return tmp;
					else if(x>tmp->value) 
						tmp=tmp->right; // proceeed to right
					else 
						tmp=tmp->left; // proceeed to left
					
				}
				return NULL;
			}
		}
		
		int height(TreeNode *r)
		{
			if(r == NULL)
				return -1;
			else
			{
				int lheight = height(r->left); // Collect recursively height on left side
				int rheight = height(r->right);// Collect recursively height on right side 
				
				if(lheight > rheight) // if left found to larger return it else return right one
					return (lheight+1); 
				else
					return (rheight+1);
			}
		}
		
		// For print BFS
		void printGivenLevel(TreeNode *r,int level)
		{
			if (r == NULL)
				return;
			else if(level == 0)
				cout<<r->value<<" ";
			else
			{
				printGivenLevel(r->left, level-1);
				printGivenLevel(r->right, level-1);
			}
		}
		
		void printLeveLOrderBFS(TreeNode *r)
		{
			int h = height(r);
			for(int i=0; i<=h; i++)
			printGivenLevel(r,i);
		}
		
		// For Deletion
		TreeNode *minValueNode(TreeNode* node) // Finding smallest value usually for Right side for case of node with right & left child
		{
			TreeNode *current = node;
			while(current->left != NULL) //finding leftmost leaf
				current = current->left;
			return current;
		}
		
		TreeNode *deleteNode(TreeNode *r, int x)
		{
			if(r = NULL) // Base case
				return NULL;
			
			else if(x < r->value) // if user value is less then root's one then we proceed to left sub-tree
				r->left = deleteNode(r->left, x);

			else if(x > r->value) // if user value is less then root's one then we proceed to right sub-tree
				r->right = deleteNode(r->right, x);
				
			else // When value matches !!
			{
				// if & else-if for node with one or no child
				if(r->left == NULL) // node with only right or no child
				{
					TreeNode *tmp = r->right;
					delete r;
					return tmp;
				}
				
				else if(r->right == NULL) // node with only left or no child
				{
					TreeNode *tmp = r->left;
					delete r;
					return tmp;
				}
				
				else // Node with 2 children
				{
					TreeNode *tmp = minValueNode(r->right); // Getting smallest value in right side of tree/sub-tree
					r->value = tmp->value; // coping smallest found node value in that node which is supposed to be deleted
					r->right = deleteNode(r->right,tmp->value); // deleting the smallest value so, no copy exist
				}
			}
		}
};

int main()
{
	BST obj;
	int option, user;
	do
	{
		cout<<"Enter the option you want to perform?";
		cout<<"Selection option number. (0 to Exit)"<<endl;
		cout<<"1. Insert Node"<<endl;
		cout<<"2. Search Node"<<endl;
		cout<<"3. Delete Node"<<endl;
		cout<<"4. Print Node"<<endl;
		cout<<"5. Height of Tree"<<endl;
		cout<<"6. Clear screen"<<endl;
		cout<<"0. Exit Program"<<endl;
		
		
		cin>>option;
		
		TreeNode *new_Node= new TreeNode();
		switch(option)
		{
			case 0:
				break;
			
			case 1:
				cout<<"INSERT"<<endl;
				cout<<"Enter Value of TREE NODE to INSERT in BST: ";
				cin>>user;
				
				new_Node->value=user;
				obj.root = obj.insertNodeRecusively(obj.root,new_Node);
				//obj.insertNode(new_Node);
				cout<<endl;
				break;
				
			case 2:
				cout<<"SEARCH"<<endl;
				cout<<"Enter the value of Node to Seach in BST: ";
				cin>>user;
				new_Node = obj.itreativeSearch(user);
				if(new_Node) 
					cout<<"Value Found"<<endl;
				else 
					cout<<"Value Not Found"<<endl;
				break;
			
			case 3:
				cout<<"DELETE"<<endl;
				cout<<"Enter value of TREE NODE to DELETE in BST:";
				cin>>user;
				new_Node = obj.itreativeSearch(user);
				if(new_Node != NULL)
				{
					obj.deleteNode(obj.root, user);
					cout<<"Value Deleted"<<endl;
				}
				else
					cout<<"Value NOT FOUND"<<endl;
				break;
			
			case 4:
				cout<<"PRINT AND TRAVERSE"<<endl;
				obj.print_2D(obj.root,5);
				cout<<endl<<endl;
				
				cout<<"PRINT BFS"<<endl;
				obj.printLeveLOrderBFS(obj.root);
				cout<<endl<<endl;
				
//				cout<<"Pre-Order Printing"<<endl;
//				obj.printPreorder(obj.root);
//				cout<<endl<<endl;

//				cout<<"In-Order Printing"<<endl;
//				obj.printInorder(obj.root);
//				cout<<endl<<endl;

//				cout<<"Post-Order Printing"<<endl;
//				obj.printPostorder(obj.root);
//				cout<<endl<<endl;

				break;
			
			case 5:
				cout<<"Height of TREE"<<endl;
				cout<<"Height: "<<obj.height(obj.root);
				cout<<endl;
				break;
			
			case 6:
				cout<<"CLS SCR"<<endl;
				system("cls");
				break;
			
			default:
				cout<<"Enter Proper Option Number !!!"<<endl;
		}
				
	} while(option != 0);
	return 0;
}
