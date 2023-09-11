#include<stdio.h>
void sortarrays(int arr[][3],int n);
void selection(int arr[][3],int *select,int n);
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
    }
    sortarrays(arr,n);
    selection(arr,select,n);
    printf("Activities: \n");
    for(int i=0;i<n;i++){
        if(arr[i]==-1)break;
        printf("%d ",arr[i]+1);
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
void selection(int arr[][3],int *select,int n){
   int k=0;
   select[0]=k;
   int m;
   m=k+1;
   for(int i=1;i<n;i++){
    if(arr[i][0]>=arr[k][1]){
        select[m]=arr[i][2];
        m++;
        k=i;
    }
   }
}