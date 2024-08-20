/*
    https://www.acmicpc.net/problem/11724
    (number of connected components)

    similar problem
        https://www.acmicpc.net/problem/17197
        (fence planning)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define SIZE 1001
int N, M;
int u, v;
vector<int> graph[SIZE];
bool visited[SIZE];
queue<int> nodes;
int num;

void bfs(int start){
    nodes.push(start);
    visited[start] = true;

    while(!nodes.empty()){
        int current = nodes.front();
        nodes.pop();

        for(int next : graph[current]){
            if(!visited[next]){
                nodes.push(next);
                visited[next] = true;
            }
        }
    }
}

void calculate_number_of_connected_component(){
    for(int i=1; i<=N; ++i){
        if(!visited[i]){
            bfs(i);
            ++num;
        }
    }

    cout << num << endl;
}

void input(){
    cin >> N >> M;
    for(int i=0; i<M; ++i){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

int main(){
    IOS;

    input();

    calculate_number_of_connected_component();

    return 0;
}
