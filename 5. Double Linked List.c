//Double Linked List
#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node *prev;
    int data;
    struct Node* next;
};
struct Node *head = NULL;
struct Node *createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}
void addBeg(int data){
    struct Node* current = createNode(data);
    if(head == NULL){
        head = current;
        return;
    }
    current->next = head;
    head->prev = current;
    head = current;
}
void addEnd(int data){
    struct Node* current = createNode(data);
    if(head == NULL){
        head = current;
        return;
    }
    struct Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = current;
    current->prev = temp;
}
void delBeg(){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
}
void delEnd(){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    if(head->next == NULL){
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
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
		temp->prev=curr; 
		head=curr;
		return;
	}
    prev->next = curr;
    curr->prev=prev;
    curr->next = temp;
    temp->prev=curr;
    return;
}
void delPosition(int x){
	struct Node* temp=head,*prev,*next;
	if(x<1||x>count()){
		printf("Position not found");
		return;
	}
	int i=1;
	while(temp->next!=NULL && i<x){
		prev=temp;  //4
		next=temp->next;
		temp=temp->next;
		i++;
	}
	if(temp==head){ //only for first element del
		head=head->next; //2
		free(temp);//1
		printf("\nItem deleted successfully");
		return;
	}
	else if(temp->next==NULL){ // last element del
		prev->next=NULL;
		free(temp);
		printf("\nItem deleted successfully");
		return;
	}
	else{
		prev->next=temp->next; //4-->6
		next->prev=prev;
		free(temp); //5
		printf("\nItem deleted successfully");
		return;
	}
}
int search(int data){
    struct Node* temp = head;
    while(temp!=NULL){
        if(temp->data == data){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
void display(){
    struct Node *temp = head;
    printf("List : ");
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    int item,pos,choice;
    while(1){
        printf("\n0.To exit\n1.Add at beginning \n2.Add at end \n3.Display \n4.Delete beg \n5.Delete end\n6.Search\n7.Insert by position\n8.Delete by position\nEnter your choice : \n");
        scanf("%d", &choice);
        switch(choice){
            case 0:
                exit(0);
            case 1:
                printf("Enter an item to add at beginning : ");
                scanf("%d", &item);
                addBeg(item);
                break;
            case 2:
                printf("Enter an item to add at end : ");
                scanf("%d", &item);
                addEnd(item);
                break;
            case 3:
                display();
                break;
            case 4:
                delBeg();
                break;
            case 5:
                delEnd();
                break;
            case 6:
                printf("Enter an item to search : ");
                scanf("%d", &item);
                if(search(item)){
                    printf("%d is found in the List\n", item);
                }
                else{
                    printf("%d not found in the list\n", item);
                }
                break;
            case 7:
               	printf("Enter the item to add : ");
                scanf("%d",&item);
                printf("Enter its position : ");
                scanf("%d",&pos);
                addPos(item,pos);
                break;
            case 8:
            	printf("Enter the position where you want to delete : ");
            	scanf("%d",&item);
            	delPosition(item);
            	break;
            default:
                printf("Invalid choice\n");
        }
    }
}
