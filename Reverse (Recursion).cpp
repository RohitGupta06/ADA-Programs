#include<iostream>
using namespace std;
int Rev(int n)
{
	if(n==0)
	{
		cout<<endl;
		return 0;
	}
	cout<<n%10;
	return (n%10) + Rev(n/10);
}
int main()
{
	int N;
	cout<<"Enter a number: ";
	cin>>N;
	cout<<"Sum of "<<N<<" is "<<Rev(N);
	return 0;
}
