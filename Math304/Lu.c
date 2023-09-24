#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define n 3
#define eps 1e-5
void multi(double arr1[][n],double arr2[][n],double mat[][n]);
void print(double mat[][n]);
void Lu(double L[][n],double U[][n],double arr[][n]);
int main(){
	double arr[n][n],L[n][n],U[n][n];
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			if(i==j)L[i][j]=1;
			else{
				L[i][j]=0;		
			}	
	}
	freopen("Lu.txt","r",stdin);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			scanf("%lf",&arr[i][j]);
			U[i][j]=arr[i][j];		
		}
	Lu(L,U,arr);
}
void multi(double arr1[][n],double arr2[][n],double mat[][n]){
	int i,j,k;	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
			mat[i][j]=mat[i][j]+arr1[i][k]*arr2[k][j];	
			}
		}
	}
}
void print(double mat[][n]){
		int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)printf("%.3lf ",mat[i][j]);
		printf("\n");	
	}
}
void Lu(double L[][n],double U[][n],double arr[][n]){
	int i,j,k,m,z;
	double Lu[n][n],Li[n][n],temp,fact;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)Lu[i][j]=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			if(i==j)Li[i][j]=1;
			else{
				Li[i][j]=0;		
			}	
	}
	for(i=0;i<n-1;i++){
		if(fabs(U[i][i])<eps){
		for(m=i+1;m<n;m++){
			if(fabs(U[m][i])>eps){
				for(z=i;z<n+1;z++){
					temp=U[i][z];
					U[i][z]=U[m][z];
					U[m][z]=temp;			
				}	
			break;
			}	
		}
		
	}
		for(j=i+1;j<n;j++){
			fact=U[j][i]/U[i][i];
			L[j][i]=fact;
			Li[j][i]=(-1)*fact;
			for(k=i;k<n+1;k++){
				U[j][k]=U[j][k]-fact*U[i][k];		
			}	
		}	
	}
	multi(L,U,Lu);
	printf("L matrix:\n");
	print(L);
	printf("\nL inverse :\n");
	print(Li);
	printf("\nU matrix:\n");
	print(U);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)U[i][j]=0;
	printf("\nL^-1 * A = U : \n");
	//multi(arr,Li,U);
	multi(Li,arr,U);
	print(U);
	printf("\nA Matrix :\n");
	print(arr);
	printf("\nLU matrix:\n");
	print(Lu);

}
