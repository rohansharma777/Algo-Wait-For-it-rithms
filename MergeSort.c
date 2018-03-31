#include <stdio.h>
#include <stdlib.h>

int n;
int *arr2;

void merge(int *arr, int i, int high){
  int mid = (i+high)/2, j = mid+1, itr=i,low = i;
  while(i<=mid && j<=high){
      if(arr[i]<=arr[j]){
        arr2[itr] = arr[i];
        ++i;
      }
      else{
        arr2[itr] = arr[j];
        ++j;
      }
      ++itr;
  }


    while(i <=mid){
      arr2[itr] = arr[i];
      ++i;
      ++itr;
    }
    while(j<=high){
      arr2[itr] = arr[j];
      ++j;
      ++itr;
    }


  for(itr = low; itr <= high ; itr++){
    arr[itr] = arr2[itr];
  }
}

void divide(int *arr, int low, int high){
  int mid = (low+high)/2;
  if(low<high){
    divide(arr, low, mid);
    divide(arr, mid+1, high);
    merge(arr, low, high);
  }

}

int main(){
  printf("Enter the number of elements you want to sort: ");
  int i;
  scanf("%d",&n);
  int arr[n];
  arr2 = (int *) malloc (n*sizeof(int));
  for(i=0; i<n; i++){
    scanf("%d",&arr[i]);
  }
  int l=0, h=n-1;
  divide(arr, l, h);
  for(i=0; i<n; i++){
    printf("%d",arr[i]);
  }
}
