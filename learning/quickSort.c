#include <stdio.h>

// int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

int partition(int a[], int l, int h)
{
    int p = a[l];
    int i = l, j = h;

    while (i < j)
    {
        do
        {
            i++;
        } while (a[i] <= p);

        do
        {
            j--;
        } while (a[j] > p);

        if (i < j)
        {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }

    int t = a[l];
    a[l] = a[j];
    a[j] = t;

    return j;
}

void quickSort(int a[], int l, int h)
{
    if (l < h)
    {
        int j = partition(a, l, h);
        quickSort(a, l, j);
        quickSort(a, j + 1, h);
    }
}





// int partition(int arr[], int low, int high)
// {
//     // pivot (Element to be placed at right position)
//     int pivot = arr[high];

//     int i = (low - 1); // Index of smaller element and indicates the
//                        // right position of pivot found so far

//     for (int j = low; j <= high - 1; j++)
//     {
//         // If current element is smaller than the pivot
//         if (arr[j] < pivot)
//         {
//             i++; // increment index of smaller element
//             int t = arr[j];
//             arr[j] = arr[i];
//             arr[i] = t;
//         }
//     }
//     int t = arr[i + 1];
//     arr[i + 1] = arr[high];
//     arr[high] = t;
//     return (i + 1);
// }

// void quickSort(int arr[], int low, int high)
// {
//     if (low < high)
//     {
//         //pi is partitioning index, arr[pi] is now at right place
//         int pi = partition(arr, low, high);

//         quickSort(arr, low, pi - 1); // Before pi

//         quickSort(arr, pi + 1, high); // After pi
//     }
// }

void main()
{
    int a[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    quickSort(a, 0, 10);

    for (int i = 0; i < 10; i++)
        printf("%d ", a[i]);
}