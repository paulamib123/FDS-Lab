#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[30];
int top = -1;
int n;

void push(char x) {
    if (top == n - 1)
        printf("\n Stack Overflow!!");

    top++;
    stack[top] = x;
}

char pop() {
    if (top == -1) {
        printf("\n Stack Underflow!!");
        return -1;
    }
    char value = stack[top];
    top--;
    return value;
}

char getTop() {
    return stack[top];
}

int isBalanced(char exp[20], int n) {
    for (int i = 0; i < n; i++) {
        if (isspace(exp[i]) == 0) 
            continue;
        if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(') {
            push(exp[i]);
        }
        else {
            if (top == -1) 
                return -1;
            if ((exp[i] == '}' && getTop() == '{') || (exp[i] == ']' && getTop() == '[') || (exp[i] == ')' && getTop() == '(')) {
                pop();
            }
            else 
                return -1;
        } 
    }
    if (top == -1)
        return 0;
    return -1;
}

int main() {
    char exp[20];
    int res;

    printf("\nEnter expression: ");
    scanf("%s", exp);
    n = strlen(exp);

    res = isBalanced(exp, n);
    if (res == -1) {
        printf("\n Expression is not well formed");
    }
    else {
        printf("\n Expression is well formed"); 
    }
    printf("\n");
    return 0;
}

