#include<stdio.h>
#include<stdlib.h>

#ifndef _queue_h
#define _queue_h
#define MaxQueue 500
#define MinQueue 5
#define Empty -1

struct QueueHead;
typedef struct QueueHead *queue;
typedef char elequeue;

queue newqueue(int x);
void emptyqueue(queue head);
int isemptyqueue(queue head);
void inqueue(queue headi,elequeue x);
elequeue outqueue(queue head);
void delqueue(queue head);

#endif

struct QueueHead{
	int capacity;
	int front;
	int rear;
	int size;
	elequeue *array;
};

queue newqueue(int x)
{
	if(x<MinQueue||x>MaxQueue){
		printf("Too short(or long) to creat a new queue !!\n");
		return NULL;
	}
	
	queue head=malloc(sizeof(struct QueueHead));
	if(head==NULL){
		printf("Out of space !!Can't creat a new queue!!\n");
		return NULL;
	}
	
	head->array=malloc(sizeof(elequeue)*x);
	if(head->array==NULL){
		printf("Out of space !! Can't creat the cache!!\n");
		return head;
	}
	head->capacity=x;
	emptyqueue(head);
	return head;
}

void emptyqueue(queue head){
	head->front=0;
	head->rear=-1;
	head->size=0;
}

int isemptyqueue(queue head)
{
	return head->size==0;
}

void inqueue(queue head,elequeue x)
{
	if(head->size==head->capacity){
		printf("The queue is full!!\nCan't insert !!\n");
		return ;
	}
	
	head->rear=(head->rear==head->capacity-1)?0:head->rear+1;
	head->array[head->rear]=x;
	++head->size;
}

elequeue outqueue(queue head)
{
	elequeue x;	

	if(isemptyqueue(head)){
		printf("Can't output a empty queue!!\n");
		return 0;
	}
	
	x=head->array[head->front];
	head->front=(head->front==head->capacity-1)?0:head->front+1;
	return x;
}

void delqueue(queue head)
{
	free(head->array);
	free(head);
}

	
