/*
 * array.cpp
 *
 *  Created on: 2016��10��23��
 *      Author: xjwhhh
 */
#include <iostream>
using namespace std;

int figure(int n,int m){
 int a[n];
 for(int j=0;j<n;j++){
 a[j]=j+1;
 }//�����ʼ��
 int k=1;
 int i=-1;
 while(1) {
  for(int j=0;j<m;){
   i=(i+1)%n;
      if(a[i]!=0){
    j++;
      }//˵�������û�б���̭,������1
  }
  if(k==n) { //�ж�һ���Ѿ���̭������
   break;
  }
  //cout<<a[i]<<",";  //�����̭����
  a[i]=0;
  k++;//����˱���̭
 }

 return a[i];
}

int main(){
	int x=figure(8,3);
	cout<<x;
}

