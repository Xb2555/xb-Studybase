//�˺��������ҵ���������м�ڵ�
#include"head.h"
void findmid(Node* node) {
	//���ж��Ƿ�Ϊ������򵥽ڵ��ֻ�������ڵ�
	if (node == NULL) {
		printf("���ȴ���������\n");
	}
	else if(node->next==NULL||node->next->next==NULL) {
		printf("�м�ڵ�Ϊ%d", node->i);
	}
	else {
		//���ÿ���ָ�뷨
		Node* fast = node;
		Node* slow = node;
		while (fast->next!= NULL) {
			fast = fast->next->next;
			slow = slow->next;
		}
		printf("�м�ڵ�Ϊ%d", slow->i);
	}
}