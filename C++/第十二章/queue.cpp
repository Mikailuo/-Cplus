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
	
	if(front==NULL) 		//队空时先行创建队首元素 
		front=add;
	else					//否则链接在rear之后 
		rear->next=add;
	rear=add; 			//然后将rear更新为add 
	return true;
}

bool queue::dequeue(elem &data){
	if(isempty()) return false;
	node *temp=front;
	front=front->next;
	delete temp;
	items--;
//	cout<<"deq--items: "<<items<<endl;
	if(items==0)		//此时队空了，重置front和rear为NULL 
		rear=NULL;
	return true;
}

queue::~queue(){		//防止出现程序最后队列不空，则new的结点必须要释放，故显式定义析构函数 
	node *temp;
	while(front!=NULL){
		temp=front;
		front=front->next; 
		delete temp;
	}
} 



