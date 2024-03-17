#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//基础单链表,只有int类型数据
typedef struct node {
	int i;
	struct node* next;
}Node;
//双链表结构
typedef struct node2 {
	int i;
	struct node2* next;
	struct node2* prior;
}Node2;
//以下为函数的声明
//菜单
void menu();
void menu2();
void menu3();
void menu4();
Node* create_adt(void);//创建单链表
Node2* creat_ADT2(void);//创建双向链表
void pre_node(Node* node);//遍历单链表
void pre_node2(Node2* node);//遍历双向链表
Node* exchange1(Node* node);//单链表的奇偶调换
void judgecircle(Node2* node);//判断成环
Node* reverse1(Node* node);//递归反转链表
Node* reverse2(Node* node);//迭代反转链表
void findmid(Node* node);//找到单链表中间节点
//释放链表
void release(Node* node);
void release2(Node2* node);