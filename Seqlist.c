#include "Seqlist.h"

void SeqListInit(SL* ps)//初始化
{
	ps->a = NULL;  //ps->a ==  *(ps).a
	ps->size = ps->capacity = 0;
}

void SLCheckCapacity(SL* ps) {   //检查增容
	if (ps->size == ps->capacity) {   //要么没有初始化，要么满了
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;;//如果capa是0，赋值4，不是扩容二倍
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newcapacity * sizeof(SLDataType));
		if (tmp == NULL) {
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}


void SeqListPushBack(SL* ps, SLDataType x)//尾插
{
	SLCheckCapacity(ps);   //空间不足就扩容
	//空间足够的情况
	ps->a[ps->size] = x;  //a[size],size是目前存储的多少数据
	ps->size++;  //下表加1
}

void SeqListPrint(SL* ps) //打印
{
	for (int i = 0; i < ps->size; ++i) {
		printf(" %d", ps->a[i]);
	}
	printf("\n");
}

void SeqListDestory(SL* ps) {    //销毁空间
	free(ps->a);  //先free再置空
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

void SeqListPopBack(SL* ps) {
	if (ps->size == 0) {
		// 列表为空，处理错误或返回
		// 或者，你可以选择不进行任何操作，并静默地忽略这个操作
		return;
	}

	ps->size--;
	// 可选地，如果需要清除元素的值，可以将最后一个元素赋为0
	// ps->a[ps->size] = 0;
}

void SeqListPushFront(SL* ps, SLDataType x)//头插
{
	SLCheckCapacity(ps);  //SeqListPushFront已经定义类型名SL，这里直接用ps
	int end = ps->size - 1;
	while (end >= 0) {
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}

void SeqListPopFront(SL* ps)//头删
{
	assert(ps->size > 0); //在编译时进行断言检查，以确保顺序表中至少存在一个元素（size > 0）。
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
			return i;  //返回下标
		}
	}
	return -1;
}

void SLInsert(SL* ps, int pos, SLDataType x) {   //中间插入，挪动数据
	/*if (pos > ps->size || pos < 0) {
		printf("pos error");
		return;
	}*/
	assert(pos < ps->size || pos >= 0);   //真继续，假中止
	void SLCheckCapacity(ps);
	int end = ps->size - 1;
	//挪动数据
	while (end >= pos) {   //从pos的位置开始，每个位置向后移动
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
	printf("**********菜单**********\n");
	printf("1. 初始化\n");
	printf("2. 尾插\n");
	printf("3. 头插\n");
	printf("4. 尾删\n");
	printf("5. 头删\n");
	printf("6. 查找\n");
	printf("7. 中间插入\n");
	printf("8. 删除指定位置元素\n");
	printf("9. 打印顺序表\n");
	printf("0. 退出\n");
	printf("*************************\n");
}