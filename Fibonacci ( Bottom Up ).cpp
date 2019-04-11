#include<iostream>
using namespace std;
int main()
{
	int N;
	cout<<"Enter the value of n: ";
	cin>>N;
	int X[N];
	X[0]=0;
	X[1]=1;
	for(int i=2;i<N;i++)
	{
		X[i]=X[i-1]+X[i-2];
	}
	cout<<"The Fibonacci Sequence is: \n";
	for(int i=0;i<N;i++)
	{
		cout<<X[i]<<" ";
	}
	cout<<"\nThe Required term i.e X["<<N<<"] is "<<X[N-1];
	return 0;
}
