#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18


int N, M, V;
int a, b;

void dfs(int start, set<int>* graph, bool* visited){
    visited[start] = true;
    cout << start << " ";

    for(int next : graph[start]){
        if(!visited[next]){
            dfs(next, graph, visited);
        }
    }
}

queue<int> q;

void bfs(int start, set<int>* graph, bool* visited){
    visited[start] = true;
    cout << start << " ";
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int next : graph[node]){
            if(!visited[next]){
                visited[next] = true;
                cout << next << " ";
                q.push(next);
            }
        }
    }
}

int main(){
    IOS;

    cin >> N >> M >> V;
    // undirected graph, multiple edges between two vertices available.
    set<int> graph[N+1];
    for(int i=0; i<M; ++i){
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }

    bool visited_dfs[N+1] = { false };
    bool visited_bfs[N+1] = { false };

    // print vertices in visiting order.
    dfs(V, graph, visited_dfs);
    cout << endl;
    bfs(V, graph, visited_bfs);
    cout << endl;

    return 0;
}
