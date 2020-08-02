#include<stdio.h>
#include<string.h>
#include<Windows.h>/*sleep函数的头文件*/
/*									主系统菜单											*/
/*登录界面功能_头*/
int  login()
{
	int i, k, j, n=2 ,x;
	char ACCOUNT[10] = "001";
	char PASSWORD[10] = "010203";
	char account[10];
	char password[10];
	printf("\t\t\t***************************************\n");
	printf("\t\t\t*      欢迎使用医院信息管理系统       *\n");
	printf("\t\t\t*      输入账号密码以登陆系统         *\n");
	printf("\t\t\t*      账号：");
	scanf("%s", account);
	printf("\t\t\t*      密码：");
	scanf("%s", password);
	printf("\t\t\t***************************************\n");
	k = strcmp(account, ACCOUNT);
	j = strcmp(password, PASSWORD);
	while (k != 0 || j != 0)
	{
		system("cls");
		printf("\n\t\t\t账号或密码错误，请重新输入，剩余%d次机会\n", n--);
		printf("\t\t\t***************************************\n");
		printf("\t\t\t*      欢迎使用医院信息管理系统       *\n");
		printf("\t\t\t*      输入账号密码以登陆系统         *\n");
		printf("\t\t\t*      账号：");
		scanf("%s", account);
		printf("\t\t\t*      密码：");
		scanf("%s", password);
		printf("\t\t\t***************************************\n");

		k = strcmp(account, ACCOUNT);
		j = strcmp(password, PASSWORD);
		if (n == 0 && (k != 0 || j != 0))
		{
			printf("\t\t\t登录失败，自动退出系统...");
			i = 0;
			break;
		}
	}
	if (k == 0 && j == 0)
	{
		printf("\t\t\t登录成功，即将进入系统");
		for (x = 0; x < 6; x++)
		{
			Sleep(250);
			printf(".");
		}
		i = 1;
		Sleep(1500);
	}
	return i;
}
/*登录界面功能_尾*/
void Quitesys()
{
	system("cls");
	printf("成功退出系统\n");
}
void PaitentIm_menu();/*病人信息系统菜单声明*/
void Out_allpaitents();
/*								病人结构体_头							*/
struct Date_in/*入院时间*/
{
	int year;
	int month;
	int day;
};
struct Date_out/*出院时间*/
{
	int year;
	int month;
	int day;
};
struct family1
{
	char name[10];
	char telenumber[11];
};
struct family2
{
	int numberlogin;
	char name[10];
	char telenumber[11];
};
struct Zhuyuan/*住院信息及费用*/
{
	int In_dengji;
	int Out_dengji;
	char address[20];
	struct Date_in In_day;
	struct Date_out Out_day;
};
struct Paitents_family
{
	struct family1 fm;
	struct family2 hw;
};
typedef struct Paitents
{
	char name[10];
	char sex[3];
	int age;
	char Id_card[18];
	char  departments[15];
	struct Paitents_family family_teach;
	char illness[300];
	struct Zhuyuan Zhuyuan_Im;
	/*struct Operation operate;*/
	struct Paitents* next;
}Paitents;
Paitents* head = NULL;
Paitents* p1, * p2;
/*								病人结构体_尾							*/
void Findpaitent();/*病人信息查询系统声明*/
//病人信息添加功能_头
void Addpaitents()
{
	head = NULL;
	int n,i=1;
	char ch;
	printf("请输入要添加病人的人数：");
	scanf("%d", &n);
	getchar();
	while (n)
	{
		p1 = (Paitents*)malloc(sizeof(Paitents));
		if (head == NULL)
			head = p1;
		else
			p2->next = p1;
		p1->next = NULL;
		system("cls");
		printf("请输入第%d个病人信息\n", i);
		printf("\t\t姓名\t\t性别\t\t年龄\t例:张三 tab键 男 tab键 20 回车结束输入\n");
		scanf("%s%s%d", p1->name, p1->sex, &p1->age);
		getchar();
		printf("身份证\n");
		scanf("%s", p1->Id_card);
		getchar();
		printf("\t\t家属姓名\t\t家属联系方式\t例:张三 tab键 19923583668 回车结束输入\n");
		scanf("%s%s", p1->family_teach.fm.name, p1->family_teach.fm.telenumber);
		getchar();
		printf("是否继续添加家属联系方式？\t\t1.继续添加    2.添加下一类信息\n");
		scanf("%d", &p1->family_teach.hw.numberlogin);
		getchar();
		switch (p1->family_teach.hw.numberlogin)
		{
		case 1:	printf("\t\t家属姓名\t\t家属联系方式\t例:张三 tab键 19923583668 回车结束输入\n");
				scanf("%s%s", p1->family_teach.hw.name, p1->family_teach.hw.telenumber); 
				getchar();
				break;
		case 2: strcpy(p1->family_teach.hw.name, "0");
				strcpy(p1->family_teach.hw.telenumber, "0");
				break;
		default:
			while (p1->family_teach.hw.numberlogin != 1 && p1->family_teach.hw.numberlogin != 2)
			{
				printf("输入错误，请重新输入 1或者2以执行操作\n");
				scanf("%d", &p1->family_teach.hw.numberlogin);
				getchar();
				if (p1->family_teach.hw.numberlogin == 1)
				{
					printf("\t\t家属姓名\t\t家属联系方式\t例:张三 tab键 19923583668 回车结束输入\n");
					scanf("%s%s", p1->family_teach.hw.name, p1->family_teach.hw.telenumber);
					getchar();
					break;
				}
				if (p1->family_teach.hw.numberlogin == 2)
				{
					strcpy(p1->family_teach.hw.name, "0");
					strcpy(p1->family_teach.hw.telenumber, "0");
					break;
				}
			}
		}
		printf("输入病人病情\n");
		scanf("%s", p1->illness);
		getchar();
		printf("隶属科室：");
		scanf("%s", p1->departments);
		getchar();
		printf("是否住院\t\t1.已住院  2.未住院\n");
		scanf("%d", &p1->Zhuyuan_Im.In_dengji);
		getchar();
 		if (p1->Zhuyuan_Im.In_dengji == 1)
		{
			printf("请输入住院房间信息:\t例：A-538 回车键结束\n请输入：");
			scanf("%s", p1->Zhuyuan_Im.address);
			getchar();
			printf("入院时间：\t 例：年 tab键 月 tab键 日\n请输入：");
			scanf("%d%d%d", &p1->Zhuyuan_Im.In_day.year, &p1->Zhuyuan_Im.In_day.month, &p1->Zhuyuan_Im.In_day.day);
			getchar();
			printf("病人是否出院\t\t1.已出院  2.未出院\n");
			scanf("%d", &p1->Zhuyuan_Im.Out_dengji);
			getchar();
			if (p1->Zhuyuan_Im.Out_dengji == 1)
			{
				printf("请输入出院时间：\t 例：年 tab键 月 tab键 日\n请输入：");
				scanf("%d%d%d", &p1->Zhuyuan_Im.Out_day.year, &p1->Zhuyuan_Im.Out_day.month, &p1->Zhuyuan_Im.Out_day.day);
				getchar();
			}
			else
			{
				p1->Zhuyuan_Im.Out_day.year = 0;
				p1->Zhuyuan_Im.Out_day.month = 0;
				p1->Zhuyuan_Im.Out_day.day = 0;
				printf("病人未出院\n");
			}

		}
		else
		{
			p1->Zhuyuan_Im.In_dengji = 0;
			strcpy(p1->Zhuyuan_Im.address, "0");
			p1->Zhuyuan_Im.In_day.year = 0;
			p1->Zhuyuan_Im.In_day.month = 0;
			p1->Zhuyuan_Im.In_day.day = 0;
			p1->Zhuyuan_Im.Out_dengji = 0;
			p1->Zhuyuan_Im.Out_day.year = 0;
			p1->Zhuyuan_Im.Out_day.month = 0;
			p1->Zhuyuan_Im.Out_day.day = 0;
			printf("病人未住院\n");
		}
		p2 = p1;
		n--;
		i++;
	}
	FILE* fp;
	if ((fp = fopen("Addpaitents.txt", "a+")) == NULL)
	{
		printf("打开文件失败！\n");
		exit(0);
	}
	p1 = head;
	while (p1 != NULL)
	{
		fprintf(fp,"%s	%s	%d	%s	%s	%s	%d	%s	%s	%s	%s	%d	%s	%d	%d	%d	%d	%d	%d	%d\n", p1->name, p1->sex, p1->age, p1->Id_card, p1->family_teach.fm.name, p1->family_teach.fm.telenumber,
			p1->family_teach.hw.numberlogin, p1->family_teach.hw.name, p1->family_teach.hw.telenumber, p1->illness, p1->departments, p1->Zhuyuan_Im.In_dengji, p1->Zhuyuan_Im.address, p1->Zhuyuan_Im.In_day.year, p1->Zhuyuan_Im.In_day.month, p1->Zhuyuan_Im.In_day.day,
			p1->Zhuyuan_Im.Out_dengji, p1->Zhuyuan_Im.Out_day.year, p1->Zhuyuan_Im.Out_day.month, p1->Zhuyuan_Im.Out_day.day);
		p1 = p1->next;
	}
	fclose(fp);
	printf("\t\t病人信息已注册，2s 后返回上一级菜单");
	Sleep(1000);
	printf("\n\t\t病人信息已注册，1s 后返回上一级菜单");
	Sleep(1000);
	Findpaitent();
}
//病人信息添加功能_尾
/*删除所有病人功能函数_ 头*/
void Delete_all_p()
{
	char bh;
	int n, i;
	printf("是否清空所有病人数据？");
	printf("\n9.清空所有病人数据并自动返回到病人主菜单\t0.放弃删除操作并直接返回主菜单\n请输入数字以执行操作：");
	scanf("%d", &n);
	if (n == 9)
	{
		FILE* s;
		if ((s = fopen("Addpaitents.txt", "w")) == NULL)
		{
			printf("找不到指定文件！\n");
			exit(0);
		}
		bh = fgetc(s);
		rewind(s);
		if (bh == EOF)
		{
			printf("\t\t\t***************************************\n");
			printf("\t\t\t*        数据库无病人信息请注册       *\n");
			printf("\t\t\t*        1.返回病人信息显示功能       *\n");
			printf("\t\t\t*        2.返回病人信息管理系统       *\n");
			printf("\t\t\t***************************************\n请输入：");
			scanf("%d", &i);
			getchar();
			switch (i)
			{
			case 1:Out_allpaitents(); break;
			case 2:PaitentIm_menu(); break;
			default:
				while (i != 1 && i != 2)
				{
					printf("\t\t\t***************************************\n");
					printf("\t\t\t*    你输入的值有误，请你重新选择     *\n");
					printf("\t\t\t***************************************\n");
					printf("请输入：");
					scanf("%d", &i);
					getchar();
				}
				if (i == 1)
					Out_allpaitents();
				else
					PaitentIm_menu();
			}
		}
		fclose(s);
	}
}
/*删除所有病人功能函数_ 尾*/
/*删除指定病人功能函数_ 头*/
void Delete_unique_p()
{
	int i, j, k, n, flag = 0;
	char Id[18], bh;
	Paitents* p1, * p2;
	Paitents* head = NULL;
	p1 = (Paitents*)malloc(sizeof(Paitents));
	FILE* s;
	if ((s = fopen("Addpaitents.txt", "r")) == NULL)
	{
		printf("找不到指定文件！\n");
		exit(0);
	}
	bh = fgetc(s);
	rewind(s);
	if (bh == EOF)
	{
		printf("\t\t\t***************************************\n");
		printf("\t\t\t*        数据库无病人信息请注册       *\n");
		printf("\t\t\t*        1.注册病人信息               *\n");
		printf("\t\t\t*        2.返回病人信息管理系统       *\n");
		printf("\t\t\t***************************************\n请输入：");
		scanf("%d", &i);
		getchar();
		switch (i)
		{
		case 1:Addpaitents(); break;
		case 2:PaitentIm_menu(); break;
		default:
			while(i != 1 && i != 2)
			{
				printf("\t\t\t***************************************\n");
				printf("\t\t\t*    你输入的值有误，请你重新选择     *\n");
				printf("\t\t\t***************************************\n");
				printf("请输入：");
				scanf("%d", &i);
				getchar();
			}
			if (i == 1)
				Addpaitents();
			else
				PaitentIm_menu();
		}
	}
	else
	{
		while (!feof(s))/*当文件内部指针指向文件末尾时，返回1以结束*/
		{
			p1 = (Paitents*)malloc(sizeof(Paitents));
			if (head == NULL)
				head = p1;
			else
				p2->next = p1;
			fscanf(s,"%s	%s	%d	%s	%s	%s	%d	%s	%s	%s	%s	%d	%s	%d	%d	%d	%d	%d	%d	%d\n", p1->name, p1->sex, &p1->age, p1->Id_card, p1->family_teach.fm.name, p1->family_teach.fm.telenumber,
				&p1->family_teach.hw.numberlogin, p1->family_teach.hw.name, p1->family_teach.hw.telenumber, p1->illness, p1->departments, &p1->Zhuyuan_Im.In_dengji, p1->Zhuyuan_Im.address, &p1->Zhuyuan_Im.In_day.year, &p1->Zhuyuan_Im.In_day.month, &p1->Zhuyuan_Im.In_day.day,
				&p1->Zhuyuan_Im.Out_dengji, &p1->Zhuyuan_Im.Out_day.year, &p1->Zhuyuan_Im.Out_day.month, &p1->Zhuyuan_Im.Out_day.day);
			p1->next = NULL;
			p2 = p1;
		}
		fclose(s);
		system("cls");
		printf("\n已有病人姓名和身份证\n");
		p1 = head;
		while (p1 != NULL)
		{
			printf("%s\t%s\n", p1->name, p1->Id_card);
			Sleep(150);
			p1 = p1->next;
		}
		printf("\n请输入要删除的病人的身份证号：");
		scanf("%s", Id);
		getchar();
		p1 = head;
		p2 = head;
		if (strcmp(Id, head->Id_card) == 0)
		{
			flag = 1;
			printf("\n病人%s已被删除", p1->name);
			head = p1->next;
		}
		else
		{
			while (p1->next != NULL)
			{
				p2 = p1->next;
				k = strcmp(Id, p2->Id_card);
				if (k == 0)
				{
					flag = 1;
					printf("\n病人%s已被删除", p1->next->name);
					p1->next = p2->next;
					break;
				}
				else
					flag = 0;
				p1 = p1->next;
			}
		}
		if (flag == 1)
		{
			FILE* s;
			if ((s = fopen("Addpaitents.txt", "w")) == NULL)
			{
				printf("找不到指定文件！\n");
				exit(0);
			}
			p1 = head;
			while (p1 != NULL)
			{
				fprintf(s, "%s	%s	%d	%s	%s	%s	%d	%s	%s	%s	%s	%d	%s	%d	%d	%d	%d	%d	%d	%d\n", p1->name, p1->sex, p1->age, p1->Id_card, p1->family_teach.fm.name, p1->family_teach.fm.telenumber,
					p1->family_teach.hw.numberlogin, p1->family_teach.hw.name, p1->family_teach.hw.telenumber, p1->illness, p1->departments, p1->Zhuyuan_Im.In_dengji, p1->Zhuyuan_Im.address, p1->Zhuyuan_Im.In_day.year, p1->Zhuyuan_Im.In_day.month, p1->Zhuyuan_Im.In_day.day,
					p1->Zhuyuan_Im.Out_dengji, p1->Zhuyuan_Im.Out_day.year, p1->Zhuyuan_Im.Out_day.month, p1->Zhuyuan_Im.Out_day.day);
				p1 = p1->next;
			}
			fclose(s);
		}
		else
		{
			printf("该病人不存在，请正确输入病人身份证:");
			p1 = head;
			Sleep(1500);
			while (p1 != NULL)
			{
				p2 = p1->next;
				free(p1);
				p1 = p2;
			}
			Delete_unique_p();
		}
		if (flag == 1)
		{
			p1 = head;
			while (p1 != NULL)
			{
				p2 = p1->next;
				free(p1);
				p1 = p2;
			}
			printf("\n即将返回主菜单");
			Sleep(2500);
			PaitentIm_menu();
		}
	}
}
/*删除指定病人功能函数_ 尾*/

