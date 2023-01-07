#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int T;
int n;
int ans;

// set<int> cycle;

void dfs(int vertex, vector<int>* graph, int* visited){
    visited[vertex] = true;
    // cycle.insert(vertex);

    for(int next : graph[vertex]){
        if(!visited[next]){
            dfs(next, graph, visited);
        }
        else{   // visited[next]
            // auto search = cycle.find(vertex);
            // if(search != cycle.end()){
            ++ans;
            // return;
            // }
        }
    }
}

int main(){
    IOS;

    cin >> T;
    while(T--){
        cin >> n;
        // directed graph.
        vector<int> graph[n+1];
        int visited[n+1] = { false };

        int input;
        for(int i=1; i<=n; ++i){
            cin >> input;
            graph[i].push_back(input);
        }

        ans = 0;
        // cycle.clear();
        for(int i=1; i<=n; ++i){
            if(!graph[i].empty() && !visited[i]){
                dfs(i, graph, visited);
            }
        }

        cout << ans << endl;
    }

    return 0;
}
