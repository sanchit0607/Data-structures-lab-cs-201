#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}node;

node* newnode(int x)
{
	node* p=(node*)malloc(sizeof(node));
	p->data=x;
	p->left=NULL;
	p->right=NULL;
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
	if(search(root->right,x))
		return search(root->right,x);
	return NULL;
}


void inorder(node* root)
{
	if(root==NULL)
		return;
	//cout<<endl;
	inorder(root->left);
	cout<<root->data<<"  ";
	inorder(root->right);
}

void preorder(node* root)
{
	if(root==NULL)
		return;
	//cout<<endl;
	cout<<root->data<<"  ";
	preorder(root->left);
	
	preorder(root->right);
}

void postorder(node* root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	
	inorder(root->right);
	cout<<root->data<<"  ";
}




int main()
{
	int n;
	cin>>n;
	int n1,n2;
	char ch;
	node* root,* parent,* child;
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
				cout<<endl;
				cout<<"there is a root there!!!"<<endl;
				continue;
			}
		}
		else
		{
			node* p=search(root,n2);
			if(p==NULL)
			{
				cout<<"there is no node or root is null"<<endl;
				continue;
			}
			else
			{
				parent=p;
				child=newnode(n1);
				if(ch=='L')
				{
					if(parent->left==NULL)
						parent->left=child;
					else
					{
						cout<<"there is left element!!!"<<endl;
					}
				}
					
				if(ch=='R')
				{
					if(parent->right==NULL)
						parent->right=child;
					else
					{
						cout<<"there is right element!!!"<<endl;
					}
				}
			}
		}
	}
	inorder(root);
	cout<<endl;
	preorder(root);
	cout<<endl;
	postorder(root);
	return 0;
	
}