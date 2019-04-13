#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack {
	int *a;			//֧�ֶ�̬����������
	int top;		//ջ��
	int capacity;	//��������
}Stack;

//1.��ʼ��ջ
void StackInit(Stack* ps) {
	//ȫ����0
	ps->top = 0;
}

//2.����ջ
int * StackDestory(Stack* ps) {
	free(ps->a);
	ps->a = NULL;	
	return ps->a;
}

//3.��ջ
void StackPush(Stack* ps, int x) {
	//���¼����Ԫ�ر�Ϊջ��Ԫ��
	ps->a[ps->top] = x;
	ps->top++;
}

//4.��ջ
void StackPop(Stack* ps) {
	//��ջ����1����
	ps->top--;
}

//5.�鿴ջ��Ԫ��
int StackTop(Stack* ps) {
	int a = ps->top-1;
	return ps->a[a];
}

//6.�鿴Ԫ�ظ���
int memNum(Stack* ps) {
	return ps->top;
}

//7.�ж�ջ�Ƿ�Ϊ��

bool stackEmpty(Stack* ps) {
	return ps->top == 0;
}

//��ӡջ��Ԫ��
void print(Stack* ps) {
	for (int i = 0; i < ps->top; ++i) {
		printf("%d   ", ps->a[i]);
	}
}

void test() {
	Stack ps;
	ps.capacity = 10;
	ps.a = (int*)malloc(sizeof(int)*ps.capacity);
	StackInit(&ps);
	//��ջ
	StackPush(&ps, 10);
	StackPush(&ps, 200);
	StackPush(&ps, 30);
	StackPush(&ps, 40);
	//�鿴ջ��Ԫ��
	int top = StackTop(&ps);
	printf("ջ��Ԫ����%d\n", top);
	//�鿴ջ��Ԫ�ظ���
	int num = memNum(&ps);
	printf("ջ����%d��Ԫ�أ�����\n", ps.top);
	//�ж�ջ�Ƿ�Ϊ��
	bool empty = stackEmpty(&ps);
	if (empty) {
		printf("ջΪ�գ�����\n");
	}
	else {
		printf("ջ�ǿգ�����\n");
	}
	//��ӡջ��Ԫ��
	print(&ps);
	//��ջ
	printf("\n\n");
	StackPop(&ps, ps.a[top-1]);
	print(&ps);
	//����ջ
	int* result = StackDestory(&ps);
	if (result == NULL) {
		printf("���ٳɹ�������\n");
	}
	else {
		printf("����ʧ�ܣ�����\n");
	}
}



int main() {
	test();
	system("pause");
	return 0;
}