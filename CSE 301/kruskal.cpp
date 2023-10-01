#include<bits/stdc++.h>
using namespace std;
#define Size 100
int graph[Size][Size];
int edge;
int vertex;
vector<set<string>> Vset; 
vector<string> Vname;
set<pair<int,pair<string,string>>> ecost;
void kruskalf();
int FindSet(string name);
void Makeset( );
void read();
int indexnum(string str);
void print();
set<pair<int,pair<string,string>>> A;
int main(){
    read();
    Makeset();
    kruskalf();
    print();
}
void Makeset(){
         int i;
    for(i=0;i<vertex;i++){
        set<string>y;
        y.insert(Vname[i]);
        Vset.push_back(y);
    }
}
void read(){
        int i,j,m,n;
        for(i=0;i<Size;i++){
        for(j=0;j<Size;j++){
            graph[i][j]=INT_MAX;
        }
    }
        freopen("kruskal.txt","r",stdin);
        cin>>edge;
          for(i=0;i<edge;i++){
            string x,y;
            int cost;
            pair <string,string>edg;
            cin>>x>>y>>cost;
            if(find(Vname.begin(),Vname.end(),x)==Vname.end())Vname.push_back(x);
            if(find(Vname.begin(),Vname.end(),y)==Vname.end())Vname.push_back(y);
            m=indexnum(x);
            n=indexnum(y);
            graph[m][n]=cost;
            graph[n][m]=cost;
            edg.first=x;
            edg.second=y;
            pair<int,pair<string,string>> edcost;
            edcost.first=cost;
            edcost.second=edg;
            ecost.insert(edcost);
    }
       vertex=Vname.size(); 
    }
int FindSet(string name){
    for(int i=0; i<Vset.size() ;i++){
        if(Vset[i].find(name) != Vset[i].end()){
            return i;
        }
    }
    return -1;
}
void kruskalf(){
    int i,u,v;
    for(auto it :ecost){
        u=FindSet(it.second.first);
        v=FindSet(it.second.second);
        if(u!=v){
           A.insert(it);
        for(auto x : Vset[v])Vset[u].insert(x);
           auto itr = Vset.begin()+v;
           Vset.erase(itr);
        }
    }
}
int indexnum(string str){
    for(int i=0;i<Size;i++){
        if(Vname[i]==str)return i;
    }
    return -1;
}
void print(){
    int minDis=0;
    for(auto it:A){
        minDis+=it.first;
        cout<<it.second.first<<" --> "<<it.second.second<<" : "<<it.first<<endl;
    }
    cout<<"Total Distance : "<<minDis<<endl;
}
