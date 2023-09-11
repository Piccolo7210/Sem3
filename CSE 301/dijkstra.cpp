#include<bits/stdc++.h>
using namespace std;
#define size 100
int graph[size][size];
string name[size];
bool visit[size];
int vert=0;
void readInput();
void initialize(int *distance, int *previ,int source);
int extract_min(int *distance, bool *visit);
void dijkstra(int *distance,int *previ,int source);
void relax(int *distance,int *previ,int u ,int v);
void printPath(int *previ,int node);
int main(){
	
	int distance[size],previ[size],source;
    freopen("dijkinput.txt","r",stdin);
    readInput();
    cin>>source;
    dijkstra(distance,previ,source);
    cout<<"Distance From DHAKA: "<<endl;
	for(int i=0;i<vert;i++){
        cout<<name[i]<<"  ";
        cout<<distance[i]<<endl;
    }
    cout<<"SHortest PAth from DHaka:"<<endl;
    for(int i=1;i<vert;i++){
        printPath(previ,i);
        cout<<endl;
    }
}
void initialize(int *distance, int *previ,int source){
	for(int i=0;i<vert;i++){
		distance[i]=INT_MAX;
		previ[i]=-1;
		visit[i]=false;	
	}
	distance[source]=0;
}
int extract_min(int *distance){
	int min =INT_MAX,in;
	for(int i=0;i<vert;i++){
		if(min>=distance[i]&& visit[i] == false)
			{
				min=distance[i];
				in=i;	
			}	
	}
	return in;
}
void relax(int *distance,int *previ,int u , int v){
	if(distance[v]> distance[u]+graph[u][v]){
		distance[v]=distance[u]+graph[u][v];
		previ[v]=u;
	}
}
void dijkstra(int *distance,int *previ,int source){
	initialize(distance,previ,source);
	int n=vert,u,v;
	while(n>0){
	u=extract_min(distance);
	visit[u]=true;
	for(int v=0;v<vert;v++){
		if(graph[u][v]){
			relax(distance,previ,u,v);		
		}	
	}
    n--;
	}

}
void readInput()
{
    int u, v;
    string s;
    while (cin>>s)
    {
        if(s == "END")
            break;

        for(u = 0; u < vert; u++)
        {
            if(name[u] == s)
                break;
        }
        if (u == vert)
        {
            name[vert] = s;
            vert++;
        }

        cin >> s;
        for(v = 0; v < vert; v++)
        {
            if(name[v] == s)
                break;
        }
        if (v == vert)
        {
            name[vert] = s;
            vert++;
        }

        cin >> graph[u][v];

    }
}
void printPath(int *previ,int node){
    if(previ[node]==-1){
        cout<<name[node]<<"  ";
        return;
    }
    printPath(previ,previ[node]);
    cout<<name[node]<<"  ";
}