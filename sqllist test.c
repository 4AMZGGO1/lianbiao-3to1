#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Seqlist.h"

int main() {
    SL seqList;
    SeqListInit(&seqList);

    int choice;
    SLDataType value;
    int position;

    do {
        PrintMenu();
        printf("����������ѡ��");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            SeqListInit(&seqList);
            printf("˳����ѳ�ʼ��\n");
            break;
        case 2:
            printf("������Ҫ�����Ԫ��ֵ��");
            scanf("%d", &value);
            SeqListPushBack(&seqList, value);
            printf("β��ɹ�\n");
            break;
        case 3:
            printf("������Ҫ�����Ԫ��ֵ��");
            scanf("%d", &value);
            SeqListPushFront(&seqList, value);
            printf("ͷ��ɹ�\n");
            break;
        case 4:
            SeqListPopBack(&seqList);
            printf("βɾ�ɹ�\n");
            break;
        case 5:
            SeqListPopFront(&seqList);
            printf("ͷɾ�ɹ�\n");
            break;
        case 6:
            printf("������Ҫ���ҵ�Ԫ��ֵ��");
            scanf("%d", &value);
            position = SeqListFind(&seqList, value);
            if (position != -1) {
                printf("Ԫ�� %d ��λ��Ϊ %d\n", value, position);
            }
            else {
                printf("Ԫ�� %d ������\n", value);
            }
            break;
        case 7:
            printf("������Ҫ�����λ�ã�");
            scanf("%d", &position);
            printf("������Ҫ�����Ԫ��ֵ��");
            scanf("%d", &value);
            SLInsert(&seqList, position, value);
            printf("����ɹ�\n");
            break;
        case 8:
            printf("������Ҫɾ����λ�ã�");
            scanf("%d", &position);
            SeqListDelete(&seqList, position);
            printf("ɾ���ɹ�\n");
            break;
        case 9:
            SeqListPrint(&seqList);
            break;
        case 0:
            printf("�������˳�\n");
            break;
        default:
            printf("��Ч��ѡ������������\n");
            break;
        }

        printf("\n");
    } while (choice != 0);

    SeqListDestory(&seqList);

    return 0;
}