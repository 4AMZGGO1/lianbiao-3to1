#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define _CRT_SECURE_NO_WARNINGS
typedef int SLDataType;

////静态顺序表
// typedef struct Seqlist {
//    SLDataType a[N];
//    int size; //表示数组中存储了多少数据
//}SL;

//动态顺序表
typedef struct Seqlist {
    SLDataType* a;
    int size; //表示数组中存储了多少数据
    int capacity;//表示数组实际存储空间容量是多大
}SL;

//接口函数
void SeqListInit(SL* ps);//初始化
void SeqListPushBack(SL* ps, SLDataType x);//尾插
void SeqListPopBack(SL* ps);//尾删
void SeqListPushFront(SL* ps, SLDataType x);//头插
void SeqListPopFront(SL* ps);//头删
void SeqListPrint(SL* ps);  //打印函数
void SeqListDestory(SL* ps);
void SLCheckCapacity(SL* ps);
int SeqListFind(SL* ps, SLDataType x);
void SLInsert(SL* ps, int pos, SLDataType x);
void SeqListDelete(SL* ps, int pos);
void PrintMenu();
