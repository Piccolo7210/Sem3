#include<bits/stdc++.h>
using namespace std;
int num_states,num_symbols;
void print(vector<vector<vector<int> > > table);
int main(){
    int i,j,k;
    cout<<"Enter the number of symbols in alphabet: ";
    cin>> num_symbols;
    char symbols[num_symbols];
    for(i=0;i<num_symbols;i++){
        cin>>symbols[i];
    }
    cout<<"Enter the number of states in NFA: ";
    cin>> num_states;
    char states[num_symbols];
    for(i=0;i<num_states;i++){
        cin>>states[i];
    }
    cout<<"Transition table for NFA";
    vector<vector<vector<int>>> transition;
    for(i=0;i<num_states;i++){
        cout<<"For state "<<states[i]<<endl;
        vector<vector<int>> two;
        for(j=0;j<num_symbols;j++) {
            cout<<"if input is "<<symbols[j]<<", num of output is : ";
            int num,val;
            cin>>num;
            vector<int> one;
            for(k=0;k<num;k++){
                char ch;
                cin>>ch;
                val=ch-'a';
                one.push_back(val);
            }
            two.push_back(one); 
        }
        transition.push_back(two);
    }
    print(transition);
}
void print(vector<vector<vector<int> > > table){
	cout<<"\tSTATE   ||";
	for(int i=0;i<table[0].size();i++){
		cout<<"\t"<<i<<"\t||";
	}
    cout<<endl;
	for(int i=0;i<table.size();i++){
		cout<<"\t"<<(char)(i+'a')<<"\t";
        cout<<"||\t";
		for(int j=0;j<table[i].size();j++){
		    for(int k=0;k<table[i][j].size();k++){ 
				cout<<(char)(table[i][j][k]+'a')<<" ";
			}
            
            if(j==table[i].size()-1)cout<<"\t\t||";
            else cout<<"\t||";
		}
		cout<<endl;
	}
}