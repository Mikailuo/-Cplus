#include<iostream>
#include"queue.h"
using namespace std;

queue::queue(int qs):qsize(qs){
	front=rear=NULL;
	items=0;
}

bool queue::isempty()const{
	if(items==0) return true;
	else return false;
} 

bool queue::isfull()const{
	if(items==qsize) return true;
	else return false;
}

int queue::queuecout()const{
	return items;
}

bool queue::enqueue(const elem &data){
	if(isfull()) return false;
	node *add=new node;
	add->data=data;
	add->next=NULL;
	items++;
//	cout<<"enq--items: "<<items<<endl;
	
	if(front==NULL) 		//�ӿ�ʱ���д�������Ԫ�� 
		front=add;
	else					//����������rear֮�� 
		rear->next=add;
	rear=add; 			//Ȼ��rear����Ϊadd 
	return true;
}

bool queue::dequeue(elem &data){
	if(isempty()) return false;
	node *temp=front;
	front=front->next;
	delete temp;
	items--;
//	cout<<"deq--items: "<<items<<endl;
	if(items==0)		//��ʱ�ӿ��ˣ�����front��rearΪNULL 
		rear=NULL;
	return true;
}

queue::~queue(){		//��ֹ���ֳ��������в��գ���new�Ľ�����Ҫ�ͷţ�����ʽ������������ 
	node *temp;
	while(front!=NULL){
		temp=front;
		front=front->next; 
		delete temp;
	}
} 



