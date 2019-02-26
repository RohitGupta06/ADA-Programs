#include<iostream>
using namespace std;
int Binary_Search(int A[], int Beg, int End, int K)
{
	int Mid = (Beg + End)/2;
	
	if(Beg==End && A[Mid]!=K)
		return -1;
		
	if(Beg==End && A[Mid]==K)
		return Mid;
	
	if(A[Mid] == K)
		return Mid;
		
	if(K<A[Mid])
		return Binary_Search(A, Beg, Mid, K);
		
	if(K>A[Mid])
		return Binary_Search(A, Mid+1, End, K);
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
	P = Binary_Search(A, 0, N-1, e);
	if(P==-1)
		cout<<"The element is not in the array.";
	else
		cout<<"The element is present at index = "<<P;	
	
	return 0;
}
