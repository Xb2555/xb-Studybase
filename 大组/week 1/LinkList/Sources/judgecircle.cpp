#include"head.h"
//�˺��������ж������Ƿ�ɻ�
void judgecircle(Node2* node) {
	if (node == NULL) {
		printf("������\n");
	}
	//����ָ�뷨
	Node2* fast = node;
	Node2* slow = node;
	while (fast!= NULL ) {
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast) {
			printf("�ɻ�\n");
			break;
		}
	}
	printf("���ɻ�\n");
}