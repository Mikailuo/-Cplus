#ifndef MYTIME_H_
#define MYTIME_H_
#include<iostream>
using namespace std;
class Time{
	private:
		int hours;
		int minutes;
	public:
		Time(int h=0,int m=0);
		void addmin(int m);							//简单分钟的相加 
		void addhours(int h);						//简单密码的相加 
		void reset(int h=0,int m=0);				//重置 
		Time operator+(const Time &t)const;			//加法操作符的重载 
		friend Time operator+(int min,const Time &t);     //友元函数重载加法
//		friend void operator<<(ostream &os,const Time &t);
		friend ostream & operator<<(ostream &os,const Time &t);    //功能更强的重载函数 
		void show()const;						//展示函数 
};

#endif
