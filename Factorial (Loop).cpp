#include<iostream>
using namespace std;
int main()
{
	int N,fact=1;
	cout<<"Enter a number: ";
	cin>>N;
	int Temp=N;
	while(Temp>0)
	{
		fact=fact*Temp;
		Temp--;
	}
	cout<<"Factorial of "<<N<<" is "<<fact;
	return 0;
}
