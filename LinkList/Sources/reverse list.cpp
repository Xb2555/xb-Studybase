//�˺������ڷ�ת����
#include"head.h"
//�ݹ鷽��ʵ�֣�
Node* reverse1(Node* node) {
	if (node == NULL || node->next == NULL) {
		return node;
	}
	Node* newhead = reverse1(node->next);
	node->next->next = node;//ʹ��n+1���ڵ�ָ���n���ڵ�
	node->next = NULL;//�ÿսڵ㣬��ֹ������
	return newhead;
}
//��������ʵ��
Node* reverse2(Node*node) {
	if (node == NULL || node->next == NULL) {
		return node;
	}
	//����һ���µĿ�����
	Node* newhead = (Node*)malloc(sizeof(Node));
	//����ָ������������ν��ڵ������������
	newhead->next = NULL;
	Node* tmp = newhead;
	Node* cur = node;
	while (cur) {
		Node*tmp2 = tmp->next;//���ڴ��tmp��һ�ڵ�ĵ�ַ
		//��cur��ָ�ڵ����tmp��tmp2��ָ�ڵ�֮��
		tmp->next = cur;
		cur = cur->next;
		tmp->next->next = tmp2;
	}
	return tmp->next;
}