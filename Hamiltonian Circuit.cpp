#include<iostream>
using namespace std;

int main()
{
	int V,i,j;
	cout<<"Enter the number of vertices: ";
	cin>>V;
	
	bool chk[V];
	int X[V+1];
	int Adj[V][V];
	
	for(i=0;i<=V;i++)
	{
		X[i] = 0;
	}
	
	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
		{
			cout<<"Adj["<<i<<"]["<<j<<"] = ";
			cin>>Adj[i][j];
		}
	}
	
	return 0;
}
