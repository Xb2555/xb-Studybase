#include"sort.h"
int main() {
	//1.选择文件名
	FILE* fp;
	if ((fp = fopen("sort.txt", "r")) == NULL) {
		printf("cannot open file\n");
		system("pause");
		exit(0);
	}
	//计时变量
	clock_t start,finish;
	double time1 = 0.0;
	//2.开始排序
	printf("1.大数据量排序  2.小数据量排序 3.读取文件中的数组\n");
	int a;
	scanf_s("%d", &a);
	switch(a)
	{
	case 1:
		printf("1.生成10000大数组 2.生成50000大数组 3.生成200000大数组\n");
		scanf_s("%d", &a);
		switch (a) {
		case 1: {
			int* arr = randomarr(10000);
			int n = 10000;
			putsarr(arr, n, fp);//将排序前的数组存入文件
			int* tmp = (int*)malloc(n * sizeof(int));
			printf("1.插入排序 2.归并排序 3.快排 4.计数排序 5.基数排序\n");
			scanf_s("%d", &a);
			switch (a) {
			case 1:
				start = clock();
				insertSort(arr, n);
				finish = clock();
				time1 = (double)(finish - start);
				printf("用时：%f", time1);
				system("pause");
				putsarr(arr, n, fp);//将排序后的数组存入文件
				break;
			case 2:
				start = clock();
				MergeSort(arr, 0, n - 1, tmp);
				finish = clock();
				time1 = (double)(finish - start);
				printf("用时：%f", time1);
				system("pause");
				putsarr(arr, n, fp);
				break;
			case 3:
				start = clock();
				QuickSort_Recursion(arr, 0, n - 1);
				finish = clock();
				time1 = (double)(finish - start);
				printf("用时：%f", time1);
				system("pause");
				putsarr(arr, n, fp);
				break;
			case 4:
				start = clock();
				CountSort(arr, n, Getmax(arr, n));
				finish = clock();
				time1 = (double)(finish - start);
				printf("用时：%f", time1);
				system("pause");
				putsarr(arr, n, fp);
				break;
			case 5:
				start = clock();
				RadixCountSort(arr, n);
				finish = clock();
				time1 = (double)(finish - start);
				printf("用时：%f", time1);
				system("pause");
				putsarr(arr, n, fp);
				break;
			}
			break;
		}
		case 2: {
			int *arr2 = randomarr(50000);
			int n2 = 50000;
			putsarr(arr2, n2, fp);//将排序前的数组存入文件
			int*tmp2 = (int*)malloc(n2 * sizeof(int));
			printf("1.插入排序 2.归并排序 3.快排 4.计数排序 5.基数排序\n");
			scanf_s("%d", &a);
			switch (a) {
			case 1:
				start = clock();
				insertSort(arr2, n2);
				finish = clock();
				time1 = (double)(finish - start);
				printf("用时：%f", time1);
				system("pause");
				putsarr(arr2, n2, fp);//将排序后的数组存入文件
				break;
			case 2:
				start = clock();
				MergeSort(arr2, 0, n2 - 1, tmp2);
				finish = clock();
				time1 = (double)(finish - start);
				printf("用时：%f", time1);
				system("pause");
				putsarr(arr2, n2, fp);
				break;
			case 3:
				start = clock();
				QuickSort_Recursion(arr2, 0, n2 - 1);
				finish = clock();
				time1 = (double)(finish - start);
				printf("用时：%f", time1);
				system("pause");
				putsarr(arr2, n2, fp);
				break;
			case 4:
				start = clock();
				CountSort(arr2, n2, Getmax(arr2, n2));
				finish = clock();
				time1 = (double)(finish - start);
				printf("用时：%f", time1);
				system("pause");
				putsarr(arr2, n2, fp);
				break;
			case 5:
				start = clock();
				RadixCountSort(arr2, n2);
				finish = clock();
				time1 = (double)(finish - start);
				printf("用时：%f", time1);
				system("pause");
				putsarr(arr2, n2, fp);
				break;
			}
			break;
		}
		case 3: {
			int*arr3 = randomarr(200000);
			int n3 = 200000;
			putsarr(arr3, n3, fp);//将排序前的数组存入文件
			int*tmp3 = (int*)malloc(n3 * sizeof(int));
			printf("1.插入排序 2.归并排序 3.快排 4.计数排序 5.基数排序\n");
			scanf_s("%d", &a);
			switch (a) {
			case 1:
				start = clock();
				insertSort(arr3, n3);
				finish = clock();
				time1 = (double)(finish - start);
				printf("用时：%f", time1);
				system("pause");
				putsarr(arr3, n3, fp);//将排序后的数组存入文件
				break;
			case 2:
				start = clock();
				MergeSort(arr3, 0, n3 - 1, tmp3);
				finish = clock();
				time1 = (double)(finish - start);
				printf("用时：%f", time1);
				system("pause");
				putsarr(arr3, n3, fp);
				break;
			case 3:
				start = clock();
				QuickSort_Recursion(arr3, 0, n3 - 1);
				finish = clock();
				time1 = (double)(finish - start);
				printf("用时：%f", time1);
				system("pause");
				putsarr(arr3, n3, fp);
				break;
			case 4:
				start = clock();
				CountSort(arr3, n3, Getmax(arr3, n3));
				finish = clock();
				time1 = (double)(finish - start);
				printf("用时：%f", time1);
				system("pause");
				putsarr(arr3, n3, fp);
				break;
			case 5:
				start = clock();
				RadixCountSort(arr3, n3);
				finish = clock();
				time1 = (double)(finish - start);
				printf("用时：%f", time1);
				system("pause");
				putsarr(arr3, n3, fp);
				break;
			}
			break;
		}
		}
	break;
	case 2: {
		int n = 0;
		int k = 1;//排序次数
		printf("1.插入排序 2.归并排序 3.快排 4.计数排序 5.基数排序\n");
		scanf_s("%d", &a);
		switch (a) {
		case 1:
			printf("请输入要排序的次数：\n");
			scanf_s("%d", &k);
			start = clock();
			for (int i = 0; i < k; i++) {
				srand((unsigned int)time(NULL));
				int n = rand() % 100 + 10;
				int* arr = randomarr(n);
				insertSort(arr, n);
				putsarr(arr, n, fp);//将排序后的数组存入文件
			}
			finish = clock();
			time1 = (double)(finish - start);
			printf("用时：%f", time1);
			system("pause");
			break;
		case 2:
			printf("请输入要排序的次数：\n");
			scanf_s("%d", &k);
			start = clock();
			for (int i = 0; i < k; i++) {
				srand((unsigned int)time(NULL));
				int n = rand() % 100 + 10;
				int* arr = randomarr(n);
				int* tmp = (int*)malloc(n * sizeof(int));
				MergeSort(arr, 0, n - 1, tmp);
				putsarr(arr, n, fp);//将排序后的数组存入文件
			}
			finish = clock();
			time1 = (double)(finish - start);
			printf("用时：%f", time1);
			system("pause");
			break;
		case 3:
			printf("请输入要排序的次数：\n");
			scanf_s("%d", &k);
			start = clock();
			for (int i = 0; i < k; i++) {
				srand((unsigned int)time(NULL));
				int n = rand() % 100 + 10;
				int* arr = randomarr(n);
				QuickSort_Recursion(arr, 0, n - 1);
				putsarr(arr, n, fp);//将排序后的数组存入文件
			}
			finish = clock();
			time1 = (double)(finish - start);
			printf("用时：%f", time1);
			system("pause");
			break;
		case 4:
			printf("请输入要排序的次数：\n");
			scanf_s("%d", &k);
			start = clock();
			for (int i = 0; i < k; i++) {
				srand((unsigned int)time(NULL));
				int n = rand() % 100 + 10;
				int* arr = randomarr(n);
				CountSort(arr, n, Getmax(arr, n));
				putsarr(arr, n, fp);//将排序后的数组存入文件
			}
			finish = clock();
			time1 = (double)(finish - start);
			printf("用时：%f", time1);
			system("pause");
			break;
		case 5:
			printf("请输入要排序的次数：\n");
			scanf_s("%d", &k);
			start = clock();
			for (int i = 0; i < k; i++) {
				srand((unsigned int)time(NULL));
				int n = rand() % 100 + 10;
				int* arr = randomarr(n);
				RadixCountSort(arr, n);
				putsarr(arr, n, fp);//将排序后的数组存入文件
			}
			finish = clock();
			time1 = (double)(finish - start);
			printf("用时：%f", time1);
			system("pause");
			break;
		}
		break;
	}
	case 3:
		int n = 0;
		printf("请输入要读取的数组长度\n");
		scanf_s("%d", &n);
		int* arr4 = (int*)malloc((n+1) * sizeof(int));
		fread(arr4,sizeof(int),n,fp);
		printf("1.插入排序 2.归并排序 3.快排 4.计数排序 5.基数排序\n");
		scanf_s("%d", &a);
		switch (a) {
		case 1:
			insertSort(arr4, n);
			putsarr(arr4, n,fp);
			printf("排序后：\n");
			prearr(arr4, n);
			system("pause");
			break;
		case 2: {
			int* tmp = (int*)malloc(n * sizeof(int));
			MergeSort(arr4, 0, n - 1, tmp);
			putsarr(arr4,n,fp);
			printf("排序后：\n");
			prearr(arr4, n);
			system("pause");
			break;
		}
		case 3:
			QuickSort_Recursion(arr4, 0, n - 1);
			putsarr(arr4, n, fp);
			printf("排序后：\n");
			prearr(arr4, n);
			system("pause");
			break;
		case 4:
			CountSort(arr4, n, Getmax(arr4, n));
			putsarr(arr4,n,fp);
			printf("排序后：\n");
			prearr(arr4, n);
			system("pause");
			break;
		case 5:
			RadixCountSort(arr4, n);
			putsarr(arr4, n, fp);
			printf("排序后：\n");
			prearr(arr4, n);
			system("pause");
			break;
		}
		break;
	}
}