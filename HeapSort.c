#include <stdio.h>

int swap(float *a, float *b){
        float temp;
        temp = *a;
        *a = *b;
        *b = temp;
        return 0;
}

int heapcorrect(float *arr, int i){
        int parent=(i-1)/2;

        if(arr[i] < arr[parent]) {
                swap(&arr[i], &arr[parent]);
                if(parent>0) {
                        heapcorrect(arr, parent);
                }
        }

        return 0;
}

int heapify(float *arr, int ind, int m){
        int left=ind*2+1, right=ind*2+2;
        if(left<m)
        {  if(arr[left]<arr[ind] && arr[left]<arr[right]) {
                   swap(&arr[left],&arr[ind]);
                   heapify(&arr[left], left, m);
           }
           else{
                   if(arr[right]<arr[ind] && arr[right]<arr[left]) {
                           swap(&arr[right], &arr[ind]);
                           heapify(&arr[right],right, m);
                   }
           }}
        return 0;
}

int main(){
        printf("Enter no of elements you want to sort");

        int n,i=0;

        scanf("%d",&n);

        float arr[n];

        printf("Enter all %d elements",n);
        scanf("%f",&arr[0]);

        for(i=1; i<n; i++) {
                scanf("%f",&arr[i]);
                heapcorrect(arr, i);
        }

        for(i=0; i<n; i++) {
                printf("\n%.3f",arr[i]);
        }

        int count = 0, m = n,last;
        last = n-1;
        float arr2[m];

        while(count<m) {
                swap(&arr[0],&arr[last]);
                arr2[count] = arr[last];
                arr[last]=99999;
                --last;
                heapify(arr,0, m);
                ++count;
        }

        for(i=0; i<m; i++) {
                printf("\n%.3f",arr2[i]);
        }
}
