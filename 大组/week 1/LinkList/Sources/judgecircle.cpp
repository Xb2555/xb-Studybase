#include"head.h"
//此函数用于判断链表是否成环
void judgecircle(Node2* node) {
	if (node == NULL) {
		printf("空链表\n");
	}
	//快慢指针法
	Node2* fast = node;
	Node2* slow = node;
	while (fast!= NULL ) {
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast) {
			printf("成环\n");
			break;
		}
	}
	printf("不成环\n");
}