/*
    https://www.acmicpc.net/problem/1260
    (dfs bfs)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    implemented in parallel
        dfs : stack
        bfs : queue
*/

const int NUM_VERTEX = 1'000;   // 10^3
const int NUM_EDGE = 10'000;    // 10^4

int N, M, V;
int a, b;

// undirected graph, can have multiple edges between two vertices
set<int> graph[NUM_VERTEX + 1];
bool visited_dfs[NUM_VERTEX + 1];
bool visited_bfs[NUM_VERTEX + 1];

void dfs_1(int start){
    visited_dfs[start] = true;
    cout << start << " ";

    for(int next : graph[start]){
        if(!visited_dfs[next]){
            dfs_1(next);
        }
    }
}

stack<int> stk;
void dfs_2(){
    // visited_dfs[V] = true;
    stk.push(V);

    while(!stk.empty()){
        int curr = stk.top();
        stk.pop();

        if(visited_dfs[curr]){
            continue;
        }
        visited_dfs[curr] = true;
        cout << curr << " ";

        // NOTE : visit small node first
        for(auto it=graph[curr].rbegin(); it!=graph[curr].rend(); ++it){
            int next = *it;
            if(!visited_dfs[next]){
                // visited_dfs[next] = true;    // WRONG
                stk.push(next);
            }
        }
    }
    cout << endl;
}

queue<int> nodes;
void bfs(){
    // visited_bfs[V] = true;
    nodes.push(V);

    while(!nodes.empty()){
        int node = nodes.front();
        nodes.pop();

        if(visited_bfs[node]){
            continue;
        }
        visited_bfs[node] = true;
        cout << node << " ";

        for(int next : graph[node]){
            if(!visited_bfs[next]){
                // NOTE : avoid visiting again
                // visited_bfs[next] = true;
                nodes.push(next);
            }
        }
    }
    cout << endl;
}

int main(){
    IOS;

    cin >> N >> M >> V;

    for(int ith=0; ith<M; ++ith){
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }

    // NOTE : print vertices in [visiting order] != [finishing order]
    // dfs_1(V);
    // cout << endl;

    dfs_2();

    bfs();

    return 0;
}
