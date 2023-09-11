#include<stdio.h>
int strlength(char *arr);
int main(){
	char cond[20];
	int len;
	scanf("%s",cond);
	len=strlength(cond);
	char state[len+1],d;
	for(int i=0;i<len+1;i++){
		state[i]='A'+i;	
	}
	switch
}
int strlength(char *arr){
	int count=0;
	for(int i=0;arr[i];i++)count++;
	return count;
}
