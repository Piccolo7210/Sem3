#include<stdio.h>
#include<stdlib.h>
#define n 3
void multi(int arr1[][n],int arr2[][n],int mat[][n]);
void print(int mat[][n]);
int main(){
	int arr1[n][n],mat[n][n];
	int arr2[n][n],i,j;
	freopen("matinput.txt","r",stdin);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)scanf("%d",&arr1[i][j]);	
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)scanf("%d",&arr2[i][j]);	
	}
	multi(arr1,arr2,mat);
	print(mat);
}
void multi(int arr1[][n],int arr2[][n],int mat[][n]){
	int i,j,k;	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			mat[i][j]=0;
			for(k=0;k<n;k++){
			mat[i][j]=mat[i][j]+arr1[i][k]*arr2[k][j];	
			}
		}
	}
}
void print(int mat[][n]){
		int i,j;	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)printf("%d ",mat[i][j]);
		printf("\n");	
	}
}
