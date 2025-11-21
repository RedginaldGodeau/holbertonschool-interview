#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

static void merge_sort_recursive(int *array, size_t left, size_t right,
                                 int *temp);
static void merge(int *array, size_t left, size_t mid, size_t right, int *temp);

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge Sort
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void merge_sort(int *array, size_t size) {
  int *temp;

  if (array == NULL || size < 2)
    return;

  temp = malloc(size * sizeof(int));
  if (temp == NULL)
    return;

  merge_sort_recursive(array, 0, size, temp);

  free(temp);
}

/**
 * merge_sort_recursive - Recursively sorts a subarray using merge sort
 * @array: The array to be sorted
 * @left: Starting index of the subarray
 * @right: Ending index (exclusive) of the subarray
 * @temp: Temporary array for merging
 */
static void merge_sort_recursive(int *array, size_t left, size_t right,
                                 int *temp) {
  size_t mid;

  if (right - left < 2)
    return;

  mid = left + (right - left) / 2;

  merge_sort_recursive(array, left, mid, temp);
  merge_sort_recursive(array, mid, right, temp);
  merge(array, left, mid, right, temp);
}

/**
 * merge - Merges two sorted subarrays
 * @array: The array containing subarrays to merge
 * @left: Starting index of left subarray
 * @mid: Ending index (exclusive) of left subarray, start of right subarray
 * @right: Ending index (exclusive) of right subarray
 * @temp: Temporary array for merging
 */
static void merge(int *array, size_t left, size_t mid, size_t right,
                  int *temp) {
  size_t i;
  size_t j;
  size_t k;

  printf("Merging...\n");

  printf("[left]: ");
  print_array(array + left, mid - left);

  printf("[right]: ");
  print_array(array + mid, right - mid);

  i = left;
  j = mid;
  k = left;

  while (i < mid && j < right) {
    if (array[i] <= array[j]) {
      temp[k] = array[i];
      ++i;
    } else {
      temp[k] = array[j];
      ++j;
    }
    ++k;
  }

  while (i < mid) {
    temp[k] = array[i];
    ++i;
    ++k;
  }

  while (j < right) {
    temp[k] = array[j];
    ++j;
    ++k;
  }

  for (i = left; i < right; ++i)
    array[i] = temp[i];

  printf("[Done]: ");
  print_array(array + left, right - left);
}