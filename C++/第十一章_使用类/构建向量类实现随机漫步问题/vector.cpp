#include<cmath>
#include"vector.h"
using namespace std;

//creat namespace Vec
namespace Vec
{
	const double Rad_to_deg=45.0/atan(1.0);			//转弧度常量，atan1等于pi/4，正好得到180/pi 
	
	//以x,y基本量的向量定义（rect） 
	void vector::set_mag(){ 
		mag=sqrt(x*x+y*y);
	}
	void vector::set_ang(){
		if(x==0&&y==0)   ang=0;
		else ang=atan2(x,y);
	}
	
	//以长度,角度为基本量定义的向量（POL）  即极坐标 
	void vector::set_x(){
		x=mag*cos(ang);
	} 
	void vector::set_y(){
		y=mag*sin(ang);
	}
	
	vector::vector(double n1,double n2,Mode form){
		mode=form;
		if(form==RECT){
			x=n1;
			y=n2;
			set_mag();
			set_ang();
		}
		else if(form==POL){
			mag=n1;
			ang=n2;
			set_x();
			set_y();
		}
		else{
			cout<<"ERROR MODE!"<<endl;
			x=y=mag=ang=0;
			mode=RECT;
		} 
	}
	
	void vector::reset(double n1,double n2,Mode form){
		mode=form;
		if(form==RECT){
			x=n1;
			y=n2;
			set_mag();
			set_ang();
		}
		else if(form==POL){
			mag=n1;
			ang=n2;
			set_x();
			set_y();
		}
		else{
			cout<<"No correct form,automatically reset to 0;"<<endl;
			x=y=mag=ang=0;
			form=RECT;
		}
	}
	
	vector::~vector(){}
	
	void vector::polar_mode(){
		mode=POL;
	}	
	void vector::rect_mode(){
		mode=RECT;
	}
	
	//operator overloading
	//add
	vector vector::operator+(const vector &b)const{
		return vector(x+b.x,y+b.y);         //这里相当于直接调用构造函数返回对象，使得代码更简洁 
	}
	//subtract b from a
	vector vector::operator-(const vector &b)const{
		return vector(x-b.x,y-b.y);
	}
	//reverse sign of vector
	vector vector::operator-()const{
		return vector(-x,-y);
	}
	//mutiply vector
	vector vector::operator*(double n)const{
		return vector(n*x,n*y);
	}
	//友元函数的mutiply，从而实现可交换性 
	vector operator*(double n,const vector &a){
		return a*n;
	}
	
	ostream & operator<<(ostream &os,const vector &v){
		if(v.mode==vector::RECT)
			os<<"(x,y)=("<<v.x<<","<<v.y<<")";
		else if(v.mode==vector::POL)
			os<<"(m,a)=("<<v.mag<<","<<v.ang*Rad_to_deg<<")";
		else
			os<<"vector object mode is invalid";
		return os;
	}
}//end namespace Vec;
