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
char Queue[9];
int front = 0;
int rear = 0;
int cnt = 0;

void Queue_add(char a)
{	rear++;
	Queue[rear]=a;	
	chk[std::distance(nods, std::find(nods, nods+9, a))]++;
}

void Queue_remove()
{
	processnods[cnt]=Queue[front];
	chk[std::distance(nods, std::find(nods, nods+9,Queue[front]))]++;
	front++;
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
void BFS_traverse()
{
	Queue[rear]='A';
	++chk[std::distance(nods, std::find(nods, nods+9, 'A'))];
	Queue_remove();
	int i=0;
	int k=0;
	while(k<9)
	{
        for (int j=0; j<vect[i].size(); j++) 
        {
        	if(chk[std::distance(nods, std::find(nods, nods+9,vect[i][j]))]==1)
			{
				Queue_add(vect[i][j]);
			}
		}
		i = std::distance(nods, std::find(nods, nods+9, Queue[front]));
		k++;
		Queue_remove();	
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
   BFS_traverse();
} 
