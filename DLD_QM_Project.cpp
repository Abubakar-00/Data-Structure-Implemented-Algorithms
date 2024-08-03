// QM METHOD
/*
	1. Muhammad Abubakar Saddique
	2. Talha
	3. Ahmad Ijaz
	4. Abdul Rehman
	5. Haider Ali
*/


#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdlib>
#include<cmath>

#define DELIMITER ','
#define PARSE_DELIMETERS " ,"

#define EXPRESSION_MAX_LENGTH 1001

#define VARIABLES_MAX 20

typedef char booll;

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
		
void list_merge(lnodeT **newRoot, lnodeT *firstRoot, lnodeT *secondRoot )
{
	list_init(newRoot, firstRoot->id );
	
	lnodeT *curr = firstRoot->next;
	while( curr != NULL ){
		list_insert( *newRoot, curr->id );
		curr = curr->next;
	}
	
	curr = secondRoot;
	while( curr != NULL ){
		list_insert( *newRoot, curr->id );
		curr = curr->next;
	}
}

bool list_equal(lnodeT *firstRoot, lnodeT *secondRoot)
{
	lnodeT *fNode = firstRoot;
	lnodeT *sNode = secondRoot;
	while( fNode != NULL ){
		// Not equal lists
		if(fNode->id != sNode->id)
			return 0;
		
		fNode = fNode->next;
		sNode = sNode->next;
	}
	// Lists are equal
	return 1;
}


// Struct for group Minterms
struct mintermGroup
{
	char *repr;
	lnodeT* root;
	unsigned int cPosBits;
};
typedef struct mintermGroup mintermGroupT;

int max(int a,int b)
{
	return a > b ? a : b;
}

void StrReverse(char *s)
{
	int low = 0;
	int high = strlen(s) - 1;
	while(low < high)
	{
		char c = s[low];
		s[low] = s[high];
		s[high] = c;
		
		low++;high--;
	}
}
 
 //Compare functions used in Qsort 

int CompareMintermsByRepr( const void *a , const void * b)
{
	mintermGroupT *first  = (mintermGroupT *)a;
	mintermGroupT *second = (mintermGroupT *)b;
	
	if( first->cPosBits == second->cPosBits )
		return strcmp( first->repr, second->repr );
	
	return (first->cPosBits - second->cPosBits);
}

int CompareMintermsById( const void * a, const void * b)
{
	mintermGroupT * first  = (mintermGroupT *)a;
	mintermGroupT * second = (mintermGroupT *)b;
	
	return ( first->root->id - second->root->id);
}


void ReadInput(int *cMinterms,char *exp_minterms)
{
	
	cout << "        Q-M Method     \n";
	cout << "-------------------------"<<endl;
	cout << "Enter the minterms: ";
	cin >> exp_minterms;

	CountTerms(exp_minterms, cMinterms); // counting inserted terms
}

void ParseInput(char *exp, mintermGroupT *mt, int cTerms, int *cVariables)
{
	int i,j;
	int maxMinterm = 0;
	
	char * pch = strtok(exp, PARSE_DELIMETERS);
	for(i = 0; i < cTerms; i++){
		/* Initialize the number bits that are one as zero */ 
		mt[i].cPosBits = 0;
		
		/* Add the minterm to the list */
		mt[i].root = NULL;
		int id = atoi(pch);
		list_init(&mt[i].root, id);
		
		/* Find the minterm with the greatest number of bits */
		maxMinterm = max(maxMinterm, id );
		
		/* Construct the binary representation of the minterm */
		/* NOTE: It is constructed in the reverse order */
		char *binaryRepr = (char *)malloc( (VARIABLES_MAX + 1) * sizeof(char) );
		for(j = 0; j < VARIABLES_MAX; j++){
			if( (id & (1 << j) ) != 0){
				binaryRepr[j] = '1';
				mt[i].cPosBits++;
			}
			else{
				binaryRepr[j] = '0';
			}
		}
		binaryRepr[VARIABLES_MAX] = '\0';
		

		mt[i].repr = (char *)malloc( (VARIABLES_MAX + 1) * sizeof(char) );
		strcpy(mt[i].repr, binaryRepr);
		

		if(i < cTerms - 1){
			pch = strtok(NULL, PARSE_DELIMETERS);
		}
	}
	
	//For calculating number of variables
	(*cVariables) = 0;
	int binary = 1;
	while( maxMinterm > (binary - 1) )
	{
		binary = binary * 2;
		(*cVariables)++;
	}
	
	for(i = 0; i < cTerms; i++)
	{
		mt[i].repr = (char *)realloc( mt[i].repr , (*cVariables + 1) * sizeof(char) );
		mt[i].repr[ *cVariables ] = '\0';
		StrReverse( mt[i].repr );
	}
}


