#include<iostream>
using namespace std;

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

void DFS(int i)
{
	int j;
	cout<<i<<" ";
	visited[i]=1;
	
	for(int j=0; j<7; j++)
	{
		if(g[i][j] == 1 && !visited[j])
		{
			DFS(j);
		}
	}
}

int main()
{
	
	// DFS IMPLEMENTATION
		
	DFS(0);
	
	return 0;
}

