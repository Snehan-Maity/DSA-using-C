#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node *head = NULL;
struct Node *createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void addBeg(int data){
    struct Node* newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}
void addEnd(int data){
    struct Node * newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}
void delBeg(){
    if(head == NULL)return;
    struct Node* temp = head;
    head = head->next;
    free(temp);
}
void delEnd(){
    if(head == NULL)return;
    if(head->next == NULL){
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return;
}
void display(){
    struct Node* temp = head;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void reverseList(){
    if(head == NULL)return;
    struct Node *curr = head, *prev = NULL, *next;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}
int search(int data){
    if(head == NULL)return 0;
    struct Node* temp = head;
    while(temp!=NULL){
        if(temp->data == data){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
int maximum(){
    if(head == NULL)return INT_MIN;
    struct Node* temp = head;
    int max = head->data;
    while(temp!=NULL){
        if(temp->data > max)max = temp->data;
        temp = temp->next;
    }
    return max;
}
int minimum(){
    if(head == NULL)return INT_MAX;
    struct Node* temp = head;
    int min = head->data;
    while(temp!=NULL){
        if(temp->data < min)min = temp->data;
        temp = temp->next;
    }
    return min;
}
int count(){
    if(head == NULL)return 0;
    int count = 0;
    struct Node* temp = head;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;
}
void addPos(int item,int x){
	struct Node *curr = createNode(item);
	struct Node* temp=head,*prev;
	if(x<1 || x>count()+1){
		printf("Position not found");
		return;
	}
	int i=1;
	while(temp!=NULL && i<x){
		prev=temp;
		temp=temp->next;
		i++;
	}
	if(temp==head){
		curr->next=temp; 
		head=curr;
		return;
	}
    prev->next = curr;
    curr->next = temp;
    return;
}
void deletePosition(int x){
	struct Node* temp=head,*prev;
	if(x<1||x>count()){
		printf("Position not found");
		return;
	}
	int i=1;
	while(temp!=NULL && i<x){
		prev=temp;
		temp=temp->next;
		i++;
	}
	if(temp==head){
		head=head->next; 
		free(temp);
		printf("\nItem deleted successfully");
		return;
	}
	else if(temp->next==NULL){
		prev->next=NULL;
		free(temp);
		printf("\nItem deleted successfully");
		return;
	}
	else{
		prev->next=temp->next; 
		free(temp); 
		printf("\nItem deleted successfully");
		return;
	}
}
int main(){
    int item,pos,choice,x;
    while(1){
        printf("\n0. Exit\n1. Add at beginning\n2. Add at end\n3. Delete at beginning\n4. Delete at end\n5. Display\n6. Reverse\n7. Search\n8. Maximum\n9. Minimum\n10. Count Nodes\n11. Insert by Position\n12. Delete by position\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 0:
                exit(0);
            case 1:
                printf("Enter an item to add at beginning: ");
                scanf("%d",&item);
                addBeg(item);
                break;
            case 2:
                printf("Enter an item to add at end: ");
                scanf("%d",&item);
                addEnd(item);
                break;
            case 3:
                delBeg();
                break;
            case 4:
                delEnd();
                break;
            case 5:
                display();
                break;
            case 6:
                reverseList();
                break;
            case 7:
                printf("Enter an item to search: ");
                scanf("%d",&item);
                x=search(item);
                if(x==1){
        		printf("%d is present in the Linked List",item);
		}
		else{
			printf("%d is not present in the Linked List",item);
		}
                break;
            case 8:
                printf("The maximum value is %d\n",maximum());
                break;
            case 9:
                printf("The minimum value is %d\n",minimum());
                break;
            case 10:
                printf("The count of nodes is %d\n",count());
                break;
            case 11:
               	printf("Enter the item to add : ");
                scanf("%d",&item);
                printf("Enter its position : ");
                scanf("%d",&pos);
                addPos(item,pos);
                break;
            case 12:
            	printf("Enter the position where you want to delete element : ");
            	scanf("%d",&item);
            	deletePosition(item);
            	break;
            default: printf("Invalid Choice !!");
        }
    }
}