void GetPrimeImplicants( mintermGroupT **table, bool ** termsUsed, mintermGroupT *primeImplicants, int *lenCol, int cColumns)
{
	int index = 0;
	int i,j;
	

	for( i = 0; i <= cColumns; i++)
	{
		for( j = 0; j < lenCol[i]; j++)
		{
			if( !termsUsed[i][j] )
			{
				primeImplicants[index] = table[i][j];
				index++;
			}
		}
	}
}

void CreatePrimeChart(bool ** primeChart, mintermGroupT* minterms, int cMinterms,mintermGroupT * primeImplicants, int cPrimeImplicants)
{
	int i,j, mintermId;
	lnodeT * curr;
	for(i = 0; i < cPrimeImplicants; i++)
	{
		j = 0;
		
		curr = primeImplicants[i].root;
		while(curr != NULL)
		{
			
			mintermId = minterms[j].root->id;
			while( mintermId < (curr->id) )
			{
				j++;
				mintermId = minterms[j].root->id;
			}
			
			primeChart[i][j] = 1;
			
			curr = curr->next;
		}
	}
}

void GetEssentialImplicants(bool ** primeChart, int cPrimeImplicants, int cMinterms, bool * isEssential )
{
	int i,j;
	int nextEssential;
	
	for(j = 0; j < cMinterms; j++)
	{ 
		nextEssential = -1;
		for(i = 0; i < cPrimeImplicants; i++)
		{ 
			if( primeChart[i][j] == 1 )
			{
				if(nextEssential == -1)
					nextEssential = i;
				
				else
				{
					nextEssential = -1;
					break;
				}
			}
		}
		
		if(nextEssential != -1)
			isEssential[nextEssential] = 1;
	}
}


