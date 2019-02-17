#include<iostream>
using namespace std;
int Table(int n, int i)
{
	if(i==11)
	{
		return 0;
	}
	cout<<n<<" X "<<i<<" = "<<n*i<<endl;
	return Table(n, i+1);
}
int main()
{
	int N;
	cout<<"Enter a number: ";
	cin>>N;
	cout<<"The table of "<<N<<" is: \n";
	cout<<Table(N,1);
	return 0;
}
