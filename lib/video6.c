//【UP从0到1带你手撕数据结构全集(C语言版)】https://www.bilibili.com/video/BV1W64y1z7jh/?p=2&share_source=copy_web&vd_source=3110460ab802fd8e0175c2badd842f78
#include<stdio.h>
#include<stdlib.h>
// 队列
typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node *initQueue(){
    Node * Q = (Node*)malloc(sizeof(Node));
    if(Q == NULL) exit(-1);
    Q->data = 0;
    Q->next = NULL;
    return Q;
}

int isEmpty(Node* S){
    if(S-> data == 0 || S->next == NULL){
        return 1;
    }else{
        return 0;
    }
}

int deQueue(Node* S){
    if(isEmpty(S)){
        return -1;
    }else{
        Node * p = S->next;
        int temp = p->data;
        S->next = p->next;
        free(p);
        S->data--;
        return temp;
    }
}

void enQueue(Node* Queue,int data){
    Node* head = Queue;
    Node * node = (Node*)malloc(sizeof(Node));
    if(node == NULL) exit(-1);
    node->data = data;
    node->next = NULL;
    while(Queue->next)
        Queue = Queue->next;
    Queue->next = node;
    head->data++;
}

void printQueue(Node * S){
    while(1){
        int a = deQueue(S);
        if(a == -1)
            break;
        printf("%d\n",a);
    }
}

int main() {
    Node* Queue = initQueue();
    for(int i =0;i<8;i++)
        enQueue(Queue,i);
    printQueue(Queue);
    free(Queue);
    system("pause");
    return 0;
}