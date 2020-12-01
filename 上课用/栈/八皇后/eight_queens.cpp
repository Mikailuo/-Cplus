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
		if(locat==L.collum[i]||abs(locat-L.collum[i])==abs(row-i)){      //row是当前行，i是某一点的行数 
			judgement=1;
			break;                                            //此时已经不符合条件 
		}
		else{
			continue; 
		}
	}
	return judgement;
}

//bool traverse(stock &L,int e){				//遍历栈空间 
//	int piv;
//	int judge=0;
//	for(piv=0;piv<=L.top;piv++){
//		if(piv==e){
//			judge=1;
//			break;
//		}
//	}
//	if(judge==1) return true;    			//此时栈中存在该值 
//	else return false;
//} 

void output(stock &L){
	int i;
	for(i=0;i<L.top;i++){
		cout<<L.collum[i]<<" "; 
	}
	cout<<endl;
}

int play(stock &L,int row,int start){                  //下棋决策
	int i;
	int jud=0;
	for(i=start;i<8;i++){				 
		if(!judge(L,i,row)){					//这里后期可以改进：将i改为a【i】;
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
		if(play(L,row,locat)){   					//	row行，start之后下棋成功; 
			cout<<"此时，行："<<row<<" 列："<<locat<<" 栈顶值："<<L.collum[L.top]<<endl;
			locat=0;  			 //重置为零 
			row++;     			//进行下一行play 
		}
		else{
			row--;    	 		//此时play该行失败，回溯到row-1行 
			pop(L,locat);		//row-1行出栈,保存row-1行原旗子所在列数 
			locat++;   			//列数加一 
			cout<<"vv	"<<"此时，行："<<row<<" 列："<<locat<<" 栈顶值："<<L.collum[L.top]<<endl;
		}
		if(full(L)){
			cout<<"第"<<times+1<<"个解："; 
			output(L);
			times++;
			row--;
			pop(L,locat);
			locat++;
		}
	}while(L.collum[0]<8);
}
