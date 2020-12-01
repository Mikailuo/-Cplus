//一个简单的入栈压栈展示，就不打注释了。
//唯一注意的一点就是这里采用枚举的手段解决类域中常量的问题，之前一直使用宏替换 
//那么能不能通过枚举解决宏替换数据类型呢？ 
#include <iostream>
#include <cstdlib>
#include "mytime.h"

using namespace std;

int main(void){
	Time planning;
	Time coding(2,40);
	Time fixing(5,55);
	Time total;
	
	cout<<"Planing time=";
	planning.show();
	cout<<endl;
	
	cout<<"coding time=";
	coding.show();
	cout<<endl;
	
	cout<<"fixing time=";
	fixing.show();
	cout<<endl;
	
	total=coding+fixing;					//说明加法已被重载 ，此处的重载加法对应的是coding对象所在类域对应 
	cout<<"coding+fixing=";					//的重载加法 
	total.show();
	cout<<endl;
	
	total=65+fixing;					//说明加法已被重载 ，此处的重载加法对应的是coding对象所在类域对应 
	cout<<"65min+fixing=";					//的重载加法 
	total.show();
	cout<<endl;
	
	cout<<"total: "<<endl;
//	cout<<total;					//采用的是void的那个重载函数 
	cout<<fixing<<";"<<endl;		//这个采用的是返回ostream &的那个重载函数 ，void那个函数不能使用 
	
	Time morefixing(3,28);
	cout<<"more fixing=";
	morefixing.show();
	cout<<endl;
	
	total=morefixing.operator+(total);
	total.show();
	cout<<endl;
	
	morefixing=morefixing.operator+(total);		
	morefixing.show();
	
	return 0;
}



