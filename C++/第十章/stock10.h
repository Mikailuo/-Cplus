#ifndef STOCK10_H_
#define STOCK10_H_
#include <string>

class stock{
	private:
		std::string company;
		long shares;
		double share_val;
		double total_val;
		void set_tot(){ total_val=shares*share_val;	}
		
	public:
//		stock();
		stock(const std::string &co,long n,double pr);
		~stock();
		void buy(long num,double price);
		void sell(long num,double price);
		void update(double price);
		void show();
		const stock & topval(const stock &s)const;
};

#endif
