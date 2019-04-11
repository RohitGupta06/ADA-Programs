#include<iostream>
using namespace std;

Fib(int X[], int i)
{
	if(i==0)
		return 0;
	if(i==1)
		return 1;
		
	if(X[i] == 0)
	{
		X[i] = Fib(X,i-1) + Fib(X,i-2);
	}
	
	return X[i];		
}

int main()
{
	int N,i;
	cout<<"Enter the value of N: ";
	cin>>N;
	int X[N+1]={0};
	cout<<"The required term i.e Fib("<<N<<") is "<<Fib(X,N);
	return 0;
}
