// Binary Search in C

#include <stdio.h>
#include <time.h>

int binarySearch(int array[], int x, int low, int high)
{
    // Repeat until the pointers low and high meet each other
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (array[mid] == x)
            return mid;

        if (array[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main(void)
{
    int array[1000];
    // int n = sizeof(array) / sizeof(array[0]);
    int n;
    int x, result;
    double t;
    printf("enter size:");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
        array[i] = i; // initializing elements automatically

    printf("enter key:");
    scanf("%d", &x);

    clock_t s, e; // to calculate time
    s = clock(); // timer starts

    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 1000; j++)
            result = binarySearch(array, x, 0, n - 1); // to delay because size of array is small

    printf("Array is:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");

    // printf("Element to be searched:%d",x);
    printf("\n");

    if (result == -1)
        printf("Not found");
    else
        printf("Element is found at index %d", result);

    e = clock(); // timer stopps
    t = (double)(e - s) / CLK_TCK;
    printf("\nTime taken:%1f", t);
    return 0;
}