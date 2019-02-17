#include<iostream>
using namespace std;
int LS(int A[], int N, int i, int E)
{
	if(A[i]==E)
		return i+1;
		
	if(i==N)
		return -1;	
		
	return LS(A, N, i+1, E);	
}
int main()
{
	int N,i,e,P;
	cout<<"Enter the size of array: ";
	cin>>N;
	int A[N];
	for(i=0;i<N;i++)
	{
		cout<<"A["<<i<<"] = ";
		cin>>A[i];
	}
	cout<<"Enter the element to be find: ";
	cin>>e;
	P = LS(A, N, 0, e);
	if(P==-1)
		cout<<"The element is not in the array.";
	else
		cout<<"The element is present at position "<<P;	
	
	return 0;
}
