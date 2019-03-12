#include<iostream>
using namespace std;

struct Tree
{
	Tree *left;
	int Length;
	Tree *Right;
};

class Linked_list
{
	private:
		Tree *head;
		Tree *tail;	
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
		head = node;
		tail = node;
	}
	else if(node->Length <= head->Length)
	{
		node->Right = head;
		head->left = node;
		head = node;
	}
	else if(node->Length >=tail->Length)
	{
		tail->Right = node;
		node->left = tail;
		tail = node;
	}
	else
	{
		Tree *Temp;
		Temp = head;
		while(Temp->Length <= node->Length)
		{
			Temp = Temp->Right;
		}
		node->Right = Temp;
		node->left = Temp->left;
		Temp->left->Right = node;
		Temp->left = node;
	}
}

void Linked_list::display()
{
	Tree *Temp;
	Temp = head;
	while(Temp != NULL)
	{
		cout<<Temp->Length<<" ";
		Temp = Temp->Right;
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
		Temp->Length = head->Length + head->Right->Length;
		
		if(head->Right->Right == NULL)
		{
			head = Temp;
			tail = Temp;
		}
		else
		{
			Tree *demo = head;
			head = demo->Right->Right;
			head->left = NULL;
			insert(Temp);
		}
		
		display();
		cout<<endl<<endl;
		sum();
	}
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
	cout<<"Changes occuring in list...\n";
	obj.sum();
	return 0;
}
