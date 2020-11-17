#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
void execute1();   // 功能1 
void log_in();     //登录界面 
void execute2();   // 功能2 
void execute3();  // 功能3 及其所用函数 
void jduge();     //判断是否是节日   
void execute4();  // 功能4 
void hint();      //输入格式错误提示，并返回上一步 
void Select();   //选择实现功能 
void Menu();    //菜单页面 
void exit();    //退出 
int DAY(int y, int m, int d);  //功能3调用函数，该日到1900-1-1相差的天数 

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
	printf(" \t\t    ↖(^ω^)↗        ↖(^ω^)↗\n\n");
	printf("\t~~~///(^v^)\\\\\\~~~   按任意键进入菜单    ~~~///(^v^)\\\\\\~~~ \n\n");
	printf("\t\t ∩__∩y                     ∩__∩y \n\n");
	printf(" \t\t  >_<       按Esc退出程序      >_< \n\n");
	printf("================================================================");
}




//Select函数   函数功能：1、调用菜单，2选择所需查询项目； 
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


//hint 函数         判断输入是否正确
void hint()
{
	system("cls");
	printf("您的输入格式有误，请按回车键返回");
	getchar();
	getchar();
	Select();
}


//**功能1及其所使用函数 
long int f(int year, int month)

{

	if (month < 3) return year - 1;

	else return year;

}/*f(年，月)＝年－1，如月<3;否则，f(年，月)＝年*/
long int g(int month)

{

	if (month < 3) return month + 13;

	else return month + 1;

}/*g(月)＝月＋13，如月<3;否则，g(月)＝月＋1*/
long int n(int year, int month, int day)

{

	return 1461L * f(year, month) / 4 + 153L * g(month) / 5 + day;

}/*N=1461*f(年、月)/4+153*g(月)/5+日*/
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

	int year;/*年*/

	char title[] = "SUN MON TUE WED THU FRI SAT";

	system("cls");

	printf("Please input the year whose calendar you want to know: ");/*输入年*/

	scanf("%d%*c", &year);/*输入年份值和掠过值后的回车*/

	sw = w(year, 1, 1);

	leap = year % 4 == 0 && year % 100 || year % 400 == 0;/*判闰年*/

	for (i = 0; i < 12; i++)

		for (j = 0; j < 6; j++)

			for (k = 0; k < 7; k++)

				date[i][j][k] = 0;/*日期表置0*/

	for (i = 0; i < 12; i++)/*一年十二个月*/

		for (wd = 0, day = 1; day <= day_tbl[leap][i]; day++)

		{/*将第i＋1月的日期填入日期表*/

			date[i][wd][sw] = day;

			sw = ++sw % 7;/*每星期七天，以0至6计数*/

			if (sw == 0) wd++;/*日期表每七天一行，星期天开始新的一行*/

		}

	printf("\n|==================The Calendar of Year %d =====================|\n|", year);

	for (i = 0; i < 6; i++)

	{/*先测算第i+1月和第i+7月的最大星期数*/

		for (wd = 0, k = 0; k < 7; k++)/*日期表的第六行有日期，则wd!=0*/

			wd += date[i][5][k] + date[i + 6][5][k];

		wd = wd ? 6 : 5;

		printf("%2d %s %2d %s |\n|", i + 1, title, i + 7, title);

		for (j = 0; j < wd; j++)

		{

			printf("  ");/*输出四个空白符*/

			/*左栏为第i+1月，右栏为第i+7月*/

			for (k = 0; k < 7; k++)

				if (date[i][j][k])

					printf("%4d", date[i][j][k]);

				else printf(" ");

			printf(" ");/*输出十个空白符*/

			for (k = 0; k < 7; k++)

				if (date[i + 6][j][k])

					printf("%4d", date[i + 6][j][k]);

				else printf(" ");

			printf(" |\n|");

		}

		/*scanf("%*c");/*键入回车输出下一个月的日历*/

	}

	puts("=================================================================|");

	getchar();

}
// **功能1结束 





