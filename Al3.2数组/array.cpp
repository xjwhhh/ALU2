/*
 * array.cpp
 *
 *  Created on: 2016年10月23日
 *      Author: xjwhhh
 */
#include <iostream>
using namespace std;

int figure(int n,int m){
 int a[n];
 for(int j=0;j<n;j++){
 a[j]=j+1;
 }//数组初始化
 int k=1;
 int i=-1;
 while(1) {
  for(int j=0;j<m;){
   i=(i+1)%n;
      if(a[i]!=0){
    j++;
      }//说明这个人没有被淘汰,报数加1
  }
  if(k==n) { //判断一下已经淘汰的人数
   break;
  }
  //cout<<a[i]<<",";  //输出淘汰的人
  a[i]=0;
  k++;//这个人被淘汰
 }

 return a[i];
}

int main(){
	int x=figure(8,3);
	cout<<x;
}

