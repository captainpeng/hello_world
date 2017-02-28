#include<stdio.h>
#include<stdlib.h>

#ifndef _searchtree_h
#define _searchtree_h

typedef char eleSearchTree;
struct SearchTreeNode;
typedef struct SearchTreeNode *searchtree;

int IsEmpSTree(searchtree node);
void EmptySTree(searchtree node);
searchtree NewSTree(eleSearchTree x);
searchtree STreeFind(searchtree node,eleSearchTree x);
searchtree STreeFindMax(searchtree node);
searchtree STreeFindMin(searchtree node);
searchtree STreeIn(searchtree node,eleSearchTree x);
searchtree STreeDel(searchtree node,eleSearchTree x);	


#endif

struct
SearchTreeNode{
	eleSearchTree x;
	struct SearchTreeNode * right;
	struct SearchTreeNode * left;
};


int
IsEmpSTree(searchtree node)
{
	return node->right==NULL&&node->left==NULL;
}


void
EmptySTree(searchtree node)
{
	if(node!=NULL){
		EmptySTree(node->right);
		EmptySTree(node->left);
		free(node);
	}
	return ;

}

searchtree
NewSTree(eleSearchTree x)
{
	searchtree node=malloc(sizeof(struct SearchTreeNode));
	if(node==NULL)	return 0;
	node->right=node->left=NULL;
	node->x=x;
	return node;
}

searchtree
STreeFind(searchtree node,eleSearchTree x)
{
	if(node==NULL)
		return 0;
	if(x>node->x)
		return STreeFind(node->right,x);
	if(x<node->x)
		return STreeFind(node->left,x);
	return 0;
}	

searchtree
STreeFindMax(searchtree node)
{
	if(node==NULL)
		return NULL;
	if(node->right==NULL)
		return node;
	else 
		return STreeFindMax(node->right);
}

searchtree
STreeFindMin(searchtree node)
{
	if(node==NULL)
		return NULL;
	if(node->left==NULL)
		return node;
	else
		return STreeFindMin(node->left);

}

searchtree
STreeIn(searchtree node,eleSearchTree x)
{
	if(node==NULL){
		node=NewSTree(x);
		return node;
	}
	
	else if(x<node->x)	
		node->left=STreeIn(node->left,x);
	else if(x>node->x)
		node->right=STreeIn(node->right,x);
	return node;
}	

/*searchtree
STreeDel(searchtree node,eleSearchTree x)
{
	searchtree tmpp;
	node=STreeFind(node,x);
	if(node==NULL)
		return 0;
	if(node->left&&node->right){
		tmpp=STreeFindMin(node->right);
		node->x=tmpp->x;
		node->right=STreeDel(node->right,node->x);
	}
	else if(node->left||node->right){
			if(node->left==NULL){
				node->x=node->right->x;
				tmpp=node->right;
			}
			if(node->right==NULL){
				node->x=node->left->x;
				tmpp=node->left;
			}
	}
	else
		free(node);
	return 0;
}	*/

searchtree
STreeDel(searchtree node,eleSearchTree x)
{
	searchtree tmpp;
	if(node==NULL)
		return 0;
	else
	if(x<node->x)
		node->left=STreeDel(node->left,x);
	else 
	if(x>node->x)
		node->right=STreeDel(node->right,x);
	else
	if(node->left&&node->right){
		tmpp=STreeFindMin(node->right);
		node->x=tmpp->x;
		node->right=STreeDel(node->right,node->x);
	}
	else{
		tmpp=node;
		if(node->left==NULL)
			node=node->right;
		else if(node->right==NULL)
			node=node->left;
		free(tmpp);
	}
	return node;
}		
		
