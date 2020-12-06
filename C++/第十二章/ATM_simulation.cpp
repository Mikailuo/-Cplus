#include<iostream>
#include<cstdlib>	//for rand()\srand()
#include<ctime>		//for time() 
#include"queue.h"
#define MIN_PER_HR 60
using namespace std;

bool newcustomer(double x);
int main(void){
	srand(time(0));
	
	cout<<"Case study:bank of xxx"<<endl;
	cout<<"enter maximum size of queue:";
	int qs;
	cin>>qs;
	queue line(qs);
	
	cout<<"enter the number of simulation hours:";
	int hours;
	cin>>hours;
	//simulation will run 1 cycle per minute
	long cyclelimit = MIN_PER_HR*hours;
	cout<<"average number of customers per hour:";
	double perhour;
	cin>>perhour;				//ÿСʱƽ�������� 
	double min_per_cust;	//average time between arrivals
	min_per_cust=MIN_PER_HR/perhour;		//�˿ͼ��ʱ������ 
	
	elem temp;					//new customer
	long turnaways=0;			//customers who leave 
	long customers=0;			//the number of wait_customers
	long served=0;				//the number of served_customers(���ܻ��customers��) 
	long sum_line=0;			
	int wait_time=0;			//wait time
	long line_wait=0;				//���ڵȴ��ϵ�ʱ��
	//running the simulation
	for(int cycle=0;cycle<cyclelimit;cycle++){			//��ʱ��cycle 
		if(newcustomer(min_per_cust)){ 			//have newcomer
			if(line.isfull()){
				turnaways++;
			}
			else{
				customers++;
				temp.set(cycle);			//cycle��Ϊ�ù˿͵�arrive time,���˹˿�һ��(���)processtimeʱ�� 
				line.enqueue(temp);			//���ù˿���� 
			}
		}
		if(wait_time<=0&&!line.isempty()){		//��һλ�˿Ͳ�����ɣ��ֵ���һλ�˿ͣ���һ����Ȼ���õĵȴ�������ʼֵ0������ӣ� 
			line.dequeue(temp);				//�˿ͳ��� 
			wait_time=temp.ptime();			//��processtime��ֵ��wait_time 
			line_wait+=cycle-temp.when();		//��ǰʱ���ȥ��������ʱ�䣬����λ�ͻ��ȴ�������ʱ�� 
			served++;			//��������������һ�� 
		}		
		else if(wait_time>0){					//��ʱ��һλ�˿ͻ�û�����������ȴ�
				wait_time--;
			}
		sum_line+=line.queuecout();			//ÿһ��cycle�¶���ռ���� 
	}
	//reporting results
	if(customers>0){
		cout<<"customers accepted: "<<customers<<endl;
		cout<<"  customers served: "<<served<<endl;
		cout<<"			turnaways: "<<turnaways<<endl;
		cout<<" average queue size:";
		cout<<(double)sum_line/cyclelimit<<endl;				//һ���ַ���ģ���£���λ���Ӷ�����Դ��ʹ����� 
		cout<<" average wait time: "
			<<(double)line_wait/served<<" minutes"<<endl;			//�ܷ���˿͵�ƽ���ȴ�ʱ�� 
	} 
	else
		cout<<"no customers!"<<endl;
	cout<<"Done!"<<endl;
	
	return 0;
}

bool newcustomer(double x){				//ģ��ƽ��ÿx������һλ�˿ͣ�һ������ԣ� 
	return (rand()*x/RAND_MAX<1);			//RAND_MAX��Ϊ�꣬��ʾ����������ֵ 
}
