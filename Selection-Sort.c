#include <stdio.h>

int main(){
  printf("Enter no of elements you want to sort");
  int n,i=0, j=0, min;
  scanf("%d",&n);
  float arr[n],temp;
  printf("Enter all %d elements",n);
  for(i=0; i<n; i++){
    scanf("%f",&arr[i]);
  }
  i = 0;
  for(i=0;i<n-1;i++){
    min = i;
    for(j=i+1;j<n;j++){
      if(arr[j] <= arr[min]){
        min = j;
      }
    }
    temp = arr[min];
    arr[min] = arr[i];
    arr[i]=temp;
  }
  
  for(i=0;i<n;i++){
    printf("%.3f\n",arr[i]);
  }
}
