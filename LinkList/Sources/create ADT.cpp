//此函数用于创建一个单链表
#include "head.h"
Node* create_adt(void) {
	//开辟一个新空间给头节点
	Node* headnode = (Node*)malloc(sizeof(Node));
	//利用遍历指针完成链表结点的依次创建
	Node* current = headnode;
	Node* tmp;
	int i;//用于接收创建的节点的值
	int a=1;//用于记录节点个数
	int flag=1;//用于判断是否结束创建
	while (flag != -1) {
		printf("请输入第%d个节点的值\n",a);
		scanf_s("%d", &i);
		current->i = i;
		printf("第%d个节点创建完成,若创建完毕，则输入-1,否则输入1\n", a);
		scanf_s("%d", &flag);
		a++;//节点个数加一
		//为下一节点开辟新空间
		Node* newnode = (Node*)malloc(sizeof(Node));
		current->next = newnode;//连接刚开辟的新节点
		tmp = current;
		current = newnode;//遍历指针下移一个节点
	}
	tmp->next = NULL;
	free(current);
	printf("单链表创建完成\n");
	return headnode;
}
