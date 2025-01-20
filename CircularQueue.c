#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 5
int arr[MAX];
int front=0,rear=0;
int isFull(){
    return((rear+1)%MAX == front);
}
int isEmpty(){
    return(front==rear);
}
void enQueue(int item){
    if(isFull()) {
        printf("Queue is full, can't insert %d\n", item);
        return;
    }
    rear = (rear+1)%MAX;
    arr[rear] = item;
}
int deQueue(){
    if(isEmpty()){
        printf("Queue is empty");
        return INT_MIN;
    }
    front=(front+1)%MAX;
    return arr[front];
}
int peek(){
    if(isEmpty()){
        printf("Queue is empty");
        return INT_MIN;
    }
    return arr[(front+1)%MAX];
}
void display(){
    if(isEmpty()){
        printf("Queue is empty");
        return;
    }
    for(int i=(front+1)%MAX; i!=rear; i=(i+1)%MAX){
        printf("%3d",arr[i]);
    }
    printf("%3d\n",arr[rear]);
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
