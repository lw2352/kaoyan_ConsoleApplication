// kaoyan_ConsoleApplication.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

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

//选择排序
void SelectSort(int k[], int n)
{
	int i, j, min, temp;
	for(i=0;i<n-1;i++)
	{
		min = i;
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

int main()
{
	int a[5] = {5,2,3,4,2};
	//InsertSort(a,5);
	//BubbleSort(a,5);
	SelectSort(a,5);
    return 0;
}

