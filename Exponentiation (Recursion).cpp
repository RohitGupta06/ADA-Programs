#include<iostream>
using namespace std;
float Pow(float x, int y)
{
	if(y==1)
	{
		return x;
	}
	return x*Pow(x,y-1);
}
int main()
{
	float Num;
	int Exp;
	cout<<"Enter a number: ";
	cin>>Num;
	cout<<"Enter the exponent: ";
	cin>>Exp;
	if(Exp<0)
		cout<<"Negative Exponentiation cant be calculated.";
	else if(Exp==0)
		cout<<"Num power 0 is 1.";
	else
	{
		cout<<"Num power Exp, i.e. "<<Num<<"^"<<Exp<<" is "<<Pow(Num, Exp);
	}
	return 0;
}
