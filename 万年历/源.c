#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
void execute1();   // ����1 
void log_in();     //��¼���� 
void execute2();   // ����2 
void execute3();  // ����3 �������ú��� 
void jduge();     //�ж��Ƿ��ǽ���   
void execute4();  // ����4 
void hint();      //�����ʽ������ʾ����������һ�� 
void Select();   //ѡ��ʵ�ֹ��� 
void Menu();    //�˵�ҳ�� 
void exit();    //�˳� 
int DAY(int y, int m, int d);  //����3���ú��������յ�1900-1-1�������� 

int main()
{
	system("cls");
	log_in();
	char ch;
	ch = _getch();
	if (ch == 27);
	else
		Select();
}


void log_in()
{
	system("color FA");
	printf("\n\n\n\n\n");
	printf("===============================================================\n");
	printf(" \t\t    �I(^��^)�J        �I(^��^)�J\n\n");
	printf("\t~~~///(^v^)\\\\\\~~~   �����������˵�    ~~~///(^v^)\\\\\\~~~ \n\n");
	printf("\t\t ��__��y                     ��__��y \n\n");
	printf(" \t\t  >_<       ��Esc�˳�����      >_< \n\n");
	printf("================================================================");
}




//Select����   �������ܣ�1�����ò˵���2ѡ�������ѯ��Ŀ�� 
void Select()
{
	Menu();
	char c;
loop:c = _getch();
	if (c > '9' || c < '0')
	{
		system("cls");
		Menu();
		goto loop;
	}
	else
		printf("%c", c);
	if (c - '0' > 4 || c - '0' < 1)
		hint();
	else
		switch (c - '0')
		{
		case 1:
			system("cls");
			execute1();
			main();
		case 2:
			system("cls");
			execute2();
			main();
			break;
		case 3:
			system("cls");
			execute3();
			main();
			break;
		case 4:
			system("cls");
			execute4();
			main();
			break;
		}

}


//hint ����         �ж������Ƿ���ȷ
void hint()
{
	system("cls");
	printf("���������ʽ�����밴�س�������");
	getchar();
	getchar();
	Select();
}


//**����1������ʹ�ú��� 
long int f(int year, int month)

{

	if (month < 3) return year - 1;

	else return year;

}/*f(�꣬��)���꣭1������<3;����f(�꣬��)����*/
long int g(int month)

{

	if (month < 3) return month + 13;

	else return month + 1;

}/*g(��)���£�13������<3;����g(��)���£�1*/
long int n(int year, int month, int day)

{

	return 1461L * f(year, month) / 4 + 153L * g(month) / 5 + day;

}/*N=1461*f(�ꡢ��)/4+153*g(��)/5+��*/
int w(int year, int month, int day)

{

	return(int)((n(year, month, day) % 7 - 621049L % 7 + 7) % 7);

}/*w=(N-621049)%7(0<=w<7)*/
int date[12][6][7];

