#include"head.h"
//�ú������ڱ���������
void pre_node(Node*node) {
	if (node == NULL) {
		printf("��δ�����������ȴ���һ������\n");
	}
	Node* curr = node;//���õ�ָ�����
	while (curr) {
		printf("%d  ", curr->i);//��ӡ�ڵ�ֵ
		curr = curr->next;
	}
	printf("\n");
}
//����˫����
void pre_node2(Node2* node) {
	if (node == NULL) {
		printf("��δ�����������ȴ���һ������\n");
	}
	Node2* curr = node;//���õ�ָ�����
	while (curr) {
		printf("%d  ", curr->i);//��ӡ�ڵ�ֵ
		curr = curr->next;
	}
	printf("\n");
}