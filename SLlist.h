#pragma once


#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#include <stdbool.h>

typedef int SLTDatatype;

typedef struct SListNode {
    SLTDatatype data;
    struct SListNode* next;
} SLTNode;

void SLlistprint(SLTNode* phead); // ��ӡ����
void SListPushBack(SLTNode** phead, SLTDatatype x); // β��
void SListPushFront(SLTNode** phead, SLTDatatype x);
void SListPopFront(SLTNode** phead);
void SListPopBack(SLTNode** phead);
void SListPushFront(SLTNode** phead, SLTDatatype x);
SLTNode* SListFind(SLTNode* phead, SLTDatatype x);
void SListPushInsert(SLTNode** phead, SLTNode* pos, SLTDatatype x);
void SListEase(SLTNode** phead, SLTNode* pos);  //ease���ڵ�λ��
void SListDestory(SLTNode** phead, SLTDatatype x);  // ��������