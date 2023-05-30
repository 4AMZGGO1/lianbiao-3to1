#define _CRT_SECURE_NO_WARNINGS
#include "SLlist.h"


void printMenu() {
    printf("************\n");
    printf("1. 打印链表\n");
    printf("2. 尾插元素\n");
    printf("3. 头插元素\n");
    printf("4. 头删元素\n");
    printf("5. 尾删元素\n");
    printf("6. 查找元素\n");
    printf("7. 在指定位置插入元素\n");
    printf("8. 删除指定位置的元素\n");
    printf("9. 销毁链表\n");
    printf("0. 退出\n");
    printf("************\n");
    printf("请输入操作编号：");
}

int main() {
    SLTNode* head = NULL;
    int choice;
    SLTDatatype data;
    SLTNode* position;
    bool exitFlag = false;

    while (!exitFlag) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
        case 1:  // 打印链表
            printf("链表内容：");
            SLlistprint(head);
            break;
        case 2:  // 尾插元素
            printf("请输入要插入的元素：");
            scanf("%d", &data);
            SListPushBack(&head, data);
            break;
        case 3:  // 头插元素
            printf("请输入要插入的元素：");
            scanf("%d", &data);
            SListPushFront(&head, data);
            break;
        case 4:  // 头删元素
            SListPopFront(&head);
            break;
        case 5:  // 尾删元素
            SListPopBack(&head);
            break;
        case 6:  // 查找元素
            printf("请输入要查找的元素：");
            scanf("%d", &data);
            position = SListFind(head, data);
            if (position) {
                printf("元素 %d 存在于链表中\n", data);
            }
            else {
                printf("元素 %d 不存在于链表中\n", data);
            }
            break;
        case 7:  // 在指定位置插入元素
            printf("请输入要插入的位置和元素，以空格分隔：");
            int index;
            scanf("%d%d", &index, &data);
            position = head;
            for (int i = 1; i < index; i++) {
                if (position == NULL) {
                    printf("插入位置无效\n");
                    position = NULL;
                    break;
                }
                position = position->next;
            }
            if (position) {
                SListPushInsert(&head, position, data);
            }
            break;
        case 8:  // 删除指定位置的元素
            printf("请输入要删除的位置：");
            scanf("%d", &index);
            position = head;
            for (int i = 1; i < index; i++) {
                if (position == NULL || position->next == NULL) {
                    printf("删除位置无效\n");
                    position = NULL;
                    break;
                }
                position = position->next;
            }
            if (position) {
                SListErase(&head, position);
            }
            break;
        case 9: // 销毁链表
            SListDestroy(&head);
            printf("链表已销毁\n");
            break;
        case 0: // 退出程序
            exitFlag = true;
            break;
        default:
            printf("无效的操作编号\n");
            break;
        }
    }
    return 0;
}

//#include "SLlist.h"
//
//void test1() {
//	SLTNode* plist = NULL;
//	SListPushBack(&plist, 1);
//	SListPushBack(&plist, 2);
//	SListPushBack(&plist, 3);
//	SListPushBack(&plist, 4);
//	SLlistprint(plist);
//	SListPushFront(&plist, 1);
//	SListPushFront(&plist, 2);
//	SListPushFront(&plist, 3);
//	SListPushFront(&plist, 4);
//	SLlistprint(plist);
//}
//
//void test2() {
//	SLTNode* plist = NULL;
//	SListPushFront(&plist, 1);
//	SListPushFront(&plist, 2);
//	SListPushFront(&plist, 3);
//	SListPushFront(&plist, 4);
//	SLlistprint(plist);
//	SListPopBack(&plist);
//	SLlistprint(plist);
//}
//
//void test3() {
//	SLTNode* plist = NULL;
//	SListPushFront(&plist, 1);
//	SListPushFront(&plist, 2);
//	SListPushFront(&plist, 2);
//	SListPushFront(&plist, 4);
//	SLTNode* pos1 = SListFind(plist, 2);
//	int i = 1;
//	while (pos1!=NULL) {
//		printf("第%d个pos的节点是:%p->%d\n", i++, pos1,pos1->data);
//		pos1 = SListFind(pos1->next, 2);
//	}
//}
//
//void test4() {
//	SLTNode* plist = NULL;
//	SListPushFront(&plist, 1);
//	SListPushFront(&plist, 2);
//	SListPushFront(&plist, 2);
//	SListPushFront(&plist, 4);
//	SLlistprint(plist);
//	SLTNode* pos = SListFind(plist, 4);
//	if (pos) {
//		pos->data = 40;
//	}
//	SLlistprint(plist);
//}
//
//void test5() {
//	SLTNode* plist = NULL;
//	SListPushFront(&plist, 1);
//	SListPushFront(&plist, 2);
//	SListPushFront(&plist, 2);
//	SListPushFront(&plist, 4);
//	SListPushFront(&plist, 6);
//	SListPushFront(&plist, 9);
//	SLlistprint(plist);
//	SLTNode* pos = SListFind(plist, 9);
//	if (pos) {
//		SListPushInsert(&plist, pos, 30);
//	}
//	SLlistprint(plist);
//}
//
//
//int main() {
//	test5();
//	return 0;
//}