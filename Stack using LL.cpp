#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* next;
};
struct Node* top=NULL;
struct Node* createNode(int item){
	struct Node* ptr=(struct Node *)malloc(sizeof(struct Node));
	ptr->data=item;
	ptr->next=NULL;
	return ptr;
}
int isEmpty(){
	return(top==NULL);
}
void push(int item){
	struct Node* curr=createNode(item);
	if(top==NULL){
		top=curr;
		curr->next=NULL;
		return;
	}
	curr->next=top;
	top=curr;
	return;
}
int peek(){
	if(isEmpty()){
		printf("Stack is Empty");
		return INT_MAX;
	}
	return top->data;
}
void pop(){
	if(isEmpty()){
		printf("Stack Empty");
		return;
	}
	struct Node* temp=top;
	top=top->next;
	free(temp);
	return;
}
void display(){
	struct Node* temp=top;
	if(temp==NULL){
		printf("Stcak Empty");
		return;
	}
	do{
		printf("%3d",temp->data);
		temp=temp->next;
	}
	while(temp!=NULL);
}
int main(){
	int choice,n,p;
	while(1){
		printf("\n0. To Exit\n1. To Push\n2. To Peek\n3.To Pop\n4.To Display\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 0: exit(0);
					break;
			case 1: printf("Enter the number to push : ");
					scanf("%d",&n);
					push(n);
					break;
			case 2: p=peek();
					if(p!=INT_MAX){
						printf("%d",p);
					}
					break;
			case 3: pop();
					break;
			case 4: display();
					break;
			default: printf("Invalid Choice !!");
		}
	}
}
