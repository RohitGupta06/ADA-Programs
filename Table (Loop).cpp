#include<iostream>
using namespace std;
int main()
{
	int N;
	cout<<"Enter a number: ";
	cin>>N;
	cout<<"The table of "<<N<<" is: \n";
	for(int i=1;i<=10;i++)
	{
		cout<<N<<" X "<<i<<" = "<<N*i<<endl;
	}
	return 0;
}
