#include<bits/stdc++.h>
using namespace std;
char sign[100][100];
int ED(string &s1,string &s2,int m,int n,int arr[][100]);
void print(int m,int n,int end);
int main(){
	string x="muhaimeen";
	string y="toho";
	int m=x.size();
	int n=y.size();
	m+=1;
	n+=1;
	int arr[100][100],end;
	end=ED(x,y,m,n,arr);
	cout<<"\n";
	print(m,n,end);
	sign[0][0]='0';
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
		cout<<sign[i][j]<<" ";
		}
		cout<<"\n";
	}
}
int ED(string &s1,string &s2,int m,int n,int arr[][100]){
	int l1=m-1,l2=n-1;
	int i,j,x;
	for(i=0;i<m;i++)
	{
		arr[i][0]=i;
		if(i!=0)sign[i][0]='^';
	}
	for(i=0;i<n;i++)
	{	arr[0][i]=i;
		if(i!=0)sign[0][i]='<';
	}
	for(i=1;i<m;i++){
		for(j=1;j<n;j++){
			if(s1[i-1]==s2[j-1]){
				arr[i][j]=arr[i-1][j-1];
				sign[i][j]='+';// no operation
			}
			else{
				x=min(arr[i-1][j],arr[i][j-1]);
				arr[i][j]=min(arr[i-1][j-1],x)+1;
				if(arr[i-1][j-1]>x){
					if(arr[i-1][j]>arr[i][j-1])sign[i][j]='<';//insert
					else sign[i][j]='^';//delete
				}
				else sign[i][j]='#';//replace
			
			}
		}
	}
	cout<<"ED is  = "<<arr[m-1][n-1]<<endl;
	return arr[m-1][n-1];
}
void print(int m,int n,int end){
	if(end==0)return;
	if(sign[m-1][n-1] == '#'){
	print(m-1,n-1,end-1);
	cout<<"Replace\n";
	}
	else if(sign[m-1][n-1]=='+')print(m-1,n-1,end);//no operation
	else if(sign[m-1][n-1]=='^')
	{
		print(m-1,n,end-1);
		cout<<"Delete\n";
	}
	else{
		print(m,n-1,end-1);
		cout<<"Insert\n";
	}
}
