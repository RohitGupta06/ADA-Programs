#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>

using namespace std;

vector<vector<char> > vect(9);
/*{ {'F','C','B'},
	{'A','C','G'},
	{'F','B','D','E','G','A'},
	{'C','E','F','J'},
	{'C','D','G','J','K'},
	{'A','C','D'},
	{'B','C','E','K'},
	{'D','E','K'},
	{'E','G','J'} };*/

int chk[9] = {1,1,1,1,1,1,1,1,1};
char nods[9] = {'A','B','C','D','E','F','G','J','K'};
char processnods[9];
char Stack[9];
int top = 0;
int cnt = 0;

void stack_add(char a)
{	top++;
	Stack[top]=a;	
	chk[std::distance(nods, std::find(nods, nods+9, a))]++;
}

void stack_remove()
{
	processnods[cnt]=Stack[top];
	chk[std::distance(nods, std::find(nods, nods+9,Stack[top]))]++;
	top--;
	cnt++;
}
void display()
{
	for(int i=0;i<9;i++)
	{
		cout<<processnods[i]<<" ";
	}
	cout<<endl;	
}
void DFS_traverse()
{
	Stack[top]='A';
	++chk[std::distance(nods, std::find(nods, nods+9, 'A'))];
	stack_remove();
	int i=0;
	int k=0;
	while(k<9)
	{
        for (int j=0; j<vect[i].size(); j++) 
        {
        	if(chk[std::distance(nods, std::find(nods, nods+9,vect[i][j]))]==1)
			{
				stack_add(vect[i][j]);
			}
		}
		i = std::distance(nods, std::find(nods, nods+9, Stack[top]));
		k++;
		stack_remove();	
	}
	cout<<"The sequence is:\n";
	display();
}
  
int main() 
{ 
    int r=9;
    int i=0;
    int col;
    while(i<r)
    {
    	cout<<"Enter total adjacent nodes of "<<nods[i]<<" = ";
		cin>>col;
		cout<<"Enter adjacent nodes = ";
		vect[i] = vector<char>(col); 
        for (int j=0;j<col;j++) 
        {
        	cin>>vect[i][j];
		}
		cout<<endl; 	
		i++;
	}
   DFS_traverse();
} 
