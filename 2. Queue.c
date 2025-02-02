#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 5
int arr[MAX];
int front=-1,rear=-1;
int isEmpty(){
    return(front==rear);
}
int isFull(){
    return(rear==MAX-1);
}
void enQueue(int item){
    if(isFull()){
        printf("Queue full\n");
        return;
    }
    rear=rear+1;
    arr[rear]=item;
    return;
}
int deQueue(){
    if(isEmpty()){
        printf("Queue Empty\n");
        return INT_MIN;
    }
    front=front+1;
    return arr[front];
}
int peek(){
    if(isEmpty()){
        printf("Queue Empty\n");
        return INT_MIN;
    }
    return arr[front+1];
}
void display(){
    if(isEmpty()){
        printf("Queue Empty\n");
        return;
    }
    int i;
    for(i=front+1;i<=rear;i++){
        printf("%4d ",arr[i]);
    }
    return;
}
int main(){
    int item,choice;
    while(1){
        printf("\n0.Exit\n1.Insert\n2.Delete\n3.Peek\n4.Display\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1 : printf("Enter item to insert : ");
            scanf("%d",&item);
            enQueue(item);
            break;
            case 2 : printf("Popped item : %d",deQueue());
            break;
            case 3 : printf("Peeked item : %d",peek());
            break;
            case 4 : display();
            break;
            case 0 : exit(0);
            break;
            default : printf("Invalid choice");
        }
    }
}
