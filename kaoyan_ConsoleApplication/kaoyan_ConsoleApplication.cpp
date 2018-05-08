// kaoyan_ConsoleApplication.cpp : �������̨Ӧ�ó������ڵ㡣
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

//ֱ�Ӳ�������
//���룺���飬����Ԫ�ظ���
void InsertSort(int k[], int n)
{
	int i, j, temp;
	for(i=1;i<n;i++)
	{
		if(k[i]<k[i-1])//����Ԫ��С��ǰ��Ԫ�أ�����Ҫ��������
		{
			temp = k[i];
			for(j=i-1;k[j]>temp;j--)//��temp�嵽k[j]֮ǰ
			{
				k[j + 1] = k[j];//��λ�ò��������
			}

			k[j + 1] = temp;
		}

		printData(k, n, i);
	}
	
}
//ð������
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

//ѡ������
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
		//�����е�Ԫ�ض����бȽϺ󣬰���С����λ�ô���temp��
		if(min != i)//�Ƚϲ�ʵ�ֽ���
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

