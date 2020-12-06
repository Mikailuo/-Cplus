#include<iostream>
#include<string>
using namespace std;

class brass{
	private:
		string fullname;
		long acctnum;
		double balance;			//���� 
	public:
		brass(const string &s="NULLBODY",long an =-1,double bal=0.0);
		void deposit(double amt);			//��Ǯ 
		virtual void withdraw(double amt);
		double balance()const;
		virtual void view()const;
		virtual ~brass(){};
};

class brassplus:public brass{
	private:
		double maxloan;			//͸֧�������� 
		double rate;			//�������� 
		double owesbank;		//��͸֧�ܶ� 
	public:
		brassplus(const string &s="NULLBODY",long an=-1,double bal=0.0,double ml=500,double r=0.11125);
		brassplus(const brass &ba,double ml=500,double r=0.11125);			//��ʽ���ƹ��캯�� 
		virtual void view()const;					//�����෽������಻ͬʱ�Ϳ��Կ����麯�� 
		virtual void withdraw(double amt);			//ͬ�� 
		void resetmax(double m){maxloan=m};
		void resetrate(double r){rate=r;};
		void resetowes(){owesbank=0;};
};

brass::brass(const string &s,long an,double bal){
	fullname=s;
	acctnum=an;
	balance=bal;
}

void brass::deposit(double amt){			//��Ǯ 
	if(amt<0)
		cout<<"negative deposit not allowed;"<<"deposit is canceled"<<endl;
	else
		balance+=amt; 
}

void brass::withdraw(double amt){				//ȡǮ 
	if(amt<0)
		cout<<"withdrawal amount must be positive;"
		<<"withdrawal canceled"<<endl;
	else if(amt<balance)
		balance-=amt;
	else{
		cout<<"withdrawal amount of $"<<amt
		<<" exceeds your balance."<<endl;
		cout<<"withdrawal canceled"<<endl;
	}
}

double brass::balance()const{ return balance;}

void brass::view()const{
	cout<<"Client: "<<fullname<<endl;
	cout<<"Account number: "<<acctnum<<endl;
	cout<<"balance: $"<<balance<<endl;
}

brassplus::brassplus(const string &s,long an,double bal,double ml,double r):
				brass(s,an,bal)
{
	maxloan=ml;
	owesbank=0.0;
	rate=r;
}

brassplus::brassplus(const brass &ba,double ml,r):brass(ba){
	maxloan=ml;
	owesbank=0.0;
	rate=r;
}

void brassplus::view()const{
	//brass::view();
	cout<<"maxloan: $"<<maxloan<<endl;
	cout<<"owed to bank: $"<<owesbank<<endl;
	cout<<"loan rate: "<<100*rate<<"%"<<endl;
}

void brassplus::withdraw(double amt){
	double bal=balance;
	if(amt<bal){
		brass::withdraw(double amt);
	}
	else if(amt<=bal+maxloan-owesbank){
		double advance=amt-bal;
		owesbank+=advance*(1.0+rate);				//������͸֧��ȵ���͸֧��*���ʵ��ۼ� 
		cout<<"bank advance:$"<<advance<<endl;
		cout<<"finance charge:$"<<advance*rate<<endl;
		deposit(advance);				//�����advance���ȥ 
		brass::withdraw(amt);				//������ȡ������Ϊ0��ֻ����owesbank������һ������͸֧��������û��£��� 
	}
	else
		cout<<"credit limit exceeded.transaction canceled"<<endl;
}

