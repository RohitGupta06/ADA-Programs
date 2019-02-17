#include<iostream>
using namespace std;
int Fact(int N)
{
	if(N==1)
	{
		return 1;
	}
	return N*Fact(N-1);
}
int main()
{
	int Num;
	cout<<"Enter a number: ";
	cin>>Num;
	if(Num==0)
	{
		cout<<"Factorial of 0 is 1";
	}
	else
	{
		cout<<"Factorial of "<<Num<<" is "<<Fact(Num);
	}
	return 0;
}
