#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[30];
int top = -1;
int n;

int isEmpty() {
    return top == -1;
}

void push(char x) {
    if (top == n - 1)
        printf("\n Stack Overflow!!");

    top++;
    stack[top] = x;
}

char pop() {
    if (isEmpty()) {
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

int isOperand(char x) {
    if (x >= 'A' && x <= 'Z') return 1;
    if (x >= 'a' && x <= 'z') return 1;
    if (x >= '0' && x <= '9') return 1;
    return 0;
}


int getPrecedence (char x) {
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    else if (x == '^' || x == '$')
        return 3;
    return -1;
}

int infix_to_postfix(char exp[], int n) {
    for (int i = 0; i < n; i++) {
        if (isOperand(exp[i])) 
            printf("%c", exp[i]);

        else if (exp[i] == '(') 
			push(exp[i]);

        else if (exp[i] == ')') 
		{ 
			while (!isEmpty() && getTop() != '(') 
                printf("%c", pop());
			if (!isEmpty() && getTop() != '(') 
				return -1; 			 
			else
				pop();
		} 

        else
		{ 
			while (!isEmpty() && getPrecedence(exp[i]) <= getPrecedence(getTop())) 
                printf("%c", pop());
			push(exp[i]); 
		} 

    }

    while(!isEmpty()) {
        printf("%c", pop());
    }
}

int main() {
    char exp[20];
    printf("\nEnter expression: ");
    scanf("%s", exp);
    n = strlen(exp);
    printf("\nInfix is: %s", exp);
    printf("\nPostfix: "); 
    infix_to_postfix(exp, n);
    printf("\n");
    return 0;
}
