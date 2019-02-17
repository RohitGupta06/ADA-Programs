#include<iostream>
using namespace std;
int Mult(int x, int y)
{
	if(x==0 || y==0)
		return 0;
	if(y==1)
		return x;
		
	if(y%2==0)
		return 2*Mult(x,y/2);
			
	return x + 2*Mult(x,y/2);			
}
int main()
{
	int Num1, Num2;
	cout<<"Enter first number: ";
	cin>>Num1;
	cout<<"Enter second number: ";
	cin>>Num2;
	cout<<Num1<<" * "<<Num2<<" = "<<Mult(Num1, Num2);
	return 0;
}
