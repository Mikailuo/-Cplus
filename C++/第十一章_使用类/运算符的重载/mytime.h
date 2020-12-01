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
		void addmin(int m);							//�򵥷��ӵ���� 
		void addhours(int h);						//���������� 
		void reset(int h=0,int m=0);				//���� 
		Time operator+(const Time &t)const;			//�ӷ������������� 
		friend Time operator+(int min,const Time &t);     //��Ԫ�������ؼӷ�
//		friend void operator<<(ostream &os,const Time &t);
		friend ostream & operator<<(ostream &os,const Time &t);    //���ܸ�ǿ�����غ��� 
		void show()const;						//չʾ���� 
};

#endif
