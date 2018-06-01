// kaoyan_ConsoleApplication.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "string.h"

#define MAX_NUM 50

void printData(int a[], int n, int i)
{
	printf("the %d times:", i);
	for(int j = 0; j < n; j++)
	{
		printf("%d ", a[j]);
	}
	printf("\r\n");
}

//直接插入排序
//输入：数组，数组元素个数
void InsertSort(int k[], int n)
{
	int i, j, temp;
	for(i=1;i<n;i++)
	{
		if(k[i]<k[i-1])//后面元素小于前面元素，则需要重新排序
		{
			temp = k[i];
			for(j=i-1;k[j]>temp;j--)//把temp插到k[j]之前
			{
				k[j + 1] = k[j];//找位置并向后推移
			}

			k[j + 1] = temp;
		}

		printData(k, n, i);
	}
	
}
//冒泡排序
void BubbleSort(int k[], int n)
{
	int i, j, temp;
	for (i = 0; i < n-1; i++)
	{
		for (j = i; j < n; j++)
		{
			if (k[i]>k[j])
			{
				temp = k[i];
				k[i] = k[j];
				k[j] = temp;
			}
		}
		printData(k, n, i);
	}
}

//选择排序，通过n-i次关键字间的比较，从n-i+1个记录
//中选出关键字最小的记录，并和第i（1<=i<=n）个记录交换。
void SelectSort(int k[], int n)
{
	int i, j, min, temp;
	for(i=0;i<n-1;i++)
	{
		min = i;
		//找出最小元素的位置
		for(j=i+1;j<n;j++)
		{
			if(k[j]<k[min])
			{
				min = j;
			}
		}
		//对所有的元素都进行比较后，把最小变量位置存在temp中
		if(min != i)//比较并实现交换
		{
			temp = k[min];
			k[min] = k[i];
			k[i] = temp;
		}

		printData(k, n, i);
	}
}

//调换两个元素的位置
void swap(int k[], int low, int high)
{
	int temp;

	temp = k[low];
	k[low] = k[high];
	k[high] = temp;
}

//返回一个新的基准点
int Partition(int k[], int low, int high)
{
	int point;
	point = k[low];
	while(low<high)
	{
		//比较右边
		while(low<high && k[high]>=point)
		{
			high--;
		}
		//跳出while循环，说明point的右边有元素比它小，需要移动（调换位置）
		swap(k, low, high);

		//比较左边
		while (low<high && k[low] <= point)
		{
			low++;
		}
		//跳出while循环，说明point的左边有元素比它大，需要移动（调换位置）
		swap(k, low, high);
	}
	//退出最外层while循环时，low与high相等
	//返回中间点位置
	return(low);
}

//快速排序，参数：数组，起始位置，结束位置
//基本思想：
//1）选择一个基准元素, 通常选择第一个元素或者最后一个元素,
//2）通过一趟排序讲待排序的记录分割成独立的两部分，其中一部分记录的元素值均比基准元素值小。另一部分记录的 元素值比基准值大。
//3）此时基准元素在其排好序后的正确位置
//4）然后分别对这两部分记录用同样的方法继续进行排序，直到整个序列有序。
void QSort(int k[], int low, int high)
{
	int point;//基准点
	//会不断地对基准点进行比较，左右指针会移动
	//当指针重叠的时候，说明已经进行了一轮比较
	if(low<high)
	{
		//把中间点作为分界点
		point = Partition(k, low, high);
		
		//递归调用
		QSort(k, low, point - 1);//左边
		QSort(k, point + 1, high);//右边
	}
}

//这里作为外层函数，保持接口一致
void QuickSort(int k[], int n)
{
	//参数：传入的数组，初始位置，最大的位置
	QSort(k, 0, n-1);
}

//获取100以内的质数，并相加
void getNum(int n)
{
	int i, j,k;
	for(i=2;i<n;i++)
	{
		//k = sqrt(i);
		for(j=2;j<i;j++)
		{
			if(i%j==0)
			{
				//printf("%d\r\n:", i);
				break;
			}

		}
		if(j==i)
		{
			printf("%d\r\n:", i);
		}

	}

}

//返回真约数的和
int GetYueShu(int num)
{
	int ret=0;
	int i = 1;
	for(i=1;i<num;i++)
	{
		if(num%i==0)
		{
			ret += i;
		}

	}
	return ret;

}

typedef struct
{
	int HH;
	int MM;
	int SS;

	int hh;
	int mm;
	int ss;
	//char words[MAX_NUM];
	//int result;
}T_Data;
//计算组合数
int getZuHe(int r, int n)
{
	int i=1, a=1,b=1,c=1;
	//n!
	for( i=1;i<=n;i++)
	{
		a *= i;
	}
	//r!
	for ( i = 1; i <= r; i++)
	{
		b *= i;
	}
	//(n-r)!
	for (i = 1; i <= n-r; i++)
	{
		c *= i;
	}
	return a / (b*c);
}

//计算楼梯的走法
int getStairsTimes(int M)
{
	int a, b, i, k;
	
	i = 0;
	a = M / 2;
	b = M % 2;
	k = a;
	if(b==0)
	{
		i = 1;
		for(;a>0;a--,k+=1)
		{
			i += getZuHe(a,k);
		}
	}
	if(b==1)
	{
		i = 0+ getZuHe(b, a+b);

		for (; a>0; a--, k += 1)
		{
			i += getZuHe(a, k);
		}
	}
	return i;
}

int array[40];//全局
void oj_B_init(int n)
{
	
	array[1] = 0;
	array[2] = 1;
	array[3] = 2;
	for(int i=4;i<=n;i++)
	{
		array[i] = array[i - 1] + array[i - 2];
	}
}

int oj_B_get(int m)
{
	return array[m];
}

int oj_C_GetType(char input)
{
	char *BigWord = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *SmallWord = "abcdefghijklmnopqrstuvwxyz";
	char *Num = "0123456789";
	char *Symbol = "`!@#$%^";
	int i;
	for(i=0;i<strlen(BigWord);i++)
	{
		if(input == BigWord[i])
		{
			return 1;
		}

		if (input == SmallWord[i])
		{
			return 2;
		}
	}

	for (i = 0; i < strlen(Num); i++)
	{
		if (input == Num[i])
		{
			return 3;
		}
	}

	for (i = 0; i<strlen(Symbol); i++)
	{
		if (input == Symbol[i])
		{
			return 4;
		}
	}

	return 0;
}

//密码检测
int oj_C(char *array)
{
	int type=0;
	int class1 = 0;
	int class2 = 0;
	int class3 = 0;
	int class4 = 0;
	int ret=0;
	int len = strlen(array);
	if(len<8 || len >16)
	{
		return 0;
	}
	for(int i=0; i<len; i++)
	{
		type = oj_C_GetType(array[i]);
		if(type == 0)//不包含所给的字符
		{
			return 0;
		}
		else if (type == 1)
		{
			class1 |=(1<<0);
		}
		else if (type == 2)
		{
			class2 |= (1 << 1);
		}
		else if (type == 3)
		{
			class3 |= (1 << 2);
		}
		else if (type == 4)
		{
			class4 |= (1 << 3);
		}
	}

	ret = class1 + class2 + class3 + class4;
	if ((ret == 1) || (ret == 2) || (ret == 4) || (ret == 8))//只包含1类字符的结果
	{
		return 0;
	}	
	else if((ret == 3)|| (ret == 5) || (ret == 9) || (ret == 6) || (ret == 10) || (ret == 12))//只包含两类字符的结果
	{
		return 0;
	}
	return 1;
}

int main()
{
	//int a[5] = {5,2,3,4,2};
	//InsertSort(a,5);
	//BubbleSort(a,5);
	//SelectSort(a,5);
	//QuickSort(a,5);
	//getNum(100);
	//int ret = getStairsTimes(3);
	int a,b,n,i;
	int ret;
	int h, m, s;
	//char *x;
	//oj_B_init(40);
	//while (1)
	//{
		scanf("%d\n", &n);
		//n = 1;
		//动态申请内存，创建结构体类型数组
		T_Data *t_Data = (T_Data *)malloc(sizeof(T_Data)*n);
		for (i = 0; i < n; i++)
		{
			scanf("%d:%d:%d %d:%d:%d", &t_Data[i].HH, &t_Data[i].MM, &t_Data[i].SS, &t_Data[i].hh, &t_Data[i].mm, &t_Data[i].ss);
			//gets_s(t_Data[i].words,sizeof(t_Data[i].words));
			//t_Data[i].numB = b;
		}
		for (i = 0; i < n; i++)
		{
			a = t_Data[i].HH * 60 * 60 + t_Data[i].MM * 60 + t_Data[i].SS;
			b = t_Data[i].hh * 60 * 60 + t_Data[i].mm * 60 + t_Data[i].ss;
			if (a > b)
			{
				ret = a - b;
				m = ret / 60;
				h = m / 60;//小时
				m = m % 60;//分钟数
				s = ret % 60;//秒
			}
			else if (a < b)
			{
				t_Data[i].hh = t_Data[i].hh % 12;
				b = t_Data[i].hh * 60 * 60 + t_Data[i].mm * 60 + t_Data[i].ss;
				if (a > b)
				{
					ret = a - b;
					m = ret / 60;
					h = m / 60;//小时
					m = m % 60;//分钟数
					s = ret % 60;//秒
				}
				else
				{
					a = (t_Data[i].HH + 12) * 60 * 60 + t_Data[i].MM * 60 + t_Data[i].SS;
					ret = a - b;
					m = ret / 60;
					h = m / 60;//小时
					m = m % 60;//分钟数
					s = ret % 60;//秒
				}
			}
			printf("%02d:%02d:%02d\n", h, m, s);
		}
	//}
		free(t_Data);

		return 0;
}

