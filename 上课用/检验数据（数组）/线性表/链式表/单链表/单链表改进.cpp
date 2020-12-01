#include<iostream>
#define CLO 6
using namespace std;

typedef struct Lnode{
	int number;
	struct Lnode* next;
}Lnode,*node;
void init(node &L);											//�������� 
void show(node &L);											//��ӡ���� 
void insert(node &L,int e,int location,char mode);			//������ 
int find(const node &L,int e);								//����e������λ�� 
void Delete(node &L,int location); 							//ɾ����� 

int main(void){
	int origin[CLO]={1,2,3,4,5,6};
	int i;
	int location;
	node list;
	init(list);
	for(i=0;i<CLO;i++){
		insert(list,origin[i],i+1,'A');
	}
	show(list);
	insert(list,10,3,'A');
	show(list);
	location=find(list,3);
	Delete(list,location);
	show(list);
	return 0;
}

void init(node &L){
	L=new Lnode;
	L->next=NULL;
} 

void show(node &L){
	node p=L->next;
	while(p){
		cout<<p->number<<" ";
		p=p->next;
	}
	cout<<endl;
}

void insert(node &L,int e,int location,char mode){			//���д�Ĺ������ӣ����Խ��кϲ����� 
	int i=0;
	node head=L;
	node p=new Lnode;
	if(mode=='A'){               //ģʽA��ǰ��ģʽ,iȡ����1���� 
		while(head){
			p->next=head->next;
			i++;
			if(i==location){
				p->number=e;
				head->next=p;
				break;
			}
			head=head->next;
		}
		if(!head) cout<<"fail to insert!"; 
	}
	else{                  //���ģʽ�������ַ��0��ʼ   
		while(head){
			p->next=head->next;
			if(i==location){
				p->number=e;
				head->next=p;
				break;
			}
			i++;
			head=head->next;
		}
		if(!head) cout<<"fail to insert!"<<endl; 	
	}

}

int find(const node &L,int e){
	int i=0;
	node head=L;
	while(head){
		if(head->number==e){
			return i;
		}
		i++;
		head=head->next;
	}
	if(!head){
		cout<<"fail to find!!!"<<endl;
		return -1;
	}
}

void Delete(node &L,int location){
	int i=1;
	node head=L; 
	node new_head=head->next;
//	if(location<0){
//		cout<<"Error!"<<endl;
//	}
	if(location==0){
		delete head;
	}
	else{
		while(new_head){
		if(i==location){
			head->next=new_head->next;
			delete new_head;
			break;
		}
		i++;
		head=head->next;
		new_head=head->next;
		}
	}
	if(!new_head){
		cout<<"fail to delete!maybe your location is wrong."<<endl;
	}
}
