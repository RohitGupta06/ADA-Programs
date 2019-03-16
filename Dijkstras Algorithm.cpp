#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int Mindis(int Dist[], bool Sset[], int m)
{
	int Min = INT_MAX;
	int Min_index;
	int i;
	for(i=0;i<m;i++)
	{
		if(Sset[i]==false)
		{
			if(Dist[i] < Min)
			{
				Min = Dist[i];
				Min_index = i;
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
	int Distance[N];
	bool SPT_set[N];
	int Path_Distance = 0;
	for(i=0;i<N;i++)
	{
		Distance[i]=10000;
		SPT_set[i]=false;
	}
	
	Distance[0] = 0;
	
	while(count<=N-2)
	{
		u = Mindis(Distance,SPT_set,N);
		SPT_set[u] = true;
		for(v=0;v<N;v++)
		{
			if(Adj[u][v]!=0)
			{
				if(SPT_set[v]==false)
				{
					if(Distance[u] != 10000)
					{
						if(Distance[u] + Adj[u][v] < Distance[v])
						{
							Distance[v] = Distance[u] + Adj[u][v];
						}
					}
				}
			}
		}
		count++;
	}
	
	cout<<"The edges in the Shortest Path are: \n";
	for(i=1;i<N;i++)
	{
		cout<<"0--"<<i<<" = "<<Distance[i]<<endl;
		Path_Distance = Path_Distance + Distance[i];
	}
	cout<<"Distance of the shortest path is: "<<Path_Distance<<endl;
	
	return 0;
}
