#include <bits/stdc++.h>
#define author armag-pro
using namespace std;

const int N=100;
int n, m;
vector<int> nt[N][N], nt1[N][N];
set<int> closure[N];

void print_without_eps() {
	 cout << "\nNFA without epsilon moves:\n";
	 cout << "============================\n";
	 cout << "Q\t\tSymbols\n";

		for(int i=0; i<n; i++) {
			cout << "Q" << i << "\t";
			for(int j=1; j<=m; j++) {
				cout << "{";
				for(int ii: nt1[i][j]) {
                    printf("%c",ii+'A');
                    cout << " ";}
				cout << "}\t";
			}
			cout << endl;
		}
		cout << endl;
}

int main() {

    /*
        Input: 
           3
           2
           1 B
           1 A
           0
           1 C
           0
           1 B
           0
           1 C
           1 C
        Output:
            Q0  {A B C }  {B C }     
            Q1  {C}       {B C}     
            Q2  {C}       {C }
    */
freopen("EFA.txt","r",stdin);
    cout << "No. of states: ";
    cin >> n>>m;
    getchar();
    cout << "No. of input symbols: ";
   // cin >> m;
    //getchar();
    cout << "Enter transitions:\n\n";
/*
STATE -a 
row =0 -> EPS -> 


*/
    // Transition table
    for(int i=0; i<n; i++) {
        cout << "State ";
        printf("%c",i+'A');
        cout<< endl;
    	for(int j=0; j<=m; j++) {

    		cout << "\tNo of transitions for ";
    		if(j == 0) cout << "eps";
    		else cout << (j - 1);
    		cout << ": ";
    		int temp; cin >> temp;
             getchar();
    		nt[i][j].resize(temp);
            if(temp == 0) {
                
            } else if(temp == 1) {
                cout << "\tEnter the state: ";
            } else {
                cout << "\tEnter the " << temp << " states: ";
            }
    		for(int k=0; k<nt[i][j].size(); k++) {
                char x;
                cin>>x;
                 getchar();
    			nt[i][j][k]=x-'A';
                
    		}
           
    	}
        cout << endl;
    }

    // Finding epsilon closure for each state
    for(int i=0; i<n; i++) {
    	queue<int> q;
    	vector<bool> vis(n, false);
    	q.push(i); vis[i] = true;
    	while(!q.empty()) {
    		int top = q.front(); q.pop();
    		for(int k=0; k<nt[top][0].size(); k++) {
    			int cur = nt[top][0][k];
    			if(vis[cur] == false) {
    				vis[cur] = true;
    				q.push(cur);
    			}
    		}
    	}
    	for(int j=0; j<n; j++) {
    		if(vis[j] == true) closure[i].insert(j);
    	}
        //check[i]=closure[i];

    }

    // Find epsilon* --> symbol --> epsilon* for each state and symbol
    for(int i=0; i<n; i++) {
        vector<set<int>> check(m);

    	for(int ii: closure[i]) {
    		for(int j=1; j<=m; j++) {
                //set<int> x;
    			for(int k=0; k<nt[ii][j].size(); k++) {
    				int cur = nt[ii][j][k];
    				for(int iii: closure[cur]) {
                        check[j-1].insert(iii);
                       // x.insert(iii);
    					//nt1[i][j].push_back(iii);
    				}
    			}
                // int q=0;
                // for(auto it : x){
                //     auto val = next(x.begin(),q);
                //     q++;
                //     nt1[i][j].push_back(*(val));
                // }
    		}
    	}
        for(int j=1;j<=m;j++){
            for(auto val : check[j-1])
            nt1[i][j].push_back(val);
        }
    }

    print_without_eps();

    return 0; 
} 