void execute2()
{
	system("color F4");
	int Year, Month; //年、月
	int FirstDay_Year, FirstDay_Month; //某年的第一天是星期几,某年某月的第一天是星期几(范围是0~6,其中0代表星期日)
	int IsLeapYear; //是否为闰年，0表示不是闰年,1表示是闰年
	int i, d, y; //临时变量
	char YN; //Yes No,程序是否要继续
	int Days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	//Days[1~12]存储每个月有多少天，其中二月的天数是可变的(闰年29天,平年28天),这里初始化为28天
XunHuan: //循环标号(可以通过goto跳转到这里)
	system("cls");// 清屏 
	printf(" C语言简单万年历\n"); //打印标题 
	printf("请输入年份<0000~9999>: "); //提示输入年份(0~9999)
	scanf("%d", &Year); //把输入的年份赋值给变量Year
	printf("请输入月份<0~12>: "); //提示输入月份(1~12)
	scanf("%d", &Month); //把输入的月份赋值给变量Month
	if (Year > 9999 || Year < 0 || Month>12 || Month <= 0)
	{
		printf("输入有误，请按回车键重新输入");
		getchar();
		getchar();
		goto XunHuan;
	}
	y = Year;
	FirstDay_Year = 5 * (y / 4) + (y % 4) - (y / 100) + (y / 400);//蔡勒公式(计算某年的第一天是星期几)
	IsLeapYear = (y % 4 == 4 && y % 100 != 100 || y % 400 == 0) ? 1 : 0;
	//判断是否为闰年
	Days[2] = (IsLeapYear == 1) ? 29 : 28; //闰年二月29天,非闰年二月28天
	for (i = 1, d = 0; i < Month; i++)
		d = d + Days[i];
	FirstDay_Month = (d + FirstDay_Year) % 7; //当月的第一天是星期几(0代表星期日)
	printf("\n****************************************************\n");
	printf("\t\t公元 %d 年 %2d 月", Year, Month); //打印年月
	printf("\n****************************************************\n");
	printf(" 星期日 星期一 星期二 星期三 星期四 星期五 星期六\n");
	//打印星期表头
	for (i = 0; i < FirstDay_Month; i++)
		printf("%7c", ' '); //当某月的第一天不是星期日时打印空格占位
	for (d = 1; d <= Days[Month]; d++) //循环,从每个月的第一天开始打印
	{
		printf("%7d", d);
		if (((d + FirstDay_Month) % 7) == 0 && d < Days[Month])
			printf("\n"); //当输出了星期六而且还未输出所有天数时,换行
	}
	printf("\n****************************************************\n");
	printf("\n");
	printf("是否继续(Y/N)?\n");
	scanf("%c", &YN);
	scanf("%c", &YN);
	if (YN == 'Y' || YN == 'y')
		goto XunHuan;
}


//execute 3函数      功能：实现菜单功能3; 