int day_tbl[][12] = { { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },

{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };

void execute1()

{
	system("color 0F");

	int sw, leap, i, j, k, wd, day;

	int year;/*��*/

	char title[] = "SUN MON TUE WED THU FRI SAT";

	system("cls");

	printf("Please input the year whose calendar you want to know: ");/*������*/

	scanf("%d%*c", &year);/*�������ֵ���ӹ�ֵ��Ļس�*/

	sw = w(year, 1, 1);

	leap = year % 4 == 0 && year % 100 || year % 400 == 0;/*������*/

	for (i = 0; i < 12; i++)

		for (j = 0; j < 6; j++)

			for (k = 0; k < 7; k++)

				date[i][j][k] = 0;/*���ڱ���0*/

	for (i = 0; i < 12; i++)/*һ��ʮ������*/

		for (wd = 0, day = 1; day <= day_tbl[leap][i]; day++)

		{/*����i��1�µ������������ڱ�*/

			date[i][wd][sw] = day;

			sw = ++sw % 7;/*ÿ�������죬��0��6����*/

			if (sw == 0) wd++;/*���ڱ�ÿ����һ�У������쿪ʼ�µ�һ��*/

		}

	printf("\n|==================The Calendar of Year %d =====================|\n|", year);

	for (i = 0; i < 6; i++)

	{/*�Ȳ����i+1�º͵�i+7�µ����������*/

		for (wd = 0, k = 0; k < 7; k++)/*���ڱ�ĵ����������ڣ���wd!=0*/

			wd += date[i][5][k] + date[i + 6][5][k];

		wd = wd ? 6 : 5;

		printf("%2d %s %2d %s |\n|", i + 1, title, i + 7, title);

		for (j = 0; j < wd; j++)

		{

			printf("  ");/*����ĸ��հ׷�*/

			/*����Ϊ��i+1�£�����Ϊ��i+7��*/

			for (k = 0; k < 7; k++)

				if (date[i][j][k])

					printf("%4d", date[i][j][k]);

				else printf(" ");

			printf(" ");/*���ʮ���հ׷�*/

			for (k = 0; k < 7; k++)

				if (date[i + 6][j][k])

					printf("%4d", date[i + 6][j][k]);

				else printf(" ");

			printf(" |\n|");

		}

		/*scanf("%*c");/*����س������һ���µ�����*/

	}

	puts("=================================================================|");

	getchar();

}
// **����1���� 





void execute2()
{
	system("color F4");
	int Year, Month; //�ꡢ��
	int FirstDay_Year, FirstDay_Month; //ĳ��ĵ�һ�������ڼ�,ĳ��ĳ�µĵ�һ�������ڼ�(��Χ��0~6,����0����������)
	int IsLeapYear; //�Ƿ�Ϊ���꣬0��ʾ��������,1��ʾ������
	int i, d, y; //��ʱ����
	char YN; //Yes No,�����Ƿ�Ҫ����
	int Days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	//Days[1~12]�洢ÿ�����ж����죬���ж��µ������ǿɱ��(����29��,ƽ��28��),�����ʼ��Ϊ28��
XunHuan: //ѭ�����(����ͨ��goto��ת������)
	system("cls");// ���� 
	printf(" C���Լ�������\n"); //��ӡ���� 
	printf("���������<0000~9999>: "); //��ʾ�������(0~9999)
	scanf("%d", &Year); //���������ݸ�ֵ������Year
	printf("�������·�<0~12>: "); //��ʾ�����·�(1~12)
	scanf("%d", &Month); //��������·ݸ�ֵ������Month
	if (Year > 9999 || Year < 0 || Month>12 || Month <= 0)
	{
		printf("���������밴�س�����������");
		getchar();
		getchar();
		goto XunHuan;
	}
	y = Year;
	FirstDay_Year = 5 * (y / 4) + (y % 4) - (y / 100) + (y / 400);//���չ�ʽ(����ĳ��ĵ�һ�������ڼ�)
	IsLeapYear = (y % 4 == 4 && y % 100 != 100 || y % 400 == 0) ? 1 : 0;
	//�ж��Ƿ�Ϊ����
	Days[2] = (IsLeapYear == 1) ? 29 : 28; //�������29��,���������28��
	for (i = 1, d = 0; i < Month; i++)
		d = d + Days[i];
	FirstDay_Month = (d + FirstDay_Year) % 7; //���µĵ�һ�������ڼ�(0����������)
	printf("\n****************************************************\n");
	printf("\t\t��Ԫ %d �� %2d ��", Year, Month); //��ӡ����
	printf("\n****************************************************\n");
	printf(" ������ ����һ ���ڶ� ������ ������ ������ ������\n");
	//��ӡ���ڱ�ͷ
	for (i = 0; i < FirstDay_Month; i++)
		printf("%7c", ' '); //��ĳ�µĵ�һ�첻��������ʱ��ӡ�ո�ռλ
	for (d = 1; d <= Days[Month]; d++) //ѭ��,��ÿ���µĵ�һ�쿪ʼ��ӡ
	{
		printf("%7d", d);
		if (((d + FirstDay_Month) % 7) == 0 && d < Days[Month])
			printf("\n"); //����������������һ�δ�����������ʱ,����
	}
	printf("\n****************************************************\n");
	printf("\n");
	printf("�Ƿ����(Y/N)?\n");
	scanf("%c", &YN);
	scanf("%c", &YN);
	if (YN == 'Y' || YN == 'y')
		goto XunHuan;
}


//execute 3����      ���ܣ�ʵ�ֲ˵�����3; 



void execute3()
{
	system("color 8A");
	int year, month, day;
	int days;
	int week = 0;
	char a[] = { "����" };
	char b[7][4] = { "��","һ","��","��","��","��","��" };
loop:printf("�������� �� �գ�   (�ո�ָ�)\n");
	scanf("%d %d %d", &year, &month, &day);
	days = DAY(year, month, day);//���վ���1900��1��1�յ����� 
	if (days == -1)
	{
		system("cls");
		printf("�����ʽ����,����������   \n");
		fflush(stdin);
		goto loop;
	}
	else
	{
		week = days % 7;
		printf("\n\n*****************************************************\n\n");
		printf("\t\t%d��%d��%d����%s%s\n\n", year, month, day, a, b[week]);
		printf("\t\t  =^_^= \t  =^_^= \n\n");
		jduge(month, day);
		printf("\n\t\t  >o<\t\t     >o<\t\n\n");
		printf("*****************************************************\n");
		system("pause");
	}
}



void shijian()
{
	struct tm* t;
	char week[3] = "/0";
	time_t timer;
	time(&timer);
	t = localtime(&timer);

	/**********************************/
	/*   ����localtime�������Ϊ���� */
	/*   ��0~6�ֱ��ʾ���յ�������   */
	/*   �Ķ����㣬�ڴ�����С�Ż�    */
	/*********************************/

	switch (t->tm_wday)
	{
	case 1:
		strcpy(week, "Mon");
		break;
	case 2:
		strcpy(week, "Tue");
		break;
	case 3:
		strcpy(week, "Wed");
		break;
	case 4:
		strcpy(week, "Thu");
		break;
	case 5:
		strcpy(week, "Fri");
		break;
	case 6:
		strcpy(week, "Sat");
		break;
	default:
		strcpy(week, "Sun");

	}
	printf("\n\n\n\n\n\n");
	printf("====================================================================================\n\n");
	printf("\t\t`(*��_��*)��\t\t   `(*��_��*)��\n\n");
	printf("\t\tYEAR \t MONTH \t DAY \t    TIME \t WEEK\n");
	printf("\t\t%d \t   %02d    %02d  \t  %02d:%02d:%02d \t  %s\n\n", 1900 + t->tm_year, 1 + t->tm_mon, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec, week);
	printf("\t\t`(*^�n^*)�� \t\t   `(*^�n^*)�� \n\n");
	printf("=====================================================================================");
}



/************************/
/*   Sleep��λ�Ǻ���    */
/************************/

void sleep(unsigned long sec)
{
	Sleep(sec);
}

#ifdef  _SHIJIAN_H
#define _SHIJIAN_H
void shijian()

#endif


#ifdef  _SLEEP_H                                                                                                                                         
#define _SLEEP_H
extern void sleep(unsigned long sec)
#endif


//execute  4����    ���ܣ�ʵ�ֲ˵�����4�� 
void execute4()
{
	system("color 70");
	while (!kbhit())
	{
		shijian();
		sleep(1000);
		system("cls");
	}
}


//jduge����    ���ã��жϸ����ǲ��ǹ��ҷ������գ����ж���ʲô���ա� 
void jduge(int month, int day)
{
	printf("\t\t      ");
	switch (month)
	{
	case 1:if (day == 1)
		printf("%d��%d����Ԫ����\n", month, day);
		  else if (day == 12)
		printf("%d��%d������ˮ��\n", month, day);
		break;
	case 2:if (day == 2)
		printf("%d��%d��������ʪ����\n", month, day);
		  else if (day == 14)
		printf("%d��%d�������˽�\n", month, day); break;
	case 3:switch (day)
	{
	case 12: printf("%d��%d����ֲ����\n", month, day); break;
	case 21: printf("%d��%d��������˯����\n", month, day); break;
	case 22: printf("%d��%d��������ˮ��\n", month, day); break;
	case 23: printf("%d��%d��������������\n", month, day); break;
	}break;
	case 4:switch (day)
	{
	case 1: printf("%d��%d�������˽�\n", month, day); break;
	case 5: printf("%d��%d����������\n", month, day); break;
	case 7: printf("%d��%d��������������\n", month, day); break;
	case 22: printf("%d��%d�������������\n", month, day); break;
	case 25: printf("%d��%d���Ƕ����\n", month, day); break;
	case 26: printf("%d��%d���������\n", month, day); break;
	}break;
	case 5:if (day == 1)
		printf("%d��%d�����Ͷ���\n", month, day);
		if (day == 4)
			printf("%d��%d���������\n", month, day); break;
	case 6:if (day == 1)printf("%d��%d���Ƕ�ͯ��\n", month, day); break;
	case 7:if (day == 1)printf("%d��%d���ǽ�����\n", month, day); break;
	case 8: if (day == 1)printf("%d��%d���ǽ�����\n", month, day); break;
	case 9:if (day == 10)printf("%d��%d���ǽ�ʦ��\n", month, day); break;
	case 10:if (day == 1)printf("%d��%d���ǹ����\n", month, day); break;
	case 12:if (day == 13)printf("%d��%d�����Ͼ�����ɱ������\n", month, day);
		if (day == 24)printf("%d��%d����ƽ��ҹ\n", month, day);
		if (day == 25)printf("%d��%d����ʥ����\n", month, day); break;
	}

}










//�������ܣ����������գ����1900-1-1�������������-1λ���벻�Ϸ�
int DAY(int y, int m, int d)
{
	int i;
	int r = 0;  //����1900��������������
	int a[] = { 31,28,31,30,31,30,31,31,30,31,30 }; //m��ÿ���µ�����

	if (y >= 1900 && m > 0 && m < 13 && d>0 && d < 32)
	{
		for (i = 1900; i <= y; i++)  //��������ĸ���
		{
			if (i % 400 == 0 || i % 100 != 0 && i % 4 == 0)
				r++;
		}
		for (i = 0; i < m - 1; i++)  //ͳ�Ƶ���1��1�յ����µ�����
		{
			d += a[i];
		}
		if ((y % 400 == 0 || y % 100 != 0 && y % 4 == 0) && m < 3)  //������������굫�������¾Ͳ������ȥ
			r--;
		return 365 * (y - 1900) + r + d;
	}
	else
		return -1;
}







//Menu����    �ú���Ϊ�˵�ҳ�棻 

void Menu()
{
	system("cls");
	system("color E2");
	printf("\n\n\n\n\n");
	printf("\t\t=================================================\n");
	printf("\t\t|                   ������                      |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|          �t(*���`*)�s      (�䣻�أ�`)         |\n");
	printf("\t\t|  1.������**�꣬�鿴��������                   |\n");
	printf("\t\t|  2.������**��**�£��鿴�����������           |\n");
	printf("\t\t|  3.������**��**��**��                         |\n");//������죬�������ܼ����Ƿ�Ϊ�������գ�ʲô���գ� 
	printf("\t\t|  4.��ʾ��ǰʱ��                               |\n");//��ʾ�����ռ���ǰʱ���ӱ� 
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n");
	printf("\t\t\t\t\t   ����������ѡ��");
}
