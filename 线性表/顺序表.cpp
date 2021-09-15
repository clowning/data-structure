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
int main(){
    SqList L;
    InitList(L);
    for (int i = 0; i < MAXSIZE; i++)
    {
        printf("data[%d]=%d\n",i,L.data[i]);
    }
    return 0;
}