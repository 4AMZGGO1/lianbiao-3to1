#include "Seqlist.h"

void SeqListInit(SL* ps)//��ʼ��
{
	ps->a = NULL;  //ps->a ==  *(ps).a
	ps->size = ps->capacity = 0;
}

void SLCheckCapacity(SL* ps) {   //�������
	if (ps->size == ps->capacity) {   //Ҫôû�г�ʼ����Ҫô����
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;;//���capa��0����ֵ4���������ݶ���
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newcapacity * sizeof(SLDataType));
		if (tmp == NULL) {
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}


void SeqListPushBack(SL* ps, SLDataType x)//β��
{
	SLCheckCapacity(ps);   //�ռ䲻�������
	//�ռ��㹻�����
	ps->a[ps->size] = x;  //a[size],size��Ŀǰ�洢�Ķ�������
	ps->size++;  //�±��1
}

void SeqListPrint(SL* ps) //��ӡ
{
	for (int i = 0; i < ps->size; ++i) {
		printf(" %d", ps->a[i]);
	}
	printf("\n");
}

void SeqListDestory(SL* ps) {    //���ٿռ�
	free(ps->a);  //��free���ÿ�
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

void SeqListPopBack(SL* ps) {
	if (ps->size == 0) {
		// �б�Ϊ�գ��������򷵻�
		// ���ߣ������ѡ�񲻽����κβ���������Ĭ�غ����������
		return;
	}

	ps->size--;
	// ��ѡ�أ������Ҫ���Ԫ�ص�ֵ�����Խ����һ��Ԫ�ظ�Ϊ0
	// ps->a[ps->size] = 0;
}

void SeqListPushFront(SL* ps, SLDataType x)//ͷ��
{
	SLCheckCapacity(ps);  //SeqListPushFront�Ѿ�����������SL������ֱ����ps
	int end = ps->size - 1;
	while (end >= 0) {
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}

void SeqListPopFront(SL* ps)//ͷɾ
{
	assert(ps->size > 0); //�ڱ���ʱ���ж��Լ�飬��ȷ��˳��������ٴ���һ��Ԫ�أ�size > 0����
	int begin = 1;
	while (begin < ps->size) {
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}
	ps->size--;
}

int SeqListFind(SL* ps, SLDataType x) {
	for (int i = 0; i < ps->size; i++) {
		if (ps->a[i] == x) {
			return i;  //�����±�
		}
	}
	return -1;
}

void SLInsert(SL* ps, int pos, SLDataType x) {   //�м���룬Ų������
	/*if (pos > ps->size || pos < 0) {
		printf("pos error");
		return;
	}*/
	assert(pos < ps->size || pos >= 0);   //�����������ֹ
	void SLCheckCapacity(ps);
	int end = ps->size - 1;
	//Ų������
	while (end >= pos) {   //��pos��λ�ÿ�ʼ��ÿ��λ������ƶ�
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}

void SeqListDelete(SL* ps, int pos) {
	assert(pos >= 0 && pos < ps->size);
	int begin = pos + 1;
	while (begin < ps->size) {
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}
	ps->size--;
}

void PrintMenu() {
	printf("**********�˵�**********\n");
	printf("1. ��ʼ��\n");
	printf("2. β��\n");
	printf("3. ͷ��\n");
	printf("4. βɾ\n");
	printf("5. ͷɾ\n");
	printf("6. ����\n");
	printf("7. �м����\n");
	printf("8. ɾ��ָ��λ��Ԫ��\n");
	printf("9. ��ӡ˳���\n");
	printf("0. �˳�\n");
	printf("*************************\n");
}