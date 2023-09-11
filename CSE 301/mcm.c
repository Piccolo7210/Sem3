#include<stdio.h>
#include<math.h>
#include<limits.h>
#define n 6
int p[n]={10,5,1,10,2,10};
int m[n][n];
int s[n][n];
char name[]={' ','A','B','C','D','E'};
void mco();
int mco_rec(int i, int j);
void print(int i , int j);
int main(){
	mco_rec(1,n-1);
	print(1,n-1);
	
}
void mco()
{
    int i,j,k,L,q;
    for (L=2;L<n;L++)
    {
        for (i=1;i<n-L+1;i++)
        {
            j=i+L-1;
            m[i][j]=INT_MAX;
            for (k=i;k<j;k++)
            {
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j])
		{
		   m[i][j]=q;
	    	   s[i][j]=k;
		}
            }
        }
    }
}
int mco_rec(int i, int j){
	int k,q;
	if(m[i][j]<INT_MAX)return m[i][j];
	if(i==j)m[i][j]=0;
	else{
		for(k=i;k<j;k++){
			q=mco_rec(i,k)+mco_rec(k+1,j)+p[i-1]*p[k]*p[j];
			if(q<m[i][j]){
				m[i][j]=q;		
			}		
		}	
	}
	return m[i][j];
}
void print(int i , int j){
	if(i==j)printf("%c",name[i]);
	else{
		printf("( ");
		print(i,s[i][j]);
		print(s[i][j]+1,j);
		printf(" )");	
	}

}
