#include<iostream>
#include"sort.h"
using namespace std;
int main(void) {
	sqlist array;
	sqlist factor;
	int judge=5;
	do{
		cout<<"the origin array is :";
		show(array);
		cout<<endl;
		cout<<"plz,input a number to sure the mod(1,2,3,4,)"<<endl;
		cout<<"number : ";
		cin>>judge;

		if(judge==1){
			selectsort(array);
		}
		else if(judge==2){
			bubblesort(array);
		}
		else if(judge==3){
			insertsort(array);
		}
		else if(judge==4){
			fastsort(array,0,array.length-1);
		}
		if(judge==0)break;
		cout<<"\nafter sorting,now she is:";
		show(array);
		cout<<endl;
		array=factor;
	}while(judge!=0);
	return 0;
}
