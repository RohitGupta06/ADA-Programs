#include<iostream>
using namespace std;
int TS(int A[], int Beg, int End, int K)
{
	int Mid1= Beg + (End - Beg)/3;
	int Mid2= Beg + (2*(End - Beg))/3;
	
	if(Beg>End)
		return -1;
		
	if(A[Mid1]==K)
		return Mid1;
		
	if(A[Mid2]==K)
		return Mid2;
			 
	if(K<A[Mid1])
		return TS(A, Beg, Mid1-1, K);
		
	if(K<A[Mid2])
		return TS(A, Mid1+1, Mid2-1, K);
	
	return TS(A, Mid2+1, End, K);
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
	P = TS(A, 0, N-1, e);
	if(P==-1)
		cout<<"The element is not in the array.";
	else
		cout<<"The element is present at position "<<P<<endl;
	
	return 0;
}
