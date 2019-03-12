#include<iostream>
using namespace std;

//You were here
/*int findset(struct Temp, int u)
{
	Temp *S1;
	if(S1[u].Parent == u)
		return u;
	return findset(S1,S1[u].Parent);	
}

void Union(struct Temp, int u, int v)
{
	Temp *S1;
	int xcode = findset(S1,u);
	int ycode = findset(S1,v);
	
	if(S1[xcode].Rank == S1[ycode].Rank)
	{
		S1[ycode].Parent = xcode;
		S1[xcode].Rank = S1[xcode].Rank + 1;
	}
	else if(S1[xcode].Rank > S1[ycode].Rank)
	{
		S1[ycode].Parent = xcode;
	}
	else
	{
		S1[xcode].Parent = ycode;
	}
}*/

struct Subset
{
	int Parent;
	int Rank;
};

struct Graph
{
	int V,E;
	Graph *Edge;
};

struct Edge
{
	int src, dest, cost;
};

struct Result
{
	int src, dest, cost;
};

int main()
{
	int i,MST_wt = 0;
	
	Subset *S;
	Graph *gph;
	Edge *edge;
	Result *Res;
	
	cout<<"Enter the number of vertices in graph: ";
	cin>>gph->V;
	cout<<"Enter the number of edges in graph: ";
	cin>>gph->E;
	for(i=0;i<(gph->E)-1;i++)
	{
		cout<<"Enter source of edge "<<i<<": ";
		cin>>edge[i].src;
		cout<<"Enter destination of edge "<<i<<": ";
		cin>>edge[i].dest;
		cout<<"Enter cost of edge "<<edge[i].src<<"--"<<edge[i].dest<<" = ";
		cin>>edge[i].cost;
	}

	for(i=0;i<(gph->V)-1;i++)
	{
		S[i].Parent = i;
		S[i].Rank = 0;
	}
	
	i=0;
/*	while(findset(S,edge[i].src) != findset(S,edge[i].dest))
	{
		Res[i].src = edge[i].src;
		Res[i].dest = edge[i].dest;
		Res[i].cost = edge[i].cost;
		MST_wt = MST_wt + Res[i].cost;
		Union(S,Res[i].src,Res[i].dest);
		i++; 
	}*/
	
	return 0;
}
