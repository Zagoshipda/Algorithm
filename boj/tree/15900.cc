/*
    https://www.acmicpc.net/problem/15900
    (tree escape)

    similar problem
        https://www.acmicpc.net/problem/1260
        (dfs bfs)

    solution
        https://www.acmicpc.net/source/32878761
        (orslow, 280 ms)

        https://www.acmicpc.net/source/26094931
        (horong54, 288 ms)

        https://www.acmicpc.net/source/18926951
        (jw950310, 300 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int NUM_NODE = 500'000;   // 5 * 10^5
const int ROOT = 1;

int N;
int a, b;

vector<int> graph[NUM_NODE + 1];
bool visited[NUM_NODE + 1];

int sum_depth;

void dfs(int curr, int dist){
    visited[curr] = true;

    bool is_leaf = true;
    for(int next : graph[curr]){
        if(!visited[next]){
            is_leaf = false;
            dfs(next, dist + 1);
        }
    }

    if(is_leaf){
        sum_depth += dist;
    }
}

void solve_dfs(){
    dfs(ROOT, 0);
}

void solve_bfs(){
    queue<pair<int, int> > nodes;   // (node, dist)

    nodes.push({ ROOT, 0 });
    while(!nodes.empty()){
        auto [curr, curr_dist] = nodes.front();
        nodes.pop();

        // if(visited[curr]){
        //     continue;
        // }
        visited[curr] = true;

        bool is_leaf = true;
        for(int next : graph[curr]){
            if(!visited[next]){
                is_leaf = false;
                nodes.push({ next, curr_dist + 1 });
            }
        }

        if(is_leaf){
            sum_depth += curr_dist;
        }
    }
}

void solve(){
    // solve_dfs();

    solve_bfs();

    if(sum_depth & 1){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}

void input(){
    cin >> N;
    for(int ith=1; ith<N; ++ith){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
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

    solve();

    return 0;
}
