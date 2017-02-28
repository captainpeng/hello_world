#include<stdio.h>
#include<stdlib.h>
#define Max 30

struct SeqNode;	/*arrayNode */
struct SeqHead;	/*Sequence List head */
typedef struct SeqHead * seqlist; /*Sequence List head */

seqlist NewSeq(void);	/* Creat a New Sequence List,if successful,return (seqlist),else return NULL */
int Input(seqlist head,int x); /* function will put the number in the end */
void Output(seqlist head);	/* print the Sequence List */
int Insert(seqlist head,int s,int x);	/* insert the x behind seat s */
int Delete(seqlist head,int x);	/* delete the x */
int Find(seqlist head,int x);	/* find x position,if x exit,return postion,else return -1 */

struct SeqNode
{
	int x;	/* the number */
	int next;	/* the next number postion */
};

struct SeqHead
{
	int len;	/* Senquence List length && next Sequence Node position*/
	int last;	/* the end of position */
	struct SeqNode * array; /* array */
};

int main()
{
	seqlist head;
	int x;
	int s;

	head=NewSeq();
	printf("Please input 10 number you want:\n");
	for(s=0;s<10;s++){
		scanf("%d",&x);
		Input(head,x);
	}

	printf("The number you want is \n");
	Output(head);
	
	printf("Please input the number you want to find :");
	scanf("%d",&x);
	s=Find(head,x);
	if(s==-1)
		printf("Can't find!!\n");
	else 
		printf("Find!! The position is No.%d\n",s);

	printf("Input the number and the postion you want to insert\n");
	scanf("%d",&x);
	scanf("%d",&s);
	Insert(head,s,x);
	Output(head);
	
	printf("Please input the number you want to delete :");
	scanf("%d",&x);
	Delete(head,x);
	Output(head);
	
	free(head->array);
	free(head);
	printf("GOOD!!\n");
	return 0;

}

seqlist NewSeq(void)
{
	seqlist head=malloc(sizeof(struct SeqHead));
	if(head==NULL)
		return NULL;
	head->array=malloc(sizeof(struct SeqNode)*30);	
	head->len=0;
	return head;
}
	
int Input(seqlist head,int x)
{
	if(head->len>=Max||head->array==NULL)
		return -1;
	head->array[head->len].x=x;
	head->array[head->len].next=-1;
	head->array[head->last].next=head->len;
	head->last=head->len;
	return head->len++;
}

void Output(seqlist head)
{
	int a=0;
	if(head==NULL||head->array==NULL)
		return ;
	while(a!=-1){
		printf("%d ",head->array[a].x);
		a=head->array[a].next;
	}
	printf("\n");
}

int Insert(seqlist head,int s,int x)
{
	if(head->len>=Max||head->array==NULL)
		return -1;
	if(s==head->len)
		Input(head,x);
	head->array[head->len].x=x;
	head->array[head->len].next=head->array[s-1].next;
	head->array[s-1].next=head->len;
	return head->len++;
}

int Delete(seqlist head,int x)
{
	int a=0;
	if(head->array[0].x==x)
	{
		head->array[0]=head->array[head->array[0].next];
		return 0;
	}

	while(a<head->len)
	{
		if(head->array[head->array[a].next].x==x)
			break;
		++a;
	}
	
	if(a==head->len)
	{
		printf("Can't find!!\n");
		return -1;
	}

	head->array[a].next=head->array[head->array[a].next].next;
	return 0;
}

int Find(seqlist head,int x)
{
	int a;
	for(a=0;a<head->len;++a)
	{
		if(head->array[a].x==x)
			return a+1;
	}
	return -1;
}
