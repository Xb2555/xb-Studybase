#include <stdio.h>
#include<stdlib.h>
#include "head.h"
Node* head1;
Node2* head2;
int main() {
	int a;//用于判断选择结果
	do {
		system("cls");
		menu();
		scanf_s("%d",&a);
		system("cls");
		switch (a) {
		case 1:
			head1=create_adt();//创建一个单链表
			system("pause");
			break;
		case 2:
			head2=creat_ADT2();//创建一个双链表
			system("pause");
			break;
		case 3:
			pre_node(exchange1(head1));//单链表的奇偶转换
			system("pause");
			break;
		case 4:
			findmid(head1);//找到中间节点
			system("pause");
			break;
		case 5:
			judgecircle(head2);//判断是否成环
			system("pause");
			break;
		case 6:
			menu2();
			int b;
			scanf_s("%d", &b);
			switch (b) {
			case 1:
				pre_node(reverse1(head1));//递归反转链表
				system("pause");
				break;
			case 2:
				pre_node(reverse2(head1));//迭代反转链表
				system("pause");
				break;
			}
			break;
		case 7:
			//销毁链表
			menu4();
			int c;
			scanf_s("%d", &c);
			switch (c) {
			case 1:
				release(head1);
				break;
			case 2:
				release2(head2);
				break;
			}
			printf("链表销毁完成\n");
			system("pause");
			break;
		case 8:
			menu3();
			int d;
			scanf_s("%d", &d);
			switch (d)
			{
			case 1:
				pre_node(head1);
				system("pause");
				break;
			case 2:
				pre_node2(head2);
				system("pause");
				break;
			}
			break;
		}
	} while (a <= 8);
}