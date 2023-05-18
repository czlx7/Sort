#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 10


void swap(int arr[],int i,int j){
    int temp = arr[j];
    arr[j] = arr[i];
    arr[i] = temp;
}

void initArr(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        arr[i] = rand() % 20;
    }
}

void showArr(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n-------------------------\n");
}

void budSort(int arr[], int length)
{
    int flag = 1;
    while (length--&&flag)
    {
        flag = 0;
        for (int i = 0; i < length; i++)
        {
            if (arr[i + 1] < arr[i])
            {
                flag = 1;
                int temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
            }
        }
    }
}
//选择排序的基本思想就是冒泡排序
//每一轮找到最小值后和第一个交换
void SelectSort(int arr[], int length)
{
   for(int i=0;i<length;i++){
        int k = i;
        for(int j=i+1;j<length;j++){
            if(arr[k]>arr[j])
                k=j;
        }
        int temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
   }
}

//当元素基本有序的时候比较好用
void InsertSort(int arr[], int length){
    for(int i =1;i<length;i++){
        for(int j = i;j>=1&&arr[j]<arr[j-1];j--){
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
        }
    }
}

//希尔排序 优化版的插入排序 增大步长

//快排
//轴的左边 都比轴小 轴的右边 都比轴大  顺序表中1比2快
void quickSort(int arr[],int left,int right){
    if(left >= right) return;
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
    quickSort(arr,left,i-1);
    quickSort(arr,i+1,right);
}
//提供一个链表实现的思路
void quickSort2(int arr[],int left,int right){
    if(left >= right) return;
    int i = left + 1;
    int j = left + 1;
    int pivot = arr[left];
    while(j <= right){
        if(arr[j] < pivot){
            swap(arr,i,j);
            i++;
        }
        j++;
    }
    swap(arr,left,i-1);
    quickSort2(arr,left,i-2);
    quickSort2(arr,i,right);
}

//归并排序
// void mergeSort(int a[],int alen,int b[],int blen,int* temp){
//     int i = 0;
//     int j = 0;
//     int k = 0;
//     while(i<alen&&j<blen)
//         temp[k++] = (a[i]<b[j]) ? a[i++]: b[j++];
//     while(i<alen)
//         temp[k++] = a[i++];
//     while(j<blen)
//         temp[k++] = b[j++];
// }

void merge(int arr[],int low,int mid,int height,int * temp){
    int i = low;
    int j = mid+1;
    int k = low;
    while(i <= mid && j <= height)
        temp[k++] = (arr[i]<arr[j]) ? arr[i++]: arr[j++];
    while(i <= mid)
        temp[k++] = arr[i++];
    while(j <= height)
        temp[k++] = arr[j++];
    for(i = low;i<=height;i++)
        arr[i] = temp[i];
}

//分块 再排好每一块 递归排回来
void merge_sort(int arr[],int low,int height,int *temp){
    if(low >= height)
        return;
    int mid = low + (height - low) / 2;
    merge_sort(arr,low,mid,temp);
    merge_sort(arr,mid+1,height,temp);
    merge(arr,low,mid,height,temp);
}
 
void mergeSort(int arr[],int length){
    int *temp = (int *)malloc(sizeof(int)*length);
    merge_sort(arr,0,length-1, temp);
    free(temp);
}


int main()
{
    srand((unsigned int)time(NULL));
    int flag = 3;
    int arr[MAXSIZE];
    initArr(arr, MAXSIZE);
    showArr(arr, MAXSIZE);
    switch (flag)
    {
    case 0:
        budSort(arr, MAXSIZE);
        break;
    case 1:
        SelectSort(arr, MAXSIZE);
        break;
    case 2:
        quickSort2(arr,0,MAXSIZE-1);
        break;
    case 3:
        mergeSort(arr,MAXSIZE);
        break;
    default:
        break;
    }
    showArr(arr, MAXSIZE);

    // int a[5] = {1,3,5,7,9};
    // int b[3] = {2,8,10};
    // int temp[8];
    // mergeSort(a,5,b,3,temp);
    // showArr(temp,8);

    system("pause");
    return 0;
}
