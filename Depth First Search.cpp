#include<iostream>
using namespace std;

struct Stack
{
	int Data;
	Stack *Next;
}*Top=NULL;

bool is_empty()
{
	if(Top == NULL)
		return true;
	
	return false;	
}

void Push(int D)
{
	if(Top==NULL)
	{
		Stack *node = new Stack;
		node->Data = D;
		node->Next = NULL;
		Top = node;
	}
	else
	{
		Stack *node = new Stack;
		node->Data =D;
		node->Next = Top;
		Top = node;
	}
}

int Pop()
{
	if(is_empty())
	{
		return -1;
	}
	else
	{
		Stack *Temp = Top;
		Top = Top->Next;
		Temp->Next = NULL;
		return Temp->Data;
	}
}

int Peek()
{
	return Top->Data;
}

int main()
{
	int N,i;
	cout<<"Enter the number of nodes in the graph: ";
	cin>>N;
	int State[N];
	for(i=0;i<N;i++)
	{
		State[i] = 1;
	}
	
	return 0;
}
