#include<iostream>
#include<deque>
using namespace std;

template<class T>		//����ģ��ʵ�ֶ�̬ 
void print(T &deq,char *str){
//	deque<T>::iterator it;       ������ 
	typename T::iterator it;		//���������� 
	cout<<"the element of "<<str<<":";
	for(it=deq.begin();it!=deq.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
}

int main(void){
	deque<char> deq1;
	deq1.push_back('c');
	deq1.push_back('d');
	
	deq1.push_front('b');
	deq1.push_front('a');
	print(deq1,"deq1");
}
