package cn.edu.nju.software151250171.Hanoi;

import java.util.Scanner;

public class Hanoi {
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		sc.close();
		hanoi(n,"A","B","C");
	}
	public static void hanoi(int n,String a,String b,String c){
		if(n==1){
			move(n,a,c);
		}
		else{
			hanoi(n-1,a,c,b);//n-1个盘子从a到b
			move(n,a,c);//第n个盘子从a到c
			hanoi(n-1,b,a,c);//n-1个盘子从b到c
			
		}
	}
	public static void move(int n,String a,String b){
		System.out.println(n+" move from "+a+" to "+b);
	}
}
