#define _CRT_SECURE_NO_WARNINGS 1

//写一个C语言的代码，在屏幕上打印：hello bit
//#include <stdio.h>
//int main()
//{
//	printf("hello bit\n");
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	printf("%d\n%d\n", 20, 10);
//	printf("%d\n", sizeof(char));
//	printf("%d\n", sizeof(short));
//	printf("%d\n", sizeof(int));
//	printf("%d\n", sizeof(long));
//	printf("%d\n", sizeof(long long));
//	printf("%d\n", sizeof(float));
//	printf("%d\n", sizeof(double));
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int age1;
//	int age2 = 20;
//
//	float weight = 55.5f;
//	double weight2 = 80.5;
//
//	int num = 10;
//	printf("%d\n", num);
//	num = 20;
//	printf("%d\n", num);
//
//	return 0;
//}

//#include <stdio.h>
//int a = 100; //全局变量
//
//int main()
//{
//	int a = 10; //局部变量
//	printf("a = %d\n", a);
//	return 0;
//}

#include <stdio.h>
int main()
{
	//写一个代码，求两个整数的和
	int num1 = 0;
	int num2 = 0;
	int sum = 0;
	//输入两个整数的值
	scanf("%d %d", &num1, &num2);
	sum = num1 + num2;
	//打印
	printf("%d\n", sum);

	return 0;
}