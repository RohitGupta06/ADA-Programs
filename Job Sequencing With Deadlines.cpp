#include<iostream> 
#include<algorithm> 
using namespace std; 

struct Job 
{ 
   char id; 
   int Dead; 
   int Profit; 
}; 

bool comp(Job a, Job b)
{
	return (a.Profit > b.Profit);
}

int main() 
{
	int N,i,j;
	int max_profit=0;
	cout<<"Enter the number of jobs: ";
	cin>>N;
	Job *J = new Job[N];
	int Result[N];
	bool Slot[N];
		
	for(i=0;i<N;i++)
	{
		cout<<"\nEnter the id of job: ";
		cin>>J[i].id;
		cout<<"Enter the deadline of job "<<J[i].id<<": ";
		cin>>J[i].Dead;
		cout<<"Enter the profit of job "<<J[i].id<<": ";
		cin>>J[i].Profit;
		
		Slot[i] = false;
	}
	
	sort(J,J+N,comp);
	
	for(i=0;i<N;i++)
	{
		for(j=(J[i].Dead)-1;j>=0;j--)
		{
			if(Slot[j] == false)
			{
				Slot[j] = true;
				Result[j] = i;
				break;
			}
		}
	}
	
	cout<<"The sequence with maximum profit is...\n";
	for(i=0;i<N;i++)
	{
		if(Slot[i] == true)
		{
			cout<<J[Result[i]].id<<" ";
			max_profit += J[Result[i]].Profit;
		}
	}
	cout<<" "<<max_profit;
	
	return 0;
} 
  
