#include <iostream>
#include <cstring>
#include "someclass.h"
using namespace std;
int main(void) {
//	void (*fun[])(void)={magicman::Natack,magicman::Nmagiclight,magicman::addexp,fire_magic::firestorm};
	void (magicman::*fun)(void)=fire_magic::Natack;
	magicman C1;
	fire_magic skill; 
	int i;
	(C1.*fun)();
//	cout<<"��ӭ�����������ɴ󺣹���mikailuo!"<<endl;
//	while(i<0||i>4){
//		cout<<"��������һ�����ˣ���ѡ�񹥻���ʽ��";
//		cin>>i;
//		mikailuo.*fun[i];
//	}
	cout<<"ERROR!";
	return 0;
}


