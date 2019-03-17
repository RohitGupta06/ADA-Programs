#include<iostream>
using namespace std;
int main()
{
	int i,j;
	int A[2][2], B[2][2], C[2][2];
	cout<<"Enter elements of matrix A: \n";
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			cout<<"A["<<i<<"]["<<j<<"] = ";
			cin>>A[i][j];
		}
	}
	cout<<"\nEnter elements of matrix B: \n";
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			cout<<"B["<<i<<"]["<<j<<"] = ";
			cin>>B[i][j];
		}
	}
	
	int P1 = A[0][0]*(B[0][1] - B[1][1]);
	int P2 = (A[0][0] + A[0][1])*B[1][1];
	int P3 = (A[1][0] + A[1][1])*B[0][0];
	int P4 = (B[1][0] - B[0][0])*A[1][1];
	int P5 = (A[0][0] + A[1][1])*(B[0][0] + B[1][1]);
	int P6 = (A[0][1] - A[1][1])*(B[1][0] + B[1][1]);
	int P7 = (A[0][0] - A[1][0])*(B[0][0] + B[0][1]);
	
	C[0][0] = P4+P5-P2+P6;
	C[0][1] = P1+P2;
	C[1][0] = P3+P4;
	C[1][1] = P1+P5-P3-P7;
	
	cout<<"\nMatrix Multiplication of A and B is: \n";
	for(i=0;i<2;i++)
	{
		cout<<"| ";
		for(j=0;j<2;j++)
		{
			cout<<C[i][j]<<" ";
		}
		cout<<"|\n";
	}
	return 0;
}
