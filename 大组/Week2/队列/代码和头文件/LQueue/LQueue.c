#include "LQueue.h" 
#include<stdio.h>
#include<stdlib.h>
/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
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
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
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
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
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
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
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
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
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
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
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
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
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
 *    @description : 清空队列
 *    @param         Q 队列指针Q
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
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
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
 *    @description : 操作函数
 *    @param         q 指针q
 
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
        printf("1.初始化队列  2.入队  3.出队  4.得到队头元素  5.检测队长度  6.清空队  7.销毁队 8.判断队是否为空  9.遍历队列\n");
        printf("请输入选项：\n");
        scanf_s("%d", &a);
        system("cls");
        switch (a) {
        case 1:
            InitLQueue(&Q);
            printf("初始化成功\n");
            system("pause");
            break;
        case 2:
            printf("请输入要入队的数据\n");
            scanf_s("%d",&e);
            if (EnLQueue(&Q,e)==TRUE) {
                printf("入队成功\n");
                system("pause");
            }
            else {
                printf("入队失败\n");
                system("pause");
            }
            break;
        case 3:
            if (DeLQueue(&Q)==TRUE) {
                printf("成功\n");
                system("pause");
            }
            else {
                printf("出队失败\n");
                system("pause");
            }
            break;
        case 4:
            if (GetHeadLQueue(&Q)!=FALSE) {
                printf("%d",GetHeadLQueue(&Q) );
                system("pause");
            }
            else {
                printf("失败\n");
                system("pause");
            }
            break;
        case 5:
            data = LengthLQueue(&Q);
            printf("长度为：%d\n", data);
            system("pause");
            break;
        case 6:
            ClearLQueue(&Q);
            printf("成功\n");
            system("pause");
            break;
        case 7:
            DestoryLQueue(&Q);
            printf("成功\n");
            system("pause");
            break;
        case 8:
            if (IsEmptyLQueue(&Q)==TRUE) {
                printf("是空队\n");
                system("pause");
            }
            else {
                printf("不是空队\n");
                system("pause");
            }
            break;
        case 9:
            TraverseLQueue(&Q);
            system("pause");
        }
    } while (a <= 9);
}



