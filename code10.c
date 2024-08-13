#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int* a, int* b) {
int temp = *a;
*a = *b;
*b = temp;
}
int partition(int arr[], int low, int high) {
int pivot = arr[high];
int i = low - 1;
for (int j = low; j <= high - 1; j++) {
if (arr[j] < pivot) {
i++;
swap(&arr[i], &arr[j]);
}
}
swap(&arr[i + 1], &arr[high]);
return i + 1;
}
void quickSort(int arr[], int low, int high) {
if (low < high) {
int pi = partition(arr, low, high);
quickSort(arr, low, pi-1);
quickSort(arr, pi + 1, high);
}
}
int main() {
srand(time(NULL));
const int numPoints = 10; 
const int startingN = 5000; 
const int stepSize = 5000; 
printf("n\tTime (seconds)\n");
for (int i = 0; i < numPoints; ++i) {
int n = startingN + i * stepSize;
int* arr = (int*)malloc(n * sizeof(int));
for (int j=0;j<n;++j) {
arr[j] = rand();
}
clock_t start = clock();
quickSort(arr, 0, n - 1);
clock_t end = clock();
double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("%d\t%f\n", n, timeTaken);
free(arr); 
}
return 0;
}
