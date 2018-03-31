#include <stdio.h>
int num;

void binsearch(int low, int high, int* arr){
  int mid = (low+high)/2;
  if (num == arr[mid]){
    printf("No. found at index %d", mid);
  }
  else if(num<arr[mid]){
    binsearch(low, mid-1, arr);
  }
  else if(num>arr[mid]){
    binsearch(mid+1, high, arr);
  }
  else{
    printf("Sorry");
  }
}

int main(){
  printf("Enter no of elements you want to search from in sorted order");
  int n,i=0;
  scanf("%d",&n);
  int arr[n];
  printf("Enter all %d elements",n);
  for(i=0; i<n; i++){
    scanf("%d",&arr[i]);
  }
  printf("Enter the number you want to search");
  scanf("%d",&num);
  binsearch(0,n, arr);
}
