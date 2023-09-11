#include<bits/stdc++.h>
using namespace std;
int maxLength,maxIndex;
void LISNaive(int *arr,int *L,int *prev,int size);
int main(){
    int arr[]={0,9,2,5,3,7,11,8,10,13,6};
    int size=sizeof(arr)/sizeof(arr[0]);
    int L[size]={0};
    int prev[size]={0};
    prev[0]=-1;
    LISNaive(arr,L,prev,size);
    cout<<"Maximum Length: "<<maxLength<<endl;
}
void LISNaive(int *arr,int *L,int *prev,int size){
    int i,j;
    for(i=1;i<size;i++){
        for(j=0;j<i;j++){
            if(arr[j]<arr[i] && ((L[j]+1)>L[i])){
                L[i]=L[j]+1;
            }
            prev[i]=j;
            if(L[i]>maxLength){
                
                maxLength=L[i];
                maxIndex=i;
            }
        }
    }
}
void print(int *prev,int index){

}
