#include"head.h"
//该函数用于遍历单链表
void pre_node(Node*node) {
	if (node == NULL) {
		printf("还未创建链表，请先创建一个链表\n");
	}
	Node* curr = node;//利用单指针遍历
	while (curr) {
		printf("%d  ", curr->i);//打印节点值
		curr = curr->next;
	}
	printf("\n");
}
//遍历双链表
void pre_node2(Node2* node) {
	if (node == NULL) {
		printf("还未创建链表，请先创建一个链表\n");
	}
	Node2* curr = node;//利用单指针遍历
	while (curr) {
		printf("%d  ", curr->i);//打印节点值
		curr = curr->next;
	}
	printf("\n");
}