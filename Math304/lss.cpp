#include<bits/stdc++.h>
using namespace std;
#define siz 100
#define ROW 2
#define COLUMN 3
void read();
int N;
double X[siz],Fx[siz];
double C[siz];
double arr[siz][siz];
double Tarr[siz][siz];
double mat_A[ROW][COLUMN];
double Marr[2][2];
double Carr[2][1];
double mat_U[siz][siz];
void transpose();
void showArr();
void multi1(double mat1[][siz], double mat2[][siz],int R1,int C1,int R2,int C2);
void multi2(double mat1[][siz], double mat2[],int R1,int C1,int R2,int C2) ;
void llss();
int main(){
read();
transpose();
multi1(Tarr,arr,2,N,N,2);
multi2(Tarr,Fx,2,N,N,1);
llss();
//showArr();
}
void read(){
    int i,j;
    freopen("lss.txt","r",stdin);
    cin>>N;
    for(i=0;i<N;i++)cin>>X[i];
    for(i=0;i<N;i++)cin>>Fx[i];
    for(i=0;i<N;i++){
        C[i]=Fx[i];
        for(j=0;j<2;j++){
            if(j==0)arr[i][j]=1.0;
            else arr[i][j]=X[i];
        }
    }
    
}
void transpose(){
    int i,j;
    for(i=0;i<2;i++){
        for(j=0;j<N;j++){
            Tarr[i][j]=arr[j][i];
        }
    }
}
void showArr(){
    int i,j;
    for(i=0;i<2;i++){
        for(j=0;j<1;j++){
            cout<<Carr[i][j]<<" ";
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
  
            Marr[i][j]=rslt[i][j];
            mat_A[i][j]=Marr[i][j]; 
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
  
            Carr[i][j]=rslt[i][j]; 
            //cout<<rslt[i][j]<<" ";
        } 
        //cout<<endl;
    }
    for(i=0;i<2;i++)mat_A[i][2]=Carr[i][0]; 
} 
void llss(){	//LU decomposition
	
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
	   
	

	cout <<"FOURTH="<<endl;
	for(int i=0;i<ROW;i++){
	   for(int j=0;j<COLUMN;j++)
	      printf("%7.2lf ",mat_U[i][j]);
	   cout <<endl;
	}
}