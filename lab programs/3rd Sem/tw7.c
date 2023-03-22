#include <stdio.h>

void quickSort(int arr[], int left, int right)
{
  int i = left, j = right;
  int pivot = arr[(left + right) / 2];

  while (i <= j)
  {
    while (arr[i] < pivot)
      i++;
    while (arr[j] > pivot)
      j--;
    if (i <= j)
    {
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i++;
      j--;
    }
  }
  if (left < j)
    quickSort(arr, left, j);
  if (i < right)
    quickSort(arr, i, right);
}

int main()
{
  int arr[] = {10, 37, 45, 100, 8};
  int i;
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("Initial array:\n");
  for (i = 0; i < n; i++)
    printf("%d ", arr[i]);

  quickSort(arr, 0, n - 1);

  printf("\nSorted array: \n");
  for (i = 0; i < n; i++)
    printf("%d ", arr[i]);
  return 0;
}
