#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;



typedef struct node{
	int data;
	struct node* next;
} node;


node* createnode(int x)
{
	node* p=(node*)malloc(sizeof(node));
	p->data=x;
	p->next=NULL;
	return p;
}

node* push(node** s,int x)
{
	node* p=createnode(x);
	p->next=*s;
	*s=p;
	//cout<<s->data;
	return p;
}

void pop(node** s)
{
	if(*s==NULL)
		return;
	node* temp=*s;
	*s=(*s)->next;
	free(temp);
}


int main()
{
	//node* w;
	//w=NULL;
	node* s;
	s=NULL;
	push(&s,2);
	
	//cout<<s->data<<"&"<<endl;
	push(&s,4);
	//cout<<s->next->data<<"&"<<endl;
	/*if(s->next==NULL)
	{
		cout<<"heu";
	}*/
	push(&s,5);
	//cout<<s->top<<"&"<<endl;
	push(&s,9);
	//cout<<s->top<<"&"<<endl;
	pop(&s);
	//cout<<s->top<< "$"<<endl;
	//cout<<k<<"#"<<endl;

	for(node* p=s;p!=NULL;p=p->next)
	{
		cout<<p->data<<endl;
	}

	return 0;
}