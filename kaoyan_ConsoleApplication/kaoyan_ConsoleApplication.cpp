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

int main()
{
	int a[5] = {5,2,3,4,2};
	//InsertSort(a,5);
	//BubbleSort(a,5);
	//SelectSort(a,5);
	QuickSort(a,5);
    return 0;
}

