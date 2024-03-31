
#define SORT_H_INCLUDED
#include<stdio.h>
#include<math.h>
#include <malloc.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
/*���нṹ*/
typedef struct node {
	int data;
	struct node* next;
}Node;

typedef struct Lqueue {
	Node* front;
	Node* rear;
}LQueue;
/*���еĻ�������*/
void InitLQueue(LQueue* Q) {
	Q->front = (Node*)malloc(sizeof(Node));
	Q->rear = (Node*)malloc(sizeof(Node));
	Q->front = Q->rear = NULL;
}

void EnLQueue(LQueue* Q, int data) {
	Node* N = (Node*)malloc(sizeof(Node));
	N->data = data;
	N->next = NULL;
	if (Q->rear == NULL) {
		Q->front = Q->rear = N;
	}
	else {
		Q->rear->next = N;
		Q->rear = N;
	}
}

void DeLQueue(LQueue* Q) {
		if (Q->front->next == NULL) {
			free(Q->front);
			Q->front = Q->rear = NULL;
		}
		else {
			Node* next = Q->front->next;
			free(Q->front);
			Q->front = next;
		}
}

bool IsEmptyLQueue(const LQueue* Q) {
	if (Q->front == NULL) {
		return true;
	}
	else {
		return false;
	}
}

int queueFront(LQueue* q) {
	return q->front->data;
}

void queueEmpty(LQueue* q) {
	q->front = NULL;
}
/**
 *  @name        : ����
 *  @description : ��һ�������������ҵ���K��/С����
 *  @param       : ����ָ��a�����鳤��size
 */
int min(int x, int y) {
	return x < y ? x : y;
}

void swap(int* arr, int a, int b) {
	int tmp = arr[b];
	arr[b] = arr[a];
	arr[a] = tmp;
}
//���ػ���֮�󣬻�׼ֵ����λ��
int partion1(int* arr, int begin, int end)
{
	//ѡ���׼ֵ
	int key = arr[begin];
	int start = begin;
	while (begin < end) {
		//�Ӻ���ǰ����С�ڻ�׼ֵ��λ��
		while (begin < end && arr[end] >= key)
			--end;
		//��ǰ����Ҵ��ڻ�׼ֵ��λ��
		while (begin < end && arr[begin] <= key)
			++begin;
		//����
		swap(arr, begin, end);
	}
	//������׼ֵ������λ�õ�����
	swap(arr, start, begin);
	return begin;
}
//����ȡ�з��Ż�
int GetMidIndex(int* a, int begin, int end) {
	int mid = begin + ((end - begin) >> 1);
	if ((a[mid] >= a[begin] && a[mid] <= a[end]) || (a[mid] >= a[end] && a[mid] <= a[begin])) {
		return mid;
	}
	if ((a[begin] <= a[mid] && a[begin] >= a[end])||(a[begin]>=a[mid]&&a[begin]<=a[end])) {
		return begin;
	}
	return end;
}
//�ҵ���������ֵ
int Getmax(int* a,int size) {
	int max = a[0];
	for (int i = 1; i <size; i++) {
		if (max < a[i]) {
			max = a[i];
		}
	}
	return max;
}

//�����������
int* randomarr(int Max) {
	size_t arry_size = Max;
	int* arr = (int*)malloc(arry_size * sizeof(int));
	srand((unsigned int)time(NULL));
	for (size_t i=0; i < arry_size; i++) {
		arr[i] = rand();
	}
	return arr;
}

//�������鳤��
int length(int* a) {
	return sizeof(a) / sizeof(a[0]);
}

//������д���ļ�
void putsarr(int* arr, int n,FILE*fp) {
	for (int i = 0; i < n; i++) {
		fprintf(fp, "%d ", arr[i]);
	}
	fprintf(fp, "\n");
}

//��������
void prearr(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}
/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : ���������㷨
 *  @param       : ����ָ�� a, ���鳤�� n
 */
void insertSort(int* a, int n) {
	int tmp,j;
	for (int i = 1; i < n; i++) {
		tmp = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > tmp) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = tmp;
	}
}


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
void MergeArray(int* a, int begin, int mid, int end, int* temp) {
	int i = begin, j = mid + 1, k = begin;
	while (i != mid + 1 && j != end + 1) {
		if (a[i] > a[j]) {
			temp[k++] = a[j++];
		}
		else {
			temp[k++] = a[i++];
		}
	}
	while (i != mid + 1) {
		temp[k++] = a[i++];
	}
	while (j != end + 1) {
		temp[k++] = a[j++];
	}
	for (i = begin; i <= end; i++) {
		a[i] = temp[i];
	}
}


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
 */
