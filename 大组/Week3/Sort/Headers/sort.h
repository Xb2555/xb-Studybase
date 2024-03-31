
#define SORT_H_INCLUDED
#include<stdio.h>
#include<math.h>
#include <malloc.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
/*队列结构*/
typedef struct node {
	int data;
	struct node* next;
}Node;

typedef struct Lqueue {
	Node* front;
	Node* rear;
}LQueue;
/*队列的基本操作*/
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
 *  @name        : 自拟
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : 数组指针a，数组长度size
 */
int min(int x, int y) {
	return x < y ? x : y;
}

void swap(int* arr, int a, int b) {
	int tmp = arr[b];
	arr[b] = arr[a];
	arr[a] = tmp;
}
//返回划分之后，基准值所在位置
int partion1(int* arr, int begin, int end)
{
	//选择基准值
	int key = arr[begin];
	int start = begin;
	while (begin < end) {
		//从后向前先找小于基准值的位置
		while (begin < end && arr[end] >= key)
			--end;
		//从前向后找大于基准值的位置
		while (begin < end && arr[begin] <= key)
			++begin;
		//交换
		swap(arr, begin, end);
	}
	//交换基准值和相遇位置的数据
	swap(arr, start, begin);
	return begin;
}
//三数取中法优化
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
//找到数组的最大值
int Getmax(int* a,int size) {
	int max = a[0];
	for (int i = 1; i <size; i++) {
		if (max < a[i]) {
			max = a[i];
		}
	}
	return max;
}

//随机生成数组
int* randomarr(int Max) {
	size_t arry_size = Max;
	int* arr = (int*)malloc(arry_size * sizeof(int));
	srand((unsigned int)time(NULL));
	for (size_t i=0; i < arry_size; i++) {
		arr[i] = rand();
	}
	return arr;
}

//计算数组长度
int length(int* a) {
	return sizeof(a) / sizeof(a[0]);
}

//将数组写入文件
void putsarr(int* arr, int n,FILE*fp) {
	for (int i = 0; i < n; i++) {
		fprintf(fp, "%d ", arr[i]);
	}
	fprintf(fp, "\n");
}

//遍历数组
void prearr(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}
/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序算法
 *  @param       : 数组指针 a, 数组长度 n
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
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
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
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int* a, int begin, int end, int* temp) {
	int mid;
	if (begin < end) {
		mid = begin + (end - begin) / 2;
		//分出两个子数组
		MergeSort(a, begin, mid, temp);
		MergeSort(a, mid + 1, end, temp);
		//合并两个子数组
		MergeArray(a, begin, mid, end, temp);
	}
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int* a, int begin, int end) {
	if (begin < end) {
		int base = a[begin];
		int left = begin;
		int right = end;
		while (left < right) {
			//右指针遍历找到比base小的数
			while (left < right && a[right] >= base) {
				right--;
			}
			a[left] = a[right];//将较小的数替换left所在位置的数
			//左指针遍历找到比base大的数
			while (left < right && a[left] <= base) {
				left++;
			}
			a[right] = a[left];//替换right所在数的位置
		}
		a[left] = base;//此时left与right指针相遇，用base替换此处位置
		//排序比base小的数组
		QuickSort_Recursion(a, begin, left - 1);
		//排序比base大的数组
		QuickSort_Recursion(a, left+1,end);

	}
}


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int* a, int size) {
	//利用队列完成操作
	LQueue q;
	InitLQueue(&q);//初始化列队
	//将头尾入队
	EnLQueue(&q, 0);
	EnLQueue(&q, size - 1);
	while (!IsEmptyLQueue(&q)) {
		//取出起始与结束位置
		int left = queueFront(&q);
		DeLQueue(&q);
		int right = queueFront(&q);
		DeLQueue(&q);
		//划分
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
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
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
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int* a, int size, int max) {
	int index = 0;
	int* tmparr = (int*)malloc((max+1) * sizeof(int));//开辟临时数组的空间
	//将临时数组元素置为0
	for (int k = 0; k < max; k++) {
		tmparr[k] = 0;
	}
	//统计下标为a数组元素的出现次数
	for (int i = 0; i < size; i++) {
		tmparr[a[i]]++;
	}
	//将a数组的元素替换为临时数组的下标
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
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int* data, int length) {
		int i, k, maxVal, count, base;
		int bucket[10] = { 0 };
		int* buff = new int[length];
		//求数组中的最大元素 
		maxVal = data[0];
		for (i = 1; i < length; i++)
		{
			if (data[i] > maxVal)
			{
				maxVal = data[i];
			}
		}
		//printf( "maxVal = %d\n", maxVal );
		//计算最大元素的位数 
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
			//求每一个元素的 base位上的数字，对应的桶元素做累加 
			for (i = 0; i < length; i++)
			{
				bucket[(data[i] / base) % 10]++;
			}
			//重新计算桶元素的值，每一个元素都是其前面元素之和
			//如此操作，可以得到每一个桶中的元素在排序之后的位置下标 
			for (i = 1; i < 10; i++)
			{
				bucket[i] += bucket[i - 1];
			}
			//根据桶元素的值，将data中的元素重新排位存入buff中
			for (i = length - 1; i >= 0; i--)
			{
				buff[bucket[(data[i] / base) % 10] - 1] = data[i];
				bucket[(data[i] / base) % 10]--;
			}
			//将buff中元素对位存放到data中
			for (i = 0; i < length; i++)
			{
				data[i] = buff[i];
			}
			//清空桶，即让桶里元素归0 
			for (i = 0; i < 10; i++)
			{
				bucket[i] = 0;
			}
			//base的值乘以10,之后进入下一趟排序 
			base *= 10;
		}
		delete[] buff;
}


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
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
 *  @name        : 自拟
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : 数组指针a，数组长度size
 */
