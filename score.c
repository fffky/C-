/*----------------头文件--------------*/
#define  _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "SCORE.h"

/*----------------函数定义-------------*/

//1.1手动输入学生基本数据
void readData(SS stu[], int N)
{

	printf("请按照如下格式输入学生信息：学号,姓名,平时成绩,期末成绩\n");

	for (int i = 0; i < N; i++)
	{
		printf("第%d个学生:", i + 1);
		scanf("%s %s %f %f", &stu[i].number, &stu[i].name, &stu[i].dailyScore, &stu[i].finalScore);
		printf("\n");
	}

	printf("------成绩录入完毕!--------\n");

}

//1.2从文件里读取学生基本数据
SS *readDataFromFile(int *N)
{

	printf("\n\n------第一步: 从文件读取学生的成绩信息--------\n\n");

	SS *stu;// 开辟新空间,存取文件中的每个学生信息

	FILE *fp = NULL;
	int count = 6;
	int index = 0;
	char ch;
	fopen_s(&fp,"data.txt", "r");

	//1.获取学生数目
	if (fp != NULL)
	{
		*N = 6;
	}
	else
	{
		printf("failed to open the info file\n");
		getchar();
	}

	printf("学生数目为:%d\n", count);


	//2.给所有学生分配存储空间
	stu = (SS*)malloc(count * sizeof(SS));


	//3.读取每条学生的信息
	while ((!feof(fp)))
	{

		//读入文件数据到内存	
		
		fscanf_s(fp, "%10s", stu[index].number, 11);
		fscanf_s(fp, "%10s", stu[index].name, 11);
		fscanf_s(fp, "%f", &stu[index].dailyScore);
		fscanf_s(fp, "%f", &stu[index].finalScore);
		fscanf_s(fp, "%f\n", &stu[index].generalScore);
			//输出排序后的学生信息
			printf("* 学号：%s	姓名:%s		平时成绩：%4.2f分		期末成绩:%4.2f分\n", (stu[index].number), (stu[index].name), stu[index].dailyScore, stu[index].finalScore);
		index++;
	}

	return stu;
}

//2.计算N个学生各自的总评成绩
void calcuScore(SS stu[], int N)
{


	printf("\n\n------第二步: 计算每个学生的总评成绩--------\n\n");

	for (int i = 0; i < N; i++)
	{

		stu[i].generalScore = 0.2*stu[i].dailyScore + 0.8*stu[i].finalScore;
		printf("* 学号：%s	姓名:%s		总成绩:%4.2f分\n", (stu[i].number), (stu[i].name), stu[i].generalScore);

	}


}


//3.根据总评成绩排名
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

//4.按照一定的格式输出N个学生的信息
void printOut(SS stu[], int N)
{

	printf("\n------第三步: 根据总成绩输出学生排名信息!------\n\n");

	for (int i = 0; i < N; i++)
	{

		printf("第%d名信息 学号：%s	姓名:%s		总成绩:%4.2f分\n", i + 1, &(stu[i].number[0]), &(stu[i].name[0]), stu[i].generalScore);
	}

	

}
//5.用学号查询学生信息
void queryScore(SS stu[], int N)
{
	printf("\n------------第六步： 查询学生信息!----------\n\n");
	char num[11]; int i;
	printf("请输入学号\n");
	scanf("%s", num);
	for (i = 0; i < N; i++)
	{
		if (strcmp(stu[i].number, num))

			continue;

		else

			printf("* 学号：%s	姓名:%s		平时成绩：%4.2f分	实验成绩：%4.2f分	期末成绩:%4.2f分\n", (stu[i].number), (stu[i].name), stu[i].dailyScore, stu[i].experimentalScore, stu[i].finalScore);


	}
}
//6.计算各个同学的平均分
void averageScore(SS stu[], int N)
{
	printf("\n-------第四步：计算各个同学的平均分！-------\n\n");
	int  i; float m; m = 0;
	for (i = 0; i < N; i++)
	{
		m = stu[i].generalScore + m;

	};
	float average = m / N;
	printf("平均数是：%f\n", average);
};

//7.计算各个同学的标准差
void stadevScore(SS stu[], int N)
{
	printf("\n------------第五步：计算标准差！----------\n\n");
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
	printf("标准差是：%f\n", l);
}
