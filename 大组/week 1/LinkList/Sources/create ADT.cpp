//�˺������ڴ���һ��������
#include "head.h"
Node* create_adt(void) {
	//����һ���¿ռ��ͷ�ڵ�
	Node* headnode = (Node*)malloc(sizeof(Node));
	//���ñ���ָ���������������δ���
	Node* current = headnode;
	Node* tmp;
	int i;//���ڽ��մ����Ľڵ��ֵ
	int a=1;//���ڼ�¼�ڵ����
	int flag=1;//�����ж��Ƿ��������
	while (flag != -1) {
		printf("�������%d���ڵ��ֵ\n",a);
		scanf_s("%d", &i);
		current->i = i;
		printf("��%d���ڵ㴴�����,��������ϣ�������-1,��������1\n", a);
		scanf_s("%d", &flag);
		a++;//�ڵ������һ
		//Ϊ��һ�ڵ㿪���¿ռ�
		Node* newnode = (Node*)malloc(sizeof(Node));
		current->next = newnode;//���Ӹտ��ٵ��½ڵ�
		tmp = current;
		current = newnode;//����ָ������һ���ڵ�
	}
	tmp->next = NULL;
	free(current);
	printf("�����������\n");
	return headnode;
}
