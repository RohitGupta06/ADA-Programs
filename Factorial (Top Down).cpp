#include<iostream>
using namespace std;

int Fact(int n, int X[])
{
	if(n==0 || n==1)
		return 1;
		
	if(X[n] == 0)
	{
		X[n] = n * Fact(n-1,X);
	}
	return X[n];	
}
int main()
{
	int N;
	cout<<"Enter the number: ";
	cin>>N;
	int X[N+1] = {0};
	cout<<"Factorial of "<<N<<" is "<<Fact(N,X);
	return 0;
}
