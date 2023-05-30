#include "SLlist.h"

void SLlistprint(SLTNode* phead) {
    SLTNode* cur = phead;
    while (cur != NULL) {
        printf("%d->", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
    fflush(stdout); // 刷新标准输出缓冲区
}

SLTNode* BuyListNode(SLTDatatype x) {
    SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode)); // 分配新节点的内存空间
    newnode->data = x;  // 设置新节点的数据为x
    newnode->next = NULL; // 将新节点的next指针设为NULL，表示它是末尾节点
    return newnode;
}

void SListPushBack(SLTNode** phead, SLTDatatype x) {
    SLTNode* newnode = BuyListNode(x);

    if (*phead == NULL) {
        *phead = newnode; // 如果链表为空，将新节点作为头节点
    }
    else {
        SLTNode* tail = *phead; // 将tail赋值为头指针
        while (tail->next != NULL) {
            tail = tail->next; // tail指向下一个节点
        }
        tail->next = newnode; // 将新节点链接到链表的末尾
    }
}

void SListPushFront(SLTNode** phead, SLTDatatype x) {
    SLTNode* newnode = BuyListNode(x);
    newnode->next = *phead;
    *phead = newnode;
}

void SListPopFront(SLTNode** phead) {
    if (*phead == NULL) {
        return; // 链表为空，无需进行头删操作
    }

    SLTNode* temp = (*phead)->next;
    free(*phead);
    *phead = temp;
}

void SListPopBack(SLTNode** phead) {
    assert(*phead != NULL);

    if ((*phead)->next == NULL) {
        // 链表只有一个节点，直接进行尾删操作
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
        // 插入位置为头节点之前，将新节点作为新的头节点
        newnode->next = *phead;
        *phead = newnode;
        return;
    }

    while (cur && cur->next != pos) {
        cur = cur->next;
    }

    if (cur) {
        // 插入位置找到
        newnode->next = cur->next;
        cur->next = newnode;
    }
}


void SListErase(SLTNode** phead, SLTNode* pos) {
    if (*phead == NULL || pos == NULL) {
        return; // 链表为空或pos为NULL，无需删除操作
    }

    if (pos == *phead) {
        // 删除头节点
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
        // 删除pos节点
        prev->next = cur->next;
        free(cur);
    }
}

void SListDestroy(SLTNode** phead) {
    if (*phead == NULL) {
        return; // 链表为空，无需销毁操作
    }

    SLTNode* cur = *phead;
    while (cur) {
        SLTNode* temp = cur;
        cur = cur->next;
        free(temp);
    }

    *phead = NULL; // 将头指针置为NULL，表示链表已销毁
}