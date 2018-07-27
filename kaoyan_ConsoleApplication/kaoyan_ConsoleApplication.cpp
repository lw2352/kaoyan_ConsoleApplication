// kaoyan_ConsoleApplication.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "string.h"

#define MAX_NUM 50
#define N 5
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

//��ȡ100���ڵ������������
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
			printf("%d ", i);
		}

	}

}

//������Լ���ĺ�
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
	char wordsA[MAX_NUM];
	char wordsB[MAX_NUM];

	int A;
	int B;
	//int result;
}T_Data;
//���������
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

//����¥�ݵ��߷�
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

int array[40];//ȫ��
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

//������
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
		if(type == 0)//�������������ַ�
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
	if ((ret == 1) || (ret == 2) || (ret == 4) || (ret == 8))//ֻ����1���ַ��Ľ��
	{
		return 0;
	}	
	else if((ret == 3)|| (ret == 5) || (ret == 9) || (ret == 6) || (ret == 10) || (ret == 12))//ֻ���������ַ��Ľ��
	{
		return 0;
	}
	return 1;
}

//���ַ�������ת��int�ͣ�Ҫ�ж�������ȥ������
int oj_G(char *s)
{
	int i,j;
	int len;
	int ret=0;
	char *newS;
	
	len = strlen(s);

	newS = (char *)malloc(len * sizeof(char));

	if(len>12)//����=1������+9������+2������
	{
		return 0;
	}
		for (i = 0,j=0; i < len; i++)
		{
			if (s[i] != ',')
			{
				newS[j++] = s[i];
			}
			
		}

	if(newS[0]=='-')
	{
		for (i=j-1,j=1; i >= 1; i--)
		{
			
			ret += (newS[i] - 0x30)*j;
			j *= 10;
		}
		ret = 0 - ret;
	}
	else
	{
		for (i = j - 1, j = 1; i >= 0; i--)
		{

			ret += (newS[i]-0x30) * j;
			j *= 10;
		}
	}

	return ret;
}

//���������ֵ�Ƿ�Ϊ����
int checkSuShu(int num)
{
	int i;
	for(i=2;i<num;i++)
	{
		if(num%i==0)
		{
			//��������
			return 0;
		}

	}
	return num;
}


void problem30()
{
	int NN[N][N];
	int i, j;
	int sum1 = 0, sum2 = 0;
	//�������ʼ��
	for (i = 0; i<N; i++)
	{
		for (j = 0; j<N; j++)
		{
			NN[i][j] = rand() % 100;
			printf("%d ", NN[i][j]);
		}
		printf("\n");
	}

	//������
	printf("\nsushu:");
	for (i = 0; i<N; i++)
	{
		for (j = 0; j<N; j++)
		{
			//NN[i][j] = rand() % 100;
			//printf("%d ", NN[i][j]);
			if (checkSuShu(NN[i][j]) != 0)
			{
				printf("%d ", NN[i][j]);
			}
		}
		//printf("\n");
	}

	//����Խ���Ԫ��֮�ͣ�������
	printf("\nduijiaoxian:");
	for (i = 0; i<N; i++)
	{
		for (j = 0; j<N; j++)
		{
			//NN[i][j] = rand() % 100;
			//printf("%d ", NN[i][j]);
			if (i == j)
			{
				sum1 += NN[i][j];
				printf("sum1:%d ", NN[i][j]);
			}
			if ((i + j) == (N - 1))
			{
				sum2 += NN[i][j];
				printf("sum2:%d ", NN[i][j]);
			}
		}
		//printf("\n");
	}
	printf("sum1:%d ", sum1);
	printf("sum2:%d ", sum2);
}

//�������������3λС������������
float fun(double h)
{
	int n, j;
	int ret;
	float result;
	n = h * 10000;
	j = n % 10;
	if(j<5)
	{
		ret = h * 1000;
	}
	else
	{
		ret = h * 1000 + 1;
	}
	result = float(ret)/1000;
	return result;
}

void f(int a[], int i, int j)
{
	int t;
	if(i<j)
	{
		t = a[i];
		a[i] = a[j];
		a[j] = t;
		f(a, i+1, j-1);
	}
}

