#include<iostream>
namespace Vec
{
	class vector{
		public:
			enum Mode{RECT,POL};		//����ö������ 
		private:
			double x;         //һ�ַ�ʽ����ѧ�ı�׼��ʽ(x,y) 
			double y;
			double mag;		  //��һ�ַ�ʽ�����ȺͽǶ����̻� 
			double ang;
			Mode mode;		  //ѡһ�ַ�ʽ 
		//private methods
			void set_mag();
			void set_ang();
			void set_x();
			void set_y();
		
		public:
			vector(double n1=0,double n2=0,Mode form=RECT);
			void reset(double n1,double n2,Mode form=RECT);
			~vector();
			double xval()const{return x;}		//����xֵ
			double yval()const{return y;}		//����yֵ 
			double magval()const {return mag;}		//���������Ĵ�С 
			double angval()const {return ang;}		//���������ķ��򣨽Ƕȣ�
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
