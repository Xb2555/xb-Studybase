#include"head.h"
int main() {
	char s[100];
	printf("请输入表达式：\n");
	gets_s(s);
	double r = Poland(s);
	printf("%1.2lf\n", r);
	return 0;
}
