#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* next;
};
struct Node* createNode(int item){
	struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
	ptr->data=item;
	ptr->next=NULL;
	return ptr;
}
struct Node* last=NULL;
void addBeg(int item){
	struct Node* curr=createNode(item);
	if(last==NULL){ //First element
		last=curr;
		curr->next=last;
		return;
	}
	curr->next=last->next;
	last->next=curr;
	return;
	
}
void addEnd(int item){
	struct Node* curr=createNode(item);
	if(last==NULL){
		last=curr;
		curr->next=last;
		return;
	}
	curr->next=last->next;
	last->next=curr;
	last=curr;
	return;
}
void display(){
	if(last==NULL){
		printf("Empty CLL\n");
		return;
	}
	struct Node* temp=last->next;
	do{
		printf("\td",temp->data);
		temp=temp->next;
	}
	while(temp!=last->next);
	return;
}
void delBeg(){
	if(last==NULL){
		printf("Empty List. Unable to delete\n");
		return;
	}
	struct Node* temp=last->next;
	if(temp==last){
		last=NULL;
		free(temp);
		return;
	}
	last->next=temp->next;
	free(temp);
	return;
}
void delEnd(){
	if(last==NULL){
		printf("Empty List. Unable to delete\n");
		return;
	}
	struct Node* temp=last->next;
	if(temp==last){
		last=NULL;
		free(temp);
		return;
	}
	while(temp->next!=last){
		temp=temp->next;
	}
	temp->next=last->next;
	free(last);
	last=temp;
	return;
}
int main(){
	int choice,n,x;
	while(1){
		printf("\n0. To Exit\n1. To Add Beginning\n2. To Add End\n3. To display\n4. To Delete Beginning\n5. To Delete End\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 0 :exit(0);
					break;
			case 1 :printf("Enter the number to insert : ");
					scanf("%d",&n);
					addBeg(n);
					break;
			case 2 :printf("Enter the number to insert : ");
					scanf("%d",&n);
					addEnd(n);
					break;
			case 3 :display();
					break;
			case 4 :delBeg();
					break;
			case 5 :delEnd();
					break;
			default :printf("Invalid Choice !!");
		}
	}
	return 0;
}
