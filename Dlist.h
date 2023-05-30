#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DLdataType;

typedef struct ListNode {
	DLdataType data;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;

LTNode* ListInit();
void ListPushBack(LTNode* phead, DLdataType x);
void ListPrint(LTNode* phead);

void ListPopBack(LTNode* phead);
void ListPopFront(LTNode* phead);
void ListPushFront(LTNode* phead, DLdataType x);
void ListPushBack(LTNode* phead, DLdataType x);

LTNode* ListBuy(DLdataType x);
LTNode* ListFind(LTNode* phead, DLdataType x);

void ListInsert(LTNode* pos, DLdataType x);
void ListErase(LTNode* pos);
void ListDestroy(LTNode* phead);

