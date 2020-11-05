#include <stdio.h>

void linear_search(int a[], int n, int ele){
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == ele) {
            printf("Element found at position: %d", i + 1);
            flag = 1;
        }
    }

    if (flag == 0) {
        printf("\n Element not found!");
    }
}

int binary_search(int a[], int ele, int start, int end) {
  
  while (start <= end) {
    
    int mid = (start + end) / 2;

    if (a[mid] == ele)
      return mid;

    if (a[mid] < ele)
      start = mid + 1;

    else
      end = mid - 1;
  }

  return -1;
}

int recursive_binary_search(int a[], int n, int ele, int start, int end) {
    int mid;

    if (start <= end) {

        mid = (start + end) / 2;

        if (a[mid] == ele) {
            return mid;
        }

        else if (a[mid] > ele) {
            return recursive_binary_search(a, n, ele, start, mid - 1);
        }

        return recursive_binary_search(a, n, ele, mid + 1, n);
    }

    return -1;
}

int main(){
    int a[20], ele, n, choice, ans;
    char ch;

    printf("\nEnter size of array: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ",i + 1);
        scanf("%d", &a[i]);
    }

    printf("\n Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    do {
        printf("\n 1. Linear Search");
        printf("\n 2. Binary Search");
        printf("\n 3. Binary Search with Recursion");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter element to be searched: ");
                scanf("%d", &ele);
                linear_search(a, n, ele);
                printf("\n");
                break;

            case 2:
                printf("Enter element to be searched: ");
                scanf("%d", &ele);
                ans = binary_search(a, ele, 0, n - 1);
                if (ans == -1) {
                    printf("\n Element not found!");
                }
                else {
                    printf("\n Element found at position: %d", ans + 1);
                }
                printf("\n");
                break;

            case 3:
                printf("Enter element to be searched: ");
                scanf("%d", &ele);
                ans = recursive_binary_search(a, n, ele, 0, n - 1);
                if (ans == -1) {
                    printf("\n Element not found!");
                }
                else {
                    printf("\n Element found at position: %d", ans + 1);
                }
                printf("\n");
                break;
                
            default:
                printf("Wrong choice!");
                break;
        }

        printf("\n Do you want to enter again? (y/n)");
        scanf(" %c", &ch);
    } while(ch == 'y');
    
    
    return 0;
}