void MergeSort(int* a, int begin, int end, int* temp) {
	int mid;
	if (begin < end) {
		mid = begin + (end - begin) / 2;
		//�ֳ�����������
		MergeSort(a, begin, mid, temp);
		MergeSort(a, mid + 1, end, temp);
		//�ϲ�����������
		MergeArray(a, begin, mid, end, temp);
	}
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
 */
void QuickSort_Recursion(int* a, int begin, int end) {
	if (begin < end) {
		int base = a[begin];
		int left = begin;
		int right = end;
		while (left < right) {
			//��ָ������ҵ���baseС����
			while (left < right && a[right] >= base) {
				right--;
			}
			a[left] = a[right];//����С�����滻left����λ�õ���
			//��ָ������ҵ���base�����
			while (left < right && a[left] <= base) {
				left++;
			}
			a[right] = a[left];//�滻right��������λ��
		}
		a[left] = base;//��ʱleft��rightָ����������base�滻�˴�λ��
		//�����baseС������
		QuickSort_Recursion(a, begin, left - 1);
		//�����base�������
		QuickSort_Recursion(a, left+1,end);

	}
}


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
 */
void QuickSort(int* a, int size) {
	//���ö�����ɲ���
	LQueue q;
	InitLQueue(&q);//��ʼ���ж�
	//��ͷβ���
	EnLQueue(&q, 0);
	EnLQueue(&q, size - 1);
	while (!IsEmptyLQueue(&q)) {
		//ȡ����ʼ�����λ��
		int left = queueFront(&q);
		DeLQueue(&q);
		int right = queueFront(&q);
		DeLQueue(&q);
		//����
		int div = partion1(a, left, right);
		if (left < div - 1) {
			EnLQueue(&q, left);
			EnLQueue(&q, div - 1);
		}
		if (div + 1 < right) {
			EnLQueue(&q, div + 1);
			EnLQueue(&q, right);
		}
	}
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
 */
void Partition(int* a, int begin, int end) {
	int mini = GetMidIndex(a, begin, end);
	swap(a, begin, end);
	int keyi = begin;
	while (begin < end) {
		while (begin < end && a[end] >= a[keyi]) {
			end--;
		}
		while (begin < end && a[begin] <= a[keyi]) {
			begin++;
		}
		swap(a, begin, end);
	}
	swap(a, keyi, end);
}


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
 */
void CountSort(int* a, int size, int max) {
	int index = 0;
	int* tmparr = (int*)malloc((max+1) * sizeof(int));//������ʱ����Ŀռ�
	//����ʱ����Ԫ����Ϊ0
	for (int k = 0; k < max; k++) {
		tmparr[k] = 0;
	}
	//ͳ���±�Ϊa����Ԫ�صĳ��ִ���
	for (int i = 0; i < size; i++) {
		tmparr[a[i]]++;
	}
	//��a�����Ԫ���滻Ϊ��ʱ������±�
	for (int j = 0; j < max; j++) {
		while (tmparr[j]) {
			a[index++] = j;
			tmparr[j]--;
		}
	}
	free(tmparr);
	tmparr = NULL;
}


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
 */
void RadixCountSort(int* data, int length) {
		int i, k, maxVal, count, base;
		int bucket[10] = { 0 };
		int* buff = new int[length];
		//�������е����Ԫ�� 
		maxVal = data[0];
		for (i = 1; i < length; i++)
		{
			if (data[i] > maxVal)
			{
				maxVal = data[i];
			}
		}
		//printf( "maxVal = %d\n", maxVal );
		//�������Ԫ�ص�λ�� 
		count = 0;
		while (maxVal > 0)
		{
			count++;
			maxVal /= 10;
		}
		//printf( "count = %d\n", count );
		base = 1;
		for (k = 1; k <= count; k++)
		{
			//��ÿһ��Ԫ�ص� baseλ�ϵ����֣���Ӧ��ͰԪ�����ۼ� 
			for (i = 0; i < length; i++)
			{
				bucket[(data[i] / base) % 10]++;
			}
			//���¼���ͰԪ�ص�ֵ��ÿһ��Ԫ�ض�����ǰ��Ԫ��֮��
			//��˲��������Եõ�ÿһ��Ͱ�е�Ԫ��������֮���λ���±� 
			for (i = 1; i < 10; i++)
			{
				bucket[i] += bucket[i - 1];
			}
			//����ͰԪ�ص�ֵ����data�е�Ԫ��������λ����buff��
			for (i = length - 1; i >= 0; i--)
			{
				buff[bucket[(data[i] / base) % 10] - 1] = data[i];
				bucket[(data[i] / base) % 10]--;
			}
			//��buff��Ԫ�ض�λ��ŵ�data��
			for (i = 0; i < length; i++)
			{
				data[i] = buff[i];
			}
			//���Ͱ������Ͱ��Ԫ�ع�0 
			for (i = 0; i < 10; i++)
			{
				bucket[i] = 0;
			}
			//base��ֵ����10,֮�������һ������ 
			base *= 10;
		}
		delete[] buff;
}


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
 */
void ColorSort(int* a, int size) {
	int* count = (int*)malloc(3 * sizeof(int));
	for (int i = 0; i < size; i++) {
		count[a[i]]++;
	}
	int index = 0;
	for (int i = 0; i < count[0]; i++) {
		a[index++] = 0;
	}
	for (int i = 0; i < count[1]; i++) {
		a[index++] = 1;
	}
	for (int i = 0; i < count[2]; i++) {
		a[index++] = 2;
	}
}


/**
 *  @name        : ����
 *  @description : ��һ�������������ҵ���K��/С����
 *  @param       : ����ָ��a�����鳤��size
 */
