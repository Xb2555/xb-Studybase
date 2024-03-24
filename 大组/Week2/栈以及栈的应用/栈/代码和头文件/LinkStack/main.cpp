#include"LinkStack.h"
int main()
{
    int j;
    LinkStack s;
    int e;
    int a;
    do {
        system("cls");
        printf("1.初始化栈  2.入栈  3.出栈  4.得到栈顶元素  5.检测栈长度  6.清空栈  7.销毁栈 8.判断栈是否为空\n");
        printf("请输入选项：\n");
        scanf_s("%d", &a);
        system("cls");
        switch (a) {
        case 1:
            if (initLStack(&s) == SUCCESS) {
                printf("初始化成功\n");
                system("pause");
            }
            else {
                printf("初始化失败\n");
                system("pause");
            }
            break;
        case 2:
            printf("请输入要入栈的数据\n");
            scanf_s("%d", &e);
            if (pushLStack(&s, e) == SUCCESS) {
                printf("入栈成功\n");
                system("pause");
            }
            else {
                printf("入栈失败\n");
                system("pause");
            }
            break;
        case 3:
            if (popLStack(&s, &e) == SUCCESS) {
                printf("输出数据：%d\n", e);
                system("pause");
            }
            else {
                printf("出栈失败\n");
                system("pause");
            }
            break;
        case 4:
            if (getTopLStack(&s, e) == SUCCESS) {
                printf("输出数据：%d\n", e);
                system("pause");
            }
            else {
                printf("失败\n");
                system("pause");
            }
            break;
        case 5:
            if (LStackLength(&s, &e) == SUCCESS) {
                printf("输出数据：%d\n", e);
                system("pause");
            }
            else {
                printf("失败\n");
                system("pause");
            }
            break;
        case 6:
            if (clearLStack(&s) == SUCCESS) {
                printf("成功\n");
                system("pause");
            }
            else {
                printf("失败\n");
                system("pause");
            }
            break;
        case 7:
            if (destroyLStack(&s) == SUCCESS) {
                printf("成功\n");
                system("pause");
            }
            else {
                printf("失败\n");
                system("pause");
            }
            break;
        case 8:
            if (isEmptyLStack(&s) == SUCCESS) {
                printf("是空栈\n");
                system("pause");
            }
            else {
                printf("不是空栈\n");
                system("pause");
            }
            break;
        }
    } while (a <= 8);
}