int main(int argc, char *argv[])
{
	mintermGroupT *table[VARIABLES_MAX + 1];
	mintermGroupT *primeImplicants;
	mintermGroupT *minterms; 
	bool *termsUsed[VARIABLES_MAX + 1]; 
	bool **primeChart; 
						
	bool *isEssential; 
					
	bool *mintermsCovered; 	
	
	int lenCol[VARIABLES_MAX];
	int cVariables; 
	int cMinterms;	
	int cColumns;	
	int cPrimeImplicants; 
	
	
	char exp_minterms[EXPRESSION_MAX_LENGTH];
	
	ReadInput( &cMinterms, exp_minterms);
	table[0] = (mintermGroupT *)malloc( cMinterms * sizeof(mintermGroupT) );
	lenCol[0] = cMinterms;
	
	
	minterms = (mintermGroupT *)malloc( cMinterms * sizeof(mintermGroupT) );
	
	ParseInput(exp_minterms, minterms, cMinterms, &cVariables);
	
	qsort( minterms, cMinterms, sizeof(mintermGroupT), CompareMintermsById );
	
	
	memcpy( table[0], minterms, lenCol[0] * sizeof(mintermGroupT) );
	qsort( table[0], cMinterms, sizeof(mintermGroupT), CompareMintermsByRepr );
	
	cPrimeImplicants = 0;
	
	termsUsed[0] = (bool *)calloc( lenCol[0], sizeof(bool) );
	
	int i,j;
	for(i = 0; i <= cVariables; i++)
	{
		mintermGroupT *nextCol = (mintermGroupT *)malloc( (lenCol[i] * lenCol[i])  * sizeof(mintermGroupT) );
		
		int nextColPos = 0;
		for( j = 0; j < lenCol[i]; j++)
		{
			int k = j+1;
			
			while( k < lenCol[i] && table[i][k].cPosBits == table[i][j].cPosBits )
				k++;
			
			while( k < lenCol[i] && (table[i][k].cPosBits - table[i][j].cPosBits) == 1)
			{
				if( CanFormGroup( table[i][k], table[i][j], cVariables ) )
				{
					lnodeT *newGroupRoot;
					list_merge( &newGroupRoot, table[i][j].root, table[i][k].root );
					
					bool alreadyInColumn = 0;
					int c;
					for( c = 0; c < nextColPos; c++)
					{
						if( list_equal( nextCol[c].root , newGroupRoot ) != 0 )
						{
							alreadyInColumn = 1;
							break;
						}
					}
					
					if( !alreadyInColumn )
					{
						nextCol[nextColPos].root = newGroupRoot;
						nextCol[nextColPos].cPosBits = table[i][j].cPosBits;
						
						nextCol[nextColPos].repr = (char *)malloc( (cVariables + 1) * sizeof(char) );
						CreateNewGroupRepr( nextCol[nextColPos].repr, table[i][j].repr, table[i][k].repr, cVariables );
						
						nextColPos++;
					}
					termsUsed[i][j] = termsUsed[i][k] = 1;
				}
				k++;
			}
		}
		
		lenCol[i+1] = nextColPos;
		
		for( j = 0; j < lenCol[i]; j++)
		{
			if( !termsUsed[i][j] )
			{
				cPrimeImplicants++;
			}
		}
		
		if( lenCol[i+1] == 0 )
			break;
		
		
		table[i+1] = (mintermGroupT *)malloc( lenCol[i+1] * sizeof(mintermGroupT) );
		for( j = 0; j < lenCol[i+1]; j++)
			table[i+1][j] = nextCol[j];
		
		termsUsed[i+1] = (bool *)calloc( lenCol[i+1], sizeof(bool) );
		free(nextCol);
	}
	
	cColumns = i;
	
	primeImplicants = (mintermGroupT *)malloc( cPrimeImplicants * sizeof(mintermGroupT) );
	GetPrimeImplicants( table, termsUsed, primeImplicants, lenCol, cColumns );
	
	primeChart = (bool **)malloc( cPrimeImplicants * sizeof(bool *) );
	for(i = 0; i < cPrimeImplicants; i++)
		primeChart[i] = (bool *)calloc( cMinterms, sizeof(bool) );
		
	CreatePrimeChart( primeChart, minterms, cMinterms, primeImplicants, cPrimeImplicants );
	
	isEssential = (bool *)calloc( cPrimeImplicants, sizeof(bool) );
	GetEssentialImplicants( primeChart, cPrimeImplicants, cMinterms, isEssential );
	
	mintermsCovered = (bool *)calloc( cMinterms, sizeof(bool) );
	for( i = 0; i < cPrimeImplicants; i++)
	{
		if( isEssential[i] )
		{
			for( j = 0; j < cMinterms; j++)
				if( primeChart[i][j] )
					mintermsCovered[j] = 1;
		}
	}
	
	
	
	//PRINTING
	 
	
	// Printing the columns (iterations)
	cout << "                COLUMN " << j << "                \n";
	for (i = 0; i < lenCol[j]; i++) 
	{
		cout << "[ ";
		list_print(table[j][i].root);
		cout << "] " << table[j][i].repr << " " << ((termsUsed[j][i]) ? "OK" : " *") << "\n";
	}
	cout << "\n\n";

	
	// Printing the prime implicants 
	cout << "               PRIME IMPLICANTS                \n\n";
	for (int i = 0; i < cPrimeImplicants; i++) 
	{
		cout << "[P" << i << "]: " << primeImplicants[i].repr << " [ ";
		list_print(primeImplicants[i].root);
		cout << " ]\n";
	}
	
	// Printing the prime implicants chart
	cout << "\n\n                PRIME CHART                \n\n";
	cout << " ";
	for (int j = 0; j < cMinterms; j++) 
	{
		cout << "| " << j;
	}
	cout << "|\n---------";

	for (int j = 0; j < cMinterms; j++) 
	{
		cout << "----";
	}
	cout << "\n";

	for (int i = 0; i < cPrimeImplicants; i++) 
	{
		cout << "[P" << i << "]: ";
		for (int j = 0; j < cMinterms; j++) 
		{
			cout << "| " << ((primeChart[i][j]) ? 'X' : ' ');
		}
		cout << "|\n";
}
	
	//Printing the essential prime implicants
	cout << "\n\n               ESSENTIAL PRIME IMPLICANTS               \n\n";
	for (int i = 0; i < cPrimeImplicants; i++) 
	{
		if (isEssential[i]) 
		{
			cout << "[P" << i << "]: " << primeImplicants[i].repr << " [ ";
			list_print(primeImplicants[i].root);
			cout << " ]\n";
		}
	}
	
	cout<<"\n\n               MINIMIZED EXPRESSION               \n\n";
	cout<<"F = ";
	for (int i = 0; i < cPrimeImplicants; i++) 
	{	
		string values =  primeImplicants[i].repr;
		int total = values.size();

				if(values[0] == '0' ){
					cout << "A'" ;
				}
				else if(values[0] == '1'){
					cout << "A" ;
				}
				if(values[1] == '0' ){
					cout << "B'" ;
				}
				else if(values[1] == '1'){
					cout << "B" ;
				}
				if(values[2] == '0' ){
					cout << "C'" ;
				}
				else if(values[2] == '1'){
					cout << "C" ;
				}
				if(values[3] == '0' ){
					cout << "D'" ;
				}
				else if(values[3] == '1'){
					cout << "D" ;
				}
				if(values[4] == '0' ){
					cout << "E'" ;
				}
				else if(values[4] == '1'){
					cout << "E" ;
				}
			if(i!= cPrimeImplicants-1)
			cout << " + ";
		
	}
	
	
	
	return 0;
}
