#include<bits/stdc++.h>
using namespace std;
#define Siz 100
int ResG[Siz][Siz];
int graph[Siz][Siz];
bool bfs( string source,string dest,int parent[]);
int Ford();
int indexnum(string str);
void print_graph();
string src;
string des;
vector<string> Vname;
void addition();
void print_vertex();
vector<int>Vcap;
int vertex;
int edge;
void read();
int main(){
read();
// for(int i=0;i<vertex;i++){
//     for(int j=0;j<vertex;j++){
//         cout<<graph[i][j]<<" ";
//     }
//     cout<<endl;
// }
// cout<<"Source : "<<src<<endl<<"DEst: "<<des<<endl;
int maxflow = Ford();
cout<<"MAX FLOW IS : "<<maxflow<<endl;
}
int Ford(){
    int i,j;
     int parent[vertex];
    int maxFlow=0;
    src=Vname[0];
    des=Vname[vertex-1];
    while(bfs(src,des,parent)){
        int flow= INT_MAX;
        int u,v,s;
        s=indexnum(src);
        v=indexnum(des);
        while(v!=s) {
            u = parent[v];
            flow = min(flow, ResG[u][v]);
            v=parent[v];
        }
        v=indexnum(des);
        while(v!=s){
            u = parent[v];
            ResG[u][v] -= flow;
            v=parent[v];
        }
        maxFlow += flow;
    }
 
    return maxFlow;
    }
void read(){
        int i,j,m,n;
        for(i=0;i<Siz;i++){
        for(j=0;j<Siz;j++){
            graph[i][j]=0;
            ResG[i][j]=0;
        }
    }
        freopen("R2.txt","r",stdin);
        cin>>edge;
          for(i=0;i<edge;i++){
            string x,y;
            int cost;
            cin>>x>>y>>cost;
            if(find(Vname.begin(),Vname.end(),x)==Vname.end())Vname.push_back(x);
            if(find(Vname.begin(),Vname.end(),y)==Vname.end())Vname.push_back(y);
            m=indexnum(x);
            n=indexnum(y);
            graph[m][n]=cost;
            ResG[m][n]=graph[m][n];
    }
        int cap=0;
        for(i=0;i<Vname.size();i++){
            cin>>cap;
            Vcap.push_back(cap);
        }
       vertex=Vname.size(); 
       addition();
    }
bool bfs(string source,string dest,int parent[])
{
    int s,desti,u;
    queue<int> q;
    bool visited[vertex];
    for(int i=0;i<vertex;i++)visited[i]=false;
    s=indexnum(source);
    desti=indexnum(dest);
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while(!q.empty()) {
        u = q.front();
        q.pop();
        for (int v=0;v<vertex;v++) {
            if (visited[v]==false && ResG[u][v]>0) {
                if (v == desti) {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}
int indexnum(string str){
    for(int i=0;i<Siz;i++){
        if(Vname[i]==str)return i;
    }
    return -1;
}
void addition(){
    int i,j;
    int l=vertex;
    for(i=0;i<l;i++){
        string s="V"+to_string(l+i);
        Vname.push_back(s);
        graph[i][l+i]=Vcap[i];
        ResG[i][l+i]=graph[i][l+i];
    }
    vertex=Vname.size();
    // cout<<"Vertex number : "<<vertex<<endl;
    // cout<<endl;
    // print_graph();
    // print_vertex();
}
void print_graph(){
    int i,j;
    for(i=0;i<vertex;i++){
        for(j=0;j<vertex;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}
void print_vertex(){
    int i;
    for(i=0;i<vertex;i++){
        cout<<Vname[i]<<" ";
    }
    cout<<endl;
}