int a[5][5]={11,3,5,6,9,12,4,7,8,10,10,5,6,9,11,8,6,4,7,2,15,10,11,20,25};
//����Ƿ��������������Сֵ
int getMin(int j)
{
	int i=0;
	int min=0;//����ֵ

	min = a[i][0];
	for(i=0;i<5;i++)
	{
		if (min > a[i][j])
		{
			min = a[i][j];
		}
	}
	return min;
}

int f(int *p)
{
	int b = 0;
	static int c = 3;
	b++;
	*p = (*p) + b + (c++);
	return (*p);

}

//ð�����򣬵���������
void BubbleSort_1(int k[], int n)
{
	int i, j, temp;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i; j < n; j++)
		{
			//����������
			if ((k[i]%1000)>(k[j]%1000))
			{
				temp = k[i];
				k[i] = k[j];
				k[j] = temp;
			}
			else if((k[i] % 1000) == (k[j] % 1000))
			{
				if (k[i] < k[j])
				{
					temp = k[i];
					k[i] = k[j];
					k[j] = temp;
				}
			}
		}
		printData(k, n, i);
	}
}

typedef struct person
{
	int code;
	struct person *next;//��������Ľṹ��
};

#define PEOPLE_NUM 41
#define JUMP_NUM 3

//��Ȧ����
void outList()
{
	int i;
	int count = 1;//��Ϊ�������α�
	int outNum = 0;//ͳ�Ƴ����������ж�ѭ������������
	person list[PEOPLE_NUM];
	person *start_person = list;
	//��ʼ���ṹ��
	for (i = 0; i<PEOPLE_NUM; i++)
	{
		list[i].code = i + 1;//��Ա���
		list[i].next = &list[i + 1];
		if (list[i].code == PEOPLE_NUM)
		{
			list[i].next = &list[0];
		}
	}

	while (outNum<PEOPLE_NUM)
	{
		if ((count + 1) % JUMP_NUM == 0)
		{
			count = 0;
			outNum++;
			printf("%d\n", start_person->next->code);
			//Ǩ�ƽڵ�
			start_person->next = start_person->next->next;
		}
		start_person = start_person->next;
		count++;
	}
}

//����ת��
void fun(int m, int k)
{
	if(m%k == 0)
	{
		fun(m / k, k);
		printf("%d", m%k);
	}
	else printf("%d", m%k);//�˴���Ҫ����������1��ӡ����������������˳��ݹ�
}

//ð������(����)
void BubbleSort_shengxu(int *k, int n)
{
	int i, j, temp, flag;
	for (i = 0; i < n; i++)
	{
		for (j = i+1; j < n; j++)
		{
			//����������
			if (k[i]>k[j])
			{
				temp = k[i];
				k[i] = k[j];
				k[j] = temp;

				flag = 1;
			}

		}
		printData(k, n, i);
	}
}

int fun_getLen(char *s)
{
	int len=0;
	while(*(s++)!='\0')
	{
		len++;
		}
	return len;
}

float s[30], w[6];
void fun1(float s[])
{
	int k, i;
	for(k=2,i=0;i<30;i++)
	{
		s[i] = k;
		k+=2;
	}
}

void fun2(float s[], float w[])
{
	float sum = 0;
	int k, i;
	for(k=0,i=0;i<30;i++)
	{
		sum += s[i];
		if((i+1)%5!=0) 
			continue;
		{
			w[k] = sum / 5;
			sum = 0;
			k++;
		}
	}
}

void fun(char *s1,char *s2)
{
	//float a = 2.2;
	char *p1 = s1, *p2;
	while(*s1)
	{
		p2 = s2;
		while(*p2&&(*s2 != *s1))//edit
			p2++;
					
		if (*p2 == '\0') *p1++ = *s1;

		s1++;
	}
	*(--p1) = '\0';//edit

	//return a;
}

void PrintCharNtimes(char c, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%c", c);
		
	}
	
}

//���ַ�����Ԫ��
int fun1(int a[], int n, int key)
{
	int low, high, mid;
	low = 0; high = n - 1;
	while(low<=high)
	{
		mid = (low + high) / 2;
		if (key < a[mid])
			high=mid-1;
		else if (key > a[mid])
			low=mid+1;
		else
			return mid;
	}
	return -1;
}
//����ȱ�������
void fun2(char a, int h)
{
	if(h>0)
	{
		printf("%c", a);
		fun2(a, h-1);
	}
}

