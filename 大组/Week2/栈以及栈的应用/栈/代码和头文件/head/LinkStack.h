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



//Á´Õ»
Status initLStack(LinkStack*s) {//³õÊ¼»¯Õ»
		s->top = (LinkStackPtr)malloc(sizeof(StackNode));
		s->top->next = NULL;
		s->count = 0;
		return SUCCESS;
}
Status isEmptyLStack(LinkStack* s) {//ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
	if (s->top == NULL) {
		return SUCCESS;
	}
	else {
		return ERROR;
	}
}
Status getTopLStack(LinkStack* s, ElemType e) {//µÃµ½Õ»¶¥ÔªËØ
	if (s->top == NULL) {
		return ERROR;
	}
	else {
		e = s->top->data;
		return SUCCESS;
	}
}
Status clearLStack(LinkStack* s) {//Çå¿ÕÕ»
	if (s->top == NULL) {
		return ERROR;
		}
	else
	{
		s->top = NULL;
		return SUCCESS;
	}
}
Status destroyLStack(LinkStack* s) {//Ïú»ÙÕ»
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
Status LStackLength(LinkStack* s, int* length) {//¼ì²âÕ»³¤¶È
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
Status pushLStack(LinkStack* s, ElemType data) {//ÈëÕ»
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
Status popLStack(LinkStack* s, ElemType* data) {//³öÕ»
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
