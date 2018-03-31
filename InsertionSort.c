#include <stdio.h>

int main(){
        printf("Enter no of elements you want to sort");
        int n,i=0, j=0;
        scanf("%d",&n);
        float arr[n], temp;
        printf("Enter all %d elements",n);
        for(i=0; i<n; i++) {
                scanf("%f",&arr[i]);
        }

        for( i=1; i<n; i++) {
                for(j=i; j>=0 && arr[j]<arr[j-1]; j--) {
                        temp = arr[j];
                        arr[j] = arr[j-1];
                        arr[j-1]= temp;
                }
        }

        for(i=0; i<n; i++) {
                printf("%.3f\n",arr[i]);
        }


}
