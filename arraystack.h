#include<stdio.h>
#include<stdlib.h>

#ifndef _arraystack_h
#define _arraystack_h
#define ARRAYSTACK sizeof(astype)*Max /* using to the new arrrry stack */
#define MinStack 5 /* the min stack size */
#define MaxStack 500 /* the max stack size */
#define EmptyTop -1;

struct ArrayStack;
typedef struct ArrayStack *ashead;/* ashead --> array stack head */
typedef int astype;

ashead newAS(int Max);/* you need to input the max elements to create new stack */
int isemptyAS(ashead head);/* chaeck if the array stack is empty */
void emptyAS(ashead head);/* make the array stack empty */
astype AStop(ashead head);
void ASpush(ashead head,astype x);
void ASpop(ashead head);
void delAS(ashead head);
astype tapAS(ashead head); /* tap(top and pop) */
#endif

struct ArrayStack{
	int capacity;  
	int topofstack;
	astype *array;
};

ashead newAS(int Max)
{
	ashead head;
	if(Max<MinStack){
		printf("Stack size is too small\n");
		return NULL;
	}

	head=malloc(sizeof(struct ArrayStack));
	
	if(head==NULL){
		printf("Out of space!!\n");
		return head;
	}
	
	head->array=malloc(ARRAYSTACK);
	
	if(head->array==NULL){
		printf("Out of space!!\nMax is too big!!\n");
		return head;
	}
	
	head->capacity=Max;
	emptyAS(head);
	return head;
}

int isemptyAS(ashead head)
{
	return head->topofstack==EmptyTop; /* emptyAS make topofstack == EmptyTop(-1);
									return 1:is empty arraystack;
									return 0:not empty arraystack;	*/

}

void emptyAS(ashead head)
{
	head->topofstack=EmptyTop;
	
	/*	int i;
	for(i=0;i<head->capacity;++i)
		head->array[i]=0;
	*/
}

astype AStop(ashead head)
{
	if(!isemptyAS(head))
		return head->array[head->topofstack];
	printf("Empty stack!!\n");
	return 0;
}

void ASpush(ashead head,astype x)
{	
	if((head->topofstack+1)>head->capacity){
		printf("Can't push ,Out of space!!\n");
		return ;
	}
	
	++head->topofstack;
	head->array[head->topofstack]=x;
}

void ASpop(ashead head)
{	
	if(isemptyAS(head))
		printf("Empty stack ,Can't pop!!\n");
	else
		--head->topofstack;
}

void delAS(ashead head)
{
	if(head!=NULL){
		free(head->array);
		free(head);
	}
}

astype tapAS(ashead head)
{	
	if(!isemptyAS(head)){
		--head->topofstack;
		return head->array[head->topofstack+1];
	}
	else{
		printf("Empty stack ,Can't pop !!\n");	
		return 0;
	}
}	
