#include"head.h"
//�˺������ڵ��������ż����
Node* exchange1 (Node*node) {
	//�����ж��Ƿ�Ϊ�����ڵ�������
	if (node->next == NULL||node==NULL) {
		return node;
	}
	//�����µĽڵ�
	Node*newhead = (Node*)malloc(sizeof(Node));
	newhead->next = node;
	//����˫ָ������ɽڵ�ĵ���
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