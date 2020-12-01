#include<iostream>
#define SIZE 20
typedef struct{
	int number[SIZE]={3,6,2,3,7,1,9,8,5,6,4,7,};
	int length=12;
	int maxsize=SIZE;
}sqlist;

void show(const sqlist &L);
void selectsort(sqlist &L);
void bubblesort(sqlist &L);
void insertsort(sqlist &L);
int location(sqlist &L,int head1,int tail1);
void fastsort(sqlist &L,int head,int tail);
