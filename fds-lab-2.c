#include <stdio.h>

void input_matrix(int a[][10], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("Enter element a%d%d: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void print_matrix(int a[10][10], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("   %d   ", a[i][j]);
        }
        printf("\n");
    }
}

void add_matrix(int a[][10], int b[][10], int res[][10], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            res[i][j] = a[i][j] + b[i][j];
        }
    }
}

void sub_matrix(int a[][10], int b[][10], int res[][10], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            res[i][j] = a[i][j] - b[i][j];
        }
    }
}

void mul_matrix(int a[][10], int b[][10], int res[][10], int r1, int r2, int c1, int c2) {
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            res[i][j] = 0;
        }
    }

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void greatest_num(int a[][10], int r, int c) {
    int max = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (a[i][j] > max) {
                max = a[i][j];
            }
        }
        printf("\n Greatest Number In Row %d is %d", i + 1, max);
        max = 0;
    }
}

int add_diagonal(int a[][10], int r, int c) {

    int sum = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < r; j++) {
            if (i == j) {
                sum += a[i][j];
            }
        }
    }
    return sum;
}

int sparse(int a[][10], int res[][3], int r, int c, int size) {
    int k = 1, zeroes = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (a[i][j] == 0)
                zeroes++;
        }
    }

    if (zeroes <= (r * c) / 2)
        return -1;

    res[0][0] = r;
    res[0][1] = c;
    res[0][2] = size;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (a[i][j] != 0) {
                res[k][0] = i;
                res[k][1] = j;
                res[k][2] = a[i][j];
                k++;
            }
        }
    }
    return 0;
}

int main() {
    int choice, a[10][10], b[10][10], c[10][10], r1, r2, c1, c2, s, size;
    char ans;
    do {
        printf("\n 1. Addition of matrices. \n 2. Subtraction of matrices \n 3. Multiplication of matrices \n 4. Greatest element in each row \n 5. Sum of diagonal elements \n 6. Convert to sparse matrix");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("\nEnter no. of rows for both matrices: ");
            scanf("%d", &r1);
            printf("\nEnter no. of columns for both matrices: ");
            scanf("%d", &c1);
            printf("\nEnter elements for matrix 1:\n");
            input_matrix(a, r1, c1);
            printf("\n");
            printf("\nEnter elements for matrix 2:\n");
            input_matrix(b, r1, c1);
            printf("\nMatrix 1\n");
            print_matrix(a, r1, c1);
            printf("\nMatrix 2\n");
            print_matrix(b, r1, c1);
            printf("\nResult\n");
            add_matrix(a, b, c, r1, c1);
            print_matrix(c, r1, c1);
            break;

        case 2:
            printf("\nEnter no. of rows for both matrices: ");
            scanf("%d", &r1);
            printf("\nEnter no. of columns for both matrices: ");
            scanf("%d", &c1);
            printf("\nEnter elements for matrix 1: \n");
            input_matrix(a, r1, c1);
            printf("\n");
            printf("\nEnter elements for matrix 2:\n");
            input_matrix(b, r1, c1);
            printf("\nMatrix 1\n");
            print_matrix(a, r1, c1);
            printf("\nMatrix 2\n");
            print_matrix(b, r1, c1);
            printf("\nResult\n");
            sub_matrix(a, b, c, r1, c1);
            print_matrix(c, r1, c1);
            break;

        case 3:
            printf("Enter rows and column for the first matrix: ");
            scanf("%d %d", &r1, &c1);
            printf("Enter rows and column for the second matrix: ");
            scanf("%d %d", &r2, &c2);

            while (c1 != r2) {
                printf("Error! Enter rows and columns again.\n");
                printf("Enter rows and columns for the first matrix: ");
                scanf("%d%d", &r1, &c1);
                printf("Enter rows and columns for the second matrix: ");
                scanf("%d%d", &r2, &c2);
            }

            printf("\nEnter elements for matrix 1: \n");
            input_matrix(a, r1, c1);
            printf("\n");
            printf("\nEnter elements for matrix 2:\n");
            input_matrix(b, r2, c2);
            printf("\nMatrix 1\n");
            print_matrix(a, r1, c1);
            printf("\nMatrix 2\n");
            print_matrix(b, r2, c2);
            printf("\nResult\n");
            mul_matrix(a, b, c, r1, r2, c1, c2);
            print_matrix(c, r1, c2);
            break;

        case 4:
            printf("\nEnter no. of rows: ");
            scanf("%d", &r1);
            printf("\nEnter no. of columns: ");
            scanf("%d", &c1);
            printf("\nEnter elements for matrix:\n");
            input_matrix(a, r1, c1);
            printf("\n");
            printf("\nMatrix \n");
            print_matrix(a, r1, c1);
            greatest_num(a, r1, c1);
            printf("\n");
            break;
            
        case 5:
            printf("\nEnter no. of rows: ");
            scanf("%d", &r1);
            printf("\nEnter no. of columns: ");
            scanf("%d", &c1);

            while (r1 != c1) {
                printf("Error! Enter rows and columns again.\n");
                printf("\nEnter no. of rows: ");
                scanf("%d", &r1);
                printf("\nEnter no. of columns: ");
                scanf("%d", &c1);
            }

            printf("\nEnter elements for matrix:\n");
            input_matrix(a, r1, c1);
            printf("\n");
            printf("\nMatrix \n");
            print_matrix(a, r1, c1);
            s = add_diagonal(a, r1, c1);
            printf("\n The sum is: %d", s);
            printf("\n");
            break;

        case 6:
            printf("\nEnter no. of rows: ");
            scanf("%d", &r1);
            printf("\nEnter no. of columns: ");
            scanf("%d", &c1);
            printf("\nEnter elements for matrix:\n");
            input_matrix(a, r1, c1);
            printf("\n");
            printf("\nMatrix \n");
            print_matrix(a, r1, c1);
            printf("\n");
            for (int i = 0; i < r1; i++) {
                for (int j = 0; j < c1; j++) {
                    if (a[i][j] != 0)
                        size++;
                }
            }
            int res[size + 1][3];
            s = sparse(a, res, r1, c1, size);
            if (s == -1) {
                printf("This Cannot be converted into a sparse matrix! \n");
            }
            else {
                printf("Sparse Matrix \n");
                for (int i = 0; i < size + 1; i++) {
                    for (int j = 0; j < 3; j++) {
                        printf("  %d  ", res[i][j]);
                    }
                    printf("\n");
                }
                printf("\n");
            }
            break;
        }
        printf("\nDo you want to enter again?");
        scanf(" %c", &ans);
    } while (ans == 'y');
}