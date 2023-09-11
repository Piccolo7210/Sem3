#include<stdio.h>
#include<stdlib.h>
int stringchecker(char *arr){
	int i,n,flag=0;
	for(i=0;arr[i];i++){
		if(arr[i]!='1' && arr[i]!='0'){
		  printf("String is not from the alphabet!");
		  exit(1);
		  }
	}
	n=i;
	printf("q0|");
	for(i=0;i<n;i++){
	   if(flag==0){ 	
	     if(arr[i]=='0'){
	   	flag=1;
	   	i++;
	     }
	     else
	      printf("q0|");
	
	   }
	   if(flag==1){
	   	printf("q1|");
	   	if(arr[i]=='0'){	   	      
	   		flag=2;	
	   		i++;
	   	}	
	   	else
	   	  flag=0;
	   }
	   if(flag==2){
	   	printf("q2|");
	   	if(i<n && arr[i]!='0')
	   		flag=0;
	   	  	   	
	   }
	}
	return flag;
}
int main(){
    char str[100];
    scanf("%s",str);
    stringchecker(str);
}
