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
bool GetElemByLocation(SeqList L,int i ,int &e){
    if (i<1||i>L.length)
    {
        return false;
    }
    e = L.data[i-1];
    return true;
}
bool GetElemByValue(SeqList L,int &j,int e){
    for (int i = 0; i < L.length; i++)
    {
        if(L.data[i] == e){
            j= i+1;
            printf("找到该元素");
            return true;
        }
    }
    printf("查无此值");
    return false;
    
}
bool ListDeleteByLocation(SeqList &L,int i,int &e){
    if (i<1||i>L.length)
    {
        return false;
    }
    e = L.data[i-1];
    for (int j = i; j < L.length; j++)
    {
        L.data[j-1]=L.data[j];
    }
    L.length--;
    return true;
}
bool ListInsert(SeqList &L,int i,int e){
    if(i<1||i>L.MaxSize){
        printf("输入值非法");
        return false;
    }
    for (int j = L.length; j >=i; j--)
    {
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = e;
    L.length++;
    return true;

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
    int e = 9999;
    for (int i = 1; i < L.MaxSize; i++)
    {
        ListInsert(L,i,i);
    }
    bool flag2 = GetElemByLocation(L,5,e);
    if(flag2){
        printf("查找的元素值为%d\n",e);
    }
    //  bool flag1 = GetElemByValue(L,e,3);
    // if(flag1){
    //     printf("查找的值位置为%d",e);
    // }

    // ListDeleteByLocation(L,3,e);
    // printf("删除元素为%d\n",e);
    // for (int i = 0; i < L.MaxSize-1; i++)
    // {
    //     ListDeleteByLocation(L,i,e);
    //     printf("删除元素为%d",e);
    // }
    // bool flag = IncreaseSize(L,5);
    // bool flag2 = IncreaseSize(L,10);
    // printf("现在顺序表的最大长度为%d",L.MaxSize);
    //     for(int i = 0; i < L.length; i++)
    // {
    //     printf("data[%d]=%d\n",i,L.data[i]);
    // }
    return 0;
}
