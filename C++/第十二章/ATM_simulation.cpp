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
	cin>>perhour;				//每小时平均来人数 
	double min_per_cust;	//average time between arrivals
	min_per_cust=MIN_PER_HR/perhour;		//顾客间隔时间期望 
	
	elem temp;					//new customer
	long turnaways=0;			//customers who leave 
	long customers=0;			//the number of wait_customers
	long served=0;				//the number of served_customers(可能会比customers少) 
	long sum_line=0;			
	int wait_time=0;			//wait time
	long line_wait=0;				//花在等待上的时间
	//running the simulation
	for(int cycle=0;cycle<cyclelimit;cycle++){			//计时器cycle 
		if(newcustomer(min_per_cust)){ 			//have newcomer
			if(line.isfull()){
				turnaways++;
			}
			else{
				customers++;
				temp.set(cycle);			//cycle作为该顾客的arrive time,给此顾客一个(随机)processtime时间 
				line.enqueue(temp);			//将该顾客入队 
			}
		}
		if(wait_time<=0&&!line.isempty()){		//上一位顾客操作完成，轮到下一位顾客（第一次自然不用的等待，即初始值0立即入队） 
			line.dequeue(temp);				//顾客出队 
			wait_time=temp.ptime();			//将processtime赋值给wait_time 
			line_wait+=cycle-temp.when();		//当前时间减去他到来的时间，即此位客户等待所花的时间 
			served++;			//服务人又增加了一个 
		}		
		else if(wait_time>0){					//此时上一位顾客还没结束，继续等待
				wait_time--;
			}
		sum_line+=line.queuecout();			//每一个cycle下队列占用量 
	}
	//reporting results
	if(customers>0){
		cout<<"customers accepted: "<<customers<<endl;
		cout<<"  customers served: "<<served<<endl;
		cout<<"			turnaways: "<<turnaways<<endl;
		cout<<" average queue size:";
		cout<<(double)sum_line/cyclelimit<<endl;				//一整轮仿真模拟下，单位分钟队列资源的使用情况 
		cout<<" average wait time: "
			<<(double)line_wait/served<<" minutes"<<endl;			//受服务顾客的平均等待时间 
	} 
	else
		cout<<"no customers!"<<endl;
	cout<<"Done!"<<endl;
	
	return 0;
}

bool newcustomer(double x){				//模拟平均每x分钟来一位顾客（一定随机性） 
	return (rand()*x/RAND_MAX<1);			//RAND_MAX作为宏，表示随机数的最大值 
}
