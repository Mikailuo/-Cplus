#include<cstdlib>
#include<iostream>
using namespace std;

class customer{
	private:
		long arrive;			//customer arrive time
		int processtime;		//random waste time
	
	public:
		customer(){
			arrive=processtime=0;
		}
		
		void set(long when){
			processtime=rand()%3+1;
			arrive=when;
		}
		
		long when()const{
			return arrive;
		}
		
		int ptime()const{
			return processtime;
		}
}; 

typedef customer elem;


class queue{
	enum{SIZE=10};				//枚举中的变量作用域为整个类 
	private:
		//嵌套结构体 ,队列的为链式 
		struct node{
			elem data;
			struct node *next;	
		};
		//私有类成员
		node *front;		//队首指针 
		node *rear;			//队尾指针 
		int items;				//队列元素个数 
		const int qsize;			//队列的最大容量 
		
		//伪私有方法，主要用于解决“未来”可能遇到但目前不会使用的深拷贝问题 ， 在保证
		//不报错的前提下避免这额外的工作（好耶！） 
		queue(const queue &q):qsize(0){	}
		queue & operator=(const queue &q){
			return *this;
		}
	public:
		queue(int qs=SIZE);
		~queue();
		bool isempty()const;
		bool isfull()const;
		int queuecout()const;
		bool enqueue(const elem &data);
		bool dequeue(elem &data);

};

