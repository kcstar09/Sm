#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int i,j;
void selectionSort(int arr[],int n){
for(i=0;i<n-1;++i){
int minIndex=i;
for(j=i+1;j<n;++j){
if(arr[j]<arr[minIndex]){
minIndex=j;
}
}
int temp=arr[minIndex];
arr[minIndex]=arr[i];
arr[i]=temp;
}
}
int main(){
int i,j;
srand(time(NULL));
const int numPoints=10;
const int startingN=5000;
const int stepSize=5000;
printf("n\tTime(seconds)\n");
for(i=0;i<numPoints;++i){
int n=startingN+i*stepSize;
int*arr=(int*)malloc(n*sizeof(int));
for(j=0;j<n;++j){
arr[j]=rand();
}
clock_t start=clock();
selectionSort(arr,n);
clock_t end=clock();
double timeTaken=((double)(end-start))/CLOCKS_PER_SEC;
printf("%d\t%f\n",n,timeTaken);
free(arr);
}
return 0;
}

