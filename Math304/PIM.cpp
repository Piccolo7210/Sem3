#include<bits/stdc++.h>
using namespace std;
#define N 3
#define siz 100
#define EPS 10.0e-7
double X[siz][N][1],maxArr[siz];
double Carr[N][1];
double arr[siz][siz];
void multi2(double mat1[][siz], int R1,int C1,int R2,int C2,int page)  ;
void read();
void PIM();
double maxval(int page);
int main(){
read();
PIM();
}
void read(){
    freopen("pim.txt","r",stdin);
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
        cin>>arr[i][j];
        }
    }
}
void multi2(double mat1[][siz], int R1,int C1,int R2,int C2,int page) 
{ 
    double rslt[R1][C2]; 
    int i ,j;

    for ( i = 0; i < R1; i++) { 
        for ( j = 0; j < C2; j++) { 
            rslt[i][j] = 0; 
            for (int k = 0; k < R2; k++) { 
                rslt[i][j] += mat1[i][k] * X[page][k][j]; 
            } 
            
            X[page+1][i][j]=rslt[i][j]; 
            //cout<<rslt[i][j]<<" ";
        } 
        
    }

}
void PIM(){
    int i=0,j;
    X[0][0][0]=1;
    X[0][1][0]=0;
    X[0][2][0]=0;
    maxArr[0]=-900;
    cout<<"------X1-------X2-------X3--------Iteration--------- lembda------"<<endl;
    for(j=0;j<N;j++)cout<<X[0][j][0]<<"   ";
    cout<<i<<"\t"<<endl;
    while(true){
        multi2(arr,N,N,N,1,i);
        i++;
        maxArr[i]=maxval(i);
       for(j=0;j<N;j++)cout<<X[i][j][0]<<"   ";
        cout<<i<<"\t"<<maxArr[i]<<endl;
        if(fabs(maxArr[i]-maxArr[i-1])<=EPS){
            cout<<"FOUND"<<endl;
            break;
        }
    }
    cout<<"LARGEST EIGENVALUE: "<<maxArr[i]<<endl;
    cout<<"EigenVectors:"<<endl;
    for( j=0;j<N;j++){
        cout<<X[i-1][j][0]<<"  ";
    }
    cout<<endl;
}
double maxval(int page){
    double max=-800;
    for(int i=0;i<3;i++){
        if(fabs(X[page][i][0])>max)max=fabs(X[page][i][0]);
    }
    // cout<<"MAX: "<<max<<endl;
    // cout<<X[page][0][0]<<endl; 
    for(int i=0;i<3;i++){
      X[page][i][0]=X[page][i][0]/max;
    }
    return max;
}