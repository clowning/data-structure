#define MAXSIZE 10  //定义最大长度
#include<stdio.h>
#include<stdlib.h>


typedef struct 
{
    int data[MAXSIZE];//用静态的“数组”来存放顺序表的数据
    int length; //顺序表当前长度
}SqList;
//基本操作——初始化一个顺序表
void InitList(SqList &L){
    for (int i = 0; i < MAXSIZE; i++)
    {
        L.data[i]=0; //将所有的数据元素设置为默认初始值0
    }
    L.length=0;//顺序表初始长度为0
}

bool ListDelete(SqList &L,int i,int &e){
    if(i<1||i>L.length+1)//判断删除位置是否合法
        return false;
    e = L.data[i-1];//取出原来的第i个元素
    for (int j = i; j < L.length; j++)
    {
        L.data[j-1]=L.data[j];//把i以后的元素往前移一位，并覆盖原来的第i个元素
    }
    L.length--;//顺序表长度减一
    return true;
    
}


bool ListInsert(SqList &L,int i,int e){
    if(i<1||i>L.length+1)//判断插入位置是否合法
        return false;
    if(L.length>=MAXSIZE)//判断插入位置是否合法
        return false;
    for (int  j = L.length; j >=i; j--)
    {
        L.data[j]= L.data[j-1];//把i以后的所有元素全部往后移一位

    }
        L.data[i-1]=e;//给第i个元素赋值
        L.length++;//顺序表长度加一
    return true;
}
int main(){
    int e;
    SqList L;
    InitList(L);
    ListInsert(L,1,3);
    ListInsert(L,2,4);
    ListDelete(L,1,e);
    for (int i = 0; i < L.length; i++)
    {
        printf("data[%d]=%d\n",i,L.data[i]);
    }
    return 0;
}