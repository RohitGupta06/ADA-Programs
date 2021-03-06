#include<iostream>
using namespace std;
int Comparision = 0;

struct Tree
{
	Tree *left;
	int Length;
	Tree *Right;
};

struct List
{
	Tree *Root;
	List *Next;
};

class Linked_list
{
	private:
		List *head;
		List *tail;	
	public:
		Linked_list()
		{
			head = NULL;
			tail = NULL;
		}
		void getnode();
		void insert(Tree *);
		void display();
		int sum();
		void display_Tree();
};

void Linked_list::getnode()
{
	Tree *New_node = new Tree;
	New_node->left = NULL;
	New_node->Right = NULL;
	cin>>New_node->Length;
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
	else if(node->Length <= head->Root->Length)
	{
		List *Newn = new List;
		Newn->Next = head;
		Newn->Root = node;
		head = Newn;
	}
	else if(node->Length >= tail->Root->Length)
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
		List *Temp1;
		Temp = head;
		int count = 0;
		while(Temp->Root->Length <= node->Length)
		{
			Temp1 = Temp;
			Temp = Temp->Next;
		}
		
		List *Newn = new List;
		Newn->Next = Temp;
		Newn->Root = node;
		Temp1->Next = Newn;
	}
}

void Linked_list::display()
{
	List *Temp;
	Temp = head;
	while(Temp != NULL)
	{
		cout<<Temp->Root->Length<<" ";
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
		Temp->Length = head->Root->Length + head->Next->Root->Length;
		Comparision += Temp->Length;
		
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
		display();
		cout<<endl;
		sum();
	}
}

void Linked_list::display_Tree()
{
	cout<<head->Root->Length<<" ";
	cout<<head->Root->left->Length<<" ";
	cout<<head->Root->Right->Length<<" ";
	cout<<head->Root->Right->left->Length<<" ";
	cout<<head->Root->Right->Right->Length<<" ";
	cout<<head->Root->Right->Right->left->Length<<" ";
	cout<<head->Root->Right->Right->Right->Length<<" ";
	cout<<head->Root->Right->Right->left->left->Length<<" ";
	cout<<head->Root->Right->Right->left->Right->Length<<" ";
}

int main()
{
	Linked_list obj;
	int N,i;
	cout<<"Enter the total number of files: ";
	cin>>N;
	cout<<"\nEnter number of elements in each file: \n";
	for(i=0;i<N;i++)
	{
		cout<<"File"<<i+1<<" = ";
		obj.getnode();
	}
	cout<<endl;
	obj.display();
	cout<<endl;
	obj.sum();
	cout<<"\nThe Tree formed is...\n";
	obj.display_Tree();
	cout<<"\n\nThe total number of comparisions are "<<Comparision<<".";
	return 0;
}
