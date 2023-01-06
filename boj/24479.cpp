#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int N, M, R;
int u, v;
int order = 1;

void dfs(int R, set<int>* graph, bool* visited, int* out){
    visited[R] = true;
    out[R] = order++;

    for(int N : graph[R]){
        if(!visited[N]){
            dfs(N, graph, visited, out);
        }
    }
}

int main(){
    IOS;

    cin >> N >> M >> R;

    // use vector and then sorting could be faster.
    set<int> graph[N+1];
    for(int i=0; i<M; ++i){
        cin >> u >> v;
        graph[u].insert(v);
        graph[v].insert(u);
    }

    int out[N+1] = { 0 };
    bool visited[N+1] = { false };

    dfs(R, graph, visited, out);

    for(int i=1; i<=N; ++i){
        cout << out[i] << endl;
    }

    return 0;
}
