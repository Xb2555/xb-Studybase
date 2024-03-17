//此函数用于找到单链表的中间节点
#include"head.h"
void findmid(Node* node) {
	//先判断是否为空链表或单节点和只有两个节点
	if (node == NULL) {
		printf("请先创建单链表\n");
	}
	else if(node->next==NULL||node->next->next==NULL) {
		printf("中间节点为%d", node->i);
	}
	else {
		//采用快慢指针法
		Node* fast = node;
		Node* slow = node;
		while (fast->next!= NULL) {
			fast = fast->next->next;
			slow = slow->next;
		}
		printf("中间节点为%d", slow->i);
	}
}