#include<iostream>
#include"sort.h"
using namespace std;
void show(const sqlist &L){
	int i;
	for(i=0;i<L.length;i++){
		cout<<L.number[i]<<" ";
	}
}

void selectsort(sqlist &L){				//ѡ������ 
	int i,j,k;
	int factor;							//������ 
	for(i=0;i<L.length;i++){
		k=i;
		for(j=i+1;j<L.length;j++){
			if(L.number[j]<L.number[k]) k=j;
		}
		if(k!=i)
		factor=L.number[i];
		L.number[i]=L.number[k];
		L.number[k]=factor;
	}
}

void bubblesort(sqlist &L){				//ð������ 
	int i,j;
	int factor;
	for(i=L.length-1;i>=0;i--){
		for(j=0;j<i;j++){
			if(L.number[j]>L.number[j+1]){
				factor=L.number[j];
				L.number[j]=L.number[j+1];
				L.number[j+1]=factor;
			}
		}
	}
}

void insertsort(sqlist &L){					//�������� 
	int i,j;
	int factor;
	for(i=1;i<L.length;i++){
		if(L.number[i]<L.number[i-1]){
			factor=L.number[i];
			L.number[i]=L.number[i-1];
			for(j=i-1;j>=0;j--){
				if(factor<L.number[j-1]&&j!=0){
					L.number[j]=L.number[j-1];
				}
				else{
					L.number[j]=factor;
					break;
				}				
			}
		}
	}
}

//int* location(sqlist &L,int head,int tail){
//	int i;
//	int factor;														//����Ա 
//	int pivotkey;     												//��ŦԪ 
//	int lstep=0,rstep=0;
//	int information[3];             							    	//��ͬ�ؼ��ֵĸ��� ,tonaji
//	pivotkey=L.number[head];
//	while(head<tail){
//		while(head<tail&&pivotkey<L.number[tail]){
////			if(pivotkey==L.number[tail]){							//�ж���ͬʱ�Թ��ĸ��� 
////				rstep++;
////				factor=L.number[head-1];
////				L.number[head-1]=L.number[tail];
////				L.number[tail]=factor;
////			}
//			tail--;
//		}
//		if(head<tail)
//			L.number[head++]=L.number[tail];
//		while(head<tail&&pivotkey>=L.number[head]){
////			if(pivotkey==L.number[head]){							//�ж���ͬʱ�Թ��ĸ��� 
////				lstep++;
////			}
//			head++; 
//		}
//		if(head<tail)
//			L.number[tail--]=L.number[head];
//	}
//	L.number[head]=pivotkey;
////	information[0]=pivotkey;
////	information[1]=tonaji;
//	return information; 
//}
//
//void fastsort(sqlist &L,int head,int tail){
//	int information;
//	int locat;
//	int step;
//	if(head<tail){
//		information=location(L,head,tail);                                 //��ŦԪ�����ᣩ����һ�� 
//		locat=information[0];
//		lstep=information[1];
//		rstep=information[2];
//		fastsort(L,head,locat-lstep);
//		fastsort(L,locat+rstep,tail);
//	}
//} 

void fastsort2(sqlist &L,int head,int tail){
	int left,right,mid;
	int piv,temp;
	left=head-1;
	right=tail+1;
	mid=head;
	piv=L.number[head];
	
	if(head>=tail) return ;
	while(mid<right){
		if(L.number[mid]<piv){
			left++;
			temp=L.number[mid];								//mid��left���� 
			L.number[mid]=L.number[left];
			L.number[left]=temp;
			mid++;
		}
		else if(L.number[mid]>piv){
			right--;
			temp=L.number[mid];								//mid��right���� 
			L.number[mid]=L.number[right];
			L.number[right]=temp;
			mid++;
		}
		else
			mid++;
	}
	fastsort2(L,head,left);
	fastsort2(L,right,tail);
}

int location(sqlist &L,int head1,int tail1){
	int location=-1;
	int pivotkey;
	pivotkey=L.number[head1];
	while(head1!=tail1){
		while(head1<tail1&&pivotkey<=L.number[tail1]){
			tail1--;		
		}
		if(head1<tail1)
		L.number[head1++]=L.number[tail1];	
		while(head1<tail1&&pivotkey>=L.number[head1])
		head1++;
		if(head1<tail1)
		L.number[tail1--]=L.number[head1];               //�߼����� 
	}
	L.number[head1]=pivotkey;
	location=head1;
	return location;
}

void fastsort(sqlist &L,int head,int tail){
	int locat=-1;
	if(head<tail){
		locat=location(L,head,tail);
		fastsort(L,head,locat-1);
		fastsort(L,locat+1,tail);
	}
}
