#include<stdio.h>
#define length 10
int maxprofit(int *prices,int *maxprices,int *cut,int size);
int max(int a , int b);
void printprofit(int size,int *cut,int profit);
void takinginput(int *prices);
int main(){
    int size,cut[1000],prices[length+1],profit;
    printf("*****Taking Input From File*****\n");
    freopen("input.txt","r",stdin);
    takinginput(prices);
    //Taking Desired size
     scanf("%d",&size);
    int maxprices[size+1];
	for(int i=0;i<=size;i++){
	maxprices[i]=-1;
	cut[i]=-1;
	}
    profit=maxprofit(prices,maxprices,cut,size);
    printprofit(size,cut,profit);
    return 0;
}
int max(int a , int b){
    if(a>b)return a;
    else return b;
}
int maxprofit(int *prices,int *maxprices,int *cut,int size ){
    int profit,x;
   if(maxprices[size]>=0)return maxprices[size];
   if(size==0){
    profit=0;
   }
   else{
    profit=-1;
    for(int i=1;i<=10;i++){
	if(i<=size){
	x=prices[i]+maxprofit(prices,maxprices,cut,size-i);
		if(x>=profit){
			cut[size]=i;
			profit=x;		
		}	
	}
    }
   }
   maxprices[size]=profit;
   return profit;
}
void takinginput(int *prices){
	for(int i=1;i<=length;i++)
    {
        scanf("%d",&prices[i]);// price for each size
    }
   
   
}
void printprofit(int size,int *cut,int profit){
 	printf("Maximum Profit: %d\n",profit);
	int n;
	n=size;
	while(n>0){
	printf("%d ",cut[n]);
	n=n-cut[n];	
	}
}



















