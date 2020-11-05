#include <stdio.h>

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubble_sort(int arr[], int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        printf("Pass %d is: ", i + 1);
        display(arr, size);
    }

    printf("\n");
    printf("Sorted array is: ");
    display(arr, size);
}

void insertion_sort(int arr[], int size)
{
    int temp, key, j;
    for (int i = 1; i < size; i++)
    {

        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
        printf("Pass %d is: ", i);
        display(arr, size);
    }

    printf("\n");
    printf("Sorted array is: ");
    display(arr, size);
}

void selection_sort(int arr[], int size)
{
    int temp, min_index;
    for (int i = 0; i < size - 1; i++)
    {
        min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
        printf("Pass %d is: ", i + 1);
        display(arr, size);
    }

    printf("\n");
    printf("Sorted array is: ");
    display(arr, size);
}

int main()
{
    char ch;
    int choice;
    int arr[20], size;

    do
    {
        printf("\n 1. Bubble Sort");
        printf("\n 2. Insertion Sort");
        printf("\n 3. Selection Sort");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            printf("\nEnter size of array: ");
            scanf("%d", &size);
            for (int i = 0; i < size; i++)
            {
                printf("\nEnter element %d: ", i + 1);
                scanf("%d", &arr[i]);
            }
            printf("\n");
            printf("\n The Initial array is: ");
            display(arr, size);
            printf("\n");
            bubble_sort(arr, size);
            break;
        case 2:
            printf("\nEnter size of array: ");
            scanf("%d", &size);
            for (int i = 0; i < size; i++)
            {
                printf("\nEnter element %d: ", i + 1);
                scanf("%d", &arr[i]);
            }
            printf("\n");
            printf("\n The Initial array is: ");
            display(arr, size);
            printf("\n");
            insertion_sort(arr, size);
            break;
        case 3:
            printf("\nEnter size of array: ");
            scanf("%d", &size);
            for (int i = 0; i < size; i++)
            {
                printf("\nEnter element %d: ", i + 1);
                scanf("%d", &arr[i]);
            }
            printf("\n");
            printf("\n The Initial array is: ");
            display(arr, size);
            printf("\n");
            selection_sort(arr, size);
            break;
        }

        printf("\nDo you want to enter again? (y/n)");
        scanf(" %c", &ch);
    } while (ch == 'y');
    return 0;
}
