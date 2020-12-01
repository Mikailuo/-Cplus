/*
#include<stdio.h>
struct date {
	int month;
	int day;
	int year;
};
struct my {
	int month;
	int day;
	int year;
};
int main(int argc, char const *argv[]) {
	struct date mybirthday = { 07,17,2000 };
	struct date today = { 05,6,2020 };
	struct my yesterday;
	//yesterday = today;
	yesterday = (struct date) { 05, 5, 2020 };


	printf("today' date is %i-%i-%i.\n", today.year, today.month, today.day);
	printf("yesterday' date is %i-%i-%i.\n", yesterday.year, yesterday.month,yesterday.day);
	printf("my year is %i", today.year - mybirthday.year);
	return 0;
}
*/
/*
#include<stdio.h>
enum Money{
    fen1,fen2,fen5,jiao1,jiao2,jiao5,yuan1,yuan2,yuan5,yuan10,yuan50,yuan100
};
int main(void){
    printf("%d",yuan10);
    return 0;
}
*/
/*
#include<stdio.h>
#define SWITCH(a) (((a>=65&&a<90)||(a>=97&&a<=122))?1:0)
int main(void) {
	char c;
	scanf("%c", &c);
#if SWITCH(c)
	printf("YES!");
#else
	printf("NO!");
#endif
	return 0;
}
*/
#include <stdio.h>
#include <string.h>
#define N 10
typedef struct ss
{
	char num[10];
	int s;
} STU;

void fun(STU a[], STU *s)
{
	/*sum用于存放累加和，ave用于存放平均值*/
	/*min用于存放最低分数*/
	float sum, ave, min;
	int i;

	/*清零*/
	sum = min = ave = 0;
	/*求累加和*/
	for (i = 0; i < N; i++)
	{
		sum += a[i].s;
	}
	/*求平均值*/
	ave = sum / N;
	printf("The average is: %f\n", ave);

	/*假设a[0]是最低分的学生记录*/
	min = a[0].s;
	/*把a[0]的记录复制到形参s中*/
//	s->num = a[0].num;
    strcpy(s->num,a[0].num);
	s->s = a[0].s;
	for (i = 0; i < N; i++)
	{
		/*如果记录a[i]中的分数比min还低*/
		/*则将a[i]的记录复制到形参s中，并更新min中的值*/
		if (a[i].s < min)
		{
            strcpy(s->num,a[i].num);
			s->s = a[i].s;
			min = a[i].s;
		}
	}
}

int main(void)
{
	STU a[N] =
	{
		{"0901", 81}, {"0902", 89}, {"0903", 66},
		{"0904", 87}, {"0905", 77}, {"0906", 90},
		{"0907", 79}, {"0908", 61}, {"0909", 80},
		{"0910", 71}
	};
	STU m;
	fun(a, &m);
	printf("The lowest is: %s, %d\n", m.num, m.s);
	return 0;
}