//病人信息删除功能_头
void Deletepaitent()
{
	int n;
	system("cls");
	printf("\t\t\t***************************************\n");
	printf("\t\t\t*      病人信息删除功能               *\n");
	printf("\t\t\t*                                     *\n");
	printf("\t\t\t*      1.删除所有病人信息             *\n");
	printf("\t\t\t*      2.删除指定病人信息             *\n");
	printf("\t\t\t*      3.返回主菜单                   *\n");
	printf("\t\t\t***************************************\n");
	printf("\n");
	printf("请输入数字以执行操作：");
	scanf("%d", &n);
	getchar();
	switch (n)
	{
	case 1:Delete_all_p(); break;
	case 2:Delete_unique_p(); break;
	case 3:PaitentIm_menu(); break;
	default:
		while (n != 1 && n != 2 && n != 3)
		{
			printf("\t\t\t***************************************\n");
			printf("\t\t\t*    你输入的值有误，请你重新选择     *\n");
			printf("\t\t\t***************************************\n");
			printf("请输入：");
			scanf("%d", &n);
			getchar();
		}
		if (n == 1)
			Delete_all_p();
		if(n == 2)
			Delete_unique_p();
		if ( n == 3 )
			PaitentIm_menu();
	}
}
//病人信息删除功能_尾

