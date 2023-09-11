#include<stdio.h>
int min(int a,int b);
int fraction(int arr[][3],int n,int W);
void sort(int arr[][3],int n);
int main(){
    int n;
    printf("Enter the number of items: ");
    scanf("%d",&n);
    int item[n][3];
    for(int i=0;i<n;i++)scanf("%d %d",&item[i][0],&item[i][1]);
    for(int i=0;i<n;i++)item[i][2]=item[i][1]/item[i][0];   // arr[][0]=weight arr[][1]=benefit arr[][2]
    int capacity;
    printf("Highest capacity: ");
    scanf("%d",&capacity);
    sort(item,n);
    int profit = fraction(item,n,capacity);
    printf("Profit = %d\n",profit);
}
int min(int a,int b){
    return (a>b) ? b :a;
}
void sort(int arr[][3],int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            if(arr[i][2]<arr[j][2]){
                int temp;
                temp=arr[i][2];
                arr[i][2]=arr[j][2];
                arr[j][2]=temp;
                temp=arr[i][0];
                arr[i][0]=arr[j][0];
                arr[j][0]=temp;
                temp=arr[i][1];
                arr[i][1]=arr[j][1];
                arr[j][1]=temp;
            }
        }
    }
}
int  fraction(int arr[][3],int n,int W){
    int x=0,w=0;
    int i=0,profit=0;
    while(w<W){
        x=min(arr[i][0],W-w);
        w+=x;
        //printf("weight = %d , profit = %d\n",x,arr[i][1]);
        profit+=arr[i][2]*x;
        i++;
    }
    return profit;
}