#include <stdio.h>

//1. ��ӡ100~200 ֮������� 
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
//2. ����˷��ھ���
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
//3. �ж�1000��---2000��֮�������
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

