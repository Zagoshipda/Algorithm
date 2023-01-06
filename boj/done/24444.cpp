#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18


int N, M, R;
int u, v;
int order = 1;
queue<int> q;

void bfs(int R, vector<int>* graph, bool* visited, int* out){
    visited[R] = true;
    out[R] = order++;
    q.push(R);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int N : graph[node]){
            if(!visited[N]){
                visited[N] = true;
                out[N] = order++;
                q.push(N);
            }
        }

    }
}

int main(){
    IOS;

    cin >> N >> M >> R;
    vector<int> graph[N+1];
    for(int i=0; i<M; ++i){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // visit neighboring vertices in the ascending order.
    for(int i=1; i<=N; ++i){
        sort(graph[i].begin(), graph[i].end());
        sort(graph[i].begin(), graph[i].end(), greater<int>());
    }

    int out[N+1] = { 0 };
    bool visited[N+1] = { false };

    bfs(R, graph, visited, out);

    for(int i=1; i<=N; ++i){
        cout << out[i] << endl;
    }

    return 0;
}
