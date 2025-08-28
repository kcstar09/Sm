#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
void merge(int arr[], int l, int m, int r) {
 int i = l, j = m + 1, k = 0;
 int temp[r - l + 1];
 while (i <= m && j <= r) {
 if (arr[i] <= arr[j])
 temp[k++] = arr[i++];
 else
 temp[k++] = arr[j++];
 }
 while (i <= m) temp[k++] = arr[i++];
 while (j <= r) temp[k++] = arr[j++];
 for (i = l, k = 0; i <= r; i++, k++)
 arr[i] = temp[k];
}
void sequentialMergeSort(int arr[], int l, int r) {
 if (l < r) {
 int m = (l + r) / 2;
 sequentialMergeSort(arr, l, m);
 sequentialMergeSort(arr, m + 1, r);
 merge(arr, l, m, r);
 }
}
void parallelMergeSort(int arr[], int l, int r) {
 if (l < r) {
 int m = (l + r) / 2;
 #pragma omp parallel sections
 {
 #pragma omp section
 parallelMergeSort(arr, l, m);
#pragma omp section
 parallelMergeSort(arr, m + 1, r);
 }
 merge(arr, l, m, r);
 }
}
int main() {
 int n = 100000;
 int arr1[n], arr2[n];
 for (int i = 0; i < n; i++) {
 arr1[i] = rand() % 1000;
 arr2[i] = arr1[i];
 }
 double start, end, seq, par;
 start = omp_get_wtime();
 sequentialMergeSort(arr1, 0, n - 1);
 end = omp_get_wtime();
 seq = end - start;
 printf("Sequential Merge Sort Time: %f seconds\n", end - start);
 start = omp_get_wtime();
 parallelMergeSort(arr2, 0, n - 1);
 end = omp_get_wtime();
 par = end - start;
 printf("Parallel Merge Sort Time: %f seconds\n", end - start);
 printf("Performance Difference: %f seconds\n", seq - par);
 return 0;
}