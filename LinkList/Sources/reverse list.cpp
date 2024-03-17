//此函数用于反转链表
#include"head.h"
//递归方法实现：
Node* reverse1(Node* node) {
	if (node == NULL || node->next == NULL) {
		return node;
	}
	Node* newhead = reverse1(node->next);
	node->next->next = node;//使第n+1个节点指向第n个节点
	node->next = NULL;//置空节点，防止产生环
	return newhead;
}
//迭代方法实现
Node* reverse2(Node*node) {
	if (node == NULL || node->next == NULL) {
		return node;
	}
	//开辟一个新的空链表
	Node* newhead = (Node*)malloc(sizeof(Node));
	//利用指针遍历链表依次将节点插入新链表中
	newhead->next = NULL;
	Node* tmp = newhead;
	Node* cur = node;
	while (cur) {
		Node*tmp2 = tmp->next;//用于存放tmp下一节点的地址
		//将cur所指节点插入tmp与tmp2所指节点之间
		tmp->next = cur;
		cur = cur->next;
		tmp->next->next = tmp2;
	}
	return tmp->next;
}