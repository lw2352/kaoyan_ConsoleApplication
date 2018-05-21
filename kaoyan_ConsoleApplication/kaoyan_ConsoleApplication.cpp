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

//ѡ������ͨ��n-i�ιؼ��ּ�ıȽϣ���n-i+1����¼
//��ѡ���ؼ�����С�ļ�¼�����͵�i��1<=i<=n������¼������
void SelectSort(int k[], int n)
{
	int i, j, min, temp;
	for(i=0;i<n-1;i++)
	{
		min = i;
		//�ҳ���СԪ�ص�λ��
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

//��������Ԫ�ص�λ��
void swap(int k[], int low, int high)
{
	int temp;

	temp = k[low];
	k[low] = k[high];
	k[high] = temp;
}

//����һ���µĻ�׼��
int Partition(int k[], int low, int high)
{
	int point;
	point = k[low];
	while(low<high)
	{
		//�Ƚ��ұ�
		while(low<high && k[high]>=point)
		{
			high--;
		}
		//����whileѭ����˵��point���ұ���Ԫ�ر���С����Ҫ�ƶ�������λ�ã�
		swap(k, low, high);

		//�Ƚ����
		while (low<high && k[low] <= point)
		{
			low++;
		}
		//����whileѭ����˵��point�������Ԫ�ر�������Ҫ�ƶ�������λ�ã�
		swap(k, low, high);
	}
	//�˳������whileѭ��ʱ��low��high���
	//�����м��λ��
	return(low);
}

//�������򣬲��������飬��ʼλ�ã�����λ��
//����˼�룺
//1��ѡ��һ����׼Ԫ��, ͨ��ѡ���һ��Ԫ�ػ������һ��Ԫ��,
//2��ͨ��һ�����򽲴�����ļ�¼�ָ�ɶ����������֣�����һ���ּ�¼��Ԫ��ֵ���Ȼ�׼Ԫ��ֵС����һ���ּ�¼�� Ԫ��ֵ�Ȼ�׼ֵ��
//3����ʱ��׼Ԫ�������ź�������ȷλ��
//4��Ȼ��ֱ���������ּ�¼��ͬ���ķ���������������ֱ��������������
void QSort(int k[], int low, int high)
{
	int point;//��׼��
	//�᲻�ϵضԻ�׼����бȽϣ�����ָ����ƶ�
	//��ָ���ص���ʱ��˵���Ѿ�������һ�ֱȽ�
	if(low<high)
	{
		//���м����Ϊ�ֽ��
		point = Partition(k, low, high);
		
		//�ݹ����
		QSort(k, low, point - 1);//���
		QSort(k, point + 1, high);//�ұ�
	}
}

//������Ϊ��㺯�������ֽӿ�һ��
void QuickSort(int k[], int n)
{
	//��������������飬��ʼλ�ã�����λ��
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

