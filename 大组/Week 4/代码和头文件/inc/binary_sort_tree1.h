#pragma once
//
// Created by eke_l on 2021/4/21.
//

#include <cstddef>
#include <malloc.h>
#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>
#ifndef BINARYSORTTREE_BINARY_SORT_TREE_H
#define BINARYSORTTREE_BINARY_SORT_TREE_H

#define true 1
#define false 0
#define succeed 1
#define failed 0
#define Status int
#define exited 1;
#define unexited 0;
#define MAX 200;
typedef int ElemType;

typedef struct Node {
    ElemType value;
    struct Node* left, * right;
}Node, * NodePtr;

typedef struct BinarySortTree {
    NodePtr root;
} BinarySortTree, * BinarySortTreePtr;

//��ӡ�ڵ�
void displayElem(NodePtr p) {
    printf("%d  ", p->value);
}
/*
���к���
*/
//���нṹ
typedef NodePtr Type;
typedef struct QueueNode {
    struct QueueNode* next;
    Type data;
}Qnode;
typedef struct Queue {
    Qnode* head;
    Qnode* tail;
    int size;
}Queue;

//��ʼ������
void Queue_init(Queue* pq) {
    assert(pq);
    pq->head = pq->tail = NULL;
    pq->size = 0;
}
//�п�
bool Queue_empty(Queue* pq)
{
    assert(pq);
    return pq->head == NULL && pq->tail == NULL;
}

//�����
void Queue_push(Queue* pq, Type x) {
    assert(pq);
    Qnode* newnode = (Qnode*)malloc(sizeof(Qnode));
    if (newnode == NULL) {
        perror("malloc");
        printf("error");
    }
    newnode->data = x;
    newnode->next = NULL;
    if (pq->tail == NULL) {
        pq->head = pq->tail = newnode;
    }
    else {
        pq->tail->next = newnode;
        pq->tail = newnode;
    }
    pq->size++;
}
//������
void Queue_pop(Queue* pq)
{
    assert(pq);
    assert(!Queue_empty(pq));
    if (pq->head->next == NULL)
    {
        free(pq->head);
        pq->head = pq->tail = NULL;
    }
    else
    {
        Qnode* del = pq->head;
        pq->head = pq->head->next;
        free(del);
        del = NULL;
    }
    pq->size--;
}

//ȡ����Ԫ��
Type Queue_front(Queue* pq)
{
    assert(pq);
    assert(!Queue_empty(pq));
    return pq->head->data;
}

/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
Status BST_init(BinarySortTreePtr root) {
    root->root=NULL;
    return succeed;
}

/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
Status BST_search(NodePtr root, ElemType data) {
    if (root == NULL) return failed;
    if (root->value == data) {
        return exited;
    }
    else if (data < root->value) {//С�ڸýڵ㣬��ýڵ���߱���
        BST_search(root->left, data);
    }
    else if (data > root->value) {//���ڸýڵ㣬���ұ���
        BST_search(root->right, data);
    }
}

/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
Status BST_insert(BinarySortTreePtr root,ElemType data){
    NodePtr p = root->root;
    NodePtr q = NULL;
    while (p != NULL) {
        if (p->value == data) {
            return failed;
        }
        else if (p->value > data) {
            q = p;
            p = p->left;
        }
        else {
            q = p;
            p = p->right;
        }
    }
    p = (NodePtr)malloc(sizeof(Node));
    p->value = data;
    p->left = NULL;
    p->right = NULL;
    if (!q) {
        root->root = p;
    }
    else if (q->value > data) {
        q->left = p;
    }
    else q->right = p;
    return succeed;
}

