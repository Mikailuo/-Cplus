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

Time Time::operator+(const Time &t)const{		//主要点在于operater+的使用 
	Time sum;
	sum.minutes=minutes+t.minutes;
	sum.hours=hours+t.hours+sum.minutes/60;		//这里在复习一下，类的封装只是对类外而言，同类之间的对象不存在封装性，可以随意访问 
	sum.minutes%=60;
	return sum;
}

Time operator+(int min,const Time &t){
	Time sum;
	sum.minutes=min+t.minutes;
	sum.hours=t.hours+sum.minutes/60;		//由于传入的是非成员参数min，故这里没有hours 
	sum.minutes%=60;
	return sum;
}

void Time::show()const{
	cout<<hours<<"hours, "<<minutes<<" minutes"<<endl;
}

//void operator<<(ostream &os,const Time &t){					//友元函数不是类方法，所以没有类域定义时也不需要friend 
//	os<<t.hours<<"hours, "<<t.minutes<<"minutes"<<endl;
//}

ostream & operator<<(ostream &os,const Time &t){
	os<<t.hours<<"hours, "<<t.minutes<<"minutes"<<endl;
	return os;
}
