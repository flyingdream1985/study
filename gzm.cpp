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
}DATA;//�����ṹ�壬�������֣�ѧ�ţ��Ա𣬳ɼ���

typedef struct user 
{
	char ID[20];
	char PASSWORD[20];
}USER;//�����ṹ�壬�����û��˺š�����

short login() {
	USER user[3] = { {"123456789","13141158"},{"223589","11475896"},{"gzm2333","GZMgzmzm"} };
	char id[20];//�������˺�
	char password[20];//����������

	int n = 0;
	n = sizeof(user) / sizeof(user[0]);//�����˺Ÿ���

	printf("����������˺ţ�\n");
	//gets_s(id);
	scanf_s("%s", id, sizeof(id));
	for (int i = 0; i < n; i++) 
	{
		if (strcmp(user[i].ID, id)==0) //Ѱ�Ҷ�Ӧ�˺�
		{
			printf("���������룺\n");
			gets_s(password);
			if (strcmp(user[i].PASSWORD, password)==0)//Ѱ�Ҷ�Ӧ����
			{
				printf("������ȷ��");
				return 1;
			}
				
		}
	}
	printf("�޸��˺�");
	return 0;
}//�˺ŵ�¼

short cornumb(char number[],int n) //�ж�ѧ��λ��������,��������Ҫ�������0
{
	while (1) 
	{
		if (strlen(number) != 10) //�ж�ѧ��λ�����������10λ�����0
		{
			printf("ѧ���������Ӧ��10λ������������%dλ��\n", (int)strlen(number));
			return 0;
		}

		for (int i = 0; i < 10; i++)//�ж�ѧ�����ͣ�������з����������0
		{
			if (isdigit(number[i]) == 0)
			{
				printf("ѧ�ź���δ֪�ַ�������������\n");
				return 0;
			}
			if (9 == i)	//���ѧ����δ֪�ַ��������1��������һ��
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
			printf("�������������֣�ѧ�ţ��Ա�(��������0/Ů������1)���ɼ�\n");
			scanf_s("%s%s%d%d", &people.name, 10, &people.number, 20, (bool) & people.sex, &people.grade);//������� ѧ�� �Ա� �ɼ�
			if (cornumb(people.number, 20))
				break;
		}
		if (people.sex && people.grade > 80)
			printf("��ϲ���������");
		else
			printf("��Ǹ����û�н�������");
	}
	return 0;
}
























//short login() {
//	char ID[3][20] = { "123456789", "223589", "gzm2333" };//��ʼ���˺�
//	char id[20];//�������˺�
//	char PASSWORD[3][20] = { "13141158", "11475896", "GZMgzmzm" };//��ʼ������
//	char password[20];//����������
//	int n = 0;//�˺Ÿ���
//	n = sizeof(ID) / sizeof(ID[0]);//�����˺Ÿ���
//
//	printf("����������˺ţ�\n");
//	//scanf("%s", &id);//&
//	gets_s(id);
//	for (int i = 0; i < n; i++)
//	{
//		if (strcmp(ID[i], id)) //Ѱ�Ҷ�Ӧ�˺�
//		{
//			printf("���������룺\n");
//			//scanf("%s",&password);//&
//			gets_s(password);
//			for (int j = 0; j < n; j++)
//			{
//				if (strcmp(PASSWORD[j], password))//Ѱ�Ҷ�Ӧ����
//				{
//					printf("������ȷ��");
//					return 1;
//				}
//			}
//
//		}
//		printf("ji");
//	}
//	printf("�޸��˺�");
//	return 0;
//}//�˺ŵ�¼


//gets_s(people.name);
			//gets_s(people.number);
			//scanf_s("%d",&people.sex);
			//scanf_s("%d", &people.grade);
			/*strcpy_s(people.name, "xxx");
			strcpy_s(people.number, "1234567890");
			people.sex = 1;
			people.grade = 70;*/





//#include<stdio.h>
//int XUNZHI(int a) //�ж��Ƿ�Ϊ����
//{
//	if (2 == a)//Ϊ2ֱ���������
//	{
//		return 1;//�������1
//	}
//	for (int i = 2; i < a; i++)//ֱ��a-1��û����������Ϊ����
//	{
//		if (a % i == 0)
//			return 0;//���������0
//		if (i == a - 1)
//		{
//			return 1;//�������1
//		}
//	}
//}
//
//int main() {
//	int a, i;
//	for (a = 2, i = 0; i < 100; a++)
//	{
//		if (XUNZHI(a)) //ŵΪ�������ӡ����i��¼
//		{
//			printf("%d  ", i);//��ʾ��ţ���ʡ��
//			printf("%d\n", a);
//			i++;
//			
//		}
//	}
//	return 0;
//}


//#include<stdio.h>
//
//int count_1 = 0;//����ȫ�ֱ���count_1
//int count_2 = 0;//����ȫ�ֱ���count_2
//int getCallCount() {
//	count_1++;
//	count_2++;
//	return count_1, count_2;
//}//ʹȫ�ֱ���count_1��count_2������1
//
//int main() {
//	int count_2 = 0;
//	for (int i = 0; i < 5; i++) {
//		printf("%d\n",getCallCount());
//	}//ѭ�����ú���
//	printf("XXX��%d\n", count_1);//չʾȫ�ֱ���
//
//	printf("XXX��%d\n", count_2);//չʾ�ֲ�����
//	return 0;
//}












//#include<stdio.h>
//int XUNZHI(int a) {
//	for (int i = 2; i<a; i++) {
//		if (a % i == 0)//������������0
//			return 0;
//		if (i == a - 1)//�����a-1����������˵������������ӡ�����������1
//		{
//			printf("%d", a);
//			return 1;
//		}
//	}
//}//Ѱ������
//int main() {
//	int a, i;
//	for (i = 0, a = 2; i < 100; a++) 
//	{	
//		if (2 == a) //�ж��Ƿ�Ϊ2�����Ϊ2�����2����ʹ���ҵ���������һ
//		{
//			printf("%d", a);
//			i++;
//			printf("  %d\n", i);//���ڷ���������ҵ�����������ʡ��
//		}
//		else if (XUNZHI(a)) //�����Ϊ�������ж��Ƿ�Ϊ��������Ϊ1����Ϊ0
//		{
//			i++;
//			printf("  %d\n", i);//���ڷ���������ҵ�����������ʡ��
//		}
//	}
//		
//	return 0;
//}