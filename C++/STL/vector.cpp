//����container��ѧ����׼�� ,temp/max*100;
#include<iostream>
#include<vector>
using namespace std;
int main(void){
	vector<double> a;				//����һ��vector���� 
	double max,temp;
	int i;
	cin>>max;
	a.push_back(max);				//vector��push���� 
	for(i=1;true;i++){
		cout<<"Enter thr origin score"<<i+1<<":";
		cin>>temp;
		if(temp==-1) break;
		a.push_back(temp);
		if(temp>max) max=temp; 
	}
	max/=100;
	cout<<"output:"<<endl;
	for(i=0;i<a.size();i++){
		a[i]/=max;
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}


