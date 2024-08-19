/*
    https://www.acmicpc.net/problem/10451
    (permutation cycles)

    similar problem
        https://www.acmicpc.net/problem/2487
        (mix sequence)

    solutions
        https://www.acmicpc.net/source/8995164
        (cepiloth, 36 ms) : recursive dfs
        https://www.acmicpc.net/source/43759312
        (p_ce1052, 36 ms) : iterative dfs
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        counts the [number of permuation cycles] in a given permutation of n integers

ex.
1
10
2 1 3 4 5 6 7 9 10 8

// 7

*/

const int MAX_NUM = 1'000;  // 10^3
int T;
int n;

int ans;
bool visited[MAX_NUM + 1];

// NOTE : graph can have self loops (k -> k identity permutation)
vector<int> graph[MAX_NUM + 1]; // directed graph

void initialize(){
    for(int idx=0; idx<=MAX_NUM; ++idx){
        visited[idx] = false;
        // graph[idx].clear();
    }
    ans = 0;
}

void dfs_graph(int curr){
    visited[curr] = true;

    for(int next : graph[curr]){
        if(!visited[next]){
            dfs_graph(next);
        }
    }
}

void solve_graph(){
    for(int idx=1; idx<=n; ++idx){
        if(!visited[idx]){
            // if(!graph[idx].empty()){    // WRONG
            if(idx != graph[idx].front()){
                dfs_graph(idx);
            }

            ++ans;
        }
    }

    cout << ans << endl;
}

int perm[MAX_NUM + 1];
void dfs_1(int curr){
    if(visited[curr]){
        return;
    }

    visited[curr] = true;
    dfs_1(perm[curr]);
}

void dfs_2(int curr){
    visited[curr] = true;

    if(!visited[perm[curr]]){
        dfs_2(perm[curr]);
    }
}

void solve_dfs_recursive(){
    for(int idx=1; idx<=n; ++idx){
        if(!visited[idx]){
            // dfs_1(idx);
            dfs_2(idx);

            ++ans;
        }
    }

    cout << ans << endl;
}


void solve_dfs_iterative(){
    for(int ith=1; ith<=n; ++ith){
        if(!visited[ith]){
            int pos = ith;
            // while(perm[pos] != ith){
            //     visited[pos] = true;
            //     pos = perm[pos];
            // }
            // visited[pos] = true;

            while(!visited[pos]){
                visited[pos] = true;
                pos = perm[pos];
            }

            ++ans;
        }
    }
    cout << ans << endl;
}

void solve(){
    // solve_graph();              // 40 ms

    // solve_dfs_recursive();  // 36 ms

    solve_dfs_iterative();  // 36 ms
}

void input(){
    cin >> T;
    while(T--){
        cin >> n;

        initialize();

        int input;
        for(int ith=1; ith<=n; ++ith){
            cin >> input;
            perm[ith] = input;

            // graph[ith].push_back(input);
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
