#include<iostream>
#include<math.h>
#include"eight_queens.h"
#define SIZE 8;
using namespace std;

void init(stock &L,int num){
	L.collum=new int[num];
	L.top=-1;
	L.length=num;
}

void push(stock &L,int locat){
	L.top++;
	L.collum[L.top]=locat;
}

void pop(stock &L,int &locat){
	locat=L.collum[L.top];
	L.top--;
}

int full(stock &L){
	int judge=0;
	if(L.top==L.length)
	judge=1;
	
	return judge;
}

int empty(stock &L){
	int judge=0;
	if(L.top==-1)
	judge=1;
	
	return judge;
}

void destroy(stock &L){
	delete [] L.collum;
}

int judge(stock &L,int locat,int row){
	int judgement=0;
	int i;
	for(i=0;i<row;i++){
		if(locat==L.collum[i]||abs(locat-L.collum[i])==abs(row-i)){      //row�ǵ�ǰ�У�i��ĳһ������� 
			judgement=1;
			break;                                            //��ʱ�Ѿ����������� 
		}
		else{
			continue; 
		}
	}
	return judgement;
}

//bool traverse(stock &L,int e){				//����ջ�ռ� 
//	int piv;
//	int judge=0;
//	for(piv=0;piv<=L.top;piv++){
//		if(piv==e){
//			judge=1;
//			break;
//		}
//	}
//	if(judge==1) return true;    			//��ʱջ�д��ڸ�ֵ 
//	else return false;
//} 

void output(stock &L){
	int i;
	for(i=0;i<L.top;i++){
		cout<<L.collum[i]<<" "; 
	}
	cout<<endl;
}

int play(stock &L,int row,int start){                  //�������
	int i;
	int jud=0;
	for(i=start;i<8;i++){				 
		if(!judge(L,i,row)){					//������ڿ��ԸĽ�����i��Ϊa��i��;
			push(L,i);
			jud=1;
			break;
		}
	}
	return jud;
}

void resolution(stock &L){
	int row=0;
	int times=0;
	int locat=0;
	push(L,locat);
	row++;
	do{
		if(play(L,row,locat)){   					//	row�У�start֮������ɹ�; 
			cout<<"��ʱ���У�"<<row<<" �У�"<<locat<<" ջ��ֵ��"<<L.collum[L.top]<<endl;
			locat=0;  			 //����Ϊ�� 
			row++;     			//������һ��play 
		}
		else{
			row--;    	 		//��ʱplay����ʧ�ܣ����ݵ�row-1�� 
			pop(L,locat);		//row-1�г�ջ,����row-1��ԭ������������ 
			locat++;   			//������һ 
			cout<<"vv	"<<"��ʱ���У�"<<row<<" �У�"<<locat<<" ջ��ֵ��"<<L.collum[L.top]<<endl;
		}
		if(full(L)){
			cout<<"��"<<times+1<<"���⣺"; 
			output(L);
			times++;
			row--;
			pop(L,locat);
			locat++;
		}
	}while(L.collum[0]<8);
}
