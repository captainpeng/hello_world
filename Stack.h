#include<stdio.h>
#include<stdlib.h>
/*----------------------------------------------------------------------------------
	This is the stack of linst,It's too busy to using function "malloc" and "free".
	So,i will write anthor head file using array.
	If you use this ,i think you need to make sure you are not use in the web or date base.
	If yes,you can think about the stack of array.
	Nice to see you!
  --------------------------------------------------------------------------------*/
#ifndef _stack_h
#define _stack_h
#define STACK sizeof(stacknode) 
struct StackNode;
typedef struct StackNode *stack;
typedef struct StackNode *stackhead;
typedef struct StackNode stacknode;

int isemptystack(stackhead h);
stackhead newstack(char x);
void push(stackhead head,char x);
char top(stackhead head);
void pop(stackhead head);
#endif
/*-------------------Function-----------------------*/

struct StackNode{
	char act;
	struct StackNode *next;
};

/*-----------------isemptystack--------------------
	This function is using judge stack of 'h' pointer whether 
	it is empty.
	Yes,return (int)1;No,return(int)0.
  ------------------------------------------------*/
int isemptystack(stackhead h)
{
	return h->next==NULL;
}
/*------newstack----
	As it name,using creat a empty stack coded 'x'.
	("char x" is the code i named,because someone will creat >1 group stack,
		and the code 'x' will be helpful to you to judge which stack you 
		 want.)
  	after do that,it will return a stack pointer 'h'.
  ----------------*/
stackhead newstack(char x)
{
	stackhead h=malloc(STACK);
	if(!h)
		return NULL;
	h->act=x;
	h->next=NULL;
	return h;
}

void push(stackhead head,char x)
{
	stack tempp=malloc(STACK);
	if(tempp==NULL){
		printf("Can't push!\n");
		return ;
	}
	
	tempp->act=x;
	tempp->next=head->next;
	head->next=tempp;
}

char top(stackhead head)
{
	if(!isemptystack(head))
		return head->next->act;
	printf("Empty stack!\n");
	return 0;
}	

void pop(stackhead head)
{
	stack tempp;
	if(isemptystack(head)){
		printf("It is empty stack,can't pop");
		return ;
	}
	else{
		tempp=head->next;
		head->next=head->next->next;
		free(tempp);
	}
}
