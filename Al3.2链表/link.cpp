/*
 * link.cpp
 *
 *  Created on: 2016年10月23日
 *      Author: xjwhhh
 */
#include <iostream>
#include <malloc.h>

using namespace std;

struct LNode{
	int num;
	struct LNode* next;
};


int Josephus(int n,int m){
	LNode *head;
	LNode *p;
	LNode *q;
	//head=(LNode*)malloc(sizeof(LNode));
	p=(LNode*)malloc(sizeof(LNode));
	//q=(LNode*)malloc(sizeof(LNode));

	//构造循环链表
	head=p;
	p->num=1;
	for(int i=2;i<=n;i++){
		q=(LNode*)malloc(sizeof(LNode));
		q->num=i;
		p->next=q;
		p=q;
	}
	p->next=head;

	LNode *temp;

	for(int j=0;j<m;j++){
			temp=p;
			p=p->next;

			}
//			cout<<p->num<<" ";
			temp->next=p->next;
			free(p);
			p=temp->next;
	for(int i=2;i<n;i++){
		for(int j=1;j<m;j++){
		temp=p;
		p=p->next;

		}
		//cout<<p->num<<" ";
		temp->next=p->next;
		free(p);
		p=temp->next;

//		if(i==1){
//			head=rear->next;
//			tail=head;
//		}
//		else{
//			tail->next=rear->next;
//			tail=rear->next;
//
//		}
//		rear->next=tail->next;
//
//	}
//	tail->next=rear;
//	rear->next=NULL;
//	int winner=rear->num;
//
//	head=tail=NULL;

//		free(rear);


}
	int winner=p->num;
		return winner;
}

int main(){
	int winner=Josephus(8,3);
	cout<<winner;
}
