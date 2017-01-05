package cn.edu.nju.software151250171.combine;


import java.util.Scanner;

public class Combination {
	public static void main(String[] args){
		int n;
		int r;
		System.out.println("Please input the number");
		Scanner sc=new Scanner(System.in);
		n=sc.nextInt();
		r=sc.nextInt();
		sc.close();
		
		for(int i=n;i>=r;i--){
			combin(i,r);
		}
	}

	static int[] a=new int[10000000];
	
	public static void combin(int n,int r){
		if(r==1){
			a[r-1]=n;
			int j=0;
			while(a[j]!=0){
				j++;
			}
			for(int i=j-1;i>=0;i--){
				System.out.print(a[i]+",");
			}
			System.out.println("");
			
		}
		else{
			a[r-1]=n;
			for(int j=n-1;j>=r-1;j--){
				combin(j,r-1);
			}
		}
		}
}
		
		
	    
	
		

