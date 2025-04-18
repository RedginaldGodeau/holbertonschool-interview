#include "sort.h"

int getMax(int *arr, int n) {
  int mx = arr[0];
  int i = 0;

  if (n <= 0)
    return 0;

  for (i = 1; i < n; i++) {
    if (arr[i] > mx)
      mx = arr[i];
  }
  return mx;
}

void countSort(int *arr, int n, int exp) {
  int output[n];
  int count[10] = {0};
  int i = 0;

  for (i = 0; i < n; i++)
    count[(arr[i] / exp) % 10]++;

  for (i = 1; i < 10; i++)
    count[i] += count[i - 1];

  for (i = n - 1; i >= 0; i--) {
    output[count[(arr[i] / exp) % 10] - 1] = arr[i];
    count[(arr[i] / exp) % 10]--;
  }

  for (i = 0; i < n; i++) {
    arr[i] = output[i];
  }
}

void radix_sort(int *array, size_t size) {
  int m = getMax(array, size);
  int exp = 1;

  if (!array || size < 2)
    return;

  for (exp = 1; m / exp > 0; exp *= 10) {
    countSort(array, size, exp);
    print_array(array, size);
  }
}
