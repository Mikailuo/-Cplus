#include <iostream>
#include"eight_queens.h"
#define SIZE 8
using namespace std;

int main(void){
	int chess[8][8]={0};			//∆Â≈Ã 
	stock solve;
	
	init(solve,SIZE);
	resolution(solve);
	return 0;
}
