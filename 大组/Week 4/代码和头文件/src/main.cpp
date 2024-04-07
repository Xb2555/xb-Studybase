#include"binary_sort_tree1.h"
int main() {
	//���ȳ�ʼ��һ������
	BinarySortTreePtr root = (BinarySortTreePtr)malloc(sizeof(NodePtr));
	if (BST_init(root)) {
		printf("��ʼ���ɹ�\n");
	}
	int a=0;
	ElemType data=0;
	do {
		printf("\n");
		printf("1.�����½ڵ�  2.ɾ���ڵ�  3.�����Ƿ���ڽڵ� 4.ǰ����� 5.������� 6.������� 7.������� 8.�˳�\n");
		scanf_s("%d", &a);
		switch (a) {
		case 1:
			printf("enter number\n");
			scanf_s("%d", &data);
			if (BST_insert(root, data)) {
				printf("����ɹ�\n");
			}
			else {
				printf("����ʧ��\n");
			}
			break;
		case 2:
			printf("������Ҫɾ���Ľڵ�\n");
			scanf_s("%d", &data);
			if (BST_delete(root->root, data)) {
				printf("ɾ���ɹ�\n");
			}
			else {
				printf("ɾ��ʧ��\n");
			}
			break;
		case 3:
			printf("��������ҵ�Ԫ��ֵ\n");
			scanf_s("%d", &data);
			if (BST_search(root->root, data)) {
				printf("����\n");
			}
			else {
				printf("������\n");
			}
			break;
		case 4:
			printf("1.�ݹ��  2.�ǵݹ��\n");
			scanf_s("%d", &a);
			switch (a) {
			case 1:
				if (!BST_preorderR(root->root)) {
					printf("����ʧ��\n");
				}
				break;
			case 2:
				if (!BST_preorderI(root->root)) {
					printf("����ʧ��\n");
				}
				break;
			}
			break;
		case 5:
			printf("1.�ݹ��  2.�ǵݹ��\n");
			scanf_s("%d", &a);
			switch (a) {
			case 1:
				if (!BST_inorderR(root->root)) {
					printf("����ʧ��\n");
				}
				break;
			case 2:
				if (!BST_inorderI(root->root)) {
					printf("����ʧ��\n");
				}
				break;
			}
			break;
		case 6:
			printf("1.�ݹ��  2.�ǵݹ��\n");
			scanf_s("%d", &a);
			switch (a) {
			case 1:
				if (!BST_postorderR(root->root)) {
					printf("����ʧ��\n");
				}
				break;
			case 2:
				if (!BST_postorderI(root->root)) {
					printf("����ʧ��\n");
				}
				break;
			}
			break;
		case 7:
			if (!BST_levelOrder(root->root)) {
				printf("����ʧ��\n");
			}
			break;
		case 8:
			exit(0);
			break;
		}
	} while (a <= 7);
}