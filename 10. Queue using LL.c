#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* next;
};
struct Node* createNode(int item){
	struct Node* ptr= (struct Node*) malloc(sizeof(struct Node));
	ptr->data=item;
	ptr->next=NULL;
	return ptr;
}
struct Node* front=NULL;
struct Node* rear=NULL;
int isEmpty(){
	return (front==NULL);
}
void enQueue(int item){
	struct Node* curr=createNode(item);
	if(rear==NULL){
		rear=curr;
		front=curr;
		return;
	}
	rear->next=curr;
	rear=curr;
	return;
}
int peek(){
	if(isEmpty()){
		printf("Empty Queue");
		return INT_MAX;
	}
	return (front->data);
}
void deQueue(){
	struct Node* temp=front;
	if(isEmpty()){
		printf("Empty Queue");
		return;
	}
	front=front->next;
	if(front==NULL){
		rear=NULL;
		free(temp);
		return;
	}
}
void display(){
	struct Node* temp=front;
	if(temp==NULL){
		printf("Queue Empty");
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
		printf("\n0. To Exit\n1. To Insert Element\n2. To Peek\n3. To Delete\n4. To display\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 0: exit(0);
					break;
			case 1: printf("Enter the number to insert : ");
					scanf("%d",&n);
					enQueue(n);
					break;
			case 2: p=peek();
					if(p!=INT_MAX){
						printf("%d",p);
					}
					break;
			case 3: deQueue();
					break;
			case 4: display();
					break;
			default: printf("Invalid Choice !!");
		}
	}
}
