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
		//���캯�� 
		magicman(int HP=100,int MP=100,int AD=5,int AP=5,int exp=0){
			this->HP=HP;
			this->MP=MP;
			this->AD=AD;
			this->AP=AP;
			this->exp=exp;
		}
		//��������Ĭ�� 
		~magicman(){
		}
		
		void Natack(); 					//��ͨ������ 
		void Nmagiclight();		//ħ������ 
		void addexp();					//�������� 
};

class fire_magic:public magicman{
	private:
		int fire;              //�������� 
		int elecontrol;        //Ԫ���ƿ�
	public:
		//���캯��
		fire_magic(int HP,int MP,int exp,int AP,int AD,int fire=5,int elecontrol=10):magicman(HP,MP,AD,AP,exp){
			this->fire=fire;
			this->elecontrol=elecontrol;
		}
		void firestorm();
		~fire_magic();
        //��������Ĭ�� 
};

void magicman::Natack(){
	cout<<"������� "<<this->AD<<" �������˺���"<<endl;
}

void magicman::Nmagiclight(){
	int damage=0;
	damage=AP*1.0+AD*0.1;
	cout<<"���ͷ���ħ�����ߣ�������������� "<<damage<<" ��ħ���˺�!"<<endl; 
}

void magicman::addexp(){
	exp++;
}

void fire_magic::firestorm(){
	int damage=0;
	damage=AP*1.0*(fire+elecontrol*1.0/10);
	cout<<"���ͷ��˻���籩��������������� "<<damage<<" �Ļ����˺���"<<endl; 
}

