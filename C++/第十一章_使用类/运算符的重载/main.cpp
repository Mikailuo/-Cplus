//һ���򵥵���ջѹջչʾ���Ͳ���ע���ˡ�
//Ψһע���һ������������ö�ٵ��ֶν�������г��������⣬֮ǰһֱʹ�ú��滻 
//��ô�ܲ���ͨ��ö�ٽ�����滻���������أ� 
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
	
	total=coding+fixing;					//˵���ӷ��ѱ����� ���˴������ؼӷ���Ӧ����coding�������������Ӧ 
	cout<<"coding+fixing=";					//�����ؼӷ� 
	total.show();
	cout<<endl;
	
	total=65+fixing;					//˵���ӷ��ѱ����� ���˴������ؼӷ���Ӧ����coding�������������Ӧ 
	cout<<"65min+fixing=";					//�����ؼӷ� 
	total.show();
	cout<<endl;
	
	cout<<"total: "<<endl;
//	cout<<total;					//���õ���void���Ǹ����غ��� 
	cout<<fixing<<";"<<endl;		//������õ��Ƿ���ostream &���Ǹ����غ��� ��void�Ǹ���������ʹ�� 
	
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



