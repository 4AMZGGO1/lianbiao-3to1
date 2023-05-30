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
        printf("请输入您的选择：");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            SeqListInit(&seqList);
            printf("顺序表已初始化\n");
            break;
        case 2:
            printf("请输入要插入的元素值：");
            scanf("%d", &value);
            SeqListPushBack(&seqList, value);
            printf("尾插成功\n");
            break;
        case 3:
            printf("请输入要插入的元素值：");
            scanf("%d", &value);
            SeqListPushFront(&seqList, value);
            printf("头插成功\n");
            break;
        case 4:
            SeqListPopBack(&seqList);
            printf("尾删成功\n");
            break;
        case 5:
            SeqListPopFront(&seqList);
            printf("头删成功\n");
            break;
        case 6:
            printf("请输入要查找的元素值：");
            scanf("%d", &value);
            position = SeqListFind(&seqList, value);
            if (position != -1) {
                printf("元素 %d 的位置为 %d\n", value, position);
            }
            else {
                printf("元素 %d 不存在\n", value);
            }
            break;
        case 7:
            printf("请输入要插入的位置：");
            scanf("%d", &position);
            printf("请输入要插入的元素值：");
            scanf("%d", &value);
            SLInsert(&seqList, position, value);
            printf("插入成功\n");
            break;
        case 8:
            printf("请输入要删除的位置：");
            scanf("%d", &position);
            SeqListDelete(&seqList, position);
            printf("删除成功\n");
            break;
        case 9:
            SeqListPrint(&seqList);
            break;
        case 0:
            printf("程序已退出\n");
            break;
        default:
            printf("无效的选择，请重新输入\n");
            break;
        }

        printf("\n");
    } while (choice != 0);

    SeqListDestory(&seqList);

    return 0;
}