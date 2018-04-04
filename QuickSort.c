#include <stdio.h>
#include <stdlib.h>

int *arr;

void swap(int *a, int *b){
  *a = *a+*b;
  *b = *a-*b;
  *a = *a-*b;
}

int Partition(int low, int high){
  int v = arr[low], i = low, j = high;
  while(i<j){
    while(arr[i]<= v)i++;
    while(arr[j]> v)j--;
    if(i<j)swap(&arr[i], &arr[j]);
  }

  arr[low] = arr[j];
  arr[j] = v;

  return j;
}

void QuickSort(int low, int high){
  int j;
  if(low<high){
    j = Partition(low, high);
    QuickSort(low, j-1);
    QuickSort( j+1, high);
  }
}

int main(){
  printf("Enter the no of digits you want to sort");
  int n, i;
  scanf("%d",&n);
  arr = (int *)malloc((n+1)*sizeof(int));
  for(i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }

arr[n]=99999;

QuickSort(0,n);

for(i=0; i<n; i++){
  printf("%d", arr[i]);
}

}
