//【UP从0到1带你手撕数据结构全集(C语言版)】https://www.bilibili.com/video/BV1W64y1z7jh/?p=2&share_source=copy_web&vd_source=3110460ab802fd8e0175c2badd842f78
#include<stdio.h>
#include<stdlib.h>
// 双链表
typedef struct Node{
    int data;
    struct Node* pre;
    struct Node* next;
}Node;

Node *initList(){
    Node * list;
    if((list = (Node*)malloc(sizeof(Node)))==NULL)
        exit(-1);
    list->data = 0;
    list->pre = list;
    list->next = list;
    return list;
}

void headInsert(Node* list,int data){
    Node* node;
    if((node = (Node*)malloc(sizeof(Node)))==NULL)
        exit(-1);
    node->data = data;
    //新的一定变
    node->pre = list;
    node->next = list->next;
    //旧的稳定变两个
    list->next->pre = node;
    list->next = node;

    list->data++;
}

void tailInsert(Node* list,int data){
    Node* head = list;
    Node* node;
    if((node = (Node*)malloc(sizeof(Node)))==NULL)
        exit(-1);
    node->data = data;
    //新的一定变
    node->pre = head->pre;
    node->next = head;
    //okok
    head->pre->next = node;
    head->pre = node;   

    head->data++;
}

void deleteListAll(Node* list,int data){
    Node* pre = list;
    Node* current = list->next;
    while(current!=list){
        while(current->data == data){
            pre->next = current->next;
            free(current); 
            current = pre->next;  //perfect 防止出现一样的
            current->pre = pre;
            list->data --;
        }
        pre = pre->next;
        current = pre->next;
    }
}


void deleteListByOne(Node* list,int data){
    Node* current = list->next;
    while(current!=list){
        if(current->data == data){
            current->next->pre = current->pre; 
            current->pre->next = current->next;
            free(current); 
            list->data --;
            break;
        }
        current = current->next;
    }
}

void printList(Node* list){
        Node* head = list;
        printf("the total is %d\n",list->data);
        printf("head");
        while(list->next!=head){
            printf("->");
            list = list->next;
            printf("%d ",list->data);
        }
        printf("-> head\n");
        printf("\n");
}

int main() {
    Node * list = initList();
    for(int i=0;i<10;i++){
        headInsert(list,i);
    }
    for(int i=0;i<10;i++){
        headInsert(list,i);
    }
    tailInsert(list,16);
    printList(list);
    deleteListByOne(list,16);
    printList(list);
    system("pause");
    return 0;
}