#include <stdio.h>
#include <string.h>

int sum_of_digits(int);
int reverse_num(int);
float average();
void tri_no(int);
void num_to_words(char *);

int main()
{

    int n, choice;
    char ans;
    char num[3];

    do
    {
        printf("\n 1. Sum of digits \n 2. Reverse Number \n 3. Avg Numbers \n 4. Triangular Numbers \n 5. Number to words");
        printf("\n Please enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter number: ");
            scanf("%d", &n);
            printf("\n%d", sum_of_digits(n));
            break;
        case 2:
            printf("\nEnter number: ");
            scanf("%d", &n);
            printf("\n%d", reverse_num(n));
            break;
        case 3:
            printf("\nAverage = %f", average(n));
            break;
        case 4:
            printf("\nEnter number: ");
            scanf("%d", &n);
            tri_no(n);
            printf("\n");
            break;
        case 5:
            printf("Enter any number (upto 5 digits): ");
            scanf("%s", num);
            num_to_words(num);
            break;
        default:
            printf("Wrong choice! Enter Again!");
            break;
        }
        printf("\nChoose again (y or n)");
        scanf(" %c", &ans);
    } while (ans == 'y' || ans == 'Y');

    return 0;
}

int sum_of_digits(int n)
{
    int digit, sum = 0;

    while (n != 0)
    {
        digit = n % 10;
        sum += digit;
        n = n / 10;
    }
    return sum;
}

int reverse_num(int n)
{
    int digit, rem, rev = 0;

    while (n != 0)
    {
        digit = n % 10;
        rev = rev * 10 + digit;
        n = n / 10;
    }

    return rev;
}

float average()
{
    int size, a[20];
    float sum = 0;

    printf("\nEnter Size of array: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        printf("\nEnter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < size; i++)
    {
        sum += a[i];
    }

    return sum / size;
}

void tri_no(int n)
{
    int sum = 0;

    for (int i = 1; i <= n; i++)
    {
        sum += i;
        printf("%d ", sum);
    }
}

void num_to_words(char *num)
{
    int no = (int)num;

    int len = strlen(num);

    if (len >= 6)
    {
        printf("Numbers above length 5 are not supported!\n");
        return;
    }

    char *single_digits[] = {"zero", "one", "two",
                             "three", "four", "five",
                             "six", "seven", "eight", "nine"};

    char *two_digits[] = {"", "ten", "eleven", "twelve",
                          "thirteen", "fourteen",
                          "fifteen", "sixteen",
                          "seventeen", "eighteen", "nineteen"};

    char *tens_multiple[] = {"", "", "twenty", "thirty", "forty", "fifty",
                             "sixty", "seventy", "eighty", "ninety"};

    char *tens_power[] = {"hundred", "thousand"};

    printf("\n%s: ", num);

    if (len == 1)
    {
        printf("%s\n", single_digits[*num - '0']);
        return;
    }

    if (len == 5)
    {
        if (*num - '0' == 1)
        {
            int sum = *num - '0' + *(num + 1) - '0';
            printf("%s ", two_digits[sum]);
            printf("%s ", tens_power[1]);
        }
        else
        {
             printf("%s ", tens_multiple[*num - '0']);
            printf("%s ", single_digits[*(num + 1) - '0']);
            printf("%s ", tens_power[1]);
        }
        
        num += 2;
        len -= 2;

    }
    goto words;

    words:
    while (*num != '\0')
    {

        if (len >= 3)
        {
            if (*num - '0' != 0)
            {
                printf("%s ", single_digits[*num - '0']);
                printf("%s ", tens_power[len - 3]);
            }
            --len;
        }

        else
        {
            /* 10-19 */
            if (*num == '1')
            {
                int sum = *num - '0' + *(num + 1) - '0';
                printf("%s\n", two_digits[sum]);
                return;
            }

            /* 20 */
            else if (*num == '2' && *(num + 1) == '0')
            {
                printf("twenty\n");
                return;
            }

            /* 21 to 99 */
            else
            {
                int i = *num - '0';
                printf("%s ", i ? tens_multiple[i] : "");
                ++num;
                if (*num != '0')
                    printf("%s ", single_digits[*num - '0']);
            }
        }
        ++num;
    }
}
