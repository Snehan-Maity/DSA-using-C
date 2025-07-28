#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
char str[MAX];
int top=-1;
int n;
int isEmpty(){
	return(top==-1);
}
int isFull(){
	return (top==MAX-1);
}
void push(int item){
	if(isFull()){
		printf("Stack is Full");
		return;
	}	
	else{
		top=top+1;
		str[top]=item;
	}
}
int pop(){
	if(isEmpty()){
		printf("Stack is Empty");
		return INT_MIN;
	}
	else{
		int x=str[top];
		top=top-1;
		return x;
	}
}
int isOperator(char ch){
	if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	int n,op1,op2,result,ans;
	printf("Enter the Expression : ");
	gets(str);
	n=strlen(str);
	printf("Postfix Expression : ");
	puts(str);
	for(int i=0;i<=n;i++){
		if(str[i]>='0' && str[i]<='9'){
			push(str[i]-48);
		}
		else if(isOperator(str[i])){
			op2=pop();
			op1=pop();
			switch(str[i]){
				case '+':result=op1+op2;
						break;	
				case '-':result=op1-op2;
						break;
				case '*':result=op1*op2;
						break;
				case '/':result=op1/op2;
						break;
			}
			push(result);
		}
	}
	ans=pop();
	printf("Output : %d",ans);
}
