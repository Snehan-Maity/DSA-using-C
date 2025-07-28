#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	int priority;
	struct Node* next;
};
struct Node* createNode(int d,int p){
	struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
	ptr->data=d;
	ptr->priority=p;
	ptr->next=NULL;
	return ptr;
}
struct Node* front=NULL;
int isEmpty(){
	return(front==NULL);
}
void enQueue(int d,int p){
	struct Node* curr=createNode(d,p);
	if(front==NULL||p<front->priority){
		curr->next=front;
		front=curr;
		return;
	}
	struct Node* temp=front;
	while(temp->next!=NULL && temp->next->priority<=p){
		temp=temp->next;
	}
	curr->next=temp->next;
	temp->next=curr;
	return;
}
int peek(){
	if(!isEmpty()){
		return front->data;
	}
	return INT_MAX;
}
void deQueue(){
	if(!isEmpty()){
		struct Node* temp=front;
		front=front->next;
		free(temp);
		return;
	}
	else{
		printf("Empty Queue. Unable to delete");
		return;
	}
}
void display(){
	struct Node* temp=front;
	if(temp==NULL){
		printf("Empty Queue");
		return;
	}
	while(temp!=NULL){
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	return;
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
					printf("Enter its priority : ");
					scanf("%d",&p);
					enQueue(n,p);
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
