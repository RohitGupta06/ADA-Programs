#include<iostream>
using namespace std;
int Div(int x, int y)
{
	if(y>x)
	{
		cout<<"The Remainder is "<<x;
		return 0;
	}
	    
	return 1 + Div(x-y, y);    
}
int main()
{
	int Dividend, Divisor;
	cout<<"Enter the Dividend: ";
	cin>>Dividend;
	cout<<"Enter the Divisor: ";
	cin>>Divisor;
	cout<<"\n"<<"The Quotient is "<<Div(Dividend, Divisor);
	return 0;
}
