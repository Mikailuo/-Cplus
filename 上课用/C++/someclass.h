#include<iostream>
using namespace std;
class magicman{
	private:
		int HP;
		int AD;
		int exp;
	protected:
		int MP;
		int AP;
	public:
		//构造函数 
		magicman(int HP=100,int MP=100,int AD=5,int AP=5,int exp=0){
			this->HP=HP;
			this->MP=MP;
			this->AD=AD;
			this->AP=AP;
			this->exp=exp;
		}
		//析构函数默认 
		~magicman(){
		}
		
		void Natack(); 					//普通物理攻击 
		void Nmagiclight();		//魔法光线 
		void addexp();					//经验增加 
};

class fire_magic:public magicman{
	private:
		int fire;              //火焰能力 
		int elecontrol;        //元素掌控
	public:
		//构造函数
		fire_magic(int HP,int MP,int exp,int AP,int AD,int fire=5,int elecontrol=10):magicman(HP,MP,AD,AP,exp){
			this->fire=fire;
			this->elecontrol=elecontrol;
		}
		void firestorm();
		~fire_magic();
        //析构函数默认 
};

void magicman::Natack(){
	cout<<"你造成了 "<<this->AD<<" 的物理伤害！"<<endl;
}

void magicman::Nmagiclight(){
	int damage=0;
	damage=AP*1.0+AD*0.1;
	cout<<"你释放了魔法光线（初级），造成了 "<<damage<<" 的魔法伤害!"<<endl; 
}

void magicman::addexp(){
	exp++;
}

void fire_magic::firestorm(){
	int damage=0;
	damage=AP*1.0*(fire+elecontrol*1.0/10);
	cout<<"你释放了火焰风暴（初级），造成了 "<<damage<<" 的火焰伤害！"<<endl; 
}

