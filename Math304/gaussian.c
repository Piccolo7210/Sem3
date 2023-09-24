#include<stdio.h>
#include<math.h>
#define n 3
#define eps 1e-5
void determinant(double arr[][n+1]);
void inverse(double inv[][n*2]);
int main(){
	double arr[n][n+1],fact,temp;
	int i,j,k,m,z;
	freopen("gausinput.txt","r",stdin);
	for(i=0;i<n;i++){
		for(j=0;j<n+1;j++)scanf("%lf",&arr[i][j]);	
	}
	double inv[n][2*n];
	for(i=0;i<n;i++){
		for(j=0;j<n*2;j++){
			inv[i][j]=0;
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			inv[i][j]=arr[i][j];
		}
		for(;j<n*2;j++){
			if(j==n+i){
				inv[i][j]=1;
			}
		}
	}
	printf("Inverse initial:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n*2;j++){
		printf("%.3lf\t",inv[i][j]);	
	}
		printf("\n");	
	}
	printf("Matrix:\n");
for(i=0;i<n;i++){
		for(j=0;j<n;j++){
		printf("%.3lf\t",arr[i][j]);	
	}
		printf("\n");	
	}
printf("\n\nResult1:\n\n");
	
	for(i=0;i<n-1;i++){
		if(fabs(arr[i][i])<eps){
		for(m=i+1;m<n;m++){
			if(fabs(arr[m][i])>eps){
				for(z=i;z<n+1;z++){
					temp=arr[i][z];
					arr[i][z]=arr[m][z];
					arr[m][z]=temp;			
				}	
			break;
			}	
		}
		
	}
		for(j=i+1;j<n;j++){
			fact=arr[j][i]/arr[i][i];
			for(k=i;k<n+1;k++){
				arr[j][k]=arr[j][k]-fact*arr[i][k];		
			}	
		}	
	}
	for(i=0;i<n;i++){
		for(j=0;j<n+1;j++){
		printf("%.3lf\t",arr[i][j]);	
	}
		printf("\n");	
	}
	//determinant(arr);
	for(i=n-1;i>0;i--){
		if(fabs(arr[i][i])<eps){
			for(m=i-1;m>=0;m--){
				if(fabs(arr[m][i]>eps)){
					for(z=n;z>=i;z--){
					temp=arr[i][z];
					arr[i][z]=arr[m][z];
					arr[m][z]=temp;	
					}
					break;		
				}						
			}
		}	
			
	
	for(j=i-1;j>=0;j--){
			fact=arr[j][i]/arr[i][i];
			for(k=n;k>=0;k--){
				arr[j][k]=arr[j][k]-fact*arr[i][k];		
			}	
		}	
	}
	printf("Result2:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n+1;j++){
		printf("%.3lf\t",arr[i][j]);	
	}
		printf("\n");	
	}
	printf("Solution:\n");
	for(i=0;i<n;i++){
		printf("%.3lf ",arr[i][n]/arr[i][i]);
	}
	printf("\n");
	inverse(inv);
	
}
void determinant(double arr[][n+1]){
	double det=1;
	for(int i=0;i<n;i++){
		det*=arr[i][i];
	}
	printf("Determinant is = %.3lf\n",det);
}
void inverse(double inv[][n*2]){
			int i,j,m,k,z;
			double temp,fact;
		for(i=0;i<n-1;i++){
		if(fabs(inv[i][i])<eps){
		for(m=i+1;m<n;m++){
			if(fabs(inv[m][i])>eps){
				for(z=i;z<n*2;z++){
					temp=inv[i][z];
					inv[i][z]=inv[m][z];
					inv[m][z]=temp;			
				}	
			break;
			}	
		}
		
	}
		for(j=i+1;j<n;j++){
			fact=inv[j][i]/inv[i][i];
			for(k=i;k<n*2;k++){
				inv[j][k]=inv[j][k]-fact*inv[i][k];		
			}	
		}	
	}
	// printf("Inverse1:\n");
	// for(i=0;i<n;i++){
	// 	for(j=0;j<n*2;j++){
	// 	printf("%.3lf\t",inv[i][j]);	
	// }
	// 	printf("\n");	
	// }
		for(i=n-1;i>0;i--){
		if(fabs(inv[i][i])<eps){
			for(m=i-1;m>=0;m--){
				if(fabs(inv[m][i]>eps)){
					for(z=n*2-1;z>=i;z--){
					temp=inv[i][z];
					inv[i][z]=inv[m][z];
					inv[m][z]=temp;	
					}
					break;		
				}						
			}
		}	
			
	
	for(j=i-1;j>=0;j--){
			fact=inv[j][i]/inv[i][i];
			for(k=n*2-1;k>=0;k--){
				inv[j][k]=inv[j][k]-fact*inv[i][k];		
			}	
		}	
	}
	for(i=0;i<n;i++){
		for(j=n;j<n*2;j++){
			inv[i][j]=inv[i][j]/inv[i][i];
		}
	}
	printf("Inverse Result:\n");
	for(i=0;i<n;i++){
		for(j=n;j<n*2;j++){
		printf("%.3lf\t",inv[i][j]);	
	}
		printf("\n");	
	}

}