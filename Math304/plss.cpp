#include<bits/stdc++.h>
using namespace std;
#define siz 100
int ROW,COLUMN,N;
double mat_A[siz][siz],mat_U[siz][siz];
double X[siz],Fx[siz];
double C[siz];
double arr[siz][siz];
double Tarr[siz][siz];
void multi1(double mat1[][siz], double mat2[][siz],int R1,int C1,int R2,int C2);
void multi2(double mat1[][siz], double mat2[],int R1,int C1,int R2,int C2) ;
void transpose();
void read();
void plss();
void show();
int main(){
read();
plss();

}
void read(){
    int i,j;
    freopen("plss.txt","r",stdin);
    cin>>N;
    ROW=N;
    COLUMN=N;
    for(i=0;i<N;i++)cin>>X[i];
    for(i=0;i<N;i++)cin>>Fx[i];
    for(i=0;i<N;i++){
        C[i]=Fx[i];
        for(j=0;j<N-1;j++){
            if(j==0)arr[i][j]=1;
            else arr[i][j]=pow(X[i],j);
        }
    }
    transpose();
}
void show(){
    int i,j;
    for(i=0;i<N-1;i++){
        for(j=0;j<N;j++){
            cout<<mat_A[i][j]<<" ";
        }
        cout<<endl;
    }
}
void multi1(double mat1[][siz], double mat2[][siz],int R1,int C1,int R2,int C2) 
{ 
    double rslt[R1][C2]; 

    for (int i = 0; i < R1; i++) { 
        for (int j = 0; j < C2; j++) { 
            rslt[i][j] = 0; 
            for (int k = 0; k < R2; k++) { 
                rslt[i][j] += mat1[i][k] * mat2[k][j]; 
            } 
  
            mat_A[i][j]=rslt[i][j];
        } 
    } 
} 
void multi2(double mat1[][siz], double mat2[],int R1,int C1,int R2,int C2) 
{ 
    double rslt[R1][C2]; 
    int i ,j;

    for ( i = 0; i < R1; i++) { 
        for ( j = 0; j < C2; j++) { 
            rslt[i][j] = 0; 
            for (int k = 0; k < R2; k++) { 
                rslt[i][j] += mat1[i][k] * mat2[k]; 
            } 
            
           mat_A[i][COLUMN-1]=rslt[i][j]; 
            // cout<<rslt[i][j]<<" ";
        } 
        // cout<<endl;
    }
     
} 
void plss(){
multi1(Tarr,arr,COLUMN-1,ROW,ROW,COLUMN-1);
multi2(Tarr,Fx,COLUMN-1,ROW,ROW,1);
ROW-=1;
	for(int i=0;i<ROW;i++)
	   for(int j=0;j<COLUMN;j++){
	   	mat_U[i][j]=mat_A[i][j];
	   }
	   
	for(int i=0;i<ROW;i++){
		double pivot=mat_U[i][i];
		for(int j=i+1;j<ROW;j++){
			if(mat_U[j][i]!=0){
				double div=mat_U[j][i]/pivot;
				//mat_L[j][i]=div;
				//mat_U[j][i]=0;
				for(int k=0;k<COLUMN;k++){
					mat_U[j][k]+=(-div)*mat_U[i][k];
				}	
			}
		}
		
	}
	
	for(int i=0;i<ROW;i++){
		double d=mat_U[i][i];
		if(d!=1){
		      for(int j=0;j<COLUMN;j++){
			 mat_U[i][j]/=d;
		      }
		}
	}
	for(int i=ROW-1;i>=0;i--){
		double pivot=mat_U[i][i];
		for(int j=i-1;j>=0;j--){
			if(mat_U[j][i]!=0){
				double div=mat_U[j][i]/pivot;
				
				for(int k=COLUMN-1;k>=0;k--){
					mat_U[j][k]+=(-div)*mat_U[i][k];
			
				}		
				//mat_U[j][i]=0;
			}
		}
		
	}
	   
	

	cout <<"Answers:"<<endl;
	for(int i=0;i<ROW;i++){
	   printf("%7.2lf ",mat_U[i][COLUMN-1]);
	   cout <<endl;
	}
}
void transpose(){
    int i,j;
    for(i=0;i<N-1;i++){
        for(j=0;j<N;j++){
            Tarr[i][j]=arr[j][i];
        }
    }
}