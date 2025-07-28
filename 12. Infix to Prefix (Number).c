#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

char stack[MAX];
int top = -1;

int isEmpty() {
    return (top == -1);
}

int isFull() {
    return (top == MAX - 1);
}

void push(char item) {
    if (isFull()) {
        printf("Stack is Full\n");
        return;
    } else {
        top++;
        stack[top] = item;
    }
}

char pop() {
    if (isEmpty()) {
        printf("Stack is Empty\n");
        return '\0';
    } else {
        char x = stack[top];
        top--;
        return x;
    }
}

char peek() {
    if (isEmpty()) {
        return '\0';
    }
    return stack[top];
}

int precedence(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    } else if (ch == '*' || ch == '/') {
        return 2;
    } else if (ch == '^') {
        return 3;
    } else {
        return 0;
    }
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

char* reverse(char* str, int n) {
    static char reversed[MAX];
    int j = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (str[i] == '(') {
            reversed[j++] = ')';
        } else if (str[i] == ')') {
            reversed[j++] = '(';
        } else {
            reversed[j++] = str[i];
        }
    }
    reversed[j] = '\0';
    return reversed;
}

char* convertToPostfix(char* str, int n) {
    static char postfix[MAX];
    int k = 0;
    for (int i = 0; i < n; i++) {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9')) {
            postfix[k++] = str[i];
        } else if (str[i] == '(') {
            push(str[i]);
        } else if (isOperator(str[i])) {
            while (!isEmpty() && peek() != '(' && precedence(str[i]) <= precedence(peek())) {
                postfix[k++] = pop();
            }
            push(str[i]);
        } else if (str[i] == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // Remove '(' from stack
        }
    }

    while (!isEmpty()) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0'; // Null-terminate the postfix expression
    return postfix;
}

void toUpperCase(char* str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
}

int main() {
    char str[MAX];
    printf("Enter the Infix Expression (Numbers) : ");
    fgets(str, MAX, stdin); // Use fgets instead of gets to avoid buffer overflow
    str[strcspn(str, "\n")] = '\0'; // Remove newline character from input

    int n = strlen(str);
    
    // Convert infix to prefix
    char* reversedStr = reverse(str, n);
    char* postfixStr = convertToPostfix(reversedStr, n);
    char* prefixStr = reverse(postfixStr, strlen(postfixStr));

    printf("Prefix Expression: ");
    puts(prefixStr);

    return 0;
}