void execute3()
{
	system("color 8A");
	int year, month, day;
	int days;
	int week = 0;
	char a[] = { "星期" };
	char b[7][4] = { "日","一","二","三","四","五","六" };
loop:printf("请输入年 月 日：   (空格分隔)\n");
	scanf("%d %d %d", &year, &month, &day);
	days = DAY(year, month, day);//该日距离1900年1月1日的天数 
	if (days == -1)
	{
		system("cls");
		printf("输入格式有误,请重新输入   \n");
		fflush(stdin);
		goto loop;
	}
	else
	{
		week = days % 7;
		printf("\n\n*****************************************************\n\n");
		printf("\t\t%d年%d月%d日是%s%s\n\n", year, month, day, a, b[week]);
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
	/*   本身localtime输出的周为数字 */
	/*   是0~6分别表示周日到周六，   */
	/*   阅读不便，在此做个小优化    */
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
	printf("\t\t`(*∩_∩*)′\t\t   `(*∩_∩*)′\n\n");
	printf("\t\tYEAR \t MONTH \t DAY \t    TIME \t WEEK\n");
	printf("\t\t%d \t   %02d    %02d  \t  %02d:%02d:%02d \t  %s\n\n", 1900 + t->tm_year, 1 + t->tm_mon, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec, week);
	printf("\t\t`(*^﹏^*)′ \t\t   `(*^﹏^*)′ \n\n");
	printf("=====================================================================================");
}



/************************/
/*   Sleep单位是毫秒    */
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


//execute  4函数    功能：实现菜单功能4； 
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


//jduge函数    作用：判断该日是不是国家法定节日，并判断是什么节日。 
void jduge(int month, int day)
{
	printf("\t\t      ");
	switch (month)
	{
	case 1:if (day == 1)
		printf("%d月%d日是元旦节\n", month, day);
		  else if (day == 12)
		printf("%d月%d日是香水节\n", month, day);
		break;
	case 2:if (day == 2)
		printf("%d月%d日是世界湿地日\n", month, day);
		  else if (day == 14)
		printf("%d月%d日是情人节\n", month, day); break;
	case 3:switch (day)
	{
	case 12: printf("%d月%d日是植树节\n", month, day); break;
	case 21: printf("%d月%d日是世界睡眠日\n", month, day); break;
	case 22: printf("%d月%d日是世界水日\n", month, day); break;
	case 23: printf("%d月%d日是世界气象日\n", month, day); break;
	}break;
	case 4:switch (day)
	{
	case 1: printf("%d月%d日是愚人节\n", month, day); break;
	case 5: printf("%d月%d日是清明节\n", month, day); break;
	case 7: printf("%d月%d日是世界卫生日\n", month, day); break;
	case 22: printf("%d月%d日是世界地球日\n", month, day); break;
	case 25: printf("%d月%d日是读书节\n", month, day); break;
	case 26: printf("%d月%d日是秘书节\n", month, day); break;
	}break;
	case 5:if (day == 1)
		printf("%d月%d日是劳动节\n", month, day);
		if (day == 4)
			printf("%d月%d日是青年节\n", month, day); break;
	case 6:if (day == 1)printf("%d月%d日是儿童节\n", month, day); break;
	case 7:if (day == 1)printf("%d月%d日是建党节\n", month, day); break;
	case 8: if (day == 1)printf("%d月%d日是建军节\n", month, day); break;
	case 9:if (day == 10)printf("%d月%d日是教师节\n", month, day); break;
	case 10:if (day == 1)printf("%d月%d日是国庆节\n", month, day); break;
	case 12:if (day == 13)printf("%d月%d日是南京大屠杀纪念日\n", month, day);
		if (day == 24)printf("%d月%d日是平安夜\n", month, day);
		if (day == 25)printf("%d月%d日是圣诞节\n", month, day); break;
	}

}










//函数功能：输入年月日，输出1900-1-1到该天的天数，-1位输入不合法
int DAY(int y, int m, int d)
{
	int i;
	int r = 0;  //储存1900到该天的闰年个数
	int a[] = { 31,28,31,30,31,30,31,31,30,31,30 }; //m给每出月的天数

	if (y >= 1900 && m > 0 && m < 13 && d>0 && d < 32)
	{
		for (i = 1900; i <= y; i++)  //计算闰年的个数
		{
			if (i % 400 == 0 || i % 100 != 0 && i % 4 == 0)
				r++;
		}
		for (i = 0; i < m - 1; i++)  //统计当年1月1日到当月的天数
		{
			d += a[i];
		}
		if ((y % 400 == 0 || y % 100 != 0 && y % 4 == 0) && m < 3)  //如果当年是闰年但不到二月就不能算进去
			r--;
		return 365 * (y - 1900) + r + d;
	}
	else
		return -1;
}







//Menu函数    该函数为菜单页面； 

void Menu()
{
	system("cls");
	system("color E2");
	printf("\n\n\n\n\n");
	printf("\t\t=================================================\n");
	printf("\t\t|                   万年历                      |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|          ╰(*′︶`*)╯      (′；ω；`)         |\n");
	printf("\t\t|  1.请输入**年，查看该年日历                   |\n");
	printf("\t\t|  2.请输入**年**月，查看此年该月日历           |\n");
	printf("\t\t|  3.请输入**年**月**日                         |\n");//距今相差几天，改日是周几，是否为公历节日，什么节日？ 
	printf("\t\t|  4.显示当前时间                               |\n");//显示年月日及当前时刻钟表； 
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n");
	printf("\t\t\t\t\t   请输入您的选择：");
}
