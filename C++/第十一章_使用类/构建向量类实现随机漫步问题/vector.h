#include<iostream>
namespace Vec
{
	class vector{
		public:
			enum Mode{RECT,POL};		//典型枚举体了 
		private:
			double x;         //一种方式，数学的标准方式(x,y) 
			double y;
			double mag;		  //另一种方式，长度和角度来刻画 
			double ang;
			Mode mode;		  //选一种方式 
		//private methods
			void set_mag();
			void set_ang();
			void set_x();
			void set_y();
		
		public:
			vector(double n1=0,double n2=0,Mode form=RECT);
			void reset(double n1,double n2,Mode form=RECT);
			~vector();
			double xval()const{return x;}		//返回x值
			double yval()const{return y;}		//返回y值 
			double magval()const {return mag;}		//返回向量的大小 
			double angval()const {return ang;}		//返回向量的方向（角度）
			void polar_mode();			//set mode to POL	
			void rect_mode();			//set mode to rect 
		//operator overloading
			vector operator+(const vector &b)const;
			vector operator-(const vector &b)const;
			vector operator-()const;
			vector operator*(double n)const;
		//friends
			friend vector operator*(double n,const vector &a);
			friend std::ostream & operator<<(std::ostream &os,const vector &v);
	}; 
} 
