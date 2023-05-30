#define _CRT_SECURE_NO_WARNINGS
#include "SLlist.h"


void printMenu() {
    printf("************\n");
    printf("1. ��ӡ����\n");
    printf("2. β��Ԫ��\n");
    printf("3. ͷ��Ԫ��\n");
    printf("4. ͷɾԪ��\n");
    printf("5. βɾԪ��\n");
    printf("6. ����Ԫ��\n");
    printf("7. ��ָ��λ�ò���Ԫ��\n");
    printf("8. ɾ��ָ��λ�õ�Ԫ��\n");
    printf("9. ��������\n");
    printf("0. �˳�\n");
    printf("************\n");
    printf("�����������ţ�");
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
        case 1:  // ��ӡ����
            printf("�������ݣ�");
            SLlistprint(head);
            break;
        case 2:  // β��Ԫ��
            printf("������Ҫ�����Ԫ�أ�");
            scanf("%d", &data);
            SListPushBack(&head, data);
            break;
        case 3:  // ͷ��Ԫ��
            printf("������Ҫ�����Ԫ�أ�");
            scanf("%d", &data);
            SListPushFront(&head, data);
            break;
        case 4:  // ͷɾԪ��
            SListPopFront(&head);
            break;
        case 5:  // βɾԪ��
            SListPopBack(&head);
            break;
        case 6:  // ����Ԫ��
            printf("������Ҫ���ҵ�Ԫ�أ�");
            scanf("%d", &data);
            position = SListFind(head, data);
            if (position) {
                printf("Ԫ�� %d ������������\n", data);
            }
            else {
                printf("Ԫ�� %d ��������������\n", data);
            }
            break;
        case 7:  // ��ָ��λ�ò���Ԫ��
            printf("������Ҫ�����λ�ú�Ԫ�أ��Կո�ָ���");
            int index;
            scanf("%d%d", &index, &data);
            position = head;
            for (int i = 1; i < index; i++) {
                if (position == NULL) {
                    printf("����λ����Ч\n");
                    position = NULL;
                    break;
                }
                position = position->next;
            }
            if (position) {
                SListPushInsert(&head, position, data);
            }
            break;
        case 8:  // ɾ��ָ��λ�õ�Ԫ��
            printf("������Ҫɾ����λ�ã�");
            scanf("%d", &index);
            position = head;
            for (int i = 1; i < index; i++) {
                if (position == NULL || position->next == NULL) {
                    printf("ɾ��λ����Ч\n");
                    position = NULL;
                    break;
                }
                position = position->next;
            }
            if (position) {
                SListErase(&head, position);
            }
            break;
        case 9: // ��������
            SListDestroy(&head);
            printf("����������\n");
            break;
        case 0: // �˳�����
            exitFlag = true;
            break;
        default:
            printf("��Ч�Ĳ������\n");
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
//		printf("��%d��pos�Ľڵ���:%p->%d\n", i++, pos1,pos1->data);
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