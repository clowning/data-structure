#define MAXSIZE 10
#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int data[MAXSIZE];
    int length;
}SqList;
void InitList(SqList &L)
{
    for(int i=0;i<MAXSIZE;i++){
        L.data[i]=0;
    }
    L.length=0;
    // printf("初始化完成 %d",L.length);

}
int main(){
    SqList L;
    InitList(L);
    for(int i = 0; i < L.length; i++)
    {
        printf("data[%d]=%d\n",i,L.data[i]);
    }
    
    return 0;
}