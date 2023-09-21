#include <stdio.h>
#define N 10

void selection_sort(int a[], int n);
int find_largest(int a[], int n);

int main(void)
{
    int i;
    int a[N];
    printf("Enter %d numbers to be sorted: ", N);
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);

    // printf("The largest num is %d\nThe index is %d\n", a[find_largest(a, N)],find_largest(a, N));
    selection_sort(a, N);
    printf("In sorted order:");

    for (i = 0; i < N; i++)
        printf(" %d", a[i]);
    printf("\n");
    return 0;
}

// IMPLEMENTING AS RECURSIVE FUNCTION
void selection_sort(int a[], int n)
{
    int largest = 0, temp;
    //  Case Base
    if (n == 1)
    {
        return;
    }
    else
    {
        largest = find_largest(a, n);
        temp = a[largest];
        a[largest] = a[n - 1];
        a[n - 1] = temp;
        return selection_sort(a, n - 1);
    }
}

// Find Largest number in array
int find_largest(int a[], int n)
{
    int largest_index = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > a[largest_index])
        {
            largest_index = i;
        }
    }

    return largest_index;
}
