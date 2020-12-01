#include<iostream>
using namespace std;

typedef struct{
	int* collum;
	int top;
	int length;
}stock;

void init(stock &L,int num);
void push(stock &L,int locat);
void pop(stock &L,int &locat);
int full(stock &L);
int empty(stock &L);
void destroy(stock &L);
bool traverse(stock &L,int e);
void output(stock &L);

void resolution(stock &L);
int play(stock &L,int row,int start);
int judge(stock &L,int locat,int row);
