#include<bits/stdc++.h>
using namespace std;

int num_states, num_symbols, start_state, final_state, state, symbol, num_transition;
vector<int> states, symbols;
vector<vector<vector<int>>> transition_table;
set<set<int>> dfa_states, used_states;
vector<vector<int>> dfa_transition_table;
vector<int> finals;

void print_dfa_states();
bool is_visited(set<int> s);
int get_index(set<int> s);
bool is_final_state(set<int> s);
void print_nfa_transition_table();
void print_dfa_transition_table();

/*
    states 0 1 
    1     12 1
    12    12 13
    13    12 1
*/

int main(){
    freopen("DFAtoNFA.txt", "r", stdin);
    //freopen("input2.txt", "r", stdin);
    cin >> num_states;
    
    for(int i = 0; i < num_states; ++i){
        cin >> state;
        states.push_back(state);
    }

    for(int i = 0; i < num_states; ++i) cout << states[i] << " ";
    cout << endl;

    cin >> num_symbols;

    for(int i = 0; i < num_symbols; ++i){
        cin >> symbol;
        symbols.push_back(symbol);
    }

    for(int i = 0; i < num_symbols; ++i) cout << symbols[i] << " ";
    cout << endl;

    cin >> start_state >> final_state;
    cout << "Starting State: " << start_state << endl << "Final State: " << final_state << endl;
    /*
        vector<vector<int>> v;

        [                             ]
        [                             ]
        [                             ] 
        v.resize(num_states, vector<int>(num_symbols));

        vector<vector<vector<int>>> transition_table;
    */

    //transition_table[num_states][num_symbols][num_states];
    transition_table.resize(num_states, vector<vector<int>>(num_symbols, vector<int> (num_states)));

    for(int i = 0; i < num_states; ++i){
        for(int j = 0; j < num_symbols; ++j){
            cin >> num_transition;
            for(int k = 0; k < num_transition; ++k){
                cin >> transition_table[i][j][k];
            }
        }
    }
    
    print_nfa_transition_table();
    
    set<int> st;
    st.insert(start_state);
    dfa_states.insert(st); // dfa_states --> {1}

        /*
        0 {1}
        1 {1,2}
        2 {1,3}
        */

    for(int i = 0; i < dfa_states.size();++i){
        auto it = next(dfa_states.begin(), i);
        set<int> ds = *it; //1
        if(is_visited(ds)) continue; 
        for(auto sym : symbols){
            set<int> new_state;
            for(auto s : ds){ // 1,2 
                for(auto e : transition_table[s-1][sym]){
                    if(e != 0) 
                        new_state.insert(e);
                }
                dfa_states.insert(new_state);
            }
        }
        used_states.insert(ds);
    }

    print_dfa_states();
    //cout << "END" <<endl;
    
    dfa_transition_table.resize(dfa_states.size(), vector<int>(num_symbols));

    for(auto ds : dfa_states){ // {1}
        for(auto sym : symbols){//{0}
            set<int> new_state;
            for(auto s: ds){
                for(auto e : transition_table[s-1][sym]){
                    if(e != 0) new_state.insert(e);/*union*/                
                }
                //                    2   0   ->  ?
                //dfa_transition_table[s-1][sym] = get_index(new_state);
            }
            dfa_transition_table[get_index(ds)][sym] = get_index(new_state);
        }
    }
    /* 0 + 'A'
        states 0 1 
        1     idx 1
        12    12 13
        13    12 1
    */

    for(auto s : dfa_states){
        if(is_final_state(s)) finals.push_back(get_index(s));
    }

    print_dfa_transition_table();

    printf("Starting state: %c\n", *states.begin() - 1 + 'A');  // start_state - 1 + 'A'
    (finals.size() > 1) ? cout << "Final states: " : cout << "Final state: ";
    for(auto f : finals){
        printf("%c ", f + 'A');
    }
    cout << endl;
    cout << "END" << endl;

    return 0;
}

void print_nfa_transition_table(){
    cout << "NFA Transition Table" << endl;
    for(int i = 0; i < num_states; ++i){
        cout << "For state: " << states[i] << ": " << endl;
        for(int j = 0; j < num_symbols; ++j){
            cout << "For symbol " << symbols[j] << ": ";
            for(auto s : transition_table[i][j]){
                if(s > 0) cout << s << " ";
                else break;
            }  
            cout << endl; 
        }
        cout << endl;
    }
}

void print_dfa_states(){
    int i = 0;
    for(auto sets : dfa_states) {
        printf("State %c == { ", i+'A');
        for(auto element : sets){
            cout << element << " ";
        }
        printf("}\n");
        i++;
        cout << endl;
    }
}

void print_dfa_transition_table(){
    cout << "DFA Transition Table" << endl;
    for(auto s : dfa_transition_table){
        for(auto e : s)
            printf("%c ", e + 'A');
        cout << endl;
    }
}

bool is_visited(set<int> s){
    for(auto element : used_states){
        if(s == element) return true;   
    }
    return false;
}

int get_index(set<int> s){
    int i = 0;
    for(auto sets : dfa_states){
        if(sets == s) return i;
        i++;
    }
    return -1;
}

bool is_final_state(set<int> s){
    for(auto e : s){
        if(e == final_state) return true;
    }
    return false;
}