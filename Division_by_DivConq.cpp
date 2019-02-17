#include<iostream>
using namespace std;
float Div(int x, float y)
{
	if(x==1)
		return 1/y;
		
	if(x%2==0)
		return 2*Div(x/2, y);
		
	return 2*Div(x/2, y) + Div(1, y);		
}
int main()
{
	int Dividend;
	float Divisor;
	cout<<"Enter the Dividend: ";
	cin>>Dividend;
	cout<<"Enter the Divisor: ";
	cin>>Divisor;
	cout<<Dividend<<" / "<<Divisor<<" will be "<<Div(Dividend, Divisor);
	return 0;
}
