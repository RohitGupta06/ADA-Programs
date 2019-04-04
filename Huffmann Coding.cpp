#include<iostream>
#include<string.h>
using namespace std;

struct Tree
{
	Tree *left;
	int Freq;
	char Data;
	Tree *Right;
};

struct List
{
	Tree *Root;
	List *Next;
};

class Linked_list
{
	public:
		List *head;
		List *tail;	

		Linked_list()
		{
			head = NULL;
			tail = NULL;
		}
		void getnode();
		void insert(Tree *);
		void display();
		int sum();
		int Display_Code(Tree *, string);
};

void Linked_list::getnode()
{
	Tree *New_node = new Tree;
	New_node->left = NULL;
	New_node->Right = NULL;
	
	cout<<"\nCharacter = ";
	cin>>New_node->Data;
	cout<<"Frequency = ";
	cin>>New_node->Freq;
	
	insert(New_node);
}

void Linked_list::insert(Tree *node)
{
	if(head == NULL)
	{
		List *Newn = new List;
		Newn->Root = node;
		Newn->Next = NULL;
		head = Newn;
		tail = Newn;
	}
	else if(node->Freq <= head->Root->Freq)
	{
		List *Newn = new List;
		Newn->Next = head;
		Newn->Root = node;
		head = Newn;
	}
	else if(node->Freq >= tail->Root->Freq)
	{
		List *Newn = new List;
		tail->Next = Newn;
		Newn->Root = node;
		Newn->Next = NULL;
		tail = Newn;
	}
	else
	{
		List *Temp;
		Temp = head;
		int count = 0;
		while(Temp->Root->Freq <= node->Freq)
		{
			Temp = Temp->Next;
			count++;
		}
		
		List *Newn = new List;
		Newn->Next = Temp;
		Newn->Root = node;
		
		Temp = head;
		while(--count != 0)
		{
			Temp = Temp->Next;
		}
		Temp->Next = Newn;
	}
}

void Linked_list::display()
{
	List *Temp;
	Temp = head;
	cout<<"Character = ";
	while(Temp != NULL)
	{
		cout<<Temp->Root->Data<<" ";
		Temp = Temp->Next;
	}
	cout<<endl;
	Temp = head;
	cout<<"Frequency = ";
	while(Temp != NULL)
	{
		cout<<Temp->Root->Freq<<" ";
		Temp = Temp->Next;
	}
}

int Linked_list::sum()
{
	if(head == tail)
		return 0;
		
	if(head != tail)
	{
		Tree *Temp = new Tree;
		Temp->left = NULL;
		Temp->Right = NULL;
		Temp->Freq = head->Root->Freq + head->Next->Root->Freq;
		
		if(head->Next->Next == NULL)
		{
			Temp->left = head->Root;
			head = head->Next;
			Temp->Right = head->Root;
			head->Root = Temp;
			tail->Root = Temp;
		}
		else
		{
			List *demo = head;
			Temp->left = head->Root;
			head = head->Next;
			Temp->Right = head->Root;
			head = head->Next;
			insert(Temp);
		}
		sum();
	}
}

int Linked_list::Display_Code(Tree *Temp, string code)
{
	if(Temp->left == NULL && Temp->Right == NULL)
	{
		cout<<"Code for "<<Temp->Data<<" is = "<<code<<"\n";
		return 0;
	}
	Display_Code(Temp->left, code+'0');
	Display_Code(Temp->Right, code+'1');
}

int main()
{
	Linked_list obj;
	int N,i;
	cout<<"Enter the total number of characters in the message: ";
	cin>>N;
	cout<<"\nEnter each of the character and its frequency: \n";
	for(i=0;i<N;i++)
	{
		obj.getnode();
	}
	cout<<endl;
	obj.display();
	cout<<endl;
	obj.sum();
	cout<<"\nThe Encoded format of characters is...\n";
	obj.Display_Code(obj.head->Root, "");
	return 0;
}
