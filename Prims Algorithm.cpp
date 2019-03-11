#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int Minkey(int Key[], bool Mset[], int m)
{
	int Min=INT_MAX;
	int Min_index;
	int i;
	for(i=0;i<m;i++)
	{
		if(Mset[i]==false)
		{
			if(Key[i]<Min)
			{
				Min=Key[i];
				Min_index=i;
			}
		}
	}
	return Min_index;
}

int main()
{
	int N,i,j,u,v,count=0;
	cout<<"Enter the number of vertices in graph: ";
	cin>>N;
	int Adj[N][N];
	cout<<"The Adjacency Matrix for the graph is:\n";
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			cout<<"Adj["<<i<<"]["<<j<<"] = ";
			cin>>Adj[i][j];
		}
	}
	int Keys[N];
	int Parent[N];
	bool MST_set[N];
	int MST_weight=0;
	for(i=0;i<N;i++)
	{
		Keys[i]=10000;
		MST_set[i]=false;
	}
	Parent[0]=-1;
	
	while(count<=N-2)
	{
		u = Minkey(Keys,MST_set,N);
		MST_set[u] = true;
		for(v=0;v<N;v++)
		{
			if(Adj[u][v]!=0)
			{
				if(MST_set[v]==false)
				{
					if(Keys[v]>Adj[u][v])
					{
						Keys[v]=Adj[u][v];
						Parent[v]=u;
					}
				}
			}
		}
		count++;
	}
	
	cout<<"The edges in the Minimum Spanning Tree are: \n";
	for(i=1;i<N;i++)
	{
		cout<<Parent[i]<<"--"<<i<<endl;
		MST_weight = MST_weight + Keys[i];
	}
	cout<<"Weight of the Minimum Spanning Tree is: "<<MST_weight<<endl;
	
	return 0;
}
