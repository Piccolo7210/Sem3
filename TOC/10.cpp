#include<bits/stdc++.h>
using namespace std;
string input;
vector< string > leftmost(int one);
vector< string > rightmost(int one);
int main(){
    int i,one;
    cout<<"Enter the input: ";
    cin>>input;
    for(i=0;input[i];i++){
        if(input[i]=='1'){
            one=i;
            break;
        }
    }
if(i==input.length()){
	cout<<"Invalid Input"<<endl;
	exit(0);
}
    vector<string> left =leftmost(one);
    cout<< "LEFTMOST"<<endl;
    for(auto it : left)cout<<it<<"  ";
    cout<<endl<<endl;
    vector<string> right = rightmost(one);
    cout<< "RighTMOST"<<endl;
    for(auto it : right)cout<<it<<"  ";
}
vector< string > leftmost(int one){
    int i;
    vector<string> steps;
    string recent;
    steps.push_back("S");
    steps.push_back("A1B");
    recent="A1B";
    for(i=0;i<one;i++){
        if(input[i]=='0')steps.push_back("0"+steps.back());
        //if(input[i]=='1')steps.push_back("1"+steps.back());
    }
    recent=steps.back();
    if(recent.find("A")>=0)recent.erase(recent.begin()+recent.find("A"));
    //if(recent.find("B")>=0)recent.erase(recent.begin()+recent.find("B"));
    steps.push_back(recent);
    if(recent.find("B")>=0)recent.erase(recent.begin()+recent.find("B"));
    for(i=one+1;input[i];i++){
        if(input[i]=='0'){
            steps.push_back(recent+"0B");
            recent+="0";
            }
        if(input[i]=='1'){
            steps.push_back(recent+"1B");
            recent+="1";
        }
    }
    recent=steps.back();
    if(recent.find("B")>=0)recent.erase(recent.begin()+recent.find("B"));
    steps.push_back(recent);
    return steps;
}
vector< string > rightmost(int one){
    int i;
    vector<string> steps;
    string recent;
    steps.push_back("S");
    steps.push_back("A1B");
    recent="A1";
    for(i=one+1;input[i];i++){
        if(input[i]=='0'){
            steps.push_back(recent+"0B");
            recent+="0";
            }
        if(input[i]=='1'){
            steps.push_back(recent+"1B");
            recent+="1";
            }
    }
    steps.push_back(recent);
    //recent.erase(recent.begin()+recent.find("A"));
    for(i=0;i<one;i++){
        if(input[i]=='0'){
            steps.push_back("0"+recent);
            recent="0"+recent;
        }
    }
    recent.erase(recent.begin()+recent.find("A"));
    steps.push_back(recent);
    return steps;
}