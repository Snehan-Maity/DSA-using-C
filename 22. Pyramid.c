#include<stdio.h>
#include<stdlib.h>
struct Node{
	struct Node* lchild,* rchild;
	int data;
	int lthread,rthread;
};
struct Node* root=NULL;
struct Node* createNode(int item){
	struct Node* ptr=(struct Node* )malloc(sizeof(struct Node));
	ptr->lchild=NULL;
	ptr->data=item;
	ptr->rchild=NULL;
	ptr->lthread=ptr->rthread=1;
	return ptr;
}
struct Node* leftMost(struct Node* r){
	if(r==NULL){
		return r;
	}
	struct Node* temp=r;
	while(temp->lthread==0){
		temp=temp->lchild;
	}
	return temp;
}
void inOrder(struct Node* r){
	if(r==NULL){
		return;
	}
	struct Node* temp=leftMost(r);
	while(temp!=NULL){
		printf("%3d",temp->data);
		if(temp->rthread==1){
			temp=temp->rchild;
		}
		else{
			temp=leftMost(temp->rchild);
		}
	}
}
