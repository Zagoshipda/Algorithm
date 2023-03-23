#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define SIZE 100001
int N;
int node1, node2;
const int ROOT = 1;
vector<int> tree[SIZE];
queue<int> nodes;
bool visited[SIZE];
int parent[SIZE];

void calculate_parent_node_bfs(int start){
    // for(int i=1; i<=N; ++i){
    //     for(int child : tree[i]){
    //         parent[child] = i;
    //     }
    // }

    nodes.push(start);
    visited[start] = true;
    while(!nodes.empty()){
        int current = nodes.front();
        nodes.pop();
        for(int child : tree[current]){
            if(!visited[child]){
                nodes.push(child);
                visited[child] = true;
                parent[child] = current;
            }
        }
    }
}

void calculate_parent_node_dfs(int current){
    visited[current] = true;
    if(tree[current].empty()){
        return;
    }
    // cout << "current " << current << endl;
    for(int child : tree[current]){
        if(!visited[child]){
            parent[child] = current;
            calculate_parent_node_dfs(child);
        }
    }
}

int main(){
    IOS;

    cin >> N;
    for(int i=0; i<N-1; ++i){
        cin >> node1 >> node2;
        tree[node1].push_back(node2);
        tree[node2].push_back(node1);
    }

    calculate_parent_node_bfs(ROOT);
    // calculate_parent_node_dfs(ROOT);

    for(int i=2; i<=N; ++i){
        cout << parent[i] << endl;
    }

    return 0;
}
