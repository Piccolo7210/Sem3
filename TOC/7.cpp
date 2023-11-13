#include<bits/stdc++.h>
using namespace std;
int main(){
    int num_states,num_symbols,num_finish,i,j,k,f_ind;
    bool flg;
    freopen("miniInput.txt","r",stdin);
    //cout<< "Enter number of states,symbols,finishing states :"<<endl;
    cin>>num_states>>num_symbols>>num_finish;
    char states[num_states],alpha[num_symbols],final,transition[num_states][num_symbols],start,mat[num_states][num_states];
    //cout<<"Enter alphabet: "<<endl;
    for( i=0;i<num_symbols;i++){
        cin>>alpha[i];
    }
    //cout<<"Enter states: "<<endl;
    for( i=0;i<num_states;i++){
        cin>>states[i];
    }
    //cout<<"Enter starting point: ";
    cin>>start;
    //cout<<"Enter Final point : ";
    cin>>final;
    //cout<<"Transition:"<<endl;
    for(i=0;i<num_states;i++){
        //cout<<"For state "<<states[i]<<endl;
        for(j=0;j<num_symbols;j++){
            //cout<<"If input is "<<alpha[j]<<" ";
            cin>>transition[i][j];
        }
    }
    bool situation[num_states];
        for( i=0;i<num_states;i++){
            if(final== states[i]){
                situation[i]=true;
                f_ind=i;
            }
            else{
                situation[i]=false;
            }
        }
        for(i=0;i<num_states;i++){
            for(j=0;j<num_states;j++){
                mat[i][j]='*';
            }
        }
        for(i=0;i<num_states;i++){
                mat[i][f_ind]='X';
                mat[f_ind][i]='X';
            
        }
        for(i=0;i<num_states;i++){
            mat[i][i]='=';
        }
        for(i=0;i<num_states;i++){
            for(j=i+1;j<num_states;j++){
                if(mat[i][j]=='*'){
                    for(int m=0;m<num_symbols;m++){
                        if(transition[i][m] == final || transition[j][m]==final){
                            if(transition[i][m]== final && transition[j][m]==final){
                                mat[i][j]='=';
                                mat[j][i]='=';
                            }
                            else{
                                mat[i][j]='X';
                                mat[j][i]='X';
                                break;
                            }
                        }
                    }
                if(mat[i][j]=='*'){
                     flg=true;
                    for(int m=0;m<num_symbols;m++){
                        for(int w=0;w<num_symbols;w++){
                            if(situation[transition[transition[i][m]-'a'][w]-'a']!=situation[transition[transition[j][m]-'a'][w]-'a']){
                                mat[i][j]='X';
                                mat[j][i]='X';
                                flg=false;
                                break;
                            }
                        }
                        if(flg==false){
                            break;
                        }
                    }
                    if(flg==true){
                       mat[i][j]='=';
                       mat[j][i]='='; 
                    }
                }
             }
                
            }
        }
        cout<<"  ";
        for(i=0;i<num_states;i++){
            cout<<states[i]<<" ";
        }
        cout<<endl;
        for(i=0;i<num_states;i++){
            cout<<states[i]<<" ";
            for(j=0;j<=i;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        bool equivalent[num_states];
        for(i=0;i<num_states;i++){
            equivalent[i]=true;
        }
        for(i=0;i<num_states;i++){
            for(j=0;j<i;j++){
                if(mat[i][j]=='='){
                    equivalent[i]=false;
                    states[i]=states[j];
                    break;
                }
            }
        }
        cout<<"  ";
        for(i=0;i<num_symbols;i++)cout<<alpha[i]<<" ";
        cout<<endl;
        for(i=0;i<num_states;i++){
            if(equivalent[i]==true){
                cout<<states[i]<<" ";
            for(j=0;j<num_symbols;j++){
                if(equivalent[transition[i][j]-'a']==false)cout<<states[transition[i][j]-'a']<<" ";
                else 
                cout<<transition[i][j]<<" ";
            }
            cout<<endl;
            }
        }
}