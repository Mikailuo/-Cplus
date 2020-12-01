#include <iostream>
#include "stock10.h"
using namespace std;
int main(void){
	stock stock1("NAN",12,20);
	stock1.show();
	stock stock2=stock("tencent",2,2);
	stock2.show();
	stock2=stock1;
	stock1.show();
	stock2.show();
	return 0;
}
