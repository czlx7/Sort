//【UP从0到1带你手撕数据结构全集(C语言版)】https://www.bilibili.com/video/BV1W64y1z7jh/?p=2&share_source=copy_web&vd_source=3110460ab802fd8e0175c2badd842f78
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
// 循环队列
typedef struct Queue{
    int front;
    int rear;
    int data[MAXSIZE];
}Queue;

Queue* initQueue(){
    Queue* Q = (Queue*)malloc(sizeof(Queue));
    if(Q == NULL) exit(-1);
    Q->front = Q->rear = 0;
    return Q;
}

int isFull(Queue* Q){
    if((Q->rear+1) % MAXSIZE == Q->front){
        return 1;
    }else{
        return 0;
    }
}

int isEmpty(Queue* Q){
    if(Q->front == Q->rear){
        return 1;
    }else{
        return 0;
    }
}

int enQueue(Queue* Q,int data){
    if(!isFull(Q)){
       Q->data[Q->rear] = data;
       Q->rear = (Q->rear + 1) % MAXSIZE;
       return 1;
    }else{ return 0;}
}

int deQueue(Queue* Q){
    if(!isEmpty(Q)){
        int temp = Q->data[Q->front];
        Q->front =  (Q->front + 1) % MAXSIZE;
        return temp;
    }
}

void printQueue(Queue* Q){
    if(!isEmpty(Q)){
        int length = ((Q->rear) - (Q->front) + MAXSIZE) % MAXSIZE;
        int index = Q->front;
        for(int i = 0;i<length;i++){
            printf("%d ",Q->data[index]);
            index = (index + 1) % MAXSIZE;
        }
        printf("\n");
    }
}

int main() {
    Queue* Q = initQueue();
    isEmpty(Q)?printf("Empty\n"):printf("not Empty\n");
    for(int i = 0;i<12;i++){
        if(enQueue(Q,i)){
            printf("insert success\n");
        }else{
            printf("Full!\n");
            break;
        }
    }
    printQueue(Q);
    free(Q);
    system("pause");
    return 0;
}