/*----------------ͷ�ļ�--------------*/
#define  _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "SCORE.h"

/*----------------��������-------------*/

//1.1�ֶ�����ѧ����������
void readData(SS stu[], int N)
{

	printf("�밴�����¸�ʽ����ѧ����Ϣ��ѧ��,����,ƽʱ�ɼ�,��ĩ�ɼ�\n");

	for (int i = 0; i < N; i++)
	{
		printf("��%d��ѧ��:", i + 1);
		scanf("%s %s %f %f", &stu[i].number, &stu[i].name, &stu[i].dailyScore, &stu[i].finalScore);
		printf("\n");
	}

	printf("------�ɼ�¼�����!--------\n");

}

//1.2���ļ����ȡѧ����������
SS *readDataFromFile(int *N)
{

	printf("\n\n------��һ��: ���ļ���ȡѧ���ĳɼ���Ϣ--------\n\n");

	SS *stu;// �����¿ռ�,��ȡ�ļ��е�ÿ��ѧ����Ϣ

	FILE *fp = NULL;
	int count = 6;
	int index = 0;
	char ch;
	fopen_s(&fp,"data.txt", "r");

	//1.��ȡѧ����Ŀ
	if (fp != NULL)
	{
		*N = 6;
	}
	else
	{
		printf("failed to open the info file\n");
		getchar();
	}

	printf("ѧ����ĿΪ:%d\n", count);


	//2.������ѧ������洢�ռ�
	stu = (SS*)malloc(count * sizeof(SS));


	//3.��ȡÿ��ѧ������Ϣ
	while ((!feof(fp)))
	{

		//�����ļ����ݵ��ڴ�	
		
		fscanf_s(fp, "%10s", stu[index].number, 11);
		fscanf_s(fp, "%10s", stu[index].name, 11);
		fscanf_s(fp, "%f", &stu[index].dailyScore);
		fscanf_s(fp, "%f", &stu[index].finalScore);
		fscanf_s(fp, "%f\n", &stu[index].generalScore);
			//���������ѧ����Ϣ
			printf("* ѧ�ţ�%s	����:%s		ƽʱ�ɼ���%4.2f��		��ĩ�ɼ�:%4.2f��\n", (stu[index].number), (stu[index].name), stu[index].dailyScore, stu[index].finalScore);
		index++;
	}

	return stu;
}

//2.����N��ѧ�����Ե������ɼ�
void calcuScore(SS stu[], int N)
{


	printf("\n\n------�ڶ���: ����ÿ��ѧ���������ɼ�--------\n\n");

	for (int i = 0; i < N; i++)
	{

		stu[i].generalScore = 0.2*stu[i].dailyScore + 0.8*stu[i].finalScore;
		printf("* ѧ�ţ�%s	����:%s		�ܳɼ�:%4.2f��\n", (stu[i].number), (stu[i].name), stu[i].generalScore);

	}


}


//3.���������ɼ�����
int cmpBigtoSmall(const void *a, const void *b)
{

	SS *aa = (SS *)(a);
	SS *bb = (SS *)(b);



	if ((*aa).generalScore < (*bb).generalScore)  return 1;

	else if ((*aa).generalScore > (*bb).generalScore)  return -1;

	else
		return 0;

}

void sortScore(SS stu[], int N)
{

	qsort(&(stu[0]), N, sizeof(stu[0]), cmpBigtoSmall);

}

//4.����һ���ĸ�ʽ���N��ѧ������Ϣ
void printOut(SS stu[], int N)
{

	printf("\n------������: �����ܳɼ����ѧ��������Ϣ!------\n\n");

	for (int i = 0; i < N; i++)
	{

		printf("��%d����Ϣ ѧ�ţ�%s	����:%s		�ܳɼ�:%4.2f��\n", i + 1, &(stu[i].number[0]), &(stu[i].name[0]), stu[i].generalScore);
	}

	

}
//5.��ѧ�Ų�ѯѧ����Ϣ
void queryScore(SS stu[], int N)
{
	printf("\n------------�������� ��ѯѧ����Ϣ!----------\n\n");
	char num[11]; int i;
	printf("������ѧ��\n");
	scanf("%s", num);
	for (i = 0; i < N; i++)
	{
		if (strcmp(stu[i].number, num))

			continue;

		else

			printf("* ѧ�ţ�%s	����:%s		ƽʱ�ɼ���%4.2f��	ʵ��ɼ���%4.2f��	��ĩ�ɼ�:%4.2f��\n", (stu[i].number), (stu[i].name), stu[i].dailyScore, stu[i].experimentalScore, stu[i].finalScore);


	}
}
//6.�������ͬѧ��ƽ����
void averageScore(SS stu[], int N)
{
	printf("\n-------���Ĳ����������ͬѧ��ƽ���֣�-------\n\n");
	int  i; float m; m = 0;
	for (i = 0; i < N; i++)
	{
		m = stu[i].generalScore + m;

	};
	float average = m / N;
	printf("ƽ�����ǣ�%f\n", average);
};

//7.�������ͬѧ�ı�׼��
void stadevScore(SS stu[], int N)
{
	printf("\n------------���岽�������׼�----------\n\n");
	int i, j;
	float n, m, k, l; m = 0; n = 0;
	for (i = 0; i < N; i++)
	{
		m = stu[i].generalScore + m;

	}

	n = 0;
	for (j = 0; j < N; j++)
	{
		n = (stu[j].generalScore - m / N)*(stu[j].generalScore - m / N) + n;

	}
	k = n / N;
	l = sqrt(k);
	printf("��׼���ǣ�%f\n", l);
}
