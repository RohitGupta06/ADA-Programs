#include<iostream>
using namespace std;
int main()
{
	int N;
	cout<<"Enter the value of N: ";
	cin>>N;
	int X[N+1];
	X[0] = 1;
	for(int i=1;i<=N;i++)
	{
		X[i]=X[i-1]*i;
	}
	cout<<"Factorial of "<<N<<" is "<<X[N];
	return 0;
}