//病人信息显示功能_头
void Out_allpaitents()
{
	system("cls");
	void Findpaitent();
	int i;
	char ch,bh;
	FILE* fp;
	if ((fp = fopen("Addpaitents.txt", "r+")) == NULL)
	{
		printf("打开文件失败\n");
		exit(0);
	}
	bh = fgetc(fp);
	rewind(fp);
	if (bh == EOF)
	{
		printf("\t\t\t***************************************\n");
		printf("\t\t\t*        数据库无病人信息请注册       *\n");
		printf("\t\t\t*        1.注册病人信息               *\n");
		printf("\t\t\t*        2.主菜单                     *\n");
		printf("\t\t\t***************************************\n请输入：");
		scanf("%d", &i);
		getchar();
		switch (i)
		{
		case 1:Addpaitents(); break;
		case 2:PaitentIm_menu(); break;
		default:
			while (i != 1 && i != 2)
			{
				printf("\t\t\t***************************************\n");
				printf("\t\t\t*    你输入的值有误，请你重新选择     *\n");
				printf("\t\t\t***************************************\n");
				printf("请输入：");
				scanf("%d", &i);
				getchar();
			}
			if (i == 1)
				Addpaitents();
			else
				PaitentIm_menu();
		}
	}
	else
	{
		head = NULL;
		while (!feof(fp))/*当文件内部指针指向文件末尾时，返回1以结束*/
		{
			p1 = (Paitents*)malloc(sizeof(Paitents));
			if (head == NULL)
				head = p1;
			else
				p2->next = p1;
			fscanf(fp, "%s	%s	%d	%s	%s	%s	%d	%s	%s	%s	%s	%d	%s	%d	%d	%d	%d	%d	%d	%d\n", p1->name, p1->sex, &p1->age, p1->Id_card, p1->family_teach.fm.name, p1->family_teach.fm.telenumber,
				&p1->family_teach.hw.numberlogin, p1->family_teach.hw.name, p1->family_teach.hw.telenumber, p1->illness, p1->departments, &p1->Zhuyuan_Im.In_dengji, p1->Zhuyuan_Im.address, &p1->Zhuyuan_Im.In_day.year, &p1->Zhuyuan_Im.In_day.month, &p1->Zhuyuan_Im.In_day.day,
				&p1->Zhuyuan_Im.Out_dengji, &p1->Zhuyuan_Im.Out_day.year, &p1->Zhuyuan_Im.Out_day.month, &p1->Zhuyuan_Im.Out_day.day);
			p1->next = NULL;
			p2 = p1;
		}
		fclose(fp);
		p1 = head;
		int n = 1;
		while (p1 != NULL)
		{
			printf("\n\t编号\t\t姓名\t\t性别\t\t年龄\t\t身份证\t\t\n");
			printf("\t%d\t\t%s\t\t%s\t\t%d\t\t%s", n, p1->name, p1->sex, p1->age, p1->Id_card);
			printf("\n\t家属联系方式\n");
			printf("\t联系人1：%s\t电话；%s", p1->family_teach.fm.name, p1->family_teach.fm.telenumber);
			if (p1->family_teach.hw.numberlogin == 1)
				printf("\n\t联系人2：%s\t电话；%s", p1->family_teach.hw.name, p1->family_teach.hw.telenumber);
			printf("\n\t病人病况：\n");
			printf("\t%s\n", p1->illness);
			printf("\t科室：%s", p1->departments);
			printf("\n\t住院情况\n");
			if (p1->Zhuyuan_Im.In_dengji == 1)
			{
				printf("\t住院\t\t病房：%s\t\t入院时间：%d年%d月%d日", p1->Zhuyuan_Im.address, p1->Zhuyuan_Im.In_day.year, p1->Zhuyuan_Im.In_day.month, p1->Zhuyuan_Im.In_day.day);
				if (p1->Zhuyuan_Im.Out_dengji == 1)
					printf("\t\t出院时间：%d年%d月%d日\n", p1->Zhuyuan_Im.Out_day.year, p1->Zhuyuan_Im.Out_day.month, p1->Zhuyuan_Im.Out_day.day);
				else
					printf("\t\t未出院\n");
			}
			else
				printf("\t未住院\n");
			Sleep(300);
			n++;
			p1 = p1->next;
		}
		system("pause");
		p1 = head;
		while (p1 != NULL)
		{
			p2 = p1->next;
			free(p1);
			p1 = p2;
		}
		printf("已显示全部病人信息，即将返回上一级菜单");
		Sleep(2000);
		Findpaitent();
	 }
}
//病人信息显示功能_尾

