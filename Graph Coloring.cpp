#include<iostream>
using namespace std;
#define V 4
int Adj[4][4] = {{0,1,1,1},{1,0,1,0},{1,1,0,1},{1,0,1,0}};
 
bool issafe(int u, int color, int X[])
{
	for(int i=0;i<V;i++)
	{
		if(Adj[u][i] == 1)
		{
			if(X[i] == color)
				return false;
		}
	}
	return true;
}

bool mcoloring(int v, int X[], int m)
{
	if(v == V)
	{
		return true;
	}
	
	for(int c=1;c<=m;c++)
	{
		if(issafe(v,c,X))
		{
			X[v] = c;
		}
	}
	
	if(mcoloring(v+1,X,m))
	{
		cout<<"[ ";
		for(int i=0;i<V;i++)
		{
			if(i==V-1)
				cout<<X[i]<<" ";
			else
				cout<<X[i]<<", ";	
		}
		cout<<"]\n";
		
		for(int i=0;i<V;i++)
		{
			cout<<"vertex "<<i<<" = color"<<X[i];
			cout<<endl;
		}
	}
	return false;	
}

int main()
{
	int i,j,max=0;
	int X[V];
	/*cout<<"Enter the number of vertices: ";
	cin>>V;
	int Adj[V][V];
	cout<<"Enter the adjacency matrix:\n";*/
	for(i=0;i<V;i++)
	{
		int count = 0;
		for(j=0;j<V;j++)
		{
			if(Adj[i][j] == 1)
				count++;
		}
		if(count>max)
			max = count;
	}
	
	for(i=0;i<V;i++)
	{
		X[i] = 0;
	}
	
	mcoloring(0,X,max);
	return 0;
}
