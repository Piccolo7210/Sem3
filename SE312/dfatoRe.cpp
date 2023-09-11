#include<bits/stdc++.h>
using namespace std;
int main(){
    int num_states,num_symbols,num_finish,i,j,k;
    cout<< "Enter number of states,symbols,finishing states :"<<endl;
    cin>>num_states>>num_symbols>>num_finish;
    char states[num_states],alpha[num_symbols],final,transition[num_states][num_symbols],start;
    cout<<"Enter alphabet: "<<endl;
    for( i=0;i<num_symbols;i++){
        cin>>alpha[i];
    }
    cout<<"Enter states: "<<endl;
    for( i=0;i<num_states;i++){
        cin>>states[i];
    }
    cout<<"Enter starting point: ";
    cin>>start;
    cout<<"Enter Final point : ";
    cin>>final;
    cout<<"Transition:"<<endl;
    for(i=0;i<num_states;i++){
        cout<<"For state "<<states[i]<<endl;
        for(j=0;j<num_symbols;j++){
            cout<<"If input is "<<alpha[j]<<" ";
            cin>>transition[i][j];
        }
    }
    vector<vector<vector<string>>> re;
    vector<vector<string>> str2;
    // vector<vector<string>> str2;
    for(i=0;i<num_states;i++){
        
        for(k=0;k<1;k++){
            vector<string> str1;
            if(k==0){
            for(j=0;j<num_states;j++){
                bool flag=false;
                for(int m=0;m<num_symbols;m++){
                    
                    if(transition[i][m]-'a'==j){
                        flag=true;
                        if(transition[i][m]-'a'==i){
                            string s,x;
                            s="^ + "; //^ self loop
                            x=to_string(m);
                            s=s+x;
                            str1.push_back(s);
                        }
                        else{
                            string s,x;
                            x=to_string(m);
                            s=x;
                            str1.push_back(s);
                        }
                    }
                }
                if(flag==false)str1.push_back("#");//NULL #
            }
        }
            str2.push_back(str1);
        }
    }
    re.push_back(str2);
    // for(i=0;i<num_states;i++){
    //         for(k=1;k<num_states;k++){
    //             vector<string>str1;
    //             for(j=0;j<num_states;j++){
    //                 str1.push_back(re[i][k-1][j]+" + "+re[i][k-1][k-1]+" ( "+re[k-1][k-1][k]+" )* "+re[k-1][k-1][j]);
    //             }
    //             str2.push_back(str1);
    //         }
    //         re.push_back(str2);
    // }
        for(i=0;i<num_states;i++){
            for(j=0;j<num_states;j++){
                cout<<re[0][i][j]<<"\t";
            }
            cout<<endl;
        }
}