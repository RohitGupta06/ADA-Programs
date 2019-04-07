#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int Count = 0;

int isattack_col(int C,int N, int X[])
{
	int i;
	for(i=1;i<=N;i++)
	{
		if(X[i]==C)
			return 1;
	}
	return 0;
}

int isattack_diag(int R, int C, int N, int X[])
{
	for(int j=1;j<=N;j++)
	{
		if(X[j] != 0)
		{
			if(abs(j-R) == abs(X[j]-C))
				return 1;
		}
	}
	return 0;
}

void NQueen(int R, int n, int X[])
{
	int C = 1;
	while(C<=n)
	{
		int chk1 = isattack_col(C,n,X);
		int chk2 = isattack_diag(R,C,n,X);
		if(chk1 == 0 && chk2 == 0)
		{
			X[R] = C;
			if(R == n)
			{
				cout<<"[ ";
				for(int i=1;i<=n;i++)
				{
					if(i==n)
						cout<<X[i];
					else
						cout<<X[i]<<", ";	
				}
				cout<<" ]\n";
				
				Count++;
			}
			else
			{
				NQueen(R+1,n,X);
			}
		}
		C++;
	}
	X[R] = 0;
	return;
}

int main()
{
	int N,i;
	cout<<"Enter the order of matrix: ";
	cin>>N;
	
	int X[N+1];
	for(i=0;i<=N;i++)
	{
		X[i] = 0;
	}
	NQueen(1,N,X);
	cout<<"Total number of solutions = "<<Count;
	return 0;
}
