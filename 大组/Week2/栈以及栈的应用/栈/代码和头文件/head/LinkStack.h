#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
typedef enum Status 
{
    ERROR = 0, 
	SUCCESS = 1
} Status;

typedef int ElemType;

typedef  struct StackNode
{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;



//��ջ
Status initLStack(LinkStack*s) {//��ʼ��ջ
		s->top = (LinkStackPtr)malloc(sizeof(StackNode));
		s->top->next = NULL;
		s->count = 0;
		return SUCCESS;
}
Status isEmptyLStack(LinkStack* s) {//�ж�ջ�Ƿ�Ϊ��
	if (s->top == NULL) {
		return SUCCESS;
	}
	else {
		return ERROR;
	}
}
Status getTopLStack(LinkStack* s, ElemType e) {//�õ�ջ��Ԫ��
	if (s->top == NULL) {
		return ERROR;
	}
	else {
		e = s->top->data;
		return SUCCESS;
	}
}
Status clearLStack(LinkStack* s) {//���ջ
	if (s->top == NULL) {
		return ERROR;
		}
	else
	{
		s->top = NULL;
		return SUCCESS;
	}
}
Status destroyLStack(LinkStack* s) {//����ջ
	if (s->top == NULL) {
		return ERROR;
	}
	LinkStack* cur = s;
	LinkStackPtr p;
	while (cur->top) {
		p = cur->top;
		cur->top = cur->top->next;
		free(p);
		cur->count--;
	}
	return SUCCESS;
}
Status LStackLength(LinkStack* s, int* length) {//���ջ����
	if (s->top == NULL) {
		return ERROR;
	}
	else {
		int sum = 0;
		while (s->top->next) {
			sum++;
			s->top = s->top->next;
		}
		*length = sum;
		return SUCCESS;
	}

}
Status pushLStack(LinkStack* s, ElemType data) {//��ջ
	if (s->top == NULL) {
		return ERROR;
	}
	else {
		LinkStackPtr s2 = (LinkStackPtr)malloc(sizeof(StackNode));
		s2->next = s->top;
		s->top = s2;
		s2->data = data;
		return SUCCESS;
	}
}
Status popLStack(LinkStack* s, ElemType* data) {//��ջ
	if (s->top == NULL) {
		return ERROR;
	}
	else {
		*data = s->top->data;
		s->count--;
		s->top = s->top->next;
		return SUCCESS;
	}
}


#endif 
