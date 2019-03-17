#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(int A[], int Low, int High)
{
	int Pivot = A[High];
	int i = Low-1;
	
	for(int j=Low; j<High; j++)
	{
		if(A[j] < Pivot)
		{
			i++;
			swap(&A[i], &A[j]);
		}
	}
	swap(&A[i+1], &A[High]);
	return i+1;
}

void QuickSort(int A[], int Beg, int End)
{
	if(Beg >= End)
		return;
		
	int P = Partition(A, Beg, End);
	
	QuickSort(A, Beg, P-1);
	QuickSort(A, P+1, End);
}

int main()
{
	int N,i;
	cout<<"Enter the size of array: ";
	cin>>N;
	int A[N];
	cout<<"Enter the elements of array: \n";
	for(i=0;i<N;i++)
	{
		cout<<"A["<<i<<"] = ";
		cin>>A[i];
	}
	
	QuickSort(A, 0, N-1);
	
	cout<<"\nSorted Array is: \n";
	cout<<"{ ";
	for(i=0;i<N;i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<"}";
	return 0;
}

