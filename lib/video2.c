//【UP从0到1带你手撕数据结构全集(C语言版)】https://www.bilibili.com/video/BV1W64y1z7jh/?p=2&share_source=copy_web&vd_source=3110460ab802fd8e0175c2badd842f78
#include<stdio.h>
#include<stdlib.h>
// 单链表
typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node *initList(){
    Node * list;
    if((list = (Node*)malloc(sizeof(Node)))==NULL)
        exit(-1);
    list->data = 0;
    list->next = list;
    return list;
}

void headInsert(Node* list,int data){
    Node* node;
    if((node = (Node*)malloc(sizeof(Node)))==NULL)
        exit(-1);
    node->data = data;
    node->next = list->next;
    list->next = node;
    list->data++;
}

void tailInsert(Node* list,int data){
    Node* head = list;
    Node* node;
    if((node = (Node*)malloc(sizeof(Node)))==NULL)
        exit(-1);
    node->data = data;
    node->next = head;
    // list = list->next; 视频中的错误
    while(list->next != head){
        list = list->next;
    }
    list->next = node;
    head->data++;
}

int deleteList(Node* list,int data){
    int flag = 0;
    Node* pre = list;
    Node* current = list->next;
    while(current != list){
        while(current->data == data){
            pre->next = current->next;
            free(current); 
            flag++;
            current = pre->next;  //perfect 防止出现一样的
            list->data --;
        }
        pre = pre->next;
        current = pre->next;
    }
    return flag;
}

void printList(Node* list){
        printf("the total is %d\n",list->data);
        printf("head ");
        Node* head = list;
        while(list->next != head){
            printf("->");
            list = list->next;
            printf(" %d ",list->data);
        }
        printf("-> head\n");
}

int main() {
    Node * list = initList();
    for(int i=0;i<5;i++){
        headInsert(list,i);
        tailInsert(list,i);
    }
    printList(list);
    printf("seccuss to delete: %d \n",deleteList(list,2));
    printList(list);
    system("pause");
    return 0;
}