/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
Status BST_delete(NodePtr root, ElemType data) {
    NodePtr p, q, s, sq;//pָ���ɾ��㣬qָ��p��˫�׽�㣬sָ�����ҷǿ�ʱ���������Ҳ�Ҷ�ڵ�
    p = q = root;
    //��ֵΪkey�Ľ�㣬��BST���� 
    while (p != NULL)
    {
        if (data == p->value)
        {
            break;
        }
        else if (data < p->value)
        {
            q = p;
            p = p->left;
        }
        else
        {
            q = p;
            p = p->right;
        }
    }
    if (p == NULL) //��ʱ�ڶ�����������û���ҵ�Ŀ���� 
    {
        return failed;
    }
    else//�ҵ�Ŀ���� 
    {
        //1�������Ŀ��������Ҷ����ɾ����Ҷ
        if (p->left == NULL && p->right == NULL)
        {
            if (p->value == root->value)
            {
                root->value = 0;
            }
            else
            {
                if (p->value < q->value)
                {
                    q->left = NULL;
                }
                else
                {
                    q->right = NULL;
                }
                free(p);
            }
        }

        //2��ɾ��ֻ���������Ľ��
        else if (p->left != NULL && p->right == NULL)
        {
            //�����Ǵ�ɾ���Ľ�� 
            if (p->value == root->value) //��ǰ�Ĳ���T�ں����ڲ������Ըı��ַ ��ֻ�ܸı�T��ַ�е�ֵ
            {
                q = root->left;
                root->value = q->value;
                root->left = q->left;
                free(q);
            }
            else
            {
                if (p->value < q->value)
                {
                    q->left = p->left;
                }
                else
                {
                    q->right = p->left;
                }
                free(p);
            }
        }
        //3��ɾ��ֻ���������Ľ��
        else if (p->left == NULL && p->right != NULL)
        {
            //�����Ǵ�ɾ���Ľ��
            if (p->value == root->value)//��ǰ�Ĳ���T�ں����ڲ������Ըı��ַ ��ֻ�ܸı�T��ַ�е�ֵ 
            {
                q = root->right;
                root->value = q->value;
                root->right = q->right;
                free(q);
            }
            else
            {
                if (p->value < q->value)
                {
                    q->left = p->right;
                }
                else
                {
                    q->right = p->right;
                }
                free(p);
            }
        }
        //4��ɾ�����Ҿ��ǿյĽ�㣬��Ҫ�������������Ҳ�������Ҷ���߷���Ҷ 
        //   ��ʱ����ͬ��ǰ�洦����֧�Ľ�㣬ֻ��Ҫ��Ŀ����s��ֵ�滻��ɾ�����p��ֵ���� 
        else
        {
            //������p�������������Ҳ�Ľ�� 
            sq = p;
            s = p->left;
            while (s->right != NULL)
            {
                sq = s;
                s = s->right;
            }
            // 41��������Ҳ�������Ҷ,��s��ֵ��ֵ��p���� 
            if (s->left == NULL)
            {
                sq->right = NULL;//��s��˫�׽��sq���������ÿ� 
                p->value = s->value;
                free(s);//�ͷ����Ҳ����Ҷ�����ռ�Ŀռ� 
            }
            else//42�����Ҳ��㲻����Ҷ
            {
                // 421��s=p->LChild û��������,��ʱsq����ָ����p,��ֻ��Ҫ��s�����������ӵ�p������������ 
                if (sq->value == p->value)
                {
                    p->left = s->left;
                }
                // 422��p->LChild ��������
                else
                {
                    sq->right = s->left;
                }
                p->value = s->value;
                free(s);
            }
        }
    }
    return succeed;
}


/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderI(NodePtr root) {
    NodePtr stack[200], node;
    int top = -1;
    if (root == NULL) {
        return failed;
    }
    else {
        top++;
        stack[top] = root;
        while (top > -1) {
            node = stack[top--];
            displayElem(node);
            if (node->right != NULL) {//���ҽ�ջ
                stack[++top] = node->right;
            }
            if (node->left != NULL) {//�����ջ
                stack[++top] = node->left;
            }
        }
    }
    return succeed;
}

/**
 * BST preorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_preorderR(NodePtr root) {
    if (root) {
        displayElem(root);
        BST_preorderR(root->left);
        BST_preorderR(root->right);
        return succeed;
    }
    return failed;
}

/**
 * BST inorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderI(NodePtr root) {
    NodePtr stack[200], node;
    int top = 0;
    if (root == NULL) {
        return failed;
    }
    node = root;
    while (node != NULL || top > 0) {
        while (node != NULL) {
            stack[++top] = node;
            node = node->left;
        }
        node = stack[top--];
        displayElem(node);
        node = node->right;
    }
    return succeed;
}

/**
 * BST inorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_inorderR(NodePtr root) {
    if (root) {
        BST_inorderR(root->left);
        displayElem(root);
        BST_inorderR(root->right);
        return succeed;
    }
    return failed;
}

/**
 * BST postorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderI(NodePtr root) {
    if (root == NULL) {
        return failed;
    }
    NodePtr p = root;
    NodePtr stack[200];
    int num = 0;
    NodePtr have_visited = NULL;
    while (NULL != p || num > 0) {
        while (NULL != p) {
            stack[num++] = p;
            p = p->left;
        }
        p = stack[num - 1];
        if (NULL == p->right || have_visited == p->right) {
            displayElem(p);
            num--;
            have_visited = p;
            p = NULL;
        }
        else {
            p = p->right;
        }
    }
    return succeed;
}

/**
 * BST postorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_postorderR(NodePtr root) {
    if (root) {
        BST_postorderR(root->left);
        BST_postorderR(root->right);
        displayElem(root);
        return succeed;
    }
    return failed;
}

/**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
Status BST_levelOrder(NodePtr root) {
    Queue q;
    Queue_init(&q);
    if (root != NULL) {
        Queue_push(&q, root);
    }
    while (!Queue_empty(&q)) {
        NodePtr front = Queue_front(&q);
        Queue_pop(&q);
        printf("%d  ", front->value);
        //��һ�����
        if (front->left) {
            Queue_push(&q, front->left);

        }
        if (front->right) {
            Queue_push(&q, front->right);
        }
    }
    if (root == NULL) {
        return failed;
    }
}

#endif //BINARYSORTTREE_BINARY_SORT_TREE_H
