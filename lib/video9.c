//【UP从0到1带你手撕数据结构全集(C语言版)】https://www.bilibili.com/video/BV1W64y1z7jh/?p=2&share_source=copy_web&vd_source=3110460ab802fd8e0175c2badd842f78
#include<stdio.h>
#include<stdlib.h>

// 循环队列
typedef struct String{
    char *data;
    int len;
}String;

String* initString(){
    String* s = (String*)malloc(sizeof(String));
    s->data = NULL;
    s->len = 0;
    return s;
}

void stringAssign(String *s,char* data){
    if(s->data) free(s->data);
    int len = 0;
    char *temp = data;
    while(*temp){
        len++;
        temp++;
    }
    if(len == 0){
        s->data = NULL;
        s->len = 0;
    }else{
        temp = data;
        s->len = len;
        //copy
        s->data = (char* )malloc(sizeof(char)*(len + 1));
        for(int i = 0;i<len;i++,temp++){
            s->data[i] = *temp;
        }
        s->data[len] = '\0';
    }
}

void printString(String * string){
    // if((string->len)!=0)
    //     printf("%s",string->data);
    for(int i = 0;i<(string->len);i++)
        i == 0?printf("%c ",string->data[i]):printf("-> %c ",string->data[i]);
    printf("\n");
}

void forceMatch(String* master,String * sub){
    int i = 0;
    int j = 0;
    while(i< master->len && j< sub->len){
        int temp = i;
        if(master->data[i] == sub->data[j]){
            i++;
            j++;
        }else{
            temp = temp + 1;
            i = temp;
            j = 0;
        }
        
    }
    if(j == sub->len){
            printf("success");
        }else{
            printf("fail");
        }
        printf("\n");
}

void KMP(String * str,int* nextval){
    int i = 1;
    int j = 0;
    nextval[1] = 0;
    while(i < str->len){
        if(j==0||str->data[i-1]==str->data[j-1]){
            i++;
            j++;
            nextval[i] = j;
            // if(str->data[i]!=str->data[j])
            //     nextval[i] = j;
            // else
            //     nextval[i] = nextval[j];
        }
        else
        {
            j = nextval[j] ;
        }
    }
}

int main() {
    String* str = initString();
    stringAssign(str,"abcxjabcd");
    int nextval[str->len];
    KMP(str,nextval);
    for(int i = 1;i<=str->len;i++){
        printf("%d\n",nextval[i]);
    }
    system("pause");
    return 0;
}


