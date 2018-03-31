#include <stdio.h>
#include <stdbool.h>

int main(){
  printf("Enter no of elements you want to sort");
  int n,i=0, j=0, last;
  bool flag = false;
  scanf("%d",&n);
  float arr[n], temp;
  printf("Enter all %d elements",n);
  for(i=0; i<n; i++){
    scanf("%f",&arr[i]);
  }

  last = n-2;

  for(i= last; i>=0; i--){
    flag = false;
    for(j=0; j <= i; j++){
      if(arr[j]>=arr[j+1]){
        flag = true;
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
    if(flag == false)break;
  }
  i = 0;
  for(i=0;i<n;i++){
    printf("%.3f\n",arr[i]);
  }

}
