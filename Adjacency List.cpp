#include<iostream>
using namespace std;

struct List
{
	List *next;
	char node;
	List *Adj;
};

int main()
{
	List *head;
	int N,i;
	cout<<"Enter the total number of nodes in the graph: ";
	cin>>N;
	
	for(i=0;i<N;i++)
	{
		List *Newn = new List;
		List *Temp1;
		cout<<"Enter node"<<i+1<<": ";
		cin>>Newn->node;
		Newn->Adj = NULL;
		Newn->next = NULL;
		List *Temp = Newn;
		
		if(i==0)
		{
			head = Temp;
		}
		else if(i!=0)
		{
			Temp1->next = Temp;
		}
		
		cout<<"Enter the nodes adjacent to node"<<i+1<<": \n";
		while(true)
		{
			List *New_Adj = new List;
			cin>>New_Adj->node;
			if(New_Adj->node == '0')
			{
				break;
			}
			else
			{
				New_Adj->next = NULL;
				New_Adj->Adj = NULL;
			
				Temp->Adj = New_Adj;
				Temp = New_Adj;
			}
		}
		
		Temp1 = Newn;
	}
	
	List *Temp = head;
	cout<<"\nThe Adjacency List of given graph is: \n";
	for(i=0;i<N;i++)
	{
		cout<<Temp->node<<"->";
		List *Temp1 = Temp;
		while(Temp1->Adj != NULL)
		{
			cout<<Temp1->Adj->node<<"->";
			Temp1 = Temp1->Adj;
		}
		cout<<"\n";
		Temp = Temp->next;
	}
	
	return 0;
}
