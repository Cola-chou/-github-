#include<stdio.h>
#include<string.h>
#include<Windows.h>/*sleep������ͷ�ļ�*/
/*									��ϵͳ�˵�											*/
/*��¼���湦��_ͷ*/
int  login()
{
	int i, k, j, n=2 ,x;
	char ACCOUNT[10] = "001";
	char PASSWORD[10] = "010203";
	char account[10];
	char password[10];
	printf("\t\t\t***************************************\n");
	printf("\t\t\t*      ��ӭʹ��ҽԺ��Ϣ����ϵͳ       *\n");
	printf("\t\t\t*      �����˺������Ե�½ϵͳ         *\n");
	printf("\t\t\t*      �˺ţ�");
	scanf("%s", account);
	printf("\t\t\t*      ���룺");
	scanf("%s", password);
	printf("\t\t\t***************************************\n");
	k = strcmp(account, ACCOUNT);
	j = strcmp(password, PASSWORD);
	while (k != 0 || j != 0)
	{
		system("cls");
		printf("\n\t\t\t�˺Ż�����������������룬ʣ��%d�λ���\n", n--);
		printf("\t\t\t***************************************\n");
		printf("\t\t\t*      ��ӭʹ��ҽԺ��Ϣ����ϵͳ       *\n");
		printf("\t\t\t*      �����˺������Ե�½ϵͳ         *\n");
		printf("\t\t\t*      �˺ţ�");
		scanf("%s", account);
		printf("\t\t\t*      ���룺");
		scanf("%s", password);
		printf("\t\t\t***************************************\n");

		k = strcmp(account, ACCOUNT);
		j = strcmp(password, PASSWORD);
		if (n == 0 && (k != 0 || j != 0))
		{
			printf("\t\t\t��¼ʧ�ܣ��Զ��˳�ϵͳ...");
			i = 0;
			break;
		}
	}
	if (k == 0 && j == 0)
	{
		printf("\t\t\t��¼�ɹ�����������ϵͳ");
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
/*��¼���湦��_β*/
void Quitesys()
{
	system("cls");
	printf("�ɹ��˳�ϵͳ\n");
}
void PaitentIm_menu();/*������Ϣϵͳ�˵�����*/
void Out_allpaitents();
/*								���˽ṹ��_ͷ							*/
struct Date_in/*��Ժʱ��*/
{
	int year;
	int month;
	int day;
};
struct Date_out/*��Ժʱ��*/
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
struct Zhuyuan/*סԺ��Ϣ������*/
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
/*								���˽ṹ��_β							*/
void Findpaitent();/*������Ϣ��ѯϵͳ����*/
//������Ϣ��ӹ���_ͷ
void Addpaitents()
{
	head = NULL;
	int n,i=1;
	char ch;
	printf("������Ҫ��Ӳ��˵�������");
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
		printf("�������%d��������Ϣ\n", i);
		printf("\t\t����\t\t�Ա�\t\t����\t��:���� tab�� �� tab�� 20 �س���������\n");
		scanf("%s%s%d", p1->name, p1->sex, &p1->age);
		getchar();
		printf("���֤\n");
		scanf("%s", p1->Id_card);
		getchar();
		printf("\t\t��������\t\t������ϵ��ʽ\t��:���� tab�� 19923583668 �س���������\n");
		scanf("%s%s", p1->family_teach.fm.name, p1->family_teach.fm.telenumber);
		getchar();
		printf("�Ƿ������Ӽ�����ϵ��ʽ��\t\t1.�������    2.�����һ����Ϣ\n");
		scanf("%d", &p1->family_teach.hw.numberlogin);
		getchar();
		switch (p1->family_teach.hw.numberlogin)
		{
		case 1:	printf("\t\t��������\t\t������ϵ��ʽ\t��:���� tab�� 19923583668 �س���������\n");
				scanf("%s%s", p1->family_teach.hw.name, p1->family_teach.hw.telenumber); 
				getchar();
				break;
		case 2: strcpy(p1->family_teach.hw.name, "0");
				strcpy(p1->family_teach.hw.telenumber, "0");
				break;
		default:
			while (p1->family_teach.hw.numberlogin != 1 && p1->family_teach.hw.numberlogin != 2)
			{
				printf("����������������� 1����2��ִ�в���\n");
				scanf("%d", &p1->family_teach.hw.numberlogin);
				getchar();
				if (p1->family_teach.hw.numberlogin == 1)
				{
					printf("\t\t��������\t\t������ϵ��ʽ\t��:���� tab�� 19923583668 �س���������\n");
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
		printf("���벡�˲���\n");
		scanf("%s", p1->illness);
		getchar();
		printf("�������ң�");
		scanf("%s", p1->departments);
		getchar();
		printf("�Ƿ�סԺ\t\t1.��סԺ  2.δסԺ\n");
		scanf("%d", &p1->Zhuyuan_Im.In_dengji);
		getchar();
 		if (p1->Zhuyuan_Im.In_dengji == 1)
		{
			printf("������סԺ������Ϣ:\t����A-538 �س�������\n�����룺");
			scanf("%s", p1->Zhuyuan_Im.address);
			getchar();
			printf("��Ժʱ�䣺\t ������ tab�� �� tab�� ��\n�����룺");
			scanf("%d%d%d", &p1->Zhuyuan_Im.In_day.year, &p1->Zhuyuan_Im.In_day.month, &p1->Zhuyuan_Im.In_day.day);
			getchar();
			printf("�����Ƿ��Ժ\t\t1.�ѳ�Ժ  2.δ��Ժ\n");
			scanf("%d", &p1->Zhuyuan_Im.Out_dengji);
			getchar();
			if (p1->Zhuyuan_Im.Out_dengji == 1)
			{
				printf("�������Ժʱ�䣺\t ������ tab�� �� tab�� ��\n�����룺");
				scanf("%d%d%d", &p1->Zhuyuan_Im.Out_day.year, &p1->Zhuyuan_Im.Out_day.month, &p1->Zhuyuan_Im.Out_day.day);
				getchar();
			}
			else
			{
				p1->Zhuyuan_Im.Out_day.year = 0;
				p1->Zhuyuan_Im.Out_day.month = 0;
				p1->Zhuyuan_Im.Out_day.day = 0;
				printf("����δ��Ժ\n");
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
			printf("����δסԺ\n");
		}
		p2 = p1;
		n--;
		i++;
	}
	FILE* fp;
	if ((fp = fopen("Addpaitents.txt", "a+")) == NULL)
	{
		printf("���ļ�ʧ�ܣ�\n");
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
	printf("\t\t������Ϣ��ע�ᣬ2s �󷵻���һ���˵�");
	Sleep(1000);
	printf("\n\t\t������Ϣ��ע�ᣬ1s �󷵻���һ���˵�");
	Sleep(1000);
	Findpaitent();
}
//������Ϣ��ӹ���_β
/*ɾ�����в��˹��ܺ���_ ͷ*/
void Delete_all_p()
{
	char bh;
	int n, i;
	printf("�Ƿ�������в������ݣ�");
	printf("\n9.������в������ݲ��Զ����ص��������˵�\t0.����ɾ��������ֱ�ӷ������˵�\n������������ִ�в�����");
	scanf("%d", &n);
	if (n == 9)
	{
		FILE* s;
		if ((s = fopen("Addpaitents.txt", "w")) == NULL)
		{
			printf("�Ҳ���ָ���ļ���\n");
			exit(0);
		}
		bh = fgetc(s);
		rewind(s);
		if (bh == EOF)
		{
			printf("\t\t\t***************************************\n");
			printf("\t\t\t*        ���ݿ��޲�����Ϣ��ע��       *\n");
			printf("\t\t\t*        1.���ز�����Ϣ��ʾ����       *\n");
			printf("\t\t\t*        2.���ز�����Ϣ����ϵͳ       *\n");
			printf("\t\t\t***************************************\n�����룺");
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
					printf("\t\t\t*    �������ֵ������������ѡ��     *\n");
					printf("\t\t\t***************************************\n");
					printf("�����룺");
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
/*ɾ�����в��˹��ܺ���_ β*/
/*ɾ��ָ�����˹��ܺ���_ ͷ*/
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
		printf("�Ҳ���ָ���ļ���\n");
		exit(0);
	}
	bh = fgetc(s);
	rewind(s);
	if (bh == EOF)
	{
		printf("\t\t\t***************************************\n");
		printf("\t\t\t*        ���ݿ��޲�����Ϣ��ע��       *\n");
		printf("\t\t\t*        1.ע�Ს����Ϣ               *\n");
		printf("\t\t\t*        2.���ز�����Ϣ����ϵͳ       *\n");
		printf("\t\t\t***************************************\n�����룺");
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
				printf("\t\t\t*    �������ֵ������������ѡ��     *\n");
				printf("\t\t\t***************************************\n");
				printf("�����룺");
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
		while (!feof(s))/*���ļ��ڲ�ָ��ָ���ļ�ĩβʱ������1�Խ���*/
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
		printf("\n���в������������֤\n");
		p1 = head;
		while (p1 != NULL)
		{
			printf("%s\t%s\n", p1->name, p1->Id_card);
			Sleep(150);
			p1 = p1->next;
		}
		printf("\n������Ҫɾ���Ĳ��˵����֤�ţ�");
		scanf("%s", Id);
		getchar();
		p1 = head;
		p2 = head;
		if (strcmp(Id, head->Id_card) == 0)
		{
			flag = 1;
			printf("\n����%s�ѱ�ɾ��", p1->name);
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
					printf("\n����%s�ѱ�ɾ��", p1->next->name);
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
				printf("�Ҳ���ָ���ļ���\n");
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
			printf("�ò��˲����ڣ�����ȷ���벡�����֤:");
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
			printf("\n�����������˵�");
			Sleep(2500);
			PaitentIm_menu();
		}
	}
}
/*ɾ��ָ�����˹��ܺ���_ β*/

//������Ϣɾ������_ͷ
void Deletepaitent()
{
	int n;
	system("cls");
	printf("\t\t\t***************************************\n");
	printf("\t\t\t*      ������Ϣɾ������               *\n");
	printf("\t\t\t*                                     *\n");
	printf("\t\t\t*      1.ɾ�����в�����Ϣ             *\n");
	printf("\t\t\t*      2.ɾ��ָ��������Ϣ             *\n");
	printf("\t\t\t*      3.�������˵�                   *\n");
	printf("\t\t\t***************************************\n");
	printf("\n");
	printf("������������ִ�в�����");
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
			printf("\t\t\t*    �������ֵ������������ѡ��     *\n");
			printf("\t\t\t***************************************\n");
			printf("�����룺");
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
//������Ϣɾ������_β

//������Ϣ��ʾ����_ͷ
void Out_allpaitents()
{
	system("cls");
	void Findpaitent();
	int i;
	char ch,bh;
	FILE* fp;
	if ((fp = fopen("Addpaitents.txt", "r+")) == NULL)
	{
		printf("���ļ�ʧ��\n");
		exit(0);
	}
	bh = fgetc(fp);
	rewind(fp);
	if (bh == EOF)
	{
		printf("\t\t\t***************************************\n");
		printf("\t\t\t*        ���ݿ��޲�����Ϣ��ע��       *\n");
		printf("\t\t\t*        1.ע�Ს����Ϣ               *\n");
		printf("\t\t\t*        2.���˵�                     *\n");
		printf("\t\t\t***************************************\n�����룺");
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
				printf("\t\t\t*    �������ֵ������������ѡ��     *\n");
				printf("\t\t\t***************************************\n");
				printf("�����룺");
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
		while (!feof(fp))/*���ļ��ڲ�ָ��ָ���ļ�ĩβʱ������1�Խ���*/
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
			printf("\n\t���\t\t����\t\t�Ա�\t\t����\t\t���֤\t\t\n");
			printf("\t%d\t\t%s\t\t%s\t\t%d\t\t%s", n, p1->name, p1->sex, p1->age, p1->Id_card);
			printf("\n\t������ϵ��ʽ\n");
			printf("\t��ϵ��1��%s\t�绰��%s", p1->family_teach.fm.name, p1->family_teach.fm.telenumber);
			if (p1->family_teach.hw.numberlogin == 1)
				printf("\n\t��ϵ��2��%s\t�绰��%s", p1->family_teach.hw.name, p1->family_teach.hw.telenumber);
			printf("\n\t���˲�����\n");
			printf("\t%s\n", p1->illness);
			printf("\t���ң�%s", p1->departments);
			printf("\n\tסԺ���\n");
			if (p1->Zhuyuan_Im.In_dengji == 1)
			{
				printf("\tסԺ\t\t������%s\t\t��Ժʱ�䣺%d��%d��%d��", p1->Zhuyuan_Im.address, p1->Zhuyuan_Im.In_day.year, p1->Zhuyuan_Im.In_day.month, p1->Zhuyuan_Im.In_day.day);
				if (p1->Zhuyuan_Im.Out_dengji == 1)
					printf("\t\t��Ժʱ�䣺%d��%d��%d��\n", p1->Zhuyuan_Im.Out_day.year, p1->Zhuyuan_Im.Out_day.month, p1->Zhuyuan_Im.Out_day.day);
				else
					printf("\t\tδ��Ժ\n");
			}
			else
				printf("\tδסԺ\n");
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
		printf("����ʾȫ��������Ϣ������������һ���˵�");
		Sleep(2000);
		Findpaitent();
	 }
}
//������Ϣ��ʾ����_β

//������Ϣ���Ĺ���_ͷ
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
		printf("�Ҳ���ָ���ļ���\n");
		exit(0);
	}
	bh = fgetc(s);
	rewind(s);
	if (bh == EOF)
	{
		printf("\t\t\t***************************************\n");
		printf("\t\t\t*        ���ݿ��޲�����Ϣ��ע��       *\n");
		printf("\t\t\t*        1.ע�Ს����Ϣ               *\n");
		printf("\t\t\t*        2.���˵�                     *\n");
		printf("\t\t\t***************************************\n�����룺");
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
				printf("\t\t\t*    �������ֵ������������ѡ��     *\n");
				printf("\t\t\t***************************************\n");
				printf("�����룺");
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
		while (!feof(s))/*���ļ��ڲ�ָ��ָ���ļ�ĩβʱ������1�Խ���*/
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
		printf("���в������������֤\n\n");
		p1 = head;
		while (p1 != NULL)
		{
			printf("%s\t%s\n", p1->name, p1->Id_card);
			Sleep(150);
			p1 = p1->next;
		}
		printf("\n������Ҫ�����Ĳ������֤�ţ�\n");
		printf("\n���֤��");
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
				printf("\t����\t\t�Ա�\t\t����\t\t���֤\t\t\n");
				printf("\t%s\t\t%s\t\t%d\t\t%s", p1->name, p1->sex, p1->age, p1->Id_card);
				printf("\n\t������ϵ��ʽ\n");
				printf("\t��ϵ��1��%s\t�绰��%s", p1->family_teach.fm.name, p1->family_teach.fm.telenumber);
				if (p1->family_teach.hw.numberlogin == 1)
					printf("\n\t��ϵ��2��%s\t�绰��%s", p1->family_teach.hw.name, p1->family_teach.hw.telenumber);
				printf("\n�Ƿ��޸Ĳ��˼�����ϵ��1��Ϣ��\t\t1.�޸�\t2.����\n�����룺");
				scanf("%d", &x);
				getchar();
				while (x != 1 && x != 2)
				{
					printf("\t\t\t***************************************\n");
					printf("\t\t\t*    �������ֵ������������ѡ��     *\n");
					printf("\t\t\t***************************************\n");
					printf("�����룺");
					scanf("%d", &x);
					getchar();
				}
				if (x == 1)
				{
					printf("\t��ϵ��1��\t\t�绰��\t��:���� tab�� 19923583668 �س���������\n");
					scanf("%s%s", p1->family_teach.fm.name, p1->family_teach.fm.telenumber);
					getchar();
					if (p1->family_teach.hw.numberlogin == 1)
					{
						printf("�Ƿ�����޸ļ�����ϵ��2��Ϣ��\t\t1.�޸Ļ���ɾ��\t2.����\n�����룺");
						scanf("%d", &x);
						getchar();
						while (x != 1 && x != 2)
						{
							printf("\t\t\t***************************************\n");
							printf("\t\t\t*    �������ֵ������������ѡ��     *\n");
							printf("\t\t\t***************************************\n");
							printf("�����룺");
							scanf("%d", &x);
							getchar();
						}
						if (x == 1)
						{
							printf("�Ƿ��޸ļ�����ϵ��2��Ϣ��\t\t1.�޸�\t2.ɾ��\n�����룺");
							scanf("%d", &p1->family_teach.hw.numberlogin);
							getchar();
							while (p1->family_teach.hw.numberlogin != 1 && p1->family_teach.hw.numberlogin != 2)
							{
								printf("\t\t\t***************************************\n");
								printf("\t\t\t*    �������ֵ������������ѡ��     *\n");
								printf("\t\t\t***************************************\n");
								printf("�����룺");
								scanf("%d", &p1->family_teach.hw.numberlogin);
								getchar();
							}
							if (p1->family_teach.hw.numberlogin == 1)
							{
								printf("\t\t��ϵ��2\t\t�绰\t��:���� tab�� 19923583668 �س���������\n");
								scanf("%s%s", p1->family_teach.hw.name, p1->family_teach.hw.telenumber);
								getchar();
							}
							else
							{
								strcpy(p1->family_teach.hw.name, "0");
								strcpy(p1->family_teach.hw.telenumber, "0");
								printf("������ϵ��2��Ϣɾ���ɹ�\n");
							}
						}
					}
					else
					{
						printf("�Ƿ������Ӽ�����ϵ��2��Ϣ��\t\t1.���\t2.����\n�����룺");
						scanf("%d", &x);
						getchar();
						while (x != 1 && x != 2)
						{
							printf("\t\t\t***************************************\n");
							printf("\t\t\t*    �������ֵ������������ѡ��     *\n");
							printf("\t\t\t***************************************\n");
							printf("�����룺");
							scanf("%d", &x);
							getchar();
						}
						if (x == 1)
						{
							p1->family_teach.hw.numberlogin = 1;
							printf("\n\t\t��ϵ��2\t\t�绰\t��:���� tab�� 19923583668 �س���������\n");
							scanf("%s%s", p1->family_teach.hw.name, p1->family_teach.hw.telenumber);
							getchar();
						}
					}
				}
				printf("\n\t���˲�����\n");
				printf("\t%s\n", p1->illness);
				printf("\n�Ƿ���²��˲�����Ϣ��\t\t1.����\t2.����\n�����룺");
				scanf("%d", &x);
				getchar();
				while (x != 1 && x != 2)
				{
					printf("\t\t\t***************************************\n");
					printf("\t\t\t*    �������ֵ������������ѡ��     *\n");
					printf("\t\t\t***************************************\n");
					printf("�����룺");
					scanf("%d", &x);
					getchar();
				}
				if (x == 1)
				{
					printf("\t����Ϊ��\t�������� ����س�����\n\t����£�");
					scanf("%s", p1->illness);
					getchar();
				}
				printf("\t���ң�%s", p1->departments);
				printf("\n\tסԺ���\n");
				if (p1->Zhuyuan_Im.In_dengji == 1)
				{
					printf("\tסԺ\t\t������%s\t\t��Ժʱ�䣺%d��%d��%d��", p1->Zhuyuan_Im.address, p1->Zhuyuan_Im.In_day.year, p1->Zhuyuan_Im.In_day.month, p1->Zhuyuan_Im.In_day.day);
					if (p1->Zhuyuan_Im.Out_dengji == 1)
						printf("\t\t��Ժʱ�䣺%d��%d��%d��\n", p1->Zhuyuan_Im.Out_day.year, p1->Zhuyuan_Im.Out_day.month, p1->Zhuyuan_Im.Out_day.day);
					else
						printf("\t\tδ��Ժ\n");
				}
				else
					printf("\tδסԺ\n");
				printf("�Ƿ��޸Ĳ���סԺ��Ϣ��\t\t1.�޸�\t2.����\n�����룺");
				scanf("%d", &x);
				getchar();
				while (x != 1 && x != 2)
				{
					printf("\t\t\t***************************************\n");
					printf("\t\t\t*    �������ֵ������������ѡ��     *\n");
					printf("\t\t\t***************************************\n");
					printf("�����룺");
					scanf("%d", &x);
					getchar();
				}
				if (x == 1)
				{
					printf("�Ƿ�סԺ\t\t1.��סԺ  2.δסԺ\n");
					scanf("%d", &p1->Zhuyuan_Im.In_dengji);
					getchar();
					while (p1->Zhuyuan_Im.In_dengji != 1 && p1->Zhuyuan_Im.In_dengji != 2)
					{
						printf("\t\t\t***************************************\n");
						printf("\t\t\t*    �������ֵ������������ѡ��     *\n");
						printf("\t\t\t***************************************\n");
						printf("�����룺");
						scanf("%d", &p1->Zhuyuan_Im.In_dengji);
						getchar();
					}
					if (p1->Zhuyuan_Im.In_dengji == 1)
					{
						printf("������סԺ������Ϣ:\t����A-538 �س�������\n�����룺");
						scanf("%s", p1->Zhuyuan_Im.address);
						getchar();
						printf("��Ժʱ�䣺\t������ tab�� �� tab�� ��\n�����룺");
						scanf("%d%d%d", &p1->Zhuyuan_Im.In_day.year, &p1->Zhuyuan_Im.In_day.month, &p1->Zhuyuan_Im.In_day.day);
						getchar();
						printf("�����Ƿ��Ժ\t\t1.�ѳ�Ժ  2.δ��Ժ\n");
						scanf("%d", &p1->Zhuyuan_Im.Out_dengji);
						getchar();
						if (p1->Zhuyuan_Im.Out_dengji == 1)
						{
							printf("�������Ժʱ�䣺\t������ tab�� �� tab�� ��\n�����룺");
							scanf("%d%d%d", &p1->Zhuyuan_Im.Out_day.year, &p1->Zhuyuan_Im.Out_day.month, &p1->Zhuyuan_Im.Out_day.day);
							getchar();
						}
						else
						{
							p1->Zhuyuan_Im.Out_day.year = 0;
							p1->Zhuyuan_Im.Out_day.month = 0;
							p1->Zhuyuan_Im.Out_day.day = 0;
							printf("����δ��Ժ\n");
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
						printf("����δסԺ\n");
					}
				}
				printf("������Ϣ�޸ĳɹ�--\n");
				break;
			}
			p1 = p1->next;
		}
		if (flag != 1)
		{
			printf("\t\t\t***************************************\n");
			printf("\t\t\t*        ���ݿ��޲�����Ϣ��ע��       *\n");
			printf("\t\t\t*        1.��������                   *\n");
			printf("\t\t\t*        2.ע�Ს����Ϣ               *\n");
			printf("\t\t\t*        3.���˵�                     *\n");
			printf("\t\t\t***************************************\n�����룺");
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
					printf("\t\t\t*    �������ֵ������������ѡ��     *\n");
					printf("\t\t\t***************************************\n");
					printf("�����룺");
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
				printf("�Ҳ���ָ���ļ���\n");
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
			printf("�������ز�����Ϣ��ѯ����....\n");
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

//������Ϣ���Ĺ���_β

//������Ϣ��ѯ����_��ʾȫ��_ͷ

//ͨ�����֤�������������˹���_ͷ
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
		printf("�Ҳ���ָ���ļ���\n");
		exit(0);
	}
	bh = fgetc(s);
	rewind(s);
	if (bh == EOF)
	{
		printf("\t\t\t***************************************\n");
		printf("\t\t\t*        ���ݿ��޲�����Ϣ��ע��       *\n");
		printf("\t\t\t*        1.ע�Ს����Ϣ               *\n");
		printf("\t\t\t*        2.���˵�                     *\n");
		printf("\t\t\t***************************************\n�����룺");
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
				printf("\t\t\t*    �������ֵ������������ѡ��     *\n");
				printf("\t\t\t***************************************\n�����룺");
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
		while (!feof(s))/*���ļ��ڲ�ָ��ָ���ļ�ĩβʱ������1�Խ���*/
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
		printf("\n��ע�Ს�����������֤\n");
		p1 = head;
		while (p1 != NULL)
		{
			printf("%s\t%s\n", p1->name, p1->Id_card);
			Sleep(150);
			p1 = p1->next;
		}
		printf("\n������Ҫ�����Ĳ��˵����֤�ţ�");
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
				printf("\t����\t\t�Ա�\t\t����\t\t���֤\t\t\n");
				printf("\t%s\t\t%s\t\t%d\t\t%s", p1->name, p1->sex, p1->age, p1->Id_card);
				printf("\n\t������ϵ��ʽ\n");
				printf("\t��ϵ��1��%s\t�绰��%s", p1->family_teach.fm.name, p1->family_teach.fm.telenumber);
				if (p1->family_teach.hw.numberlogin == 1)
					printf("\n\t��ϵ��2��%s\t�绰��%s", p1->family_teach.hw.name, p1->family_teach.hw.telenumber);
				printf("\n\t���˲�����\n");
				printf("\t%s\n", p1->illness);
				printf("\t���ң�%s", p1->departments);
				printf("\n\tסԺ���\n");
				if (p1->Zhuyuan_Im.In_dengji == 1)
				{
					printf("\tסԺ\t\t������%s\t\t��Ժʱ�䣺%d��%d��%d��", p1->Zhuyuan_Im.address, p1->Zhuyuan_Im.In_day.year, p1->Zhuyuan_Im.In_day.month, p1->Zhuyuan_Im.In_day.day);
					if (p1->Zhuyuan_Im.Out_dengji == 1)
						printf("\t\t��Ժʱ�䣺%d��%d��%d��\n", p1->Zhuyuan_Im.Out_day.year, p1->Zhuyuan_Im.Out_day.month, p1->Zhuyuan_Im.Out_day.day);
					else
						printf("\t\tδ��Ժ\n");
				}
				else
					printf("\tδסԺ\n");
				printf("\n\n���� 1.��������\t\t2.������һ���˵�\n�����룺");
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
						printf("\t\t\t*    �������ֵ������������ѡ��     *\n");
						printf("\t\t\t***************************************\n");
						printf("\n\n���� 1.��������\t\t2.������һ���˵�\n�����룺");
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
			printf("\t\t\t*        ���֤������������޴���     *\n");
			printf("\t\t\t*        1.���²���                   *\n");
			printf("\t\t\t*        2.ע���ID������Ϣ           *\n");
			printf("\t\t\t*        3.���˵�                     *\n");
			printf("\t\t\t***************************************\n�����룺");
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
					printf("\t\t\t*    �������ֵ������������ѡ��     *\n");
					printf("\t\t\t***************************************\n�����룺");
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
//ͨ�����֤�������������˹���_β
void Findpaitent()
{
	int n;
	system("cls");
	printf("\t\t\t***************************************\n");
	printf("\t\t\t*      ������Ϣ��ѯ����               *\n");
	printf("\t\t\t*                                     *\n");
	printf("\t\t\t*      1.��ʾ���в�����Ϣ             *\n");
	printf("\t\t\t*      2.����ָ��������Ϣ             *\n");
	printf("\t\t\t*      3.���˵�                       *\n");
	printf("\t\t\t***************************************\n");
	printf("\n");
	printf("������������ִ�в�����");
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
			printf("\t\t\t*    �������ֵ������������ѡ��     *\n");
			printf("\t\t\t***************************************\n�����룺");
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
//������Ϣ��ѯ����_��ʾȫ��_β
							/*								������Ϣ����ϵͳ�˵�ͷ							*/
void PaitentIm_menu()
{
	int n;
	system("cls");
	printf("\t\t\t***************************************\n");
	printf("\t\t\t*     ��ӭʹ��ҽԺ��Ϣ����ϵͳ        *\n");
	printf("\t\t\t*                                     *\n");
	printf("\t\t\t*      1.ע�Ს����Ϣ                 *\n");
	printf("\t\t\t*      2.ע��������Ϣ                 *\n");
	printf("\t\t\t*      3.��ѯ������Ϣ                 *\n");
	printf("\t\t\t*      4.�������в�����Ϣ             *\n");
	printf("\t\t\t*      0.�˳�ϵͳ                     *\n");
	printf("\t\t\t***************************************\n");
	printf("\t\t\tTips:��Ҫע�ᣬע�������²�����Ϣ����ͨ����ѯ���ܲ�ѯ�����Ƿ���ڣ��ٽ�����һ������");
	printf("\n");
	printf("������  0-4   ������ִ�в�����");
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
			printf("\t\t\t*    �������ֵ������������ѡ��     *\n");
			printf("\t\t\t***************************************\n�����룺");
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
/*								������Ϣ����ϵͳ�˵�β							*/
/*									��ϵͳ�˵�_β											*/
int main()
{
	int i;
	i = login();/*��¼�ӿ�*/
	if (i == 1)
		PaitentIm_menu();/*ҽԺ��Ϣ����ϵͳ���˵�*/
	return 0;
}