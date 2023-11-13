#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
int num_symbols,num_state,num_accpt;
bool flag=false;
int ind=0;
char path[100];
char loop;
void transition(char trans[num_state][num_symbols][3],char curr_state,char *accpt_state, char *str,char *alpha,int output_num[num_state][num_symbols],int index);
int main(){
	int i,j,k;
	printf("Input : Number of symbol,state,final state :");	
	scanf("%d %d %d",&num_symbols,&num_state,&num_accpt);
	getchar();
	char alpha[num_symbols],accpt_state[num_accpt],start_state,state[num_state],trans[num_state][num_symbols][num_state],str[50],steps[50];
	printf("Enter the symbols : ");
	for(i=0;i<num_symbols;i++){
		scanf("%c",&alpha[i]);
		getchar();
	}
	printf("Enter the state name : ");
	for(i=0;i<num_state;i++){
		scanf("%c",&state[i]);
		getchar();
	}
	printf("Starting point: ");
	scanf("%c",&start_state);
	getchar();
	printf("Enter the final state: ");
	for(i=0;i<num_accpt;i++){
		scanf("%c",&accpt_state[i]);
		getchar();
	}
	int output_num[num_state][num_symbols];
	for(i=0;i<num_state;i++){
		printf("State - %c\n",state[i]);
		for(j=0;j<num_symbols;j++){
			printf("For symbol - %c output number is: ",alpha[j]);
			scanf("%d",&output_num[i][j]);	
		}	
	}
	for(i=0;i<num_state;i++){
		for(j=0;j<num_symbols;j++){
		for(k=0;k<num_state;k++){
			trans[i][j][k]='+';	
		}	
	}
	}
	for(i=0;i<num_state;i++){
		printf("For state %c:\n",state[i]);		
		for(int j=0;j<num_symbols;j++){
			if(output_num[i][j]!=0)printf("for symbol %c output states :\n",alpha[j]);
			for(k=0;k<output_num[i][j];k++){
				scanf(" %c",&trans[i][j][k]);
				getchar();			
			}
		}	
	}
	printf("Enter the string: ");
	scanf("%s",str);
	transition(trans,start_state,accpt_state,str,alpha,output_num,0);
	if(flag==true){
		printf("Accepted.And Path:\n");
		for(i=0;path[i];i++){
			printf("%c ",path[i]);
		}
	}
	else{
		printf("Rejected and stucking point = %c\n",loop);
	}
}
void transition(char trans[num_state][num_symbols][3],char curr_state,char *accpt_state, char *str,char *alpha,int output_num[num_state][num_symbols],int index){
	int i,j;
	if(str[index] == '\0' ){
		for(i=0;i<num_accpt;i++){
			if(curr_state==accpt_state[i]){
				flag=true;
				path[ind++]=curr_state;
				return ;
			}
		}
		ind--;
		loop = curr_state;
		return;		
		}		
	for(i=0;i<num_symbols;i++){
		if(alpha[i]==str[index]){
			if(output_num[curr_state-'a'][i]==0)return ;
			else break;
		}
	}
	path[ind++]=curr_state;
	for(j=0;j<output_num[curr_state-'a'][i] && flag==false;j++){
		transition(trans,trans[curr_state-'a'][i][j],accpt_state,str,alpha,output_num,index+1);
	}
}