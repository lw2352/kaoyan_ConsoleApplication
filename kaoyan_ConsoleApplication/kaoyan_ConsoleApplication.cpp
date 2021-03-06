// kaoyan_ConsoleApplication.cpp : 定义控制台应用程序的入口点。
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
			printf("%d ", i);
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
	char wordsA[MAX_NUM];
	char wordsB[MAX_NUM];

	int A;
	int B;
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

//把字符串数字转成int型，要判断正负和去掉逗号
int oj_G(char *s)
{
	int i,j;
	int len;
	int ret=0;
	char *newS;
	
	len = strlen(s);

	newS = (char *)malloc(len * sizeof(char));

	if(len>12)//长度=1个负号+9个数字+2个逗号
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

//检测输入数值是否为素数
int checkSuShu(int num)
{
	int i;
	for(i=2;i<num;i++)
	{
		if(num%i==0)
		{
			//不是素数
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
	//给矩阵初始化
	for (i = 0; i<N; i++)
	{
		for (j = 0; j<N; j++)
		{
			NN[i][j] = rand() % 100;
			printf("%d ", NN[i][j]);
		}
		printf("\n");
	}

	//找素数
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

	//计算对角线元素之和（两条）
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

//对输入参数保留3位小数，四舍五入
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
//检查是否是数组的列上最小值
int getMin(int j)
{
	int i=0;
	int min=0;//鞍点值

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

//冒泡排序，第五道编程题
void BubbleSort_1(int k[], int n)
{
	int i, j, temp;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i; j < n; j++)
		{
			//调整成升序
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
	struct person *next;//引用自身的结构体
};

#define PEOPLE_NUM 41
#define JUMP_NUM 3

//出圈问题
void outList()
{
	int i;
	int count = 1;//作为报数的游标
	int outNum = 0;//统计出队人数，判断循环结束的条件
	person list[PEOPLE_NUM];
	person *start_person = list;
	//初始化结构体
	for (i = 0; i<PEOPLE_NUM; i++)
	{
		list[i].code = i + 1;//人员编号
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
			//迁移节点
			start_person->next = start_person->next->next;
		}
		start_person = start_person->next;
		count++;
	}
}

//进制转换
void fun(int m, int k)
{
	if(m%k == 0)
	{
		fun(m / k, k);
		printf("%d", m%k);
	}
	else printf("%d", m%k);//此处需要把最后的余数1打印出来，并由里而外退出递归
}

//冒泡排序(升序)
void BubbleSort_shengxu(int *k, int n)
{
	int i, j, temp, flag;
	for (i = 0; i < n; i++)
	{
		for (j = i+1; j < n; j++)
		{
			//调整成升序
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

//二分法查找元素
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
//输出等边三角形
void fun2(char a, int h)
{
	if(h>0)
	{
		printf("%c", a);
		fun2(a, h-1);
	}
}

//查找子串s2在字符串s1中出现的次数
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

//字符串复制
void MyStrcpy(char *s, char *t)
{
	while((*t=*s)!='\0')//先赋值再判断，最后的\0会被复制过去
	{
		t++;
		s++;
	}
}

//10个人的成绩排序，由高到低，并打印成绩不及格的学生人数
void sort(char score[], int n)
{
	int i, j;
	int startIndex = 1;
	int stopIndex = n-1;
	float temp;
	for(i= startIndex;i<stopIndex -1;i++)
	{
		for(j=i+1;j<stopIndex;j++)//注意冒泡法的此处，j=i,i只和它后面的数比较
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

//根据组合格式计算
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

//2017（845）的第16题，计算组合数，用的递归公式，注意需要return的地方!!!
int combin(int m,int n)
{
	int com;
	if (n < 2 * m) return(combin(n - m, n));//第一次写的时候掉了，导致会继续跑下面的句子，实际上应该返回

	if (m == 0) com = 1;
	else if (m == 1) return n;
	else return( combin(m, n - 1) + combin(m - 1, n - 1));

	return com;
}

//2017（845）的第17题,按降序完成从大到小的排序
int Array[10] = { 1,3,5,7,9,2,4,6,8,0 };

void swap(int *x,int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y=temp;
}

void sort(int *p, int *q)
{
	int *max, *s;
	if (p == &Array[9])
		return;
	max = p;
	for (s = p + 1; s <= q; s++)
		if (*s > *max)
		{
			max=s;
		}

	swap(p, max);
	sort(++p,s);
}

//char str[80] = "asasasa", substr[80]="asa";
//统计子串substr在字符串str中出现的次数
int fun3(char *substr, char *str)
{
	int i, j, k, num = 0;
	for (i = 0; str[i]; i++)
	{
		for (j = i, k = 0; substr[k] == str[j]; k++, j++)
		{
			if (substr[k+1] == '\0')
			{
				num++;
				break;
			}
		}
	}

	return num;
}

int f(int a)
{
	int b = 0;
	static int c = 3;
	b++; c++;
	return (a+b+c);
}
int main()
{
	int num, a[10], r;
	int i = 0, j, flag = 1;
	scanf("%d", &num);
	if (num <= 0) return -1;

	do
	{
		r = num % 10;
		a[i] = r;
		num = num / 10;
		i++;
	} while (num % 10 != 0);

	for(j=0,i--;i>=j;i--,j++)
		if(a[j]!=a[i])
		{
			flag = 0; 
			break;
		}

	if (flag == 1)
		printf("YES");
	else printf("NO");
	
	
}

/*统计字符出现次数，找最多的，若有并列，则取ascii值小的
	int n = 26;
	int i, j;
	char s[200],*p,temp;
	//改用结构体类型数组
	//int count[26][2] = { 0 };//第一列存字符A-Z,第二列存出现次数
	t_Count count[26];
	//初始化
	for(i=0;i<n;i++)
	{
		count[i].index = + i;
		count[i].num = 0;
	}
	scanf("%s", s);
	p = s;
	
	//统计频度
	while(*p!='\0')
	{
		temp = *p;
		if(temp >='A'&& temp <='Z')
		{
			count[temp-'A'].num++;
		}
		p++;
	}

	//排序
	
	t_Count a;
	for(i=0;i<n -1;i++)
	{
		for(j=1;j<n;j++)
		{
			//交换结构体信息
			if(count[i].num<count[j].num)
			{
				a = count[j];
				count[j] = count[i];
				count[i] = a;
			}
			//如果次数相同，把ascii值小的放前面
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

	/*利用pi/2=2/1 *2/3 *4/3 *4/5 *6/5 *6/7*...的前100项之积,编程计算p的值
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
/*输出等边三角形
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


/*完数，一个数如果恰好等于它的因子之和，不含本身
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
	/*//卷积编码器!!!重点题
	//实际输入的input为 0,1,1,1,0,1,1,1,1,前面要加两个0
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
	int flag=1;//分组别
	while(*a!='#')
	{
		if(*a>='0'&&*a<='9')
		{
			if(flag==0)
			{
				printf(" ");
			}
			flag = 1;
			PrintCharNtimes(*(a + 1), *a - 0x30+1);//n+1次
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
		//动态申请内存，创建结构体类型数组
	
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


