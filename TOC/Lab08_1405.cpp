#include<bits/stdc++.h>
using namespace std;
void equalSystem(int p1);
void not_equal(int p1,int p2);
int main(){
    string str;
    freopen("lab8.txt","r",stdin);
    cin>>str;
    int p1,p2;
    bool flag=false;
    srand(time(0)); 
    for(int i=0;str[i];i++){
        if(flag==false && str[i]=='^'){
            if(str[i+1]!='n')p1=str[i+1]-'0';
            else p1=1;
            flag=true;
            continue;
        }
        if(flag==true && str[i]=='^'){
            if(str[i+1]!='n')p2=str[i+1]-'0';
            else p2=1;
            break;
        }
    }
    if(p1==p2)equalSystem(p1);
    else not_equal(p1,p2);
}
void equalSystem(int p){
    int n,i,j;
    n=rand()%8+1;
    //cout<<"N = "<<n<<endl;
    string str="";
    for(i=0;i<n*p;i++)str+='0';
    for(i=0;i<n*p;i++)str+='1';
   // cout<< "String = "<<str<<endl;
    string x="",y="",z="";
    int num_x,num_z,num_y,k;
    num_y=rand()%(n+1) +1;
    num_x=n-num_y;
    num_z=str.size() - (num_x+num_y);
   // cout<<"Num x = "<<num_x<<" Num y " <<k<<" Num z "<<num_z<<endl; 
   //cout<<"String is = "<<str;
//    cout<<"X+Y+Z  = ";
   for(i=0;i<num_x;i++)x+=str[i];
   for(;i<num_x+num_y;i++)y+=str[i];
   for(;i<str[i];i++)z+=str[i];
//    cout<<x+y+z<<endl;
//    cout<<"X = "<<x<<endl;
//    cout<<"Y = "<<y<<endl;
//    cout<<"Z = "<<z<<endl;
    bool zero=true,one=true;
    j=1;
   while(zero==true && one==true){
        string test;
        test+=x;
        for(k=0;k<j;k++)test+=y;
        test+=z;
        for(i=0;i<test.size()/2;i++){
            if(test[i]!='0'){
                zero=false;
                break;
            }
        }
        for(;i<test[i];i++){
            if(test[i]!='1'){
                one=false;
                break;
            }
        }
        if(zero == false || one == false){
            
            cout<<"X = "<<x<<endl<<"Y = "<<y<<endl<<"Z = "<<z<<endl;
            cout<<"K = "<<j<<endl;
            cout<<"xy^kz = "<<test<<endl;
            cout<<"Not Regular"<<endl;
            break;
        }
    j++;
   }
}
void not_equal(int p1,int p2){
    int n1,n2,n,i,j;
    n=rand()%8+1;
    n1=n*p1;
    n2=n*p2;
     string str;
    for(i=0;i<n1;i++)str+='0';
    for(i=0;i<n2;i++)str+='1';
    string x="",y="",z="";
    int num_x,num_z,num_y,k;
    num_y=rand()%(n+1) +1;
    num_x=n-num_y;
    num_z=str.size()- (num_x+num_y);
    for(i=0;i<num_x;i++)x+=str[i];
   for(;i<num_x+num_y;i++)y+=str[i];
   for(;i<str[i];i++)z+=str[i];
   bool zero=true,one=true;
    j=1;
   while(zero==true && one==true){
        string test;
        test+=x;
        for(k=0;k<j;k++)test+=y;
        test+=z;
        for(i=0;i<n1;i++){
            if(test[i]!='0'){
                zero=false;
                break;
            }
        }
        for(;i<n1+n2;i++){
            if(test[i]!='1'){
                one=false;
                break;
            }
        }
        if(zero == false || one == false){
            cout<<"N1 = "<<n1<<endl<<"N2 = "<<n2<<endl;
            cout<<"X = "<<x<<endl<<"Y = "<<y<<endl<<"Z = "<<z<<endl;
            cout<<"K = "<<j<<endl;
            cout<<"xy^kz = "<<test<<endl;
            cout<<"Not Regular"<<endl;
            break;
        }
    j++;
   }
}