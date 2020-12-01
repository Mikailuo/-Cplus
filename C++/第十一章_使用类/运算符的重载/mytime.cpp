#include<iostream>
#include "mytime.h"
using namespace std;
Time::Time(int h,int m){
	hours=h;
	minutes=m;
}

void Time::addhours(int h){
	hours+=h;
}

void Time::addmin(int m){
	minutes+=m;
}

void Time::reset(int h,int m){
	hours=h;
	minutes=m;
}

Time Time::operator+(const Time &t)const{		//��Ҫ������operater+��ʹ�� 
	Time sum;
	sum.minutes=minutes+t.minutes;
	sum.hours=hours+t.hours+sum.minutes/60;		//�����ڸ�ϰһ�£���ķ�װֻ�Ƕ�������ԣ�ͬ��֮��Ķ��󲻴��ڷ�װ�ԣ������������ 
	sum.minutes%=60;
	return sum;
}

Time operator+(int min,const Time &t){
	Time sum;
	sum.minutes=min+t.minutes;
	sum.hours=t.hours+sum.minutes/60;		//���ڴ�����Ƿǳ�Ա����min��������û��hours 
	sum.minutes%=60;
	return sum;
}

void Time::show()const{
	cout<<hours<<"hours, "<<minutes<<" minutes"<<endl;
}

//void operator<<(ostream &os,const Time &t){					//��Ԫ���������෽��������û��������ʱҲ����Ҫfriend 
//	os<<t.hours<<"hours, "<<t.minutes<<"minutes"<<endl;
//}

ostream & operator<<(ostream &os,const Time &t){
	os<<t.hours<<"hours, "<<t.minutes<<"minutes"<<endl;
	return os;
}