//病人信息更改功能_头
void Changepaitent()
{
	int i, k, n, x, flag = 0;
	char Id[18], bh;
	Paitents* p1, * p2;
	Paitents* head = NULL;
	p1 = (Paitents*)malloc(sizeof(Paitents));
	FILE* s;
	if ((s = fopen("Addpaitents.txt", "r")) == NULL)
	{
		printf("找不到指定文件！\n");
		exit(0);
	}
	bh = fgetc(s);
	rewind(s);
	if (bh == EOF)
	{
		printf("\t\t\t***************************************\n");
		printf("\t\t\t*        数据库无病人信息请注册       *\n");
		printf("\t\t\t*        1.注册病人信息               *\n");
		printf("\t\t\t*        2.主菜单                     *\n");
		printf("\t\t\t***************************************\n请输入：");
		scanf("%d", &i);
		getchar();
		switch (i)
		{
		case 1:Addpaitents(); break;
		case 2:PaitentIm_menu(); break;
		default:
			while (i != 1 && i != 2)
			{
				printf("\t\t\t***************************************\n");
				printf("\t\t\t*    你输入的值有误，请你重新选择     *\n");
				printf("\t\t\t***************************************\n");
				printf("请输入：");
				scanf("%d", &i);
				getchar();
			}
			if(i==1)
				Addpaitents();
			else
				PaitentIm_menu();
		}
	}
	else
	{
		head = NULL;
		while (!feof(s))/*当文件内部指针指向文件末尾时，返回1以结束*/
		{
			p1 = (Paitents*)malloc(sizeof(Paitents));
			if (head == NULL)
				head = p1;
			else
				p2->next = p1;
			fscanf(s, "%s	%s	%d	%s	%s	%s	%d	%s	%s	%s	%s	%d	%s	%d	%d	%d	%d	%d	%d	%d\n", p1->name, p1->sex, &p1->age, p1->Id_card, p1->family_teach.fm.name, p1->family_teach.fm.telenumber,
				&p1->family_teach.hw.numberlogin, p1->family_teach.hw.name, p1->family_teach.hw.telenumber, p1->illness, p1->departments, &p1->Zhuyuan_Im.In_dengji, p1->Zhuyuan_Im.address, &p1->Zhuyuan_Im.In_day.year, &p1->Zhuyuan_Im.In_day.month, &p1->Zhuyuan_Im.In_day.day,
				&p1->Zhuyuan_Im.Out_dengji, &p1->Zhuyuan_Im.Out_day.year, &p1->Zhuyuan_Im.Out_day.month, &p1->Zhuyuan_Im.Out_day.day);
			p1->next = NULL;
			p2 = p1;
		}
		fclose(s);
		system("cls");
		printf("已有病人姓名和身份证\n\n");
		p1 = head;
		while (p1 != NULL)
		{
			printf("%s\t%s\n", p1->name, p1->Id_card);
			Sleep(150);
			p1 = p1->next;
		}
		printf("\n请输入要搜索的病人身份证号：\n");
		printf("\n身份证：");
		scanf("%s", Id);
		getchar();
		p1 = head;
		while (p1 != NULL)
		{
			k = strcmp(Id, p1->Id_card);
			if (k == 0)
			{
				flag = 1;
				system("cls");
				printf("\t姓名\t\t性别\t\t年龄\t\t身份证\t\t\n");
				printf("\t%s\t\t%s\t\t%d\t\t%s", p1->name, p1->sex, p1->age, p1->Id_card);
				printf("\n\t家属联系方式\n");
				printf("\t联系人1：%s\t电话；%s", p1->family_teach.fm.name, p1->family_teach.fm.telenumber);
				if (p1->family_teach.hw.numberlogin == 1)
					printf("\n\t联系人2：%s\t电话；%s", p1->family_teach.hw.name, p1->family_teach.hw.telenumber);
				printf("\n是否修改病人家属联系人1信息？\t\t1.修改\t2.跳过\n请输入：");
				scanf("%d", &x);
				getchar();
				while (x != 1 && x != 2)
				{
					printf("\t\t\t***************************************\n");
					printf("\t\t\t*    你输入的值有误，请你重新选择     *\n");
					printf("\t\t\t***************************************\n");
					printf("请输入：");
					scanf("%d", &x);
					getchar();
				}
				if (x == 1)
				{
					printf("\t联系人1：\t\t电话；\t例:张三 tab键 19923583668 回车结束输入\n");
					scanf("%s%s", p1->family_teach.fm.name, p1->family_teach.fm.telenumber);
					getchar();
					if (p1->family_teach.hw.numberlogin == 1)
					{
						printf("是否继续修改家属联系人2信息？\t\t1.修改或者删除\t2.跳过\n请输入：");
						scanf("%d", &x);
						getchar();
						while (x != 1 && x != 2)
						{
							printf("\t\t\t***************************************\n");
							printf("\t\t\t*    你输入的值有误，请你重新选择     *\n");
							printf("\t\t\t***************************************\n");
							printf("请输入：");
							scanf("%d", &x);
							getchar();
						}
						if (x == 1)
						{
							printf("是否修改家属联系人2信息？\t\t1.修改\t2.删除\n请输入：");
							scanf("%d", &p1->family_teach.hw.numberlogin);
							getchar();
							while (p1->family_teach.hw.numberlogin != 1 && p1->family_teach.hw.numberlogin != 2)
							{
								printf("\t\t\t***************************************\n");
								printf("\t\t\t*    你输入的值有误，请你重新选择     *\n");
								printf("\t\t\t***************************************\n");
								printf("请输入：");
								scanf("%d", &p1->family_teach.hw.numberlogin);
								getchar();
							}
							if (p1->family_teach.hw.numberlogin == 1)
							{
								printf("\t\t联系人2\t\t电话\t例:张三 tab键 19923583668 回车结束输入\n");
								scanf("%s%s", p1->family_teach.hw.name, p1->family_teach.hw.telenumber);
								getchar();
							}
							else
							{
								strcpy(p1->family_teach.hw.name, "0");
								strcpy(p1->family_teach.hw.telenumber, "0");
								printf("家属联系人2信息删除成功\n");
							}
						}
					}
					else
					{
						printf("是否继续添加家属联系人2信息？\t\t1.添加\t2.跳过\n请输入：");
						scanf("%d", &x);
						getchar();
						while (x != 1 && x != 2)
						{
							printf("\t\t\t***************************************\n");
							printf("\t\t\t*    你输入的值有误，请你重新选择     *\n");
							printf("\t\t\t***************************************\n");
							printf("请输入：");
							scanf("%d", &x);
							getchar();
						}
						if (x == 1)
						{
							p1->family_teach.hw.numberlogin = 1;
							printf("\n\t\t联系人2\t\t电话\t例:张三 tab键 19923583668 回车结束输入\n");
							scanf("%s%s", p1->family_teach.hw.name, p1->family_teach.hw.telenumber);
							getchar();
						}
					}
				}
				printf("\n\t病人病况：\n");
				printf("\t%s\n", p1->illness);
				printf("\n是否更新病人病历信息？\t\t1.更新\t2.跳过\n请输入：");
				scanf("%d", &x);
				getchar();
				while (x != 1 && x != 2)
				{
					printf("\t\t\t***************************************\n");
					printf("\t\t\t*    你输入的值有误，请你重新选择     *\n");
					printf("\t\t\t***************************************\n");
					printf("请输入：");
					scanf("%d", &x);
					getchar();
				}
				if (x == 1)
				{
					printf("\t更新为：\t例：病历 输入回车结束\n\t请更新：");
					scanf("%s", p1->illness);
					getchar();
				}
				printf("\t科室：%s", p1->departments);
				printf("\n\t住院情况\n");
				if (p1->Zhuyuan_Im.In_dengji == 1)
				{
					printf("\t住院\t\t病房：%s\t\t入院时间：%d年%d月%d日", p1->Zhuyuan_Im.address, p1->Zhuyuan_Im.In_day.year, p1->Zhuyuan_Im.In_day.month, p1->Zhuyuan_Im.In_day.day);
					if (p1->Zhuyuan_Im.Out_dengji == 1)
						printf("\t\t出院时间：%d年%d月%d日\n", p1->Zhuyuan_Im.Out_day.year, p1->Zhuyuan_Im.Out_day.month, p1->Zhuyuan_Im.Out_day.day);
					else
						printf("\t\t未出院\n");
				}
				else
					printf("\t未住院\n");
				printf("是否修改病人住院信息？\t\t1.修改\t2.跳过\n请输入：");
				scanf("%d", &x);
				getchar();
				while (x != 1 && x != 2)
				{
					printf("\t\t\t***************************************\n");
					printf("\t\t\t*    你输入的值有误，请你重新选择     *\n");
					printf("\t\t\t***************************************\n");
					printf("请输入：");
					scanf("%d", &x);
					getchar();
				}
				if (x == 1)
				{
					printf("是否住院\t\t1.已住院  2.未住院\n");
					scanf("%d", &p1->Zhuyuan_Im.In_dengji);
					getchar();
					while (p1->Zhuyuan_Im.In_dengji != 1 && p1->Zhuyuan_Im.In_dengji != 2)
					{
						printf("\t\t\t***************************************\n");
						printf("\t\t\t*    你输入的值有误，请你重新选择     *\n");
						printf("\t\t\t***************************************\n");
						printf("请输入：");
						scanf("%d", &p1->Zhuyuan_Im.In_dengji);
						getchar();
					}
					if (p1->Zhuyuan_Im.In_dengji == 1)
					{
						printf("请输入住院房间信息:\t例：A-538 回车键结束\n请输入：");
						scanf("%s", p1->Zhuyuan_Im.address);
						getchar();
						printf("入院时间：\t例：年 tab键 月 tab键 日\n请输入：");
						scanf("%d%d%d", &p1->Zhuyuan_Im.In_day.year, &p1->Zhuyuan_Im.In_day.month, &p1->Zhuyuan_Im.In_day.day);
						getchar();
						printf("病人是否出院\t\t1.已出院  2.未出院\n");
						scanf("%d", &p1->Zhuyuan_Im.Out_dengji);
						getchar();
						if (p1->Zhuyuan_Im.Out_dengji == 1)
						{
							printf("请输入出院时间：\t例：年 tab键 月 tab键 日\n请输入：");
							scanf("%d%d%d", &p1->Zhuyuan_Im.Out_day.year, &p1->Zhuyuan_Im.Out_day.month, &p1->Zhuyuan_Im.Out_day.day);
							getchar();
						}
						else
						{
							p1->Zhuyuan_Im.Out_day.year = 0;
							p1->Zhuyuan_Im.Out_day.month = 0;
							p1->Zhuyuan_Im.Out_day.day = 0;
							printf("病人未出院\n");
						}
					}
					else
					{
						p1->Zhuyuan_Im.In_dengji = 0;
						strcpy(p1->Zhuyuan_Im.address, "0");
						p1->Zhuyuan_Im.In_day.year = 0;
						p1->Zhuyuan_Im.In_day.month = 0;
						p1->Zhuyuan_Im.In_day.day = 0;
						p1->Zhuyuan_Im.Out_dengji = 0;
						p1->Zhuyuan_Im.Out_day.year = 0;
						p1->Zhuyuan_Im.Out_day.month = 0;
						p1->Zhuyuan_Im.Out_day.day = 0;
						printf("病人未住院\n");
					}
				}
				printf("病人信息修改成功--\n");
				break;
			}
			p1 = p1->next;
		}
		if (flag != 1)
		{
			printf("\t\t\t***************************************\n");
			printf("\t\t\t*        数据库无病人信息请注册       *\n");
			printf("\t\t\t*        1.重新输入                   *\n");
			printf("\t\t\t*        2.注册病人信息               *\n");
			printf("\t\t\t*        3.主菜单                     *\n");
			printf("\t\t\t***************************************\n请输入：");
			scanf("%d", &n);
			getchar();
			switch (n)
			{
			case 1:Changepaitent(); break;
			case 2:Addpaitents(); break;
			case 3:PaitentIm_menu(); break;
			default:
				while (n != 1 && n != 2 && n!=3)
				{
					printf("\t\t\t***************************************\n");
					printf("\t\t\t*    你输入的值有误，请你重新选择     *\n");
					printf("\t\t\t***************************************\n");
					printf("请输入：");
					scanf("%d", &n);
					getchar();
				}
				if (n == 1)
					Changepaitent();
				if(n == 2)
					Addpaitents();
				if (n == 3)
					PaitentIm_menu();
			}
		}
		else
		{
			p1 = head;
			FILE* s1;
			if ((s1 = fopen("Addpaitents.txt", "w")) == NULL)
			{
				printf("找不到指定文件！\n");
				exit(0);
			}
			while (p1 != NULL)
			{
				fprintf(s, "%s	%s	%d	%s	%s	%s	%d	%s	%s	%s	%s	%d	%s	%d	%d	%d	%d	%d	%d	%d\n", p1->name, p1->sex, p1->age, p1->Id_card, p1->family_teach.fm.name, p1->family_teach.fm.telenumber,
					p1->family_teach.hw.numberlogin, p1->family_teach.hw.name, p1->family_teach.hw.telenumber, p1->illness, p1->departments, p1->Zhuyuan_Im.In_dengji, p1->Zhuyuan_Im.address, p1->Zhuyuan_Im.In_day.year, p1->Zhuyuan_Im.In_day.month, p1->Zhuyuan_Im.In_day.day,
					p1->Zhuyuan_Im.Out_dengji, p1->Zhuyuan_Im.Out_day.year, p1->Zhuyuan_Im.Out_day.month, p1->Zhuyuan_Im.Out_day.day);
				p1 = p1->next;
			}
			fclose(s1);
			printf("即将返回病人信息查询功能....\n");
			Sleep(2000);
			Findpaitent();
		}
		p1 = head;
		while (p1 != NULL)
		{
			p2 = p1->next;
			free(p1);
			p1 = p2;
		}
	}
}

