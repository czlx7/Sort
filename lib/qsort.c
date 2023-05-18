#include<stdio.h>
#include<stdlib.h>


void qsort_arr(int arr[],int left,int right){
    if(left>=right) return;
    int i = left;
    int j = right;
    int pivot = arr[i];
    while(i<j){
        while(i<j && arr[j]>=pivot) j--;
            arr[i] = arr[j];
        while(i<j && arr[i]<=pivot) i++;
            arr[j] = arr[i];
    }
    arr[i] = pivot;
    qsort_arr(arr,left,i-1);
    qsort_arr(arr,i+1,right);
}



int main() {
    int a[] = {1,3,4,2,3,5,8,3,9,7};
    int size = (sizeof(a)/sizeof(int));
    printf("%d\n",size);
    qsort_arr(a , 0 , size - 1);
    for(int i = 0;i<size;i++){
        printf("%d\n",a[i]);
    }
    system("pause");
    return 0;
}
