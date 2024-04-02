/*
    https://www.acmicpc.net/problem/10451
    (permutation cycles)

    similar problem
        https://www.acmicpc.net/problem/2487
        (mix sequence)

    solutions
        https://www.acmicpc.net/source/8995164
        (cepiloth, 36 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    counts the number of permuation cycles in a given permutation of n integers
*/

const int MAX_NUM = 1'000;  // 10^3
int T;
int n;

int ans;
bool visited[MAX_NUM + 1];
vector<int> graph[MAX_NUM + 1]; // directed graph
// set<int> cycle;

void initialize(){
    for(int idx=0; idx<=MAX_NUM; ++idx){
        visited[idx] = false;
    }
    ans = 0;

    // cycle.clear();
}

void dfs_graph(int vertex){
    visited[vertex] = true;
    // cycle.insert(vertex);

    for(int next : graph[vertex]){
        if(!visited[next]){
            dfs_graph(next);
        }
        else{   // visited[next]
            // auto search = cycle.find(vertex);
            // if(search != cycle.end()){
            ++ans;
            // return;
            // }
        }
    }
}

void solve_graph(){
    initialize();

    for(int idx=1; idx<=n; ++idx){
        if(!graph[idx].empty() && !visited[idx]){
            dfs_graph(idx);
        }
    }

    cout << ans << endl;
}

int arr[MAX_NUM + 1];
void dfs_array(int pos){
    if(visited[pos]){
        return;
    }

    visited[pos] = true;
    dfs_array(arr[pos]);
}

void solve_array(){
    initialize();

    for(int idx=1; idx<=n; ++idx){
        if(!visited[idx]){
            ++ans;
            dfs_array(idx);
        }
    }

    cout << ans << endl;
}

void solve(){
    // solve_graph();

    solve_array();
}

void input(){
    cin >> T;
    while(T--){
        cin >> n;

        int input;
        for(int i=1; i<=n; ++i){
            cin >> input;
            arr[i] = input;
            graph[i].push_back(input);
        }

        solve();
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
