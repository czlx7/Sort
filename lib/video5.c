//【UP从0到1带你手撕数据结构全集(C语言版)】https://www.bilibili.com/video/BV1W64y1z7jh/?p=2&share_source=copy_web&vd_source=3110460ab802fd8e0175c2badd842f78
#include<stdio.h>
#include<stdlib.h>
// 栈
typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node *initStack(){
    Node * S = (Node*)malloc(sizeof(Node));
    if(S == NULL) exit(-1);
    S->data = 0;
    S->next = NULL;
    return S;
}

int isEmpty(Node* S){
    if(S-> data == 0 && S->next == NULL){
        return 1;
    }else{
        return 0;
    }
}

int pop(Node* S){
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

void push(Node* S,int data){
    Node * node = (Node*)malloc(sizeof(Node));
    if(node == NULL) exit(-1);
    node->data = data;
    node->next = S->next;
    S->next = node;
    S->data++;
}

void printStack(Node * S){
    while(1){
        int a = pop(S);
        if(a == -1)
            break;
        printf("%d\n",a);
    }
}

int main() {
    Node* Stack = initStack();
    for(int i =0;i<8;i++)
        push(Stack,i);
    printStack(Stack);
    free(Stack);
    system("pause");
    return 0;
}