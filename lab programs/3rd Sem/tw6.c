#include <stdio.h>

int binarySearch(int *arr, int size, int key)
{
    int high = size - 1, low = 0, mid = (high + low) / 2;
    
    while (high >= low)
    {
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
        mid = (high + low) / 2;
    }
    return -1;
}

int main()
{
    int *arr, value, size, i = 0;
    printf("Enter the size of array: ");
    scanf("%d", &size);

    arr = (int *)malloc(sizeof(int) * size);

    printf("Enter the elements in ascending order: ");
    for (i = 0; i < size; i++)
        scanf("%d", (arr + i));

    printf("enter the element to search: ");
    scanf("%d", &value);

    value = binarySearch(arr, size, value);

    if (value == -1)
        printf("value not found!!");
    else
        printf("value found at index %d", value);
        
    return 0;
}
