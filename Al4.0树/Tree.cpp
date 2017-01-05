/*
 * Tree.cpp
 *
 *  Created on: 2016年11月23日
 *      Author: xjwhhh
 */

#include<iostream>;
#include<string>
#include <sstream>
using namespace std;

int *findroot(string &s,int n);
void precheck(string &a,int n);
void inordercheck(string &a,int n);
void postcheck(string &a,int n);
int findmid(string &s);
bool judge(string &s);
int mpow(int num);

string prestr;
string inorderstr;
string poststr;
int main(){
	string s;
	//除了初始值其他的全部都是空格
    cin>>s;
    precheck(s,s.length());
    prestr=prestr.substr(0,prestr.size()-1);
    inordercheck(s,s.length());
    inorderstr=inorderstr.substr(0,inorderstr.size()-1);
    postcheck(s,s.length());
    poststr=poststr.substr(0,poststr.size()-1);
    cout<<"前序表达式为"<<prestr<<endl;
    cout<<"中序表达式为"<<inorderstr<<endl;
    cout<<"后序表达式为"<<poststr<<endl;

}
void precheck(string &a,int n){
	if(a==""){
	}
	else{
	string leftson;
	string leftt;
	string temp;
	string rightson;
    int *root = findroot(a,n);
    //root表示的分别是root的值和值所占的位数
    string s=a;
    leftt=s.substr(root[1]+1,n-root[1]-1);
    temp = leftt.substr(0,leftt.length()-1);
    //现在的temp表示的是一个去掉root和括号的左子树和右子树的字符串
    stringstream ss;
    ss<<root[0];
    string str1;
    ss>>str1;
    prestr=prestr+str1+" ";
    int mid = findmid(temp);
   	leftson = temp.substr(0,mid);
  	rightson = temp.substr(mid+1,temp.length()-mid-1);
   	precheck(leftson,leftson.length());
   	delete[] root;
   	precheck(rightson,rightson.length());
	}
}

void inordercheck(string &a,int n){
	if(a==""){
	}
	else{
	string leftson;
	string leftt;
	string temp;
	string rightson;
    int *root = findroot(a,n);
    //root表示的分别是root的值和值所占的位数
    string s=a;
    leftt=s.substr(root[1]+1,n-root[1]-1);
    temp = leftt.substr(0,leftt.length()-1);
    //现在的temp表示的是一个去掉root和括号的左子树和右子树的字符串
    int mid = findmid(temp);
   	leftson = temp.substr(0,mid);
  	rightson = temp.substr(mid+1,temp.length()-mid-1);
   	inordercheck(leftson,leftson.length());
   	stringstream ss;
   	ss<<root[0];
   	string str1;
   	ss>>str1;
   	inorderstr=inorderstr+str1+" ";
   	delete[] root;
   	inordercheck(rightson,rightson.length());
	}
}

void postcheck(string &a,int n){
	if(a==""){
	}
	else{
	string leftson;
	string leftt;
	string temp;
	string rightson;
    int *root = findroot(a,n);
    //root表示的分别是root的值和值所占的位数
    string s=a;
    leftt=s.substr(root[1]+1,n-root[1]-1);
    temp = leftt.substr(0,leftt.length()-1);
    //现在的temp表示的是一个去掉root和括号的左子树和右子树的字符串
    int mid = findmid(temp);
   	leftson = temp.substr(0,mid);
  	rightson = temp.substr(mid+1,temp.length()-mid-1);
   	postcheck(leftson,leftson.length());
   	postcheck(rightson,rightson.length());
   	stringstream ss;
   	ss<<root[0];
   	string str1;
   	ss>>str1;
   	poststr=poststr+str1+" ";
   	delete[] root;
	}
}
int *findroot(string &s,int n){
	int *root=new int[2];
	int num=0;
	int shu[100];
	root[0]=0;
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			shu[num]=s[i]-'0';
			num++;
		}else{
			break;
		}
	}
	root[1]=num;
	int edf=num;
	for(int i=0;i<num;i++){
		root[0]=root[0]+shu[i]*mpow(edf);
		edf--;
	}
	return root;
}
int findmid(string &s){
	int where=0;
	string left;
	string right;
    for(unsigned int i=0;i<s.length();i++){
    	if(s[i]==','){
    		left=s.substr(0,i);
    		right=s.substr(i,s.length()-i);
    		if(judge(left)&&judge(right)){
    			where = i;
    			break;
    		}
    	}
    }
    return where;
}
bool judge(string &s){
	int leftk=0;
	int rightk=0;
	bool b = true;
	for(unsigned int i=0;i<s.length();i++){
		if(s[i]=='('){
			leftk++;
		}else if(s[i]==')'){
			rightk++;
		}
	}
	if(leftk!=rightk){
		b=false;
	}
	return b;
}

int mpow(int num){
	int a=1;
	num--;
	while(num!=0){
      a=a*10;
      num--;
	}
	return a;
}






