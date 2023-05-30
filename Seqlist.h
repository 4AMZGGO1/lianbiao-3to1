#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define _CRT_SECURE_NO_WARNINGS
typedef int SLDataType;

////��̬˳���
// typedef struct Seqlist {
//    SLDataType a[N];
//    int size; //��ʾ�����д洢�˶�������
//}SL;

//��̬˳���
typedef struct Seqlist {
    SLDataType* a;
    int size; //��ʾ�����д洢�˶�������
    int capacity;//��ʾ����ʵ�ʴ洢�ռ������Ƕ��
}SL;

//�ӿں���
void SeqListInit(SL* ps);//��ʼ��
void SeqListPushBack(SL* ps, SLDataType x);//β��
void SeqListPopBack(SL* ps);//βɾ
void SeqListPushFront(SL* ps, SLDataType x);//ͷ��
void SeqListPopFront(SL* ps);//ͷɾ
void SeqListPrint(SL* ps);  //��ӡ����
void SeqListDestory(SL* ps);
void SLCheckCapacity(SL* ps);
int SeqListFind(SL* ps, SLDataType x);
void SLInsert(SL* ps, int pos, SLDataType x);
void SeqListDelete(SL* ps, int pos);
void PrintMenu();
