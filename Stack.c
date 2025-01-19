#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 10
int arr[MAX];
int top=-1;
int isFull(){
    if(top==MAX-1){
        return 1;
    }
    return 0;
}
int isEmpty(){
    return(top==-1);
}
void push(int item){
    if(isFull()){
        printf("Stack full");
        return;
    }
    arr[++top]=item;
    return;
}
int peek(){
    if(isEmpty()){
        printf("Stack is empty");
        return INT_MIN;
    }
    int x=arr[top];
    return x;
}
int pop(){
    if(isEmpty()){
        printf("Stack empty");
        return INT_MIN;
    }
    int x=arr[top];
    top=top-1;
    return x;
}
void display(){
    if(isEmpty()){
        printf("Stack empty");
        return;
    }
    for(int i=top;i>=0;i++){
        printf("%4d",arr[i]);
    }
}
int main(){
    int item,choice;
    while(1){
        printf("\n0.Exit\n1.Push\n2.Pop\n3.Peek\n4.Display\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1 : printf("Enter item to insert : ");
            scanf("%d",&item);
            push(item);
            break;
            case 2 : printf("Popped item : %d",pop());
            break;
            case 3 : printf("Top item : %d",peek());
            break;
            case 4 : display();
            break;
            case 0 : exit(0);
            break;
            default : printf("Invalid choice");
        }
    }
}