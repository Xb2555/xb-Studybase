#include "LQueue.h" 
#include<stdio.h>
#include<stdlib.h>
/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q){
	Q->front = (Node*)malloc(sizeof(Node));
	Q->rear = (Node*)malloc(sizeof(Node));
	Q->front = Q->rear = NULL;
	Q->length = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){
	Node* cur = Q->front;
	while (cur) {
		Node* next = cur->next;
		free(cur);
		cur = next;
	}
	Q->front = Q->rear = NULL;
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
	if (Q->front == NULL) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
int GetHeadLQueue(LQueue *Q){
	if (IsEmptyLQueue(Q) == TRUE) {
		return FALSE;
	}
	else {
		return Q->front->data;
	}
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
	int size = 0;
	Node* cur = Q->front;
	while (cur) {
		size++;
		cur = cur->next;
	}
	return size;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, int data){
    Node* N = (Node*)malloc(sizeof(Node));
    N->data = data;
    N->next = NULL;
    if (Q->rear == NULL) {
        Q->front = Q->rear = N;
    }
    else {
        Q->rear->next = N;
        Q->rear= N;
    }
    Q->length++;
    return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
	if (IsEmptyLQueue(Q) == TRUE) {
		return FALSE;
	}
	else {
        if (Q->front->next == NULL) {
            free(Q->front);
            Q->front = Q->rear = NULL;
        }
        else {
            Node* next = Q->front->next;
            free(Q->front);
            Q->front = next;
        }
        return TRUE;
	}
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
	Node* cur = Q->front;
	while (cur) {
		Node* next = cur->next;
		cur = NULL;
		cur = next;
	}
	Q->front = Q->rear = NULL;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
void TraverseLQueue(const LQueue *Q){
	Node* cur = Q->front;
	while (cur) {
		printf("%d  ", cur->data);
        cur = cur->next;
	}
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
 
 *  @notice      : None
 */
void LPrint(void *q){
	printf("%d", *(int*)q);
}
int main() {
	LQueue Q;
	int e;
    int e2;
	int a;
    int data;
    do {
        system("cls");
        printf("1.��ʼ������  2.���  3.����  4.�õ���ͷԪ��  5.���ӳ���  6.��ն�  7.���ٶ� 8.�ж϶��Ƿ�Ϊ��  9.��������\n");
        printf("������ѡ�\n");
        scanf_s("%d", &a);
        system("cls");
        switch (a) {
        case 1:
            InitLQueue(&Q);
            printf("��ʼ���ɹ�\n");
            system("pause");
            break;
        case 2:
            printf("������Ҫ��ӵ�����\n");
            scanf_s("%d",&e);
            if (EnLQueue(&Q,e)==TRUE) {
                printf("��ӳɹ�\n");
                system("pause");
            }
            else {
                printf("���ʧ��\n");
                system("pause");
            }
            break;
        case 3:
            if (DeLQueue(&Q)==TRUE) {
                printf("�ɹ�\n");
                system("pause");
            }
            else {
                printf("����ʧ��\n");
                system("pause");
            }
            break;
        case 4:
            if (GetHeadLQueue(&Q)!=FALSE) {
                printf("%d",GetHeadLQueue(&Q) );
                system("pause");
            }
            else {
                printf("ʧ��\n");
                system("pause");
            }
            break;
        case 5:
            data = LengthLQueue(&Q);
            printf("����Ϊ��%d\n", data);
            system("pause");
            break;
        case 6:
            ClearLQueue(&Q);
            printf("�ɹ�\n");
            system("pause");
            break;
        case 7:
            DestoryLQueue(&Q);
            printf("�ɹ�\n");
            system("pause");
            break;
        case 8:
            if (IsEmptyLQueue(&Q)==TRUE) {
                printf("�ǿն�\n");
                system("pause");
            }
            else {
                printf("���ǿն�\n");
                system("pause");
            }
            break;
        case 9:
            TraverseLQueue(&Q);
            system("pause");
        }
    } while (a <= 9);
}



