#include"Dlist.h"

LTNode* ListInit() {
	//哨兵位头节点
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

void ListPrint(LTNode* phead) {
	assert(phead);
	LTNode* start = phead->next;
	while (start->next != phead) {
		printf("%d->", start->data);
		start = start->next;
	}
	printf("\n");
}

LTNode* ListBuy(DLdataType x) {
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	newnode->prev = NULL;
	newnode->next = NULL;
	newnode->data = x;
	return newnode;
}


void ListPushBack(LTNode* phead, DLdataType x) {
	assert(phead);
	//LTNode* tail = phead->prev;//tail被赋值尾节点
	//LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	//newnode->data = x;

	//tail->next = newnode;
	//newnode->prev = tail;
	//newnode->next = phead;
	//phead->prev = newnode;
	ListInsertBack(phead, x); //尾插

}

void ListPushFront(LTNode* phead, DLdataType x) {
	assert(phead);
	/*LTNode* newnode = ListBuy(x);
	LTNode* next = phead->next;

	phead->next = newnode;
	newnode->prev = phead;

	newnode->next = next;
	next->prev = newnode;*/
	ListInsertBack(phead->next, x); //头插

}

void ListPopFront(LTNode* phead) {

	assert(phead);
	assert(phead->next != phead);

	/*LTNode* next = phead->next;
	LTNode* nextnext = next->next;

	phead->next = nextnext;
	nextnext->prev = phead;
	free(next);*/
	ListErase(phead->next);

}

void ListPopBack(LTNode* phead) {
	assert(phead);
	assert(phead->next != phead);
	/*LTNode* tail = phead->prev;
	LTNode* tailprev = tail->prev;
	free(tail);
	tailprev->next = phead;
	phead->prev = tailprev;*/
	ListErase(phead->prev);

}


LTNode* ListFind(LTNode* phead, DLdataType x) {
	LTNode* start = phead->next;
	while (start != phead) {
		if (start->data == x) {
			return start;
		}
		start = start->next;
	}
	return NULL; // 如果未找到匹配节点，返回NULL
}

void ListInsert(LTNode* pos, DLdataType x) {
	assert(pos);
	LTNode* newnode = ListBuy(x);
	LTNode* last = pos->prev;

	last->next = newnode;
	newnode->prev = last;

	newnode->next = pos;
	pos->prev = newnode;
}

void ListErase(LTNode* pos) {
	assert(pos);
	LTNode* last = pos->prev;
	LTNode* next = pos->next;
	free(pos);
	pos = NULL;
	last->next = next;
	next->prev = last;


}

void ListDestroy(LTNode* phead) {
	assert(phead);

	LTNode* current = phead->next;
	while (current != phead) {
		LTNode* temp = current;
		current = current->next;
		free(temp);
	}

	free(phead);
}