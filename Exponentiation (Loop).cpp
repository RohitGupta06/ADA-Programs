#include<iostream>
using namespace std;
int main()
{
	float Num,Res=1;
	int Exp;
	cout<<"Enter a number: ";
	cin>>Num;
	cout<<"Enter the exponent: ";
	cin>>Exp;
	int Temp=Exp;
	if(Exp<0)
	{
		cout<<"Num power 0 is 1.";
	}
	while(Temp>0)
	{
		Res=Res*Num;
		Temp--;
	}
	cout<<"Num power Exp, i.e. "<<Num<<"^"<<Exp<<" is "<<Res;
	return 0;
}
