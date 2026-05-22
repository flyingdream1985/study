//#define
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

typedef struct data {
	char name[10];
	char number[20];
	bool sex;
	int grade;
}DATA;//创建结构体，包含名字，学号，性别，成绩；

typedef struct user 
{
	char ID[20];
	char PASSWORD[20];
}USER;//创建结构体，包含用户账号、密码

short login() {
	USER user[3] = { {"123456789","13141158"},{"223589","11475896"},{"gzm2333","GZMgzmzm"} };
	char id[20];//待输入账号
	char password[20];//待输入密码

	int n = 0;
	n = sizeof(user) / sizeof(user[0]);//计算账号个数

	printf("请输入你的账号：\n");
	//gets_s(id);
	scanf_s("%s", id, sizeof(id));
	for (int i = 0; i < n; i++) 
	{
		if (strcmp(user[i].ID, id)==0) //寻找对应账号
		{
			printf("请输入密码：\n");
			gets_s(password);
			if (strcmp(user[i].PASSWORD, password)==0)//寻找对应密码
			{
				printf("密码正确！");
				return 1;
			}
				
		}
	}
	printf("无该账号");
	return 0;
}//账号登录

short cornumb(char number[],int n) //判断学号位数，类型,若不符合要求则输出0
{
	while (1) 
	{
		if (strlen(number) != 10) //判断学号位数，如果不是10位则输出0
		{
			printf("学号输入错误，应有10位数，您输入了%d位数\n", (int)strlen(number));
			return 0;
		}

		for (int i = 0; i < 10; i++)//判断学号类型，如果含有非数字则输出0
		{
			if (isdigit(number[i]) == 0)
			{
				printf("学号含有未知字符，请重新输入\n");
				return 0;
			}
			if (9 == i)	//如果学号无未知字符，则输出1，进行下一步
				return 1;
		}
	}
}

int main() 
{
	int a = 0;
	
	if (login())
	{
		DATA people;
		while(1)
		{
			printf("请依次输入名字，学号，性别(男生输入0/女生输入1)，成绩\n");
			scanf_s("%s%s%d%d", &people.name, 10, &people.number, 20, (bool) & people.sex, &people.grade);//获得名字 学号 性别 成绩
			if (cornumb(people.number, 20))
				break;
		}
		if (people.sex && people.grade > 80)
			printf("恭喜你进入面试");
		else
			printf("抱歉，你没有进入面试");
	}
	return 0;
}
























//short login() {
//	char ID[3][20] = { "123456789", "223589", "gzm2333" };//初始化账号
//	char id[20];//待输入账号
//	char PASSWORD[3][20] = { "13141158", "11475896", "GZMgzmzm" };//初始化密码
//	char password[20];//待输入密码
//	int n = 0;//账号个数
//	n = sizeof(ID) / sizeof(ID[0]);//计算账号个数
//
//	printf("请输入你的账号：\n");
//	//scanf("%s", &id);//&
//	gets_s(id);
//	for (int i = 0; i < n; i++)
//	{
//		if (strcmp(ID[i], id)) //寻找对应账号
//		{
//			printf("请输入密码：\n");
//			//scanf("%s",&password);//&
//			gets_s(password);
//			for (int j = 0; j < n; j++)
//			{
//				if (strcmp(PASSWORD[j], password))//寻找对应密码
//				{
//					printf("密码正确！");
//					return 1;
//				}
//			}
//
//		}
//		printf("ji");
//	}
//	printf("无该账号");
//	return 0;
//}//账号登录


//gets_s(people.name);
			//gets_s(people.number);
			//scanf_s("%d",&people.sex);
			//scanf_s("%d", &people.grade);
			/*strcpy_s(people.name, "xxx");
			strcpy_s(people.number, "1234567890");
			people.sex = 1;
			people.grade = 70;*/





//#include<stdio.h>
//int XUNZHI(int a) //判断是否为质数
//{
//	if (2 == a)//为2直接输出质数
//	{
//		return 1;//质数输出1
//	}
//	for (int i = 2; i < a; i++)//直到a-1仍没有能整除则为质数
//	{
//		if (a % i == 0)
//			return 0;//非质数输出0
//		if (i == a - 1)
//		{
//			return 1;//质数输出1
//		}
//	}
//}
//
//int main() {
//	int a, i;
//	for (a = 2, i = 0; i < 100; a++)
//	{
//		if (XUNZHI(a)) //诺为质数则打印并用i记录
//		{
//			printf("%d  ", i);//显示序号，可省略
//			printf("%d\n", a);
//			i++;
//			
//		}
//	}
//	return 0;
//}


//#include<stdio.h>
//
//int count_1 = 0;//定义全局变量count_1
//int count_2 = 0;//定义全局变量count_2
//int getCallCount() {
//	count_1++;
//	count_2++;
//	return count_1, count_2;
//}//使全局变量count_1与count_2均增加1
//
//int main() {
//	int count_2 = 0;
//	for (int i = 0; i < 5; i++) {
//		printf("%d\n",getCallCount());
//	}//循环调用函数
//	printf("XXX：%d\n", count_1);//展示全局变量
//
//	printf("XXX；%d\n", count_2);//展示局部变量
//	return 0;
//}












//#include<stdio.h>
//int XUNZHI(int a) {
//	for (int i = 2; i<a; i++) {
//		if (a % i == 0)//如果能整除输出0
//			return 0;
//		if (i == a - 1)//如果到a-1还不能整除说明是质数，打印质数，并输出1
//		{
//			printf("%d", a);
//			return 1;
//		}
//	}
//}//寻找质数
//int main() {
//	int a, i;
//	for (i = 0, a = 2; i < 100; a++) 
//	{	
//		if (2 == a) //判断是否为2，如果为2则输出2，并使所找到的质数加一
//		{
//			printf("%d", a);
//			i++;
//			printf("  %d\n", i);//用于方便计算所找到的质数，可省略
//		}
//		else if (XUNZHI(a)) //如果不为二，则判断是否为质数，是为1，否为0
//		{
//			i++;
//			printf("  %d\n", i);//用于方便计算所找到的质数，可省略
//		}
//	}
//		
//	return 0;
//}