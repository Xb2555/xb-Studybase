#include"LinkStack.h"
int main()
{
    int j;
    LinkStack s;
    int e;
    int a;
    do {
        system("cls");
        printf("1.��ʼ��ջ  2.��ջ  3.��ջ  4.�õ�ջ��Ԫ��  5.���ջ����  6.���ջ  7.����ջ 8.�ж�ջ�Ƿ�Ϊ��\n");
        printf("������ѡ�\n");
        scanf_s("%d", &a);
        system("cls");
        switch (a) {
        case 1:
            if (initLStack(&s) == SUCCESS) {
                printf("��ʼ���ɹ�\n");
                system("pause");
            }
            else {
                printf("��ʼ��ʧ��\n");
                system("pause");
            }
            break;
        case 2:
            printf("������Ҫ��ջ������\n");
            scanf_s("%d", &e);
            if (pushLStack(&s, e) == SUCCESS) {
                printf("��ջ�ɹ�\n");
                system("pause");
            }
            else {
                printf("��ջʧ��\n");
                system("pause");
            }
            break;
        case 3:
            if (popLStack(&s, &e) == SUCCESS) {
                printf("������ݣ�%d\n", e);
                system("pause");
            }
            else {
                printf("��ջʧ��\n");
                system("pause");
            }
            break;
        case 4:
            if (getTopLStack(&s, e) == SUCCESS) {
                printf("������ݣ�%d\n", e);
                system("pause");
            }
            else {
                printf("ʧ��\n");
                system("pause");
            }
            break;
        case 5:
            if (LStackLength(&s, &e) == SUCCESS) {
                printf("������ݣ�%d\n", e);
                system("pause");
            }
            else {
                printf("ʧ��\n");
                system("pause");
            }
            break;
        case 6:
            if (clearLStack(&s) == SUCCESS) {
                printf("�ɹ�\n");
                system("pause");
            }
            else {
                printf("ʧ��\n");
                system("pause");
            }
            break;
        case 7:
            if (destroyLStack(&s) == SUCCESS) {
                printf("�ɹ�\n");
                system("pause");
            }
            else {
                printf("ʧ��\n");
                system("pause");
            }
            break;
        case 8:
            if (isEmptyLStack(&s) == SUCCESS) {
                printf("�ǿ�ջ\n");
                system("pause");
            }
            else {
                printf("���ǿ�ջ\n");
                system("pause");
            }
            break;
        }
    } while (a <= 8);
}