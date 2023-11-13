#include<bits/stdc++.h>
using namespace std ;
bool check;
string result[10];
string str="";
string nstr="";
int len;
bool checkstring();
string rv( string input );
void cfg( int i );
int main()
{
    bool flag=true;
    cout<<"Enter the Input: " ;
    getline(cin,str);
    flag=checkstring();
    if(flag==true){
    check=false;
    len = str.length() ;
    result[(len/2) + 2] ;
     result[0] = "P" ;
     cfg( 0 );
     if(check==true){
        for(int i=0;i<len/2+2;i++)
        if(i!=len/2+1)cout<<result[i]<<" --> ";
        else cout<<result[i];
        cout<<endl;
     }
     else{
        cout<<"Not in Grammer."<<endl;
     }
    }
    else{
        cout<<"Invalid Input."<<endl;
    }
}
bool checkstring(){
    for(int i;i<str.size();i++){
        if(str[i]!='0' && str[i]!='1')return false;
    }
    return true;
}
string rv( string input ){
    string reve = "" ;
    for (int i = input.length()-1; i >= 0 ; i-- )reve += input[i];
    return reve ;
}
void cfg(int i){
    string revStr = rv(nstr) ;
    if( nstr + revStr == str ){   
        check = true ;
        result[++i] = nstr + revStr ;
        return ;
    }
    else if(nstr + "1" + revStr == str){
        check = true ;
        result[++i] = nstr + "1" + revStr ;
        return ;
    }
   else if(nstr + "0" + revStr == str){
        check = true ;
        result[++i] = nstr + "0" + revStr ;
        return ;
    }
    if(i>len/2) return ;
    else{
        if(str[i] == '1'){
            nstr += "1";
            result[++i] = nstr + "P" + rv(nstr) ;
            cfg( i );
        }
        else if(str[i] == '0'){
            nstr += "0";
            result[++i] = nstr + "P" + rv(nstr) ;
            cfg( i );
        }
    }
    return ;
}