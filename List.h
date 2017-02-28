#include<stdlib.h>
#include<stdio.h>
#ifndef _list_h
#define _list_h
#define LIST sizeof(list)
struct ListNode;
typedef struct ListNode *list;
typedef struct ListNode *listhead;
typedef struct ListNode listnode;

listhead newlist(void);
int isemptylist(listhead p);
int islastlist(list p);
list findlist(listhead h,int x);
list findlistp(listhead h,int x);
int insert(list p,int x);
void delistnode(listhead h,int x);
void delist(listhead h);

#endif /* _list_H */

struct ListNode 
{
	int num;
	struct ListNode *next;
};

listhead newlist(void)
{
	listhead h;
	h=malloc(LIST);
	if(h==NULL)
		return NULL;
	else 
		h->next=NULL;
	return h;
}

int isemptylist(listhead h)
{
	return h->next==NULL;
}

int islastlist(list p)
{
	return p->next==NULL;
}

list findlist(listhead h,int x)
{
	list p=h->next;
	while(p!=NULL&&p->num!=x)
		p=p->next;
	return p;
}

list findlistp(listhead h,int x)
{
	list p=h->next;
	while(p->next!=NULL&&p->next->num!=x)
		p=p->next;
	return p;
}

int insert(list p,int x)
{
	list tempp;
	tempp=malloc(LIST); /*(sizeof(list));*/
	if(tempp==NULL){
		printf("error");	
		return 0;}
	tempp->num=x;		/* if successfully malloc zone and tempp->x=x,else return 0*/
	tempp->next=p->next;
	p->next=tempp;
	return 1;
}

void delistnode(listhead h,int x)
{
	list p;
	p=findlistp(h,x); /* as the same as function find but find the pointer which potint to it */
	if(!islastlist(p)){
		list tempp=p->next;
		p->next=p->next->next;
		free(tempp);
	}
}

void delist(listhead h)
{
	list p,tempp;
	p=h->next;
	h->next=NULL; 
	while(p!=NULL){
		tempp=p->next;
		free(p);
		p=tempp;
	}
	h->next=NULL;
}