//病人信息更改功能_尾

//病人信息查询功能_显示全部_头

//通过身份证，姓名搜索病人功能_头
void Search_Paitents()
{
	int i, j, k, n, flag = 0;
	char Id[18], bh;
	Paitents* p1, * p2;
	Paitents* head = NULL;
	p1 = (Paitents*)malloc(sizeof(Paitents));
	FILE* s;
	if ((s = fopen("Addpaitents.txt", "r")) == NULL)
	{
		printf("找不到指定文件！\n");
		exit(0);
	}
	bh = fgetc(s);
	rewind(s);
	if (bh == EOF)
	{
		printf("\t\t\t***************************************\n");
		printf("\t\t\t*        数据库无病人信息请注册       *\n");
		printf("\t\t\t*        1.注册病人信息               *\n");
		printf("\t\t\t*        2.主菜单                     *\n");
		printf("\t\t\t***************************************\n请输入：");
		scanf("%d", &i);
		getchar();
		switch (i)
		{
		case 1:Addpaitents(); break;
		case 2:PaitentIm_menu(); break;
		default:
			while (i != 1 && i != 2)
			{
				printf("\t\t\t***************************************\n");
				printf("\t\t\t*    你输入的值有误，请你重新选择     *\n");
				printf("\t\t\t***************************************\n请输入：");
				scanf("%d", &i);
				getchar();
			}
			if (i == 1)
				Addpaitents();
			else
				PaitentIm_menu();
		}
	}
	else
	{
		while (!feof(s))/*当文件内部指针指向文件末尾时，返回1以结束*/
		{
			p1 = (Paitents*)malloc(sizeof(Paitents));
			if (head == NULL)
				head = p1;
			else
				p2->next = p1;
			fscanf(s, "%s	%s	%d	%s	%s	%s	%d	%s	%s	%s	%s	%d	%s	%d	%d	%d	%d	%d	%d	%d\n", p1->name, p1->sex, &p1->age, p1->Id_card, p1->family_teach.fm.name, p1->family_teach.fm.telenumber,
				&p1->family_teach.hw.numberlogin, p1->family_teach.hw.name, p1->family_teach.hw.telenumber, p1->illness, p1->departments, &p1->Zhuyuan_Im.In_dengji, p1->Zhuyuan_Im.address, &p1->Zhuyuan_Im.In_day.year, &p1->Zhuyuan_Im.In_day.month, &p1->Zhuyuan_Im.In_day.day,
				&p1->Zhuyuan_Im.Out_dengji, &p1->Zhuyuan_Im.Out_day.year, &p1->Zhuyuan_Im.Out_day.month, &p1->Zhuyuan_Im.Out_day.day);
			p1->next = NULL;
			p2 = p1;
		}
		system("cls");
		printf("\n已注册病人姓名和身份证\n");
		p1 = head;
		while (p1 != NULL)
		{
			printf("%s\t%s\n", p1->name, p1->Id_card);
			Sleep(150);
			p1 = p1->next;
		}
		printf("\n请输入要搜索的病人的身份证号：");
		scanf("%s", Id);
		getchar();
		p1 = head;
		while (p1 != NULL)
		{
			k = strcmp(Id, p1->Id_card);
			if (k == 0)
			{
				flag = 1;
				system("cls");
				printf("\t姓名\t\t性别\t\t年龄\t\t身份证\t\t\n");
				printf("\t%s\t\t%s\t\t%d\t\t%s", p1->name, p1->sex, p1->age, p1->Id_card);
				printf("\n\t家属联系方式\n");
				printf("\t联系人1：%s\t电话；%s", p1->family_teach.fm.name, p1->family_teach.fm.telenumber);
				if (p1->family_teach.hw.numberlogin == 1)
					printf("\n\t联系人2：%s\t电话；%s", p1->family_teach.hw.name, p1->family_teach.hw.telenumber);
				printf("\n\t病人病况：\n");
				printf("\t%s\n", p1->illness);
				printf("\t科室：%s", p1->departments);
				printf("\n\t住院情况\n");
				if (p1->Zhuyuan_Im.In_dengji == 1)
				{
					printf("\t住院\t\t病房：%s\t\t入院时间：%d年%d月%d日", p1->Zhuyuan_Im.address, p1->Zhuyuan_Im.In_day.year, p1->Zhuyuan_Im.In_day.month, p1->Zhuyuan_Im.In_day.day);
					if (p1->Zhuyuan_Im.Out_dengji == 1)
						printf("\t\t出院时间：%d年%d月%d日\n", p1->Zhuyuan_Im.Out_day.year, p1->Zhuyuan_Im.Out_day.month, p1->Zhuyuan_Im.Out_day.day);
					else
						printf("\t\t未出院\n");
				}
				else
					printf("\t未住院\n");
				printf("\n\n输入 1.继续搜索\t\t2.返回上一级菜单\n请输入：");
				scanf("%d", &n);
				getchar();
				switch (n)
				{
				case 1: Search_Paitents(); break;
				case 2:	PaitentIm_menu(); break;
				default:
					while (n != 1 && n != 2)
					{
						printf("\t\t\t***************************************\n");
						printf("\t\t\t*    你输入的值有误，请你重新选择     *\n");
						printf("\t\t\t***************************************\n");
						printf("\n\n输入 1.继续搜索\t\t2.返回上一级菜单\n请输入：");
						scanf("%d", &n);
						getchar();
					}
					if (n == 1)
						Search_Paitents();
					else
						PaitentIm_menu();
				}
				break;
			}
			p1 = p1->next;
		}
		if (flag != 1)
		{
			printf("\t\t\t***************************************\n");
			printf("\t\t\t*        身份证输入有误或暂无此人     *\n");
			printf("\t\t\t*        1.重新查找                   *\n");
			printf("\t\t\t*        2.注册此ID病人信息           *\n");
			printf("\t\t\t*        3.主菜单                     *\n");
			printf("\t\t\t***************************************\n请输入：");
			scanf("%d", &n);
			getchar();
			switch (n)
			{
			case 1:Search_Paitents(); break;
			case 2:Addpaitents(); break;
			case 3:PaitentIm_menu(); break;
			default:
				while (n != 1 && n != 2 && n != 3)
				{
					printf("\t\t\t***************************************\n");
					printf("\t\t\t*    你输入的值有误，请你重新选择     *\n");
					printf("\t\t\t***************************************\n请输入：");
					scanf("%d", &n);
					getchar();
				}
				if (n == 1)
					Search_Paitents();
				if (n == 2)
					Addpaitents();
				if (n == 3)
					PaitentIm_menu();
			}
		}
		fclose(s);
		p1 = head;
		while (p1 != NULL)
		{
			p2 = p1->next;
			free(p1);
			p1 = p2;
		}
	}
}
//通过身份证，姓名搜索病人功能_尾
void Findpaitent()
{
	int n;
	system("cls");
	printf("\t\t\t***************************************\n");
	printf("\t\t\t*      病人信息查询功能               *\n");
	printf("\t\t\t*                                     *\n");
	printf("\t\t\t*      1.显示所有病人信息             *\n");
	printf("\t\t\t*      2.搜索指定病人信息             *\n");
	printf("\t\t\t*      3.主菜单                       *\n");
	printf("\t\t\t***************************************\n");
	printf("\n");
	printf("请输入数字以执行操作：");
	scanf("%d", &n);
	getchar();
	switch (n)
	{
	case 1:Out_allpaitents(); break;
	case 2:Search_Paitents(); break;
	case 3:PaitentIm_menu(); break;
	default:
		while (n != 1 && n != 2 && n != 3)
		{
			printf("\t\t\t***************************************\n");
			printf("\t\t\t*    你输入的值有误，请你重新选择     *\n");
			printf("\t\t\t***************************************\n请输入：");
			scanf("%d", &n);
			getchar();
		} 
		if (n == 1)
			Out_allpaitents();
		if(n == 2)
			Search_Paitents();
		if(n == 3)
			PaitentIm_menu();
	}
}
//病人信息查询功能_显示全部_尾
							/*								病人信息管理系统菜单头							*/
