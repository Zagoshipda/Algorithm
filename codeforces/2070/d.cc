/*
    https://codeforces.com/contest/2070/problem/D
    (D. Tree Jumps)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int NUM_VERETX = 300'000;     // 3 * 10^5
const int ROOT = 1;                 // level = depth = 0
const int MOD = 998'244'353;

int t;
int n;
int pi;

vector<int> graph[NUM_VERETX + 2];
vector<int> levels[NUM_VERETX + 2];
int max_level;

ll level_sum[NUM_VERETX + 2];
ll dp[NUM_VERETX + 2];

void initialize(){
    // for(int vertex=0; vertex<=NUM_VERETX; ++vertex){
    for(int vertex=0; vertex<=n+1; ++vertex){
        graph[vertex].clear();
        levels[vertex].clear();
        level_sum[vertex] = 0;
        dp[vertex] = 0;
    }
    max_level = 0;
}

void bfs(){
    queue<pair<int, int> > que; // (node, level)
    que.push({ ROOT, 0 });

    while(!que.empty()){
        auto [curr, curr_level] = que.front();
        que.pop();

        levels[curr_level].push_back(curr);
        max_level = max(max_level, curr_level);

        for(int child : graph[curr]){
            que.push({ child, curr_level + 1 });
        }
    }
}

void solve_dp_2(){
    bfs();

    for(int level=max_level; 0<level; --level){
        ll val = levels[level].size();
        level_sum[level] = (val + (val - 1) * level_sum[level + 1]) % MOD;
    }

    dp[ROOT] = (1 + level_sum[1]) % MOD;

    cout << dp[ROOT] << endl;
}

void solve_dp_time_exceeded(){
    bfs();

    for(int level=max_level; 0<level; --level){
        for(int vertex : levels[level]){
            dp[vertex] = 1 + level_sum[level + 1];
            dp[vertex] %= MOD;

            for(int child : graph[vertex]){
                // if(dp[vertex] < dp[child]){
                //     dp[vertex] += MOD;
                // }
                dp[vertex] += MOD;
                dp[vertex] -= dp[child];
                dp[vertex] %= MOD;
            }

            level_sum[level] += dp[vertex];
            level_sum[level] %= MOD;
        }
    }

    dp[ROOT] = 1;
    for(int child : graph[ROOT]){
        dp[ROOT] += dp[child];
    }

    cout << dp[ROOT] << endl;
}

void solve(){
    // solve_dp_time_exceeded();

    solve_dp_2();
}

void input(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int vertex=2; vertex<=n; ++vertex){
            cin >> pi;
            graph[pi].push_back(vertex);
        }
        solve();

        initialize();
    }
}

void debug(){

}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    // debug();

    input();

    // solve();

    return 0;
}
