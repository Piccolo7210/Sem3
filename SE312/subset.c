#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void set(int k){
	int i,j,n;
	n=pow(2,k);
	char arr[n][k+1];
	for(i=0;i<n;i++){
		int a=i;
		for(j=0;j<k;j++){
			arr[i][j]=a%2+'0';
			a=a/2;	
		}
		arr[i][j]='\0';	
	}
	printf("Elements: ");
	printf("{ ");
	for(i=0;i<n;i++){		
		for(j=k-1;j>=0;j--){
			printf("%c",arr[i][j]);		
		}
		if(i!=n-1)printf(",");	
	}
	printf(" }");
}
