#include<stdio.h>
#include<string.h>
char sign[100][100];
void lcs(char *x,char *y,int m, int n);
void print(char *x,int m,int n);
int main(){
	int m,n;
	char str1[20],str2[20];
	freopen("LCSinput.txt","r",stdin);
	scanf("%s",str1);
	scanf("%s",str2);
	m=strlen(str1);
	m+=1;
	n=strlen(str2);
	n+=1;
	lcs(str1,str2,m,n);
	return 0;
}
void lcs(char *x,char *y,int m, int n){
	int arr[m][n],len1,len2;
	len1=m-1;
	len2=n-1;	
	int i,j;	
	for(i=0;i<m;i++)arr[i][0]=0;
	for(i=0;i<n;i++)arr[0][i]=0;
	for(i=1;i<m;i++){
		for(j=1;j<n;j++){
			if(x[i-1]==y[j-1]){
				arr[i][j]=arr[i-1][j-1]+1;
				sign[i-1][j-1]='+';		
			}
			else if(arr[i-1][j]>=arr[i][j-1]){
				arr[i][j]=arr[i-1][j];
				sign[i-1][j-1]='^';			
			}
			else{
				arr[i][j]=arr[i][j-1];
				sign[i-1][j-1]='<';			
			}
		}
	}
	printf("LCS Length = %d\n",arr[m-1][n-1]);
	printf("LCS is = ");
	print(x,len1,len2);
}
void print(char *x,int m,int n){
	if(m==0 || n==0)return;
	if(sign[m-1][n-1]=='+'){
		print(x,m-1,n-1);
		printf("%c",x[m-1]);	
	}
	else if(sign[m-1][n-1]=='^')print(x,m-1,n);
	else print(x,m,n-1);
}
