#include<bits/stdc++.h>
using namespace std;
#define Size 100
int V;
vector <string> name;
int d[Size][Size];
int p[Size][Size];
int graph[Size][Size];
void printPath(int s , int t);
void floydwarshall();
void read();
int indexnum(string str);
int main(){
    read();
    floydwarshall();
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            // cout<<"Source: "<<name[i]<<" Dest: "<<name[j]<<endl;
            // printPath(i,j);
            // if(i!=j)cout<<name[j]<<endl;
            // if(graph[i][j]==INT_MAX)cout<<"200 ";
            // else cout<<graph[i][j]<<" ";
            cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }
}
void read(){
    int edge,i,j,dist;
    for(i=0;i<Size;i++){
        for(j=0;j<Size;j++){
            if(i==j)graph[i][j]=0;
            else{
            graph[i][j]=INT_MAX;
            //p[i][j]=-1;
            }
        }
    }
    freopen("floyd.txt","r",stdin);
    cin>>edge;
    string x,y;
    for(i=0;i<edge;i++){
        cin>>x>>y>>dist;
        if(find(name.begin(),name.end(),x)==name.end())name.push_back(x);
        if(find(name.begin(),name.end(),y)==name.end())name.push_back(y);
        int m,n;
        m=indexnum(x);
        n=indexnum(y);
        graph[m][n]=dist;
    }
    V=name.size();
}
int indexnum(string str){
    for(int i=0;i<Size;i++){
        if(name[i]==str)return i;
    }
    return -1;
}
void floydwarshall(){
    int i,j,k;
    for(i=0;i<V;i++){
                    for(j=0;j<V;j++){
                        d[i][j]=graph[i][j];
                        if( i == j || graph[i][j]==INT_MAX){
                                p[i][j]=-1;
                        }
                        else if(i!=j && graph[i][j]<INT_MAX){
                            p[i][j]=i;
                        }
                    }
                }
    
    for (k=0;k<V;k++) {
        
        for (i=0;i<V;i++) {
            
            for (j=0;j<V;j++) {
                
                if (d[i][j]>(d[i][k]+d[k][j])&&(d[k][j] != INT_MAX&&d[i][k]!= INT_MAX)){
                    d[i][j]=d[i][k]+d[k][j];
                    p[i][j]=p[k][j];
                        }
            }
        }
    }
    }
void printPath(int s , int t){
    if(p[s][t]==-1)cout<<"No path"<<endl;
    else if(p[s][t]==s)cout<<name[s]<<" -> ";
    else{
        printPath(s,p[s][t]);
        printPath(p[s][t],t);
    }
}