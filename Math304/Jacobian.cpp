#include<bits/stdc++.h>
using namespace std;
#define n 3
double a[n][n];
double b[n];
double oldx[n];
double newx[n];
#define eps 10e-6
void gauss_sidel();
bool dominant();
void jacob();
int main(){
	int i,j;
	freopen("jacob.txt","r",stdin);
	for(i =0;i<n;i++){
		for(j=0;j<n;j++){
			cin>>a[i][j];
		}
		cin>>b[i];
		oldx[i]=0;
		newx[i]=0;
	}
	bool dom = dominant();
	if(dom)cout<<"Diagonal Dominant."<<endl;
	else {
	cout<<"Not Diagonal Dominant"<<endl;
	exit(0);
	}
	
	gauss_sidel();
	for(int m=0;m<n;m++){
		cout<<newx[m]<<endl;
	}	
}
bool dominant(){
	bool flag=false;
	double sum=0;
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i!=j)sum+=fabs(a[i][j]);
		}
		if(fabs(a[i][i])>sum)flag=true;
		else flag=false;
		sum=0;
	}
	return flag;
}
void jacob(){
	int i,j,z;
	double ax=0;
	bool flag=false;
	for(;;){
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i!=j)ax+=a[i][j]*oldx[j];
		}
		//cout<<"ax : "<<ax<<endl;
		newx[i]=(b[i]-ax)/a[i][i];
		ax=0;
	}
	//for(z=0;z<n;z++)cout<<newx[z]<<" ";
	//cout<<endl;
		for(z=0;z<n;z++){
			if(fabs(newx[z]-oldx[z])<eps){
				flag=true;
				}
			else {
				flag=false;
				break;
			}
		}
		for(z=0;z<n;z++)oldx[z]=newx[z];
		if(flag==true)break;
	}
}
void gauss_sidel(){
	int i,j,z;
	double ax=0;
	bool flag=false;
	for(;;){
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i!=j)ax+=a[i][j]*newx[j];
		}
		//cout<<"ax : "<<ax<<endl;
		newx[i]=(b[i]-ax)/a[i][i];
		ax=0;
	}
	//for(z=0;z<n;z++)cout<<newx[z]<<" ";
	//cout<<endl;
		for(z=0;z<n;z++){
			if(fabs(newx[z]-oldx[z])<eps){
				flag=true;
				}
			else {
				flag=false;
				break;
			}
		}
		for(z=0;z<n;z++)oldx[z]=newx[z];
		if(flag==true)break;
	}
}
