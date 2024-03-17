//此函数用于释放链表
#include"head.h"
//释放单链表
void release(Node*node) {
	Node* tmp;
	while (node) {
		tmp = node;
		node = node->next;
		free(tmp);
		tmp->next = NULL;
	}
}
//释放双链表
void release2(Node2* node) {
	Node2* tmp;
	while (node) {
		tmp = node;
		node = node->next;
		free(tmp);
		tmp->next = NULL;
	}
}