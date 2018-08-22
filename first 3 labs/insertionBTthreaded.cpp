#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
	bool righthread;
}node;


node* newnode(int x)
{
	node* p=(node*)malloc(sizeof(node));
	p->data=x;
	p->left=NULL;
	p->right=NULL;
	p->righthread=false;
	return p;
}

node* search(node* root,int x)
{
	if(root==NULL)
		return NULL;
	if(root->data==x)
		return root;
	if(search(root->left,x))
		return search(root->left,x);
	if(root->righthread==false && search(root->right,x))
		return search(root->right,x);
	return NULL;
}


void setleft(node* p,node* q)
{
	p->left=q;
	q->right=p;
	q->righthread=true;
}

void setright(node* p,node* q)
{
	q->right=p->right;
	p->right=q;
	p->righthread=false;
	q->righthread=true;
}

int main()
{
	int n;
	cin>>n;
	node* parent,* child,* root;
	root=NULL;
	int n1,n2;
	char ch;
	while(n--)
	{
		cin>>n1>>n2>>ch;
		if(n2==-1)
		{
			if(root==NULL)
			{
				root=newnode(n1);
				continue;
			}
			else
			{
				cout<<"there is root present!!!"<<endl;
				continue;
			}
		}
		else
		{
			node* k=search(root,n2);
			if(k==NULL)
			{
				cout<<"there is no parent present!!!"<<endl;
				continue;
			}
			else
			{
				parent=k;
				/*if(parent->left==NULL)
					cout<<"hey baby!!!";*/
				child=newnode(n1);
				if(ch=='L')
				{
					if(parent->left==NULL)
					{
						setleft(parent,child);
					}
					else
					{
						cout<<"there is left element present !!!"<<endl;
					}
				}
				if(ch=='R')
				{
					if(parent->righthread==true || parent->right==NULL)
					{
						setright(parent,child);
					}
					else
					{
						cout<<"there is a right present!!!"<<endl;
					}
				}
			}
		}
	}

	return 0;
}