#include <stdio.h>

//1. 打印100~200 之间的素数 
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 100; i <=200; i++)
//	{
//		for (j = 2; j < i; j++)
//		{
//			if (i%j == 0)
//				break;
//		}
//		if (j >= i)
//		{
//			printf("%d\n", i);
//		}
//	}system("pause");
//	return 0;
//}
//
//2. 输出乘法口诀表
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%2d ", i, j, i*j);
//		}printf("\n");
//
//	}system("pause");
//	return 0;
//}
//
//3. 判断1000年---2000年之间的闰年
int main()
{
	int i = 0;
	for (i = 1000; i <=2000; i++)
	{
		if (i % 4 == 0)
		{
			if (i % 100 != 0){
				printf("%d ", i);
			}
		}
		if (i % 400 == 0)
		{
			printf("%d ", i);
		}
	}
	system("pause");
	return 0;
}

