#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//����������,ֻ��int��������
typedef struct node {
	int i;
	struct node* next;
}Node;
//˫����ṹ
typedef struct node2 {
	int i;
	struct node2* next;
	struct node2* prior;
}Node2;
//����Ϊ����������
//�˵�
void menu();
void menu2();
void menu3();
void menu4();
Node* create_adt(void);//����������
Node2* creat_ADT2(void);//����˫������
void pre_node(Node* node);//����������
void pre_node2(Node2* node);//����˫������
Node* exchange1(Node* node);//���������ż����
void judgecircle(Node2* node);//�жϳɻ�
Node* reverse1(Node* node);//�ݹ鷴ת����
Node* reverse2(Node* node);//������ת����
void findmid(Node* node);//�ҵ��������м�ڵ�
//�ͷ�����
void release(Node* node);
void release2(Node2* node);