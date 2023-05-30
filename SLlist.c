#include "SLlist.h"

void SLlistprint(SLTNode* phead) {
    SLTNode* cur = phead;
    while (cur != NULL) {
        printf("%d->", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
    fflush(stdout); // ˢ�±�׼���������
}

SLTNode* BuyListNode(SLTDatatype x) {
    SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode)); // �����½ڵ���ڴ�ռ�
    newnode->data = x;  // �����½ڵ������Ϊx
    newnode->next = NULL; // ���½ڵ��nextָ����ΪNULL����ʾ����ĩβ�ڵ�
    return newnode;
}

void SListPushBack(SLTNode** phead, SLTDatatype x) {
    SLTNode* newnode = BuyListNode(x);

    if (*phead == NULL) {
        *phead = newnode; // �������Ϊ�գ����½ڵ���Ϊͷ�ڵ�
    }
    else {
        SLTNode* tail = *phead; // ��tail��ֵΪͷָ��
        while (tail->next != NULL) {
            tail = tail->next; // tailָ����һ���ڵ�
        }
        tail->next = newnode; // ���½ڵ����ӵ������ĩβ
    }
}

void SListPushFront(SLTNode** phead, SLTDatatype x) {
    SLTNode* newnode = BuyListNode(x);
    newnode->next = *phead;
    *phead = newnode;
}

void SListPopFront(SLTNode** phead) {
    if (*phead == NULL) {
        return; // ����Ϊ�գ��������ͷɾ����
    }

    SLTNode* temp = (*phead)->next;
    free(*phead);
    *phead = temp;
}

void SListPopBack(SLTNode** phead) {
    assert(*phead != NULL);

    if ((*phead)->next == NULL) {
        // ����ֻ��һ���ڵ㣬ֱ�ӽ���βɾ����
        free(*phead);
        *phead = NULL;
        return;
    }

    SLTNode* tail = *phead;
    SLTNode* previous = NULL;

    while (tail->next) {
        previous = tail;
        tail = tail->next;
    }

    free(tail);
    tail = NULL;
    previous->next = NULL;
}

SLTNode* SListFind(SLTNode* phead, SLTDatatype x) {
    SLTNode* cur = phead;
    while (cur) {   //cur!=null
        if (cur->data == x) {
            return cur;
        }
        else
        {
            cur = cur->next;
        }
    }
    return NULL;
}

//void SListPushInsert(SLTNode** phead, SLTNode* pos, SLTDatatype x) {
//    SLTNode* newnode = BuyListNode(x);
//    SLTNode* posprev = *phead;
//    while (posprev->next != pos) {
//        posprev = posprev->next;
//    }
//    posprev->next = newnode;
//    newnode->next = pos;
//
//}
void SListPushInsert(SLTNode** phead, SLTNode* pos, SLTDatatype x) {
    SLTNode* newnode = BuyListNode(x);
    SLTNode* cur = *phead;

    if (pos == *phead) {
        // ����λ��Ϊͷ�ڵ�֮ǰ�����½ڵ���Ϊ�µ�ͷ�ڵ�
        newnode->next = *phead;
        *phead = newnode;
        return;
    }

    while (cur && cur->next != pos) {
        cur = cur->next;
    }

    if (cur) {
        // ����λ���ҵ�
        newnode->next = cur->next;
        cur->next = newnode;
    }
}


void SListErase(SLTNode** phead, SLTNode* pos) {
    if (*phead == NULL || pos == NULL) {
        return; // ����Ϊ�ջ�posΪNULL������ɾ������
    }

    if (pos == *phead) {
        // ɾ��ͷ�ڵ�
        *phead = (*phead)->next;
        free(pos);
        return;
    }

    SLTNode* cur = *phead;
    SLTNode* prev = NULL;

    while (cur && cur != pos) {
        prev = cur;
        cur = cur->next;
    }

    if (cur) {
        // ɾ��pos�ڵ�
        prev->next = cur->next;
        free(cur);
    }
}

void SListDestroy(SLTNode** phead) {
    if (*phead == NULL) {
        return; // ����Ϊ�գ��������ٲ���
    }

    SLTNode* cur = *phead;
    while (cur) {
        SLTNode* temp = cur;
        cur = cur->next;
        free(temp);
    }

    *phead = NULL; // ��ͷָ����ΪNULL����ʾ����������
}