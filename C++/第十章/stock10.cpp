#include<iostream>
#include<cstring>
#include"stock10.h"
using namespace std;
stock::stock(const string &co="Error!",long n=0,double pr=0){
	cout<<"constructor using "<<co<<" called"<<endl;
	company=co;
	
	if(n<0){
		cout<<"Number of shares can't be negative;"<<company<<" shares set to 0."<<endl;
		shares=0;
	}
	else   shares=n;
	share_val=pr;
	set_tot();
}

stock::~stock(){
	cout<<"Bye, "<<company<<"!"<<endl;
}

void stock::buy(long num,double price){
	if(num<0){
		cout<<"error!"<<endl;
	
	}
	else{
		shares+=num;
		share_val=price;
		set_tot();
	}
}

void stock::show(){
	cout<<"company: "<<company<<"; shares: "<<shares<<"; share Price:$"<<share_val
	<<"; total values: "<<total_val<<endl;
	
}

const stock & stock::topval(const stock &s)const;
