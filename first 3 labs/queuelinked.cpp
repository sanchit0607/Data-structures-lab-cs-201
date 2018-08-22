#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

typedef struct node{
	int data;
	struct node* next;
}node;


typedef struct queue{
	node* front;
	node* rear; 
}queue;

node* createnode(int x)
{
	node* p=(node*)malloc(sizeof(node));
	p->data=x;
	p->next=NULL;
	return p;
}

queue* createqueue()
{
	queue* p=(queue*)malloc(sizeof(queue));
	p->front=NULL;
	p->rear=NULL;
	return p;
}


void push(queue* a,int x)
{
	node* p=createnode(x);
	if(a->front==NULL)
	{
		a->front=p;
		a->rear=p;
	}
	else
	{
		a->rear->next=p;
		a->rear=p;
	}
}



void pop(queue* a)
{
	if(a->front==NULL)
	{
		return;
	}
	if(a->front==a->rear)
	{
		node* temp=a->front;
		a->front=a->rear=NULL;
		free(temp);
	}
	else
	{
		node* temp=a->front;
		a->front=a->front->next;
		free(temp);
	}
}





int main()
{
	queue* q=createqueue();
	//queue* q;
	push(q,2);
	
	//cout<<s->data<<"&"<<endl;
	push(q,4);
	//cout<<s->next->data<<"&"<<endl;
	/*if(s->next==NULL)
	{
		cout<<"heu";
	}*/
	push(q,5);
	//cout<<s->top<<"&"<<endl;
	push(q,9);
	//cout<<s->top<<"&"<<endl;
	pop(q);
	//cout<<s->top<< "$"<<endl;
	//cout<<k<<"#"<<endl;

	for(node* p=q->front;p!=NULL;p=p->next)
	{
		cout<<p->data<<endl;
	}

	return 0;


}