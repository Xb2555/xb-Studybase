#include"head.h"
//此函数用于单链表的奇偶调换
Node* exchange1 (Node*node) {
	//首先判断是否为单个节点或空链表
	if (node->next == NULL||node==NULL) {
		return node;
	}
	//创建新的节点
	Node*newhead = (Node*)malloc(sizeof(Node));
	newhead->next = node;
	//利用双指针来完成节点的调换
	Node* pre = newhead;
	Node* cur = newhead->next;
	while (cur != NULL && cur->next != NULL) {
		pre->next = cur->next;
		Node* tmp = cur->next->next;
		cur->next->next = cur;
		cur->next = tmp;
		pre = cur;
		cur = cur->next;
	}
	return newhead->next;
}