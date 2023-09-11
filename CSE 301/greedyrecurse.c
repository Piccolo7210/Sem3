#include<stdio.h>
int ind;
void sortarrays(int arr[][3],int n);
void selection(int arr[][3],int *select,int n,int i);
int main(){
    int n;
    printf("Enter activity number: ");
    scanf("%d",&n);
    int arr[n][3];
    int select[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&arr[i][0],&arr[i][1]);
        arr[i][2]=i+1;
        select[i]=-1;
    }
    sortarrays(arr,n);
    selection(arr,select,n,0);
    printf("Activities: \n");
    for(int i=0;i<n;i++){
        if(select[i]!=-1)printf("%d ",select[i]);
    }
    return 0;
}
void sortarrays(int arr[][3],int n){
    int i,j;
    for(i=0;i<n;i++)
        for(j=i;j<n;j++){
            if(arr[i][1]>arr[j][1]){
                int temp;
                temp=arr[i][1];
                arr[i][1]=arr[j][1];
                arr[j][1]=temp;
                temp=arr[i][0];
                arr[i][0]=arr[j][0];
                arr[j][0]=temp;
                temp=arr[i][2];
                arr[i][2]=arr[j][2];
                arr[j][2]=temp;
            }
        }
}
void selection(int arr[][3],int *select,int n,int i){
   int m;
   if(i==0)select[ind++]=arr[i][2];
   m=i+1;
   while(m<=n && arr[m][0]<arr[i][1])m+=1;
   printf("%d ",m);
   if(m<n){
    select[ind++]=arr[m][2];
    selection(arr,select,n,m);
   }
   else return;
}