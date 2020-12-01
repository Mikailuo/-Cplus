#include<iostream>
#define NUM 6
#define Maxsize 10
using namespace std;

//define a sqlist(顺序表);
typedef struct{
	int* elem;				//顺序表主要内容 
	int length;				
	int incrementsize;		//顺序表特征 
}sqlist; 

void creat(sqlist &L,int* a,int num);
void show(sqlist &L);
void insert(sqlist &L,int location,int e);
void free(sqlist &L);
//校验主函数; 
int main(void){
	int origin[NUM]={2,5,3,6,1,4};
	sqlist goal;
	int element=0;
	int location=3;
	creat(goal,origin,NUM);
	show(goal);
	insert(goal,location,element);
	show(goal);
	free(goal);
	return 0;
}

void creat(sqlist &L,int* a,int num){
	int i;
	L.elem=new int[Maxsize];
	L.length=0;
	L.incrementsize=Maxsize;
	for(i=0;i<num;i++){
		L.elem[i]=*(a+i);
		L.length++;
	}
}
void show(const sqlist &L){
	cout<<L.elem<<endl;
	cout<<"this sqlist's length is "<<L.length<<" ;"<<endl;
}
void insert(sqlist &L,int location,int e){
	int i;
	if(location<1&&location>L.length+1){
		cout<<"Error!"<<endl;
	}
	else if(location=L.length+1){
		L.elem[location]=e;
		L.length++;
	}
	else{
		for(i=L.length-1;i>=location-1;i--){
			L.elem[i+1]=L.elem[i];
		}
		L.elem[location-1]=e;
		L.length++;
	}	
}
