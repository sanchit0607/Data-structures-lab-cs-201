#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}node;


typedef struct stack{
	node* a[100];
	int top;
}stack;

stack* newstack()
{
	stack* s=(stack*)malloc(sizeof(stack));
	s->top=-1;
	return s;
}

int empty(stack* s)
{
	if(s->top==-1)
		return 1;
	else
		return 0;
}
 

void push(stack* s,node* x)
{
	if(s->top==99)
		return;
	s->top++;
	s->a[s->top]=x;
	
}


node*  pop(stack* s)
{
	if(s->top==-1)
		return NULL;
	node* k=s->a[s->top];

	s->top--;

	return k;
}



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
	stack* s=newstack();
	do
	{
		while(root!=NULL)
		{
			push(s,root);
			root=root->left;
		}
		
		if(!empty(s))
		{
			root=s->a[s->top];
			cout<<s->a[s->top]->data<<" ";
			pop(s);
			root=root->right;
		}

	}while(!(empty(s) && root==NULL));
}


void preorder(node* root)
{
	if(root==NULL)
		return ;
	stack* s=newstack();
	do
	{
		while(root!=NULL)
		{
			push(s,root);
			cout<<root->data<<" ";
			root=root->left;
		}
		if(!empty(s))
		{
			root=pop(s);
			root=root->right;
		}
	}while(!(empty(s) && root==NULL));


}


void postorder2(node* root)  //using 2 stacks
{
	stack* s1=newstack();
	stack* s2=newstack();
	push(s1,root);
	while(!empty(s1))
	{
		root=pop(s1);
		push(s2,root);
		if(root->left)
			push(s1,root->left);
		if(root->right)
			push(s1,root->right);

	}
	for(int i=s2->top;i>-1;i--)
	{
		cout<<(s2->a[i])->data<<" ";
	}
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
	postorder2(root);
	return 0;
	
}