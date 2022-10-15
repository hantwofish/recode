#ifndef LINKEDLIST_H
#define LINKEDLIST_H
/* 链式存储 */

#include<stdio.h>
#include<stdlib.h>
#include<iostream>

#define OK 1  // 正常 返回
#define ERROR 0 // 错误
#define EXCEPTION -2   // 异常
#define YES 1
#define NO 0
typedef int Status;

// 定义数据结构 
typedef struct 
{
    float a; //  系数
    int b ; // 指数
}ElemType;

typedef struct LNode
{
    ElemType data;
    struct  LNode* next;
}Lnode , *LinkList;

// 运算符重载
bool operator ==(ElemType& A , ElemType& B)
{
    return (A.a == B.a && A.b == B.b);

}


// 带头节点的链表

/* 定义 API 接口 */
// 链表初始化
Status ListInit(LinkList& L){
    LinkList temp = (LinkList)malloc(sizeof(Lnode));
    if( !temp ){
        return EXCEPTION;
    }
    L = temp;
    L->data.a = 0;
    L->next = NULL;
    return OK;
}

// 链表是否为空
Status Empty(LinkList& L)
{
    if(L->next == nullptr){
        return YES;
    }else{
        return NO;
    }
}

// 销毁链表
Status DestorYList(LinkList& L){
    LinkList temp = L;
    while( L != nullptr){
        temp = L ->next;
        free(L);
        L = temp;
    }
    return OK;
}

// 清空链表
Status ClearList(LinkList& L){
    LinkList temp = L->next;
    if(DestorYList(L) == OK){
        return OK;
    }else{
        return ERROR;
    }

}

// 求单链表的长度
Status CalLenth(LinkList& L , int & num)
{
    LinkList temp = L ->next;
    if(temp == nullptr){
        num = 0;
        return OK;
    }
    num  = 0;
    while(temp != nullptr){
        num++;
        temp = temp ->next;
    }
    return OK;
    
}

// 取第 i  个元素的值
Status find_i_else(LinkList& L , int i , ElemType& ele)
{
    // 初始值
    int lenth = 0;
    Status tem = CalLenth(L, lenth);
    if(tem == ERROR ){
        return ERROR;
    }
    
    if(i < 1 || i > lenth){
        return ERROR;
    }
    LinkList start = L->next;
    int count = 1;
    while(count < i){
        start = start ->next;
        count++;
    }
    ele = start ->data;
    return OK;

}

// 按值查找 ，引用返回元素地址
Status find_ele(LinkList&L , ElemType ele, LinkList& res)
{
    LinkList temp = L->next;
    while(temp != nullptr){
        if(temp->data == ele){
            res = temp;
            return OK;
        }
        temp = temp ->next;
    }
    return ERROR; // 未找到
}

// 插入节点 在第 i 个之前
Status Insert_i_ele(LinkList& L , int i , ElemType inse_ele)
{
    LinkList ele_add = (LinkList) malloc(sizeof(ElemType));
    ele_add->data = inse_ele;
    ele_add->next = nullptr;

    LinkList temp  = L;
    int count  = 0; // 第 i 个元素的前一个元素的位置
    while(temp != nullptr){
        if(count + 1 == i){
            ele_add -> next = temp ->next;
            temp -> next = ele_add;
            return OK;
        }
        temp = temp -> next;
    }
    return ERROR;

}

// 单链表的建立
    // 头插法，每次建立链表，元素插入在链表头部
    // 传入结构体数组，N 为数组长度
Status CreatList_H(LinkList& L , int N, ElemType num[])
{
    L = (LinkList)malloc(sizeof(ElemType));// 头节点
    L->next = nullptr;
    for(int i = N ; i>0; i--){
        LinkList p = (LinkList)malloc(sizeof(ElemType));
        p->data = num[i];
        p->next = L->next;
        L->next = p;
    }
    return OK;

}    

    // 尾插法
    // 尾指针指向链表的尾节点
Status CreatList_E(LinkList& L , int N, ElemType num[])
{
    L = (LinkList)malloc(sizeof(ElemType));// 头节点
    L->next = nullptr;
    LinkList End_node = L; // 尾指针
    for (int i = 0; i < N; i++){
        LinkList p = (LinkList)malloc(sizeof(ElemType));
        p->data = num[i];
        End_node->next = p; // 插入到表尾
        End_node = p; // end_node 指向新的尾节点
    }
    return OK;
}    

//删除节点 删除 第 i 个元素
Status dele_ele(LinkList& L , int i)
{
    LinkList temp = L;
    int count  = 0; // i 的 前一个元素
    while(temp != nullptr){
        if( count +1  == i){
            LinkList del = temp ->next;
            temp ->next = del->next ;
            free(del);
            return OK;
        }
        temp = temp ->next;
    }
    return ERROR;
}


// 打印所有元素
Status prin_list(LinkList& L)
{
    LinkList temp = L->next;
    while(temp != nullptr){
        std::cout << temp->data.a << " " ;
    }
    return OK;
}


#endif

// 循环链表
#ifndef __CIRCLELIST__
#define __CIRCLELIST__
void m_print()
{
    printf("test...\n");

}


#endif

// 双向链表
#ifndef __DulLIST__
#define __DulLIST__

typedef struct DulNode{
    ElemType data;
    struct DulNode * pior;
    struct DulNode * next;

}DulNode, *DuLinkList;

#endif