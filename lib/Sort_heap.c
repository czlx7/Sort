#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#define MAXSIZE 50
typedef struct Heap
{
    int *root;
    int length;
} Heap;

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
        if ((i + 1) % 5 == 0)
            printf("\n");
    }
    printf("\n-------------------------\n");
}

void swap(int arr[], int i, int j)
{
    int temp = arr[j];
    arr[j] = arr[i];
    arr[i] = temp;
}

Heap *creatHeap(int length)
{
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    assert(heap);
    heap->length = 0;
    heap->root = (int *)malloc(sizeof(int) * length);
    assert(heap->root);
    return heap;
}

//外堆排序
//入堆
void pushHeap(Heap *heap, int data)
{
    int current = heap->length++;
    int parent = current / 2;
    heap->root[current] = data;
    while (parent != current)
    {
        if (heap->root[current] < heap->root[parent])
        {
            swap(heap->root, current, parent);
            current = parent;
            parent = current / 2;
        }
        else
            break;
    }
}

//出堆
int popHeap(Heap *heap)
{
    int val = heap->root[0];
    int current = 0;
    int small;
    int rchild = current * 2 + 2;
    heap->root[0] = heap->root[--heap->length];
    while (rchild <= heap->length)
    {
        small = heap->root[rchild - 1] < heap->root[rchild] ? rchild - 1 : rchild;
        if (heap->root[current] > heap->root[small])
        {
            swap(heap->root, current, small);
            current = small;
            rchild = current * 2 + 2;
        }
        else
            break;
    }
    return val;
}

void heapSort(int arr[], int length)
{
    Heap *heap = creatHeap(MAXSIZE);
    for (int i = 0; i < MAXSIZE; i++)
    {
        pushHeap(heap, arr[i]);
    }
    // showArr(heap->root, heap->length);
    for (int i = 0; i < MAXSIZE; i++)
    {
        arr[i] = popHeap(heap);
    }
    free(heap);
}

//内堆排序
void heapify(int arr[], int length, int current)
{
    int rchild = current * 2 + 2;
    int large;
    while (rchild <= length)
    {
        large = rchild == length ? rchild - 1 : (arr[rchild - 1] > arr[rchild] ? rchild - 1 : rchild);
        if (arr[large] > arr[current])
        {
            swap(arr, large, current);
            current = large;
            rchild = current * 2 + 2;
        }
        else
            break;
    }
}

void heapSort2(int arr[], int length)
{
    int current = length / 2;
    while (current >= 0)
    {
        heapify(arr, length, current);
        current--;
    }
    while (length > 0)
    {
        swap(arr, 0, --length);
        heapify(arr, length, 0);
    }
}

int main()
{
    srand((unsigned int)time(NULL));
    int arr[MAXSIZE];
    initArr(arr, MAXSIZE);
    showArr(arr, MAXSIZE);
    heapSort2(arr, MAXSIZE);
    showArr(arr, MAXSIZE);
    system("pause");
    return 0;
}