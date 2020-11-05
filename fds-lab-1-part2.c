#include <stdio.h>

void insert_pos(int arr[100], int pos, int ele, int n);
void insert_beg(int arr[100], int ele, int n);
void insert_end(int arr[100], int ele, int n);
void delete_pos(int arr[100], int pos, int n);
void delete_by_ele(int arr[100], int ele, int n);
void search_by_pos(int arr[100], int pos, int n);
void search_by_ele(int arr[100], int ele, int n);
void reverse(int arr[100], int n);

int main()
{
    int choice, n, pos, ele, arr[100], size;
    char ans;

    printf("\n Enter size of array: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        printf("Enter element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    do
    {
        printf("\n1. Insert at Position \n2. Insert at beginning \n3. Insert at end \n4. Delete at position \n5. Delete by element \n6.Search by position \n7. Search by element \n8.Reverse ");
        printf("\n");
        printf("\n Please enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter element to be inserted: ");
            scanf("%d", &ele);
            printf("\nEnter position of element to be inserted: ");
            scanf("%d", &pos);
            insert_pos(arr, pos, ele, size);
            size++;
            break;

        case 2:

            printf("\nEnter element to be inserted: ");
            scanf("%d", &ele);
            insert_beg(arr, ele, size);
            size++;
            break;
        case 3:

            printf("\nEnter element to be inserted: ");
            scanf("%d", &ele);
            insert_end(arr, ele, size);
            size++;
            break;
        case 4:

            printf("\nEnter position of element to be deleted: ");
            scanf("%d", &pos);
            delete_pos(arr, pos, size);
            size--;
            break;
        case 5:

            printf("\nEnter element to be deleted: ");
            scanf("%d", &ele);
            delete_by_ele(arr, ele, size);
            size--;
            break;
        case 6:

            printf("\nEnter position to find element: ");
            scanf("%d", &pos);
            search_by_pos(arr, pos, size);
            break;
        case 7:

            printf("\nEnter element to find position: ");
            scanf("%d", &ele);
            search_by_ele(arr, ele, size);
            break;
        case 8:

            reverse(arr, size);
            break;
        default:
        
            printf("Wrong choice! Enter Again!");
            break;
        }
        printf("\nChoose again (y or n)");
        scanf(" %c", &ans);
    } while (ans == 'y' || ans == 'Y');
}

void insert_pos(int arr[100], int pos, int ele, int n)
{
    int i;

    if (pos > n)
    {
        printf("\nEnter a valid position!");
        return;
    }

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    n++;

    for (i = n; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = ele;

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insert_beg(int arr[100], int ele, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    n++;

    for (i = n; i >= 1; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[0] = ele;

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insert_end(int arr[100], int ele, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    n++;

    arr[n - 1] = ele;

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void delete_pos(int arr[100], int pos, int n)
{
    int i;

    if (pos > n)
    {
        printf("\nEnter a valid position!");
        return;
    }

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (i = pos - 1; i <= n; i++)
    {
        arr[i] = arr[i + 1];
    }

    n--;

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void delete_by_ele(int arr[100], int ele, int n)
{
    int i, flag = 1;
    int pos;

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (i = 0; i < n; i++)
    {
        if (arr[i] == ele)
        {
            pos = i;
            flag = 0;
        }
    }

    if (flag == 1)
    {
        printf("\nElement not found!");
        return;
    }

    for (i = pos; i <= n; i++)
    {
        arr[i] = arr[i + 1];
    }

    n--;

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void search_by_pos(int arr[100], int pos, int n)
{
    int i, result;

    if (pos > n)
    {
        printf("\nEnter a valid position!");
        return;
    }

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    result = arr[pos - 1];

    printf("Element is: %d", result);
}

void search_by_ele(int arr[100], int ele, int n)
{
    int i;
    int flag = 1;

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (i = 0; i < n; i++)
    {
        if (arr[i] == ele)
        {
            printf("\nElement found at position: %d", i);
            flag = 0;
        }
    }

    if (flag == 1)
    {
        printf("\nElement not found!");
        return;
    }
}

void reverse(int arr[100], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    int revIndex = 0;
    int arrIndex = n - 1;
    while (revIndex < arrIndex)
    {
        int temp = arr[revIndex];
        arr[revIndex] = arr[arrIndex];
        arr[arrIndex] = temp;

        revIndex++;
        arrIndex--;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}