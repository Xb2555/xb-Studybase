//�˺��������ͷ�����
#include"head.h"
//�ͷŵ�����
void release(Node*node) {
	Node* tmp;
	while (node) {
		tmp = node;
		node = node->next;
		free(tmp);
		tmp->next = NULL;
	}
}
//�ͷ�˫����
void release2(Node2* node) {
	Node2* tmp;
	while (node) {
		tmp = node;
		node = node->next;
		free(tmp);
		tmp->next = NULL;
	}
}