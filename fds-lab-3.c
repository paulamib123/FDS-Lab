#include <stdio.h>

struct student {
    char name[20];
    int prn;
    float per;
};

struct student s[100];
int n;

void create(){
    int count;
    printf("\n Enter no.of records you want to create: ");
    scanf("%d", &count);
    for (int i = 0; i < count; i++) {
        printf("\n Enter name: ");
        scanf("%s", &s[i].name);
        printf("\n Enter PRN: ");
        scanf("%d", &s[i].prn);
        printf("\n Enter Percentage: ");
        scanf("%f", &s[i].per);
        n++;
    }
}

void insert(){
    int count;
    printf("\n Enter no.of records you want to insert: ");
    scanf("%d", &count);
    int initial = n;
    for (int i = initial; i < initial + count; i++) {
        printf("\n Enter Name: ");
        scanf("%s", &s[i].name);
        printf("\n Enter PRN: ");
        scanf("%d", &s[i].prn);
        printf("\n Enter Percentage: ");
        scanf("%f", &s[i].per);
        n++;
    }
}

void delete(){
    int no, index, flag = 0;
    printf("\n Enter PRN of student to delete record: ");
    scanf("%d", &no);
    for (int i = 0; i < n; i++) {
        if (no == s[i].prn) {
            index = i;
            flag = 1;
            break;
        }
    }

    if (flag == 0) {
        printf("\n PRN not found!");
        return;
    }

    for (int j = index; j < n; j++) {
            s[j] = s[j + 1];
    }
    printf("\n Deleted record of student with PRN %d", no);
    n--;
}

void modify(){
    int no, index, flag = 0, choice;
    char stu_name[20];
    float percentage;

    printf("\n Enter PRN of student to modify record: ");
    scanf("%d", &no);
    for (int i = 0; i < n; i++){
        if (no == s[i].prn) {
            printf("\n1. Change name");
            printf("\n2. Change percentage");
            printf("\n3. Change both name and percentage");
            printf("\n Enter your choice: ");
            scanf("%d", &choice);
            if (choice == 1) {
                printf("\n Enter Name: ");
                scanf("%s", &s[i].name);
            }
            else if (choice == 2) {
                printf("\n Enter Percentage: ");
                scanf("%f", &s[i].per);
            }
            else if (choice == 3) {
                printf("\n Enter Name: ");
                scanf("%s", &s[i].name);
                printf("\n Enter Percentage: ");
                scanf("%f", &s[i].per);
            }
            else {
                printf("\n Wrong choice!");
            }
            flag = 1;
        }
    }
    if (flag == 0) {
        printf("\n PRN not found!");
        return;
    }

}

void display(){
    printf("\n Displaying all records...... \n");
    for (int i = 0; i < n; i++) {
        printf("\n Name: %s", s[i].name);
        printf("\n PRN: %d", s[i].prn);
        printf("\n Percentage: %f", s[i].per);
        printf("\n");
    }
}

int main(){
    int choice;
    char ans;
    do{
    printf("\n 1. Create \n 2. Insert \n 3. Display \n 4. Delete \n 5. Modify");
    printf("\n Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        create();
        break;

    case 2:
        insert();
        break;

    case 3:
        display();
        break;

    case 4:
        delete();
        break;

    case 5:
        modify();
        break;

    default:
        printf("\n Invalid Choice!");
        break;
    }
    printf("\n Do you want to enter again?");
    scanf(" %c", &ans);
    } while(ans == 'y');
    return 0;
}