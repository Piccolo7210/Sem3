#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
#include<string.h>
#include<stdlib.h>
int main(){
    freopen("genDFA.txt","r",stdin);
	int num_symbols,num_state,num_accpt,flag=0;
	 //printf("Input : Number of symbol,state,final state :");	
	// scanf("%d %d %d",&num_symbols,&num_state,&num_accpt);
    cin>>num_symbols>>num_state>>num_accpt;
	getchar();
	char alpha[num_symbols],transition[num_state][num_symbols],accpt_state[num_accpt],start_state,state[num_state],steps[50];
	//printf("Enter the symbols : ");
	for(int i=0;i<num_symbols;i++){
		//scanf("%c",&alpha[i]);
        cin>>alpha[i];
		getchar();
	}
	//printf("Enter the state name : ");
	for(int i=0;i<num_state;i++){
		//scanf("%c",&state[i]);
        cin>>state[i];
		getchar();
	}
	//printf("Starting point: ");
	cin>>start_state;
    //scanf("%c",&start_state);
	getchar();
	//printf("Enter the final state: ");
	for(int i=0;i<num_accpt;i++){
		//scanf("%c",&accpt_state[i]);
        cin>>accpt_state;
		getchar();
	}
	
	for(int i=0;i<num_state;i++){
		//printf("For state : %c \n",state[i]);
		for(int j=0;j<num_symbols;j++){
			//printf("when input is %c transit to: ",alpha[j]);
			//scanf("%c",&transition[i][j]);
            cin>>transition[i][j];
			getchar();
		}
	}
    string str;
	//printf("Input the String : ");
	cin>>str;
    //scanf("%s",str);
	getchar();
	cout<<"No of State: "<<num_state<<endl;
	for(int i=0;i<num_state;i++)cout<<state[i]<<" ";
	cout<<endl;
	cout<<"Transition Table: "<<endl;
	cout<<"\t"<<"0\t1"<<endl;
	for(int i=0;i<num_state;i++){
		cout<<state[i]<<"\t";
		for(int j=0;j<num_symbols;j++){
			cout<<transition[i][j]<<"\t";
		}
		cout<<endl;
	}
	int i;
	for(i=0;str[i];i++){
		steps[i]=start_state;
		for(int j=0;j<num_symbols;j++){
			if(str[i]== alpha[j]){
				start_state=transition[start_state-'a'][j];
				break;
		}
		}
	}
	steps[i]=start_state;
	for(int j=0;j<num_accpt;j++){
		if(start_state==accpt_state[j])flag=1;
	}
	if(flag==1)printf("ACCEPTED.\n");
	else printf("NOT ACCEPTED.\n");
	printf("PAth: ");
	for(int j=0;j<=i;j++)
	{
		printf("%c ",steps[j]);
	}
  }