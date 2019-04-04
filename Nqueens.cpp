#include<iostream>
using namespace std;

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

isattack_diag()


int main()
{
	int N,i;
	cout<<"Enter the order of matrix: ";
	cin>>N;
	
	int X[N+1];
	for(i=0;i<N+1;i++)
	{
		X[i] = 0;
	}
	NQueen(N,X);
	return 0;
}
