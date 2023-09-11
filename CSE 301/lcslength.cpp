#include<bits/stdc++.h>
using namespace std;
int length(string &str1,string &str2,int m,int n);
int main(){
	string str1,str2;
	freopen("LCSinput.txt","r",stdin);
	cin>>str1>>str2;
	int m=str1.size();
	int n=str2.size();
	cout<<"LCS length = "<<length(str1,str2,m,n);
}
int length(string &str1,string &str2,int m,int n){
	if(m==0 || n==0)return 0;
	if(str1[m-1] == str2[n-1])return 1+length(str1,str2,m-1,n-1);
	else return max(length(str1,str2,m,n-1),length(str1,str2,m-1,n));
}
