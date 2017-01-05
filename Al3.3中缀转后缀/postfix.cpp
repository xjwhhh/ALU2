/*
 * postfix.cpp
 *
 *  Created on: 2016��11��23��
 *      Author: xjwhhh
 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int compare(char y,char ch){
	if(y=='('){
//		cout<<"r";
		return 0;
	}
	else if(y=='+'||y=='-'){
		if(ch=='*'||ch=='/'){
			cout<<"7";
			return 0;
		}
		else{
			cout<<"error";
			return 0;
		}
	}
	else {
		return 1;
	}



}

int isoperator(char x){
	char ops[] = "+-*/";
	for (int i = 0; i < sizeof(ops) / sizeof(char); i++){
	     if (x == ops[i])
	         return 1;
	    }
	    return 0;

}


void calculate(stack <char> post){
	//ȡ����������ȡ��������������������Ӧ�����������ջ
	char op=post.top();
	post.pop();
	if(op!='#'){
	int left,right;
	if(!post.empty()){
		right=post.top();
		post.pop();
	}
	if(!post.empty()){
		left=post.top();
		post.pop();
	}
	int t=0;

	switch(op){
	case('+'):t=left+right;break;
	case('-'):t=left-right;break;
	case('*'):t=left*right;break;
	case('/'):
			if(right!=0){
				t=left/right;
			}
			else{
				cout<<"wrong number";
			}
			break;
	}
	post.push(t);
	}

}


int main(){
	stack <char> s;
	char ch,y;
	stack <char> post;
	s.push('#');
	while(cin.get(ch)&&(ch!='#')){
		//��������ֱ�����
		if(isdigit(ch)){
			post.push(ch);
		}
		//��������ѹջ
		else if(ch=='('){
			s.push(ch);
		}
		//�������Ų�����ջ�����ֱ������������
		else if(ch==')'){
			while(s.top()!='('){
				post.push(s.top());
				s.pop();
			}
			s.pop();
		}
		//���������Ƚϣ����ջ�������ȼ��ߣ������ջ��
		else{
			while(isoperator(s.top())&&isoperator(ch)&&compare(s.top(),ch)){
				post.push(s.top());
				s.pop();
				calculate(post);
			}
			s.push(ch);
		}

	}
	while(!s.empty()){
				post.push(s.top());
				s.pop();
				calculate(post);
			}
	cout<<post.top();
}

