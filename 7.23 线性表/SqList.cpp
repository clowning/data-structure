#include<stdio.h>
#include<stdlib.h>
#define InitSize 10
typedef struct 
{
    int *data;
    int MaxSize;
    int length;
}SeqList;
void InitList(SeqList &L){
    L.data = (int *)malloc(InitSize*sizeof(int));
    L.length=0;
    L.MaxSize = InitSize;
}
bool IncreaseSize(SeqList &L,int len){
    int *p=L.data;
    L.data = (int *)malloc((L.MaxSize+len)*sizeof(int));

    for (int i = 0; i < L.length; i++)
    {
        L.data[i]=p[i];
    }
    L.MaxSize=L.MaxSize+len;
    free(p);
    return true;
}
int main(){
    SeqList L ;
    InitList(L);
    bool flag = IncreaseSize(L,5);
    bool flag2 = IncreaseSize(L,10);
    printf("现在顺序表的最大长度为%d",L.MaxSize);
}
