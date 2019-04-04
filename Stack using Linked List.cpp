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

int Display()
{
	Stack *Temp = Top;
	
	while(Temp != NULL)
	{
		cout<<Temp->Data<<" ";
		Temp = Temp->Next;
	}
}

int main()
{
	int Choice;
	cout<<"What do you want to do?\n";
	cout<<"1. Push into Stack.\n";
	cout<<"2. Pop from Stack.\n";
	cout<<"3. Get what's on Top of Stack.\n";
	cout<<"4. Check whether Stack is Empty or not.\n";
	cout<<"5. Display what's in Stack.\n";
	cout<<"6. Exit\n";
	cin>>Choice;
	do
	{
		switch(Choice)
		{
			case 1:
				{
					int Entry;
					cout<<"Enter the data: ";
					cin>>Entry;
					Push(Entry);
					break;
				}
			case 2:
				{
					int R;
					R = Pop();
					if(R == -1)
					{
						cout<<"Underflow Condition\n";
					}
					else
					{
						cout<<"The popped element is "<<R<<endl;
					}
					break;
				}
			case 3:
				{
					cout<<Peek()<<" is on the top of the stack."<<endl;
					break;
				}
			case 4:
				{
					if(is_empty())
					{
						cout<<"Stack is empty.\n";
					}
					else
					{
						cout<<"Stack is not empty.\n";
					}
					break;
				}
			case 5:
				{
					Display();
					cout<<endl;
					break;
				}		
		}
		cout<<"What do you want to do next?\n";
		cin>>Choice;
	}while(Choice!=6);
	
	return 0;
}
