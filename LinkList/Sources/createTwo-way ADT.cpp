#include"head.h"
Node2* creat_ADT2(void) {
	//����һ���¿ռ��ͷ�ڵ�
	Node2* headnode = (Node2*)malloc(sizeof(Node2));
	headnode->prior = NULL;
	//���ñ���ָ���������������δ���
	Node2* current = headnode;
	Node2* tmp;
	int i;//���ڽ��մ����Ľڵ��ֵ
	int a = 1;//���ڼ�¼�ڵ����
	int flag=1;//�����ж��Ƿ��������
	while (flag != -1) {
		printf("�������%d���ڵ��ֵ\n",a);
		scanf_s("%d", &i);
		current->i = i;
		printf("��%d���ڵ㴴�����,��������ϣ�������-1����������1\n", a);
		scanf_s("%d", &flag);
		a++;//�ڵ������һ
		//Ϊ��һ�ڵ㿪���¿ռ�
		Node2* newnode = (Node2*)malloc(sizeof(Node2));
		current->next = newnode;//���Ӹտ��ٵ��½ڵ�
		tmp = current;
		newnode->prior = current;//���¿��ٽڵ��ǰ��ָ��ָ����һ�ڵ�
		current = newnode;//����ָ������һ���ڵ�
	}
	tmp->next = NULL;
	free(current);
	printf("˫���������\n");
	return headnode;
}