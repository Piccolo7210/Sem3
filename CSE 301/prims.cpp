#include<bits/stdc++.h>
using namespace std;
#define Siz 100
int graph[Siz][Siz];
int vertex,edge;
vector<string> Vname; // ndoe_name
vector<pair<string,int>> Q; // For each node name and it's key value
vector< pair<string,pair<int,int>>>node; // node name, key value, parents node index
void initialise();
int index_v(string s);
int extract_min();
int indexnum(string str);
int is_there(string s);
void print_graph();
void read();
void prims();
int main(){
read();
prims();
cout<<"Vertices: "<<endl;
int i,cost=0;
for(i=0;i<node.size();i++)cout<<Vname[i]<<" ";
cout<<endl;
cout<<"Cost: "<<endl;
for(i=0;i<node.size();i++)cout<<node[i].second.first<<" ";
for(i=0;i<node.size();i++)cost+=node[i].second.first;
cout<<endl<<"Parents:"<<endl;
cout<<"#  ";
for(i=1;i<node.size();i++)cout<<Vname[node[i].second.second]<<" ";
cout<<endl<<"Minimum Cost: ";
cout<<cost<<endl;

}
void read(){
     int i,j,m,n;
        freopen("prims.txt","r",stdin);
        cin>>vertex>>edge;
          for(i=0;i<edge;i++){
            string x,y;
            int cost;
            cin>>x>>y>>cost;
            if(find(Vname.begin(),Vname.end(),x)==Vname.end())Vname.push_back(x);
            if(find(Vname.begin(),Vname.end(),y)==Vname.end())Vname.push_back(y);
            m=indexnum(x);
            n=indexnum(y);
            graph[m][n]=cost;
            graph[n][m]=cost;
    }
    for(i=0;i<vertex;i++){
        pair<string,pair<int,int>>y;
        pair<int,int> x;
        y.first=Vname[i];
        x.first=INT_MAX;
        x.second=-1;
        y.second=x;
        node.push_back(y);
    }
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
int indexnum(string str){
    for(int i=0;i<vertex;i++){
        if(Vname[i]==str)return i;
    }
    return -1;
}
void initialise(){
    int i;
    pair<string,int>y;
    y.first=Vname[0];
    y.second=0;
    Q.push_back(y);
    node[0].second.first=0;
    for(int i=1;i<vertex;i++){
        pair<string,int>x;
        x.first=Vname[i];
        x.second=INT_MAX;//key
        Q.push_back(x);
    }
}
void prims(){
    initialise();
    int u,v,j;
  
    while(!Q.empty()){
        u=extract_min();
        for(v=0;v<vertex;v++){
            if(graph[u][v]>0 ){
                int x;
                x=is_there(Vname[v]);
             if( x!=-1){
                if(node[v].second.first>graph[u][v]){
                node[v].second.first=graph[u][v];
                node[v].second.second=u;
                j=index_v(Vname[v]);
                Q[j].second=graph[u][v];
                }
            }
        }
        }
    }
}
int is_there(string s){
    for(int i=0;i<Q.size();i++){
        if(Q[i].first==s)return i;
    }
    return -1;
}
int extract_min(){
    int i,j,min=INT_MAX,ind;
    string s;
    for(i=0;i<Q.size();i++){
        if(Q[i].second<min){
            s=Q[i].first;
            ind=i;
            min=Q[i].second;
        }
    }
    Q.erase(Q.begin()+ind);
    return indexnum(s);
}
int index_v(string s){
    int i;
    for(i=0;i<Q.size();i++)if(Q[i].first==s)return i;
    return -1;
}
