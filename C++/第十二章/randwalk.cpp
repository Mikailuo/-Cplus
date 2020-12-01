//一个简单的入栈压栈展示，就不打注释了。
//唯一注意的一点就是这里采用枚举的手段解决类域中常量的问题，之前一直使用宏替换 
//那么能不能通过枚举解决宏替换数据类型呢？ 
#include <iostream>
#include <cstdlib>			//rand(),srand(),prototypes
#include <ctime>			//time(),prototypes
#include "vector.h"			

using namespace std;
using namespace Vec;

int main(void){
	srand(time(0));				//使得程序随机数种子以0时刻（当前时刻）的time()返回值为准 
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
			direction=rand()%360;			//由于随机数种子的不断变化，拟合出一种"真随机" 
			step.reset(dstep,direction,Vec::vector::POL);
			result=result+step;      //这里按照重载方式，即使rect模式下的mag和ang也会变化 
			steps++;
		}
		cout<<"After"<<steps<<"steps,the subject has the following location:"<<endl;
		cout<<result<<endl;
		
		result.polar_mode();     //使得重载后的<<按照pol模式输出 
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



