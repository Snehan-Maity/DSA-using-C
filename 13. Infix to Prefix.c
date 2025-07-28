#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
// Stack structure
typedef struct {
    int top;
    char items[MAX];
} Stack;
void push(Stack *s, char item) {
    if (s->top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    s->items[++(s->top)] = item;
}

char pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        return '\0';
    }
    return s->items[(s->top)--];
}

char peek(Stack *s) {
    if (s->top == -1) {
        return '\0';
    }
    return s->items[s->top];
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return 0;
}

void reverse(char *exp) {
    int length = strlen(exp);
    for (int i = 0; i < length / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[length - i - 1];
        exp[length - i - 1] = temp;
    }
}

void infixToPostfix(char *infix, char *postfix) {
    Stack s;
    s.top = -1;
    int k = 0;

    for (int i = 0; infix[i]; i++) {
        if (isalnum(infix[i])) {
            postfix[k++] = infix[i];
        } else if (infix[i] == '(') {
            push(&s, infix[i]);
        } else if (infix[i] == ')') {
            while (s.top != -1 && peek(&s) != '(') {
                postfix[k++] = pop(&s);
            }
            pop(&s); // Remove '(' from stack
        } else if (isOperator(infix[i])) {
            while (s.top != -1 && precedence(peek(&s)) >= precedence(infix[i])) {
                postfix[k++] = pop(&s);
            }
            push(&s, infix[i]);
        }
    }

    while (s.top != -1) {
        postfix[k++] = pop(&s);
    }

    postfix[k] = '\0';
}

void infixToPrefix(char *infix, char *prefix) {
    reverse(infix);

    for (int i = 0; infix[i]; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    char postfix[MAX];
    infixToPostfix(infix, postfix);
    reverse(postfix);
    strcpy(prefix, postfix);
}

int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter infix expression: ");
    gets(infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}

