#ifndef SQLIST_H
#define SQLIST_H
/* 列表顺序存储 */

#include<stdio.h>
#include<stdlib.h>

#define MaxSize 100

/*    */
#define OK 1 
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

/*  数据接口 */

// typedef int ElemType;
typedef struct 
{
    float a; //  系数
    int b ; // 指数
}ElemType;


typedef struct {
   ElemType *base_addr;
   int lentgth;
   
}SqList;


/*   API 接口 */
// 初始化一个空列表
Status InitList(SqList& L)
{
    L.base_addr = (ElemType*) malloc(MaxSize * (sizeof(ElemType)));
    if(!L.base_addr){
        exit(OVERFLOW);
    }
    L.lentgth = 0;
    printf("InitList successful\n");
    return OK;

}
// 销毁一个列表
Status DestoryList(SqList& L)
{
    free(L.base_addr);
    return OK;
}
// 清空一个列表
Status ClearList(SqList& L)
{
    L.lentgth = 0;
    return OK;
}

// 列表的插入

// 列表元素的删除

#endif