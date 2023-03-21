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

void print_parent_node(){
    // for(int i=1; i<=N; ++i){
    //     for(int child : tree[i]){
    //         parent[child] = i;
    //     }
    // }

    nodes.push(ROOT);
    visited[ROOT] = true;
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

    for(int i=2; i<=N; ++i){
        cout << parent[i] << endl;
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

    print_parent_node();

    return 0;
}
