//һ���򵥵���ջѹջչʾ���Ͳ���ע���ˡ�
//Ψһע���һ������������ö�ٵ��ֶν�������г��������⣬֮ǰһֱʹ�ú��滻 
//��ô�ܲ���ͨ��ö�ٽ�����滻���������أ� 
#include <iostream>
#include <cstdlib>			//rand(),srand(),prototypes
#include <ctime>			//time(),prototypes
#include "vector.h"			

using namespace std;
using namespace Vec;

int main(void){
	srand(time(0));				//ʹ�ó��������������0ʱ�̣���ǰʱ�̣���time()����ֵΪ׼ 
	double direction;
	vector step;
	vector result(0.0,0.0);
	unsigned long steps=0;
	double target;
	double dstep;
	
	cout<<"enter target distance (q to quit):";
	while(cin>>target)
	{
		cout<<"enter step length: ";
		if(!(cin>>dstep))  break;
		while(result.magval()<target){
			direction=rand()%360;			//������������ӵĲ��ϱ仯����ϳ�һ��"�����" 
			step.reset(dstep,direction,Vec::vector::POL);
			result=result+step;      //���ﰴ�����ط�ʽ����ʹrectģʽ�µ�mag��angҲ��仯 
			steps++;
		}
		cout<<"After"<<steps<<"steps,the subject has the following location:"<<endl;
		cout<<result<<endl;
		
		result.polar_mode();     //ʹ�����غ��<<����polģʽ��� 
		cout<<"or"<<endl;
		cout<<result<<endl;
		cout<<"Average outward distance per step="<<result.magval()/steps<<endl;
		steps=0;
		result.reset(0,0);
		cout<<"Enter target distance(q to quit):"; 
	}
	cout<<"Bye!"<<endl;
	cin.clear();
	while(cin.get()!='\n')
		continue;
	return 0;

	return 0;
}



