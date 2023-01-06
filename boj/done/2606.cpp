#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int num_vertex;
int num_edge;
int u, v;
int ans;

void dfs(int start, vector<int>* graph, bool* visited){
    visited[start] = true;
    ++ans;
    for(int next : graph[start]){
        if(!visited[next]){
            dfs(next, graph, visited);
        }
    }
}

int main(){
    IOS;

    cin >> num_vertex;
    cin >> num_edge;
    vector<int> graph[num_vertex+1];
    for(int i=0; i<num_edge; ++i){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    ans = 0;

    int start = 1;
    bool visited[num_vertex+1] = { false };
    dfs(start, graph, visited);

    cout << ans - 1 << endl;

    return 0;
}
