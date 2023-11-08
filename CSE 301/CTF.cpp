#include<bits/stdc++.h>
using namespace std;
string pattern = "abaabaaaa";
int transition[100][100];
string alpha="ab";
void ctf();
void FAM(string text);
int main(){
    string text;
    cin>>text;
ctf();
FAM(text);
}
void ctf(){
    int m = pattern.size();
    int lenalpha = alpha.size();
    int q,i,j,k;
    for(q=0;q<=m;q++){
        for(j=0;j<lenalpha;j++){
            k=1+min(m,q+1);
        while(1){
            k=k-1;
            if(k==0)break;
            string pref;
            string suff;
            pref=pattern.substr(0,k);
            suff=pattern.substr(0,q);
            suff+=alpha[j];
            string check = suff.substr(suff.size()-k);
            cout<<"prefix : "<<pref<<endl;
            cout<<"Suff of "<<suff<<" : "<<check<<endl;
            if(pref==check)break;
        }
        transition[q][alpha[j]-'a']=k;
        }
    }
    // cout<<"Transition Function:"<<endl;
    // for(i=0;i<m+1;i++){
    //     for(j=0;j<lenalpha;j++){
    //         cout<<transition[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}
void FAM(string text){
    int n = text.size();
    int q=0,i,m,s,count=0;
    m=pattern.size();
    for(i=0;i<n;i++){
        q=transition[q][text[i]-'a'];
        if(q==m){
            s=i-m+1;
            cout<<"Pattern occurs with shift "<<s<<endl;
            count++;
        }
    }
    cout<<"Total matched substr : "<<count<<endl;
}