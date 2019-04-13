#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack {
	int *a;			//支持动态增长的数组
	int top;		//栈顶
	int capacity;	//数组容量
}Stack;

//1.初始化栈
void StackInit(Stack* ps) {
	//全部置0
	ps->top = 0;
}

//2.销毁栈
int * StackDestory(Stack* ps) {
	free(ps->a);
	ps->a = NULL;	
	return ps->a;
}

//3.入栈
void StackPush(Stack* ps, int x) {
	//让新加入的元素变为栈顶元素
	ps->a[ps->top] = x;
	ps->top++;
}

//4.出栈
void StackPop(Stack* ps) {
	//让栈顶减1即可
	ps->top--;
}

//5.查看栈顶元素
int StackTop(Stack* ps) {
	int a = ps->top-1;
	return ps->a[a];
}

//6.查看元素个数
int memNum(Stack* ps) {
	return ps->top;
}

//7.判断栈是否为空

bool stackEmpty(Stack* ps) {
	return ps->top == 0;
}

//打印栈内元素
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
	//入栈
	StackPush(&ps, 10);
	StackPush(&ps, 200);
	StackPush(&ps, 30);
	StackPush(&ps, 40);
	//查看栈顶元素
	int top = StackTop(&ps);
	printf("栈顶元素是%d\n", top);
	//查看栈内元素个数
	int num = memNum(&ps);
	printf("栈内有%d个元素！！！\n", ps.top);
	//判断栈是否为空
	bool empty = stackEmpty(&ps);
	if (empty) {
		printf("栈为空！！！\n");
	}
	else {
		printf("栈非空！！！\n");
	}
	//打印栈内元素
	print(&ps);
	//出栈
	printf("\n\n");
	StackPop(&ps, ps.a[top-1]);
	print(&ps);
	//销毁栈
	int* result = StackDestory(&ps);
	if (result == NULL) {
		printf("销毁成功！！！\n");
	}
	else {
		printf("销毁失败！！！\n");
	}
}



int main() {
	test();
	system("pause");
	return 0;
}