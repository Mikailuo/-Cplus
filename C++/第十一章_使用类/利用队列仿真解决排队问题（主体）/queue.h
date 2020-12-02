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
	enum{SIZE=10};				//ö���еı���������Ϊ������ 
	private:
		//Ƕ�׽ṹ�� ,���е�Ϊ��ʽ 
		struct node{
			elem data;
			struct node *next;	
		};
		//˽�����Ա
		node *front;		//����ָ�� 
		node *rear;			//��βָ�� 
		int items;				//����Ԫ�ظ��� 
		const int qsize;			//���е�������� 
		
		//α˽�з�������Ҫ���ڽ����δ��������������Ŀǰ����ʹ�õ�������� �� �ڱ�֤
		//�������ǰ���±��������Ĺ�������Ү���� 
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

