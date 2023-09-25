#include<bits/stdc++.h>
using namespace std;
#define Size 100
int graph[Size][Size];
vector<string> Vname;
void kruskal(set<pair<int,pair<string,string>>> &ecost,vector<set<string>> &Vset,int vertex,int edge);
int Findset(vector<set<string>> &Vset,string name,int vertex);
void Makeset(vector<set<string>> &Vset,int vertex );
void Makeedge(set<pair<int,pair<string,string>>> &ecost,int edge);
int main(){
    int vertex,edge;
    vector<set<string>> Vset;              
    cin>>vertex>>edge;
    for(int i=0;i<vertex;i++)for(int j=0;j<vertex;j++)graph[i][j]=0;
    for(int i=0;i<vertex;i++){
        string s;
        cin>>s;
        Vname.push_back(s);
    }
    set<pair<int,pair<string,string>>> ecost;
    
}
void Makeset(vector<set<string>> &Vset,int vertex ){
         int i;
    for(i=0;i<vertex;i++){
        string x;
        cin>>x;
        set<string>y;
        y.insert(x);
        Vset.push_back(y);
    }
}
void Makeedge(set<pair<int,pair<string,string>>> &ecost,int edge){
    for(int i=0;i<edge;i++){
        string s1,s2;
        int cost;
        pair<string,string> edge;
        cin>>s1>>s2>>cost;
        int v1=0,v2=0;
        for(int j=0;j<Vname.size();j++){
            if(s1==Vname[j])v1=j;
            if(s2==Vname[j])v2=j;
            if(v1!=0 && v2!=0)break;
        }
        graph[v1][v2]=cost;
        graph[v2][v1]=cost;
        edge.first=s1;
        edge.second=s2;
        pair<int,pair<string,string>> edcost;
        edcost.first=cost;
        edcost.second=edge;
        ecost.insert(edcost);
    }
}
int Findset(vector<set<string>> &Vset,string name,int vertex){
    for(int i=0;i<vertex;i++){
        if(Vset[i].find(name)!= Vset[i].end()){
            continue;
        }
        else return i;
    }
}
void kruskal(set<pair<int,pair<string,string>>> &ecost,vector<set<string>> &Vset,int vertex,int edge){
    Makeset(Vset,vertex);
    Makeedge(ecost,edge);
    int i,u,v;
    for(auto it :ecost){
        u=Findset(Vset,it.second.first,vertex);
        v=Findset(Vset,it.second.second,vertex);
        if(u!=v){
            
        }
    }
}