void PaitentIm_menu()
{
	int n;
	system("cls");
	printf("\t\t\t***************************************\n");
	printf("\t\t\t*     欢迎使用医院信息管理系统        *\n");
	printf("\t\t\t*                                     *\n");
	printf("\t\t\t*      1.注册病人信息                 *\n");
	printf("\t\t\t*      2.注销病人信息                 *\n");
	printf("\t\t\t*      3.查询病人信息                 *\n");
	printf("\t\t\t*      4.更新已有病人信息             *\n");
	printf("\t\t\t*      0.退出系统                     *\n");
	printf("\t\t\t***************************************\n");
	printf("\t\t\tTips:如要注册，注销，更新病人信息请先通过查询功能查询病人是否存在，再进行下一步操作");
	printf("\n");
	printf("请输入  0-4   数字以执行操作：");
	scanf("%d", &n);
	getchar();
	switch (n)
	{
	case 1:Addpaitents(); break;
	case 2:Deletepaitent(); break;
	case 3:Findpaitent(); break;
	case 4:Changepaitent(); break;
	case 0:Quitesys(); break;
	default:
		while (n != 1 && n != 2 && n != 3 && n != 4 && n != 0)
		{
			printf("\t\t\t***************************************\n");
			printf("\t\t\t*    你输入的值有误，请你重新选择     *\n");
			printf("\t\t\t***************************************\n请输入：");
			scanf("%d", &n);
			getchar();
		}
		if (n == 1)
			Out_allpaitents();
		if (n == 2)
			Search_Paitents();
		if (n == 3)
			Findpaitent();
		if (n == 4)
			Changepaitent();
		if (n == 0)
			Quitesys();
	}
}
/*								病人信息管理系统菜单尾							*/
/*									主系统菜单_尾											*/
int main()
{
	int i;
	i = login();/*登录接口*/
	if (i == 1)
		PaitentIm_menu();/*医院信息管理系统主菜单*/
	return 0;
}