/*
    https://www.acmicpc.net/problem/15681
    (tree and query)
*/

#include <iostream>
#include <vector>

#define ll long long
#define endl '\n'

const int NUM_VERTEX = 100'000;     // 10^5
const int NUM_QUERY = 100'000;      // 10^5


int N, R, Q;
int U, V;

std::vector<int> graph[NUM_VERTEX + 1];
bool visited[NUM_VERTEX + 1];
int dp[NUM_VERTEX + 1];

int dfs(int curr){
    visited[curr] = true;

    int cnt = 1;
    for(int next : graph[curr]){
        if(!visited[next]){
            cnt += dfs(next);
        }
    }

    return dp[curr] = cnt;
}

void solve(){
    dfs(R);
}

void input(){
    std::cin >> N >> R >> Q;
    for(int ith=1; ith<=N-1; ++ith){
        std::cin >> U >> V;
        graph[U].push_back(V);
        graph[V].push_back(U);
    }

    solve();

    for(int ith=1; ith<=Q; ++ith){
        std::cin >> U;
        std::cout << dp[U] << endl;
    }
}

int main(){

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    input();

    solve();

    return 0;
}
