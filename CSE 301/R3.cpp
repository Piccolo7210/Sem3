#include<bits/stdc++.h>
using namespace std;
#define Siz 100
int ResG[Siz][Siz];
int graph[Siz][Siz];
int Ngraph[Siz][Siz];
bool bfs( string source,string dest,int parent[]);
int Ford();
int indexnum(string str);
void print_vertex();
int total_out();
void addnode(int out);
void newNode_calc();
void SS_calc();
void print_graph();
string src;
string des;
vector<string> Vname;
int prev_vertex,vertex;
int edge;
void read();
int main(){
read();
int maxflow = Ford();
cout<<"MAX FLOW IS : "<<maxflow<<endl;
}
int Ford(){
    
    int i,j;
     int parent[vertex];
    int maxFlow=0;
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
        freopen("R3.txt","r",stdin);
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
            //ResG[m][n]=graph[m][n];
    }
        // cin>>src>>des;
       prev_vertex=Vname.size(); 
      // print_vertex();
       addnode(total_out());
       src="SOURCE";
       des="SINK";
       Vname.push_back(src);
       Vname.push_back(des);
     newNode_calc();
     vertex=Vname.size();
      print_vertex();
      print_graph();
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
    for(int i=0;i<Vname.size();i++){
        if(Vname[i]==str)return i;
    }
    return -1;
}
int total_out(){
    int out=0,i,j;
    for(i=0;i<prev_vertex;i++){
        for(j=0;j<prev_vertex;j++){
            if(graph[i][j])out+=graph[i][j];
        }
    }
    return out+1;
}
void addnode(int out){
    int i;
    for(i=0;i<prev_vertex;i++){
        string s="V"+to_string(prev_vertex+i);
        Vname.push_back(s);
        Ngraph[i][prev_vertex+i]=out;
        ResG[i][prev_vertex+i]=Ngraph[i][prev_vertex+i];
    }
    
}
void newNode_calc(){
    int i,j,x=0,s,d;
    s=indexnum(src);
    d=indexnum(des);
   // cout<<"s : "<<s <<"  d: "<<d<<endl;
    for(i=0;i<prev_vertex;i++){
        for(j=0;j<prev_vertex;j++){
            if(graph[i][j]){
                x+=graph[i][j];
                Ngraph[i][prev_vertex+j]=graph[i][j];
               ResG[i][prev_vertex+j]=Ngraph[i][prev_vertex+j];
            }
        }
        //cout<<"x :"<<x<<endl;
        Ngraph[s][i]=x;
       // cout<<"Ngraph["<<s<<"]["<<i<<"] : "<<Ngraph[s][i]<<endl;
        Ngraph[i+prev_vertex][d]=x;
        ResG[s][i]=Ngraph[s][i];
        ResG[i+prev_vertex][d]=Ngraph[i+prev_vertex][d];
        x=0;
    }
    
}
void print_graph(){
    int i,j;
    for(i=0;i<vertex;i++){
        for(j=0;j<vertex;j++){
            cout<<ResG[i][j]<<"  ";
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