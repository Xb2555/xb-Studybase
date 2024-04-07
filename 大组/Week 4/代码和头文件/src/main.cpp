#include"binary_sort_tree1.h"
int main() {
	//首先初始化一个空树
	BinarySortTreePtr root = (BinarySortTreePtr)malloc(sizeof(NodePtr));
	if (BST_init(root)) {
		printf("初始化成功\n");
	}
	int a=0;
	ElemType data=0;
	do {
		printf("\n");
		printf("1.插入新节点  2.删除节点  3.查找是否存在节点 4.前序遍历 5.中序遍历 6.后序遍历 7.层序遍历 8.退出\n");
		scanf_s("%d", &a);
		switch (a) {
		case 1:
			printf("enter number\n");
			scanf_s("%d", &data);
			if (BST_insert(root, data)) {
				printf("插入成功\n");
			}
			else {
				printf("插入失败\n");
			}
			break;
		case 2:
			printf("请输入要删除的节点\n");
			scanf_s("%d", &data);
			if (BST_delete(root->root, data)) {
				printf("删除成功\n");
			}
			else {
				printf("删除失败\n");
			}
			break;
		case 3:
			printf("请输入查找的元素值\n");
			scanf_s("%d", &data);
			if (BST_search(root->root, data)) {
				printf("存在\n");
			}
			else {
				printf("不存在\n");
			}
			break;
		case 4:
			printf("1.递归版  2.非递归版\n");
			scanf_s("%d", &a);
			switch (a) {
			case 1:
				if (!BST_preorderR(root->root)) {
					printf("遍历失败\n");
				}
				break;
			case 2:
				if (!BST_preorderI(root->root)) {
					printf("遍历失败\n");
				}
				break;
			}
			break;
		case 5:
			printf("1.递归版  2.非递归版\n");
			scanf_s("%d", &a);
			switch (a) {
			case 1:
				if (!BST_inorderR(root->root)) {
					printf("遍历失败\n");
				}
				break;
			case 2:
				if (!BST_inorderI(root->root)) {
					printf("遍历失败\n");
				}
				break;
			}
			break;
		case 6:
			printf("1.递归版  2.非递归版\n");
			scanf_s("%d", &a);
			switch (a) {
			case 1:
				if (!BST_postorderR(root->root)) {
					printf("遍历失败\n");
				}
				break;
			case 2:
				if (!BST_postorderI(root->root)) {
					printf("遍历失败\n");
				}
				break;
			}
			break;
		case 7:
			if (!BST_levelOrder(root->root)) {
				printf("遍历失败\n");
			}
			break;
		case 8:
			exit(0);
			break;
		}
	} while (a <= 7);
}