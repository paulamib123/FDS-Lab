#include <stdio.h>

int top = -1, n, stack[20];

void push(int x) {
    if (top == n - 1) {
        printf("\nStack Overflow!!");
    }

    else {
        top++;
        stack[top] = x;
    }
}

int pop() {
    int value;
    if (top == -1) {
        return -1;
    }

    else {
        value = stack[top];
        top --;
    }

    return value;
}

void display() {
    if (top >= 0) {
        for (int i = top; i >= 0; i--) {
            printf(" %d ", stack[i]);
        }
    }
    else {
        printf("\n Stack is empty!");
    }
}

int main()
{
    char ch;
    int choice;
    int x;
    int res;
    printf("Enter the size of STACK : ");
    scanf("%d", &n);
    do
    {
        printf("\nSTACK OPERATIONS USING ARRAY \n");
        printf("1. PUSH \n");
        printf("2. POP \n");
        printf("3. DISPLAY \n");
        printf("4. EXIT \n");
        printf("Please select option : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter value of element to push into stack: ");
            scanf("%d", &x);
            push(x);
            break;

        case 2:
            res = pop();
            if (res == -1) {
                printf("Stack Underflow!!");
            }
            else {
                printf("\n Popped element: %d", res);
            }
            break;

        case 3:
            display();
            break;

        case 4:
            printf("\nEXIT");
            break;

        default:
            printf("\n This is a wrong Choice");
        }
        printf("\nDo you want to enter again? (y/n)");
        scanf(" %c", &ch);
    } while (ch == 'y');
}
