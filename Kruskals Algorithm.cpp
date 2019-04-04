#include<iostream>
using namespace std;

struct Edge
{
	int src, dest, cost;
};

struct Result
{
	int src, dest, cost;
};

struct Graph
{
	int V,E;
	struct Edge *edge;
};

struct Subset
{
	int Parent;
	int Rank;
};

int findset(struct Subset *S1, int u)
{
	if(S1[u].Parent == u)
		return u;
	return findset(S1,S1[u].Parent);	
}

void Union(struct Subset *S1, int u, int v)
{
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
}

int main()
{
	int i,count=0,MST_wt = 0;
	
	Subset *S;
	Graph *gph = new Graph;
	Result *Res;
	
	cout<<"Enter the number of vertices in graph: ";
	cin>>gph->V;
	cout<<"Enter the number of edges in graph: ";
	cin>>gph->E;
	
	S = new Subset[gph->V];
	gph->edge = new Edge[gph->E];
	Res = new Result[(gph->V)-1];
	
	for(i=0;i<gph->E;i++)
	{
		cout<<"\nEnter source of edge "<<i<<": ";
		cin>>gph->edge[i].src;
		cout<<"Enter destination of edge "<<i<<": ";
		cin>>gph->edge[i].dest;
		cout<<"Enter cost of edge "<<gph->edge[i].src<<"--"<<gph->edge[i].dest<<" = ";
		cin>>gph->edge[i].cost;
	}

	for(i=0;i<gph->V;i++)
	{
		S[i].Parent = i;
		S[i].Rank = 0;
	}
	
	for(i=0;i<gph->E;i++)
	{
		if(findset(S,gph->edge[i].src) != findset(S,gph->edge[i].dest))
		{
			Res[count].src = gph->edge[i].src;
			Res[count].dest = gph->edge[i].dest;
			Res[count].cost = gph->edge[i].cost;-
			MST_wt = MST_wt + Res[count].cost;
			Union(S,Res[count].src,Res[count].dest);
			count++;
		}
	}
	
	cout<<"\nThe resultant structure is: \n";
	for(i=0;i<count;i++)
	{
		cout<<"  | "<<Res[i].src<<" | ";
		cout<<Res[i].dest<<" | ";
		cout<<Res[i].cost<<" |";
		cout<<endl;
	}
	
	cout<<"Weight of minimum spanning tree is "<<MST_wt;
	
	return 0;
}
