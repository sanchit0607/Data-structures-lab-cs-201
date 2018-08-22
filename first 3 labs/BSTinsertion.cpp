#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
	struct node* parent;
}node;

node*  createnode(int x)
{
	node* p=(node*)malloc(sizeof(node));
	p->left=NULL;
	p->right=NULL;
	p->parent=NULL;
	return p;
}


void insert(node* r,int x)
{
	node* q=NULL;
	node* p=r;
	while(p!=NULL)
	{
		q=p;
		if(p->data<x)
			p=p->right;
		if(p->data>x)
			p=p->left;
	}
	node* z=createnode(x);
	if(q->data>x)
		{
			q->left=z;
			z->parent=q;
		}
	if(q->data<x)
		{
			q->right=z;
			z->parent=q;
		}
}


node* bstsearch(node* r,int x)
{
	node* root=r;
	if(root==NULL)
		return NULL;
	if(root->data==x)
		return root;
	if(root->data<x)
		return bstsearch(root->right,x);
	else
		return bstsearch(root->left,x);
}


node* bstsearchiter(node* r,int x)
{
	node* root=r;
	if(root==NULL)//no need of this btw
		return NULL;
	while(root!=NULL && root->data!=x)
	{
		if(root->data>x)
			root=root->left;
		else
			root=root->right;
	}
	return root;
}

node* bstmax(node* root)
{
	node* q=root;
	while(q!=NULL && q->right!=NULL)
	{
		q=q->right;
	}
	return q;
}


node* bstmin(node* root)
{
	node* r=root;
	while(r!=NULL && r->left!=NULL)
	{
		r=r->left;
	}
	return r;
}


node* bstsuccessor(node* to)
{
	node* q=to;
	if(q->right!=NULL)
	{
		return min(bstmin(q->right));
	}
	else
	{
		node* w=q->parent;
		while(w!=NULL && w->left!=q)
		{
			q=q->parent;
			w=q->parent;
		}
		return w;
	}
}


node* predecessor(node* to)
{
	node* r=to;
	if(r->left!=NULL)
		return bstmax(r->left);
	else
	{
		node* w=r->parent;
		while(w!=NULL && w->right!=r)
		{
			r=r->parent;
			w=r->parent;
		}
		return w;
	}
}



void deletenode(node* root)
{
	node* r=root;
	if(r->left==NULL && r->right==NULL) //case1
	{
		node* w=r->parent;
		if(w!=NULL)
		{
			if(w->right==r)
			{
				w->right=NULL;
			}
			if(w->left==r)
				w->left=NULL;
			free(r);
			return;
		}
		else
		{
			root=NULL;
			free(r);
			return;
		}
	}
	else
	{
		if(r->left==NULL || r->right==NULL)  //case2
		{
			node* w=r->parent;
			if(w==NULL)
			{
				if(root->left==NULL)
					root=root->right;
				if(root->right==NULL)
					root=root->left;
				free(r);
				return;
			}
			else
			{
				if(w->right==r)
				{
					if(r->right!=NULL)
					{
						w->right=r->right;
						free(r);
						return;
					}
					if(r->left!=NULL)
					{
						w->right=r->left;
						free(r);
						return;
					}
				}
				if(w->left==r)
				{
					if(r->right!=NULL)
					{
						w->left=r->right;
						free(r);
						return;
					}
					if(r->left!=NULL)
					{
						w->left=r->left;
						free(r);
						return;
					}
				}
			}
		}
	}
	if(r->left!=NULL && r->right!=NULL) //case 3
	{
		

	}
}

int main()
{
	int n;
	cin>>n;
	int a[100];
	for(int i=0;i<n;i++)
		cin>>a[i];
	node* root;
	root=createnode(a[0]);
	for(int i=1;i<n;i++)
	{
		insert(root,a[i]);
	}
	return 0;
}