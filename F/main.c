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
	/*sum���ڴ���ۼӺͣ�ave���ڴ��ƽ��ֵ*/
	/*min���ڴ����ͷ���*/
	float sum, ave, min;
	int i;

	/*����*/
	sum = min = ave = 0;
	/*���ۼӺ�*/
	for (i = 0; i < N; i++)
	{
		sum += a[i].s;
	}
	/*��ƽ��ֵ*/
	ave = sum / N;
	printf("The average is: %f\n", ave);

	/*����a[0]����ͷֵ�ѧ����¼*/
	min = a[0].s;
	/*��a[0]�ļ�¼���Ƶ��β�s��*/
//	s->num = a[0].num;
    strcpy(s->num,a[0].num);
	s->s = a[0].s;
	for (i = 0; i < N; i++)
	{
		/*�����¼a[i]�еķ�����min����*/
		/*��a[i]�ļ�¼���Ƶ��β�s�У�������min�е�ֵ*/
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



