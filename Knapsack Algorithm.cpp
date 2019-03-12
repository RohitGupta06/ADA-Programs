#include<iostream>
using namespace std;

float Knapsack_maxprofit(int m,int n,float P[],float W[],float PW[])
{
	int i,flag=0;
	float P_Total=0.0;
	float X[n];
	for(i=0;i<n;i++)
	{
		X[i] = 0.0;
	}
	for(i=n-1;i>=0;i--)
	{
		if(W[i]>m)
		{
			flag = 1;
			break;
		}
		else
		{
			X[i] = 1;
			P_Total = P_Total + P[i];
			m = m - W[i];
		}	
	}
	if(flag==1)
	{
		X[i] = m/W[i];
		P_Total = P_Total + P[i]*X[i];
	}
	return P_Total;
}

int main()
{
	int N,Max_wt,i,j,idx;
	float min,temp;
	cout<<"Enter the number of items: ";
	cin>>N;
	cout<<"Enter the maximum weight of knapsack: ";
	cin>>Max_wt;
	float P[N];
	float W[N];
	float PW[N];
	cout<<"Enter the profit and their corresponding weights in order: \n";
	for(i=0;i<N;i++)
	{
		cout<<"P["<<i<<"] = ";
		cin>>P[i];
		cout<<"W["<<i<<"] = ";
		cin>>W[i];
		PW[i] = P[i]/W[i];
		cout<<endl;
	}
	for(i=0;i<N;i++)
	{
		min = PW[i];
		idx = i;
		for(j=i;j<N;j++)
		{
			if(PW[j]==min)
			{
				if(P[j]<P[idx])
				{
					min = PW[j];
					idx = j;
				}
			}
			else if(PW[j]<min)
			{
				min = PW[j];
				idx = j;
			}
		}
		PW[idx] = PW[i];
		PW[i] = min;
		
		temp = P[idx];
		P[idx] = P[i];
		P[i] = temp;
		
		temp = W[idx];
		W[idx] = W[i];
		W[i] = temp;
	}
	
	/*cout<<"Sorted Profit-by-Weight Matrix = { ";
	for(i=0;i<N;i++)
	{
		cout<<PW[i]<<" ";
	}
	cout<<"}\n";
	
	cout<<"Sorted Profit Matrix = { ";
	for(i=0;i<N;i++)
	{
		cout<<P[i]<<" ";
	}
	cout<<"}\n";
	
	cout<<"Sorted Weight Matrix = { ";
	for(i=0;i<N;i++)
	{
		cout<<W[i]<<" ";
	}
	cout<<"}\n";
	*/
	
	float Profit = Knapsack_maxprofit(Max_wt,N,P,W,PW);
	cout<<"The maximum profit can be "<<Profit;
	return 0;
}