//�����Ӵ�s2���ַ���s1�г��ֵĴ���
int findstring(char *s, char *t)
{
	int num = 0;
	char *p, *q;
	for(;*s!='\0';s++)
	{
		if(*s!=*t)
			continue;
		else
		{
			for(p=s,q=t;*q!='\0';p++,q++)
			{
				if(*p!=*q)
					break;
			}
			if (*q == '\0')
				num++;
		}
	}
	return num;
}

void strcopy(char *str1, char *str2, int m)
{
	char *p1, *p2;
	p1 = str1 + m;
	p2 = str2;
	while(*p1)
	{
		*p2++ = *p1++;
	}
	*p2 = '\0';
}

//�ַ�������
void MyStrcpy(char *s, char *t)
{
	while((*t=*s)!='\0')//�ȸ�ֵ���жϣ�����\0�ᱻ���ƹ�ȥ
	{
		t++;
		s++;
	}
}

//10���˵ĳɼ������ɸߵ��ͣ�����ӡ�ɼ��������ѧ������
void sort(char score[], int n)
{
	int i, j;
	int startIndex = 1;
	int stopIndex = n-1;
	float temp;
	for(i= startIndex;i<stopIndex -1;i++)
	{
		for(j=i+1;j<stopIndex;j++)//ע��ð�ݷ��Ĵ˴���j=i,iֻ������������Ƚ�
		{
			if(score[i]>score[j])
			{
				temp = score[i];
				score[i] = score[j];
				score[j] = temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%c ", score[i]);
	}
}

int fail(float score[], int n)
{
	int i,count=0;
	for(i=0;i<n;i++)
	{
		if (score[i] < 60)
			count++;
	}
	return count;
}

//������ϸ�ʽ����
int getZuHe(int n, int x,int v)
{
	int i, ret=0;
	int a=1, b=1, c=1;
	for(i=1;i<=n;i++)
	{
		a *= i;
	}
	for(i=1;i<=n-x;i++)
	{
		b *= i;
	}
	for (i = 1; i <= x; i++)
	{
		c *= i;
	}
	ret = a / (b*c);
	return ret;
}

typedef struct t_Count
{
	char index;
	int num;
};

void fun(char *s, int *len)
{
	while (*s!='\0')
	{
		*len++;
		s++;
	}
}

int main()
{

}

/*ͳ���ַ����ִ����������ģ����в��У���ȡasciiֵС��
	int n = 26;
	int i, j;
	char s[200],*p,temp;
	//���ýṹ����������
	//int count[26][2] = { 0 };//��һ�д��ַ�A-Z,�ڶ��д���ִ���
	t_Count count[26];
	//��ʼ��
	for(i=0;i<n;i++)
	{
		count[i].index = + i;
		count[i].num = 0;
	}
	scanf("%s", s);
	p = s;
	
	//ͳ��Ƶ��
	while(*p!='\0')
	{
		temp = *p;
		if(temp >='A'&& temp <='Z')
		{
			count[temp-'A'].num++;
		}
		p++;
	}

	//����
	
	t_Count a;
	for(i=0;i<n -1;i++)
	{
		for(j=1;j<n;j++)
		{
			//�����ṹ����Ϣ
			if(count[i].num<count[j].num)
			{
				a = count[j];
				count[j] = count[i];
				count[i] = a;
			}
			//���������ͬ����asciiֵС�ķ�ǰ��
			if((count[i].num==count[j].num) && (count[i].index > count[j].index))
			{
				a = count[j];
				count[j] = count[i];
				count[i] = a;
			}
		}
	}

	printf("%c %d", count[0].index + 'A', count[0].num);
}*/

	/*����pi/2=2/1 *2/3 *4/3 *4/5 *6/5 *6/7*...��ǰ100��֮��,��̼���p��ֵ
	 *int i = 0;
	float  m = 1, n = 2;
	float ret = 1;
	for(i=0;i<100;i++)
	{
		if (i % 2 == 0)
		{
			ret *= n / m;
			//printf("ret*=:%f/%f\n", n,m);
			n++, m++;
		}
		else
		{
			ret *= m / n;
			//printf("ret*=:%f/%f\n", m, n);
			n++, m++;
		}
	}
	printf("pi is:%f",ret*2);
}*/
/*����ȱ�������
int i, h;
	//scanf("%d",&h);
	h = 3;
	for(i=1;i<=h;i++)
	{
		fun2(' ', h-i);
		fun2('*', 2 * i - 1);
		printf("\n");
	}
	*/


/*������һ�������ǡ�õ�����������֮�ͣ���������
 * int maxNum = 5000;
	int i = 0, j = 0, sum = 0;
	for (i = 2; i <= maxNum; i++)
	{
		sum = 0;
		for (j = 1; j<i; j++)
		{
			if (i%j == 0)
			{
				sum += j;
			}
		}
		if (i == sum)
		{
			printf("%d  ", i);
			printf("its factors are ");
			for (j = 1; j<i; j++)
			{
				if (i%j == 0)
				{
					printf("%d,", j);
				}
			}
			printf("\n");
		}
	}
 */
	/*//���������!!!�ص���
	//ʵ�������inputΪ 0,1,1,1,0,1,1,1,1,ǰ��Ҫ������0
	int input[11] = {0,0,0,1,1,1,0,1,1,1,1};
	int output[9][3] = {0};

	for(int i=2;i<11;i++)
	{
		output[i - 2][0] = input[i];
		output[i - 2][1] = input[i] ^ input[i - 2];
		output[i - 2][2] = input[i] ^ input[i - 1] ^ input[i - 2];
	}

	for(int i=0;i<9;i++)
	{
		printf("%d: ", input[i+2]);
		for(int j=0;j<3;j++)
		{
			printf("%d ", output[i][j]);
		}
		printf("\n");
	}*/


	/*int ret = 1;
	int num = 123456;
	while(num!=0)
	{
		ret *= num % 10;
		num /= 10;
	}
	printf("%d", ret);*/

	/*int Fa = 1, Fb = 1, Fc = 0, i = 2;
	printf("%d %d ", Fa,Fb);
	while(i<20)
	{
		Fc = Fa + Fb;
		printf("%d ", Fc);
		i++;
		if(i%5==0)
		{
			printf("\n");

		}
		Fa = Fb;
		Fb = Fc;
	}*/


	/*char *a="a233acdf4df2c#";
	//scanf("%s", a);
	int flag=1;//�����
	while(*a!='#')
	{
		if(*a>='0'&&*a<='9')
		{
			if(flag==0)
			{
				printf(" ");
			}
			flag = 1;
			PrintCharNtimes(*(a + 1), *a - 0x30+1);//n+1��
			printf(" ");
			a++;
		}
		else
		{
			flag = 0;
			printf("%c", *a);
		}
		a++;
	}*/



	//int a[5] = {5,2,3,4,2};
	//InsertSort(a,5);
	//BubbleSort(a,5);
	//SelectSort(a,5);
	//QuickSort(a,5);
	//getNum(100);
	//int ret = getStairsTimes(3);
	//int a,b,n=1,i=0;
	//int ret;
	//int h, m, s;
	//char *x;
	//oj_B_init(40);
	//while (1)
	//{
	//printf("%d\n", sizeof(int));
		//scanf("%d\n", &n);
		//n = 1;
		//��̬�����ڴ棬�����ṹ����������
	
	/*T_Data *t_Data = (T_Data *)malloc(sizeof(T_Data)*n);
		while (scanf("%s %s", t_Data[i].wordsA, t_Data[i].wordsB) != EOF)
		{
			//for(i=0;i<n;i++)
			//{
			//	scanf("%s %s", t_Data[i].wordsA, t_Data[i].wordsB);
			//scanf("%d:%d:%d %d:%d:%d", &t_Data[i].HH, &t_Data[i].MM, &t_Data[i].SS, &t_Data[i].hh, &t_Data[i].mm, &t_Data[i].ss);
			//gets_s(t_Data[i].words,sizeof(t_Data[i].words));
			//t_Data[i].numB = b;
			//}
			//for (i = 0; i<n; i++)
			//{

			t_Data[i].A = oj_G(t_Data[i].wordsA);
			t_Data[i].B = oj_G(t_Data[i].wordsB);
			printf("%d\n", t_Data[i].A + t_Data[i].B);
			//}
		}
		free(t_Data);*/


