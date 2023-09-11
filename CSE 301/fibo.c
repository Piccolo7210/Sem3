#include<stdio.h>

long int fibo(int *arr,int n);
int main(){
	int n;
	scanf("%d",&n);
	long int arr[200];
	for(int i=0;i<200;i++)arr[i]=-1;
	fibo(arr,50);
	printf("Fibonacci = %ld\n",arr[n]);
}
long int fibo(int *arr,int n){
	long int result;
	if(n<=1){
	arr[n]=n;
	return n;	
	}
	if(arr[n]==-1){
		result=fibo(n-1)+fibo(n-2);
		arr[n]=result;	
	}
	return arr[n];
}
