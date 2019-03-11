#include<iostream>
using namespace std;

void Merge(int A[], int Low, int Mid, int High)
{
	int i,j,k=Low;
	int N1 = Mid - Low + 1;
	int N2 = High - Mid;
	int L[N1];
	int R[N2];
	for(i=0;i<N1;i++)
	{
		L[i] = A[Low+i];
	}
	for(i=0;i<N2;i++)
	{
		R[i] = A[Mid+1+i];
	}
	
	i=0,j=0;
	while(i<N1 && j<N2)
	{
		if(L[i]<=R[j])
		{
			A[k] = L[i];
			i++;
		}
		else
		{
			A[k] = R[j];
			j++;
		}
		k++;
	}
	while(i<N1)
	{
		A[k] = L[i];
		i++;
		k++;
	}
	while(j<N2)
	{
		A[k] = R[j];
		j++;
		k++;
	}
}

int Mergesort(int A[], int Low, int High)
{
	int Mid;
	if(Low>=High)
		return 0;
	else
	{
		Mid = (Low + High)/2;
		Mergesort(A, Low, Mid);
		Mergesort(A, Mid+1, High);
		Merge(A, Low, Mid, High);	
	}	
}

void Print_Array(int A[], int M)
{
	cout<<"{ ";
	for(int i=0;i<M;i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<"}\n";
}

int main()
{
	int N,i;
	cout<<"Enter the size of array: ";
	cin>>N;
	int A[N];
	for(i=0;i<N;i++)
	{
		cout<<"A["<<i<<"] = ";
		cin>>A[i];
	}
	cout<<"The sorted array is: \n";
	Mergesort(A, 0, N-1);
	
	Print_Array(A, N);
	
	return 0;
}
