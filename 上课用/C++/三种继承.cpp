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
//	cout<<"欢迎来到马里亚纳大海沟！mikailuo!"<<endl;
//	while(i<0||i>4){
//		cout<<"你遇到了一个敌人，请选择攻击方式：";
//		cin>>i;
//		mikailuo.*fun[i];
//	}
	cout<<"ERROR!";
	return 0;
}


