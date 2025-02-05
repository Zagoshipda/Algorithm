/*
    https://hee96-story.tistory.com/28
    https://hee96-story.tistory.com/23
    https://nahwasa.com/entry/%EC%9D%B4%EB%B6%84-%EA%B7%B8%EB%9E%98%ED%94%84-bipartite-graph
    https://sanghoon9939.tistory.com/33
    https://00ad-8e71-00ff-055d.tistory.com/114
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define SIZE_V 20'001
#define SIZE_E 200'001
int K;
int V, E;
int u, v;
vector<int> graph[SIZE_V];
bool visited[SIZE_V];
bool vertex[SIZE_V];
// pair<int, int> edge[SIZE_E];

void dfs(int node){
    visited[node] = true;

    for(int next : graph[node]){
        if(!visited[next]){
            vertex[next] = !vertex[node];
            dfs(next);
        }
    }
}

bool check = true;
void dfs_and_check(int node){
    visited[node] = true;

    for(int next : graph[node]){
        if(visited[next]){
            if(vertex[next] == vertex[node]){
                check = false;
                return;
            }
        }
        else{
            vertex[next] = !vertex[node];
            dfs_and_check(next);
        }
    }
}

void bfs_and_check(int node){
    queue<int> nodes;
    nodes.push(node);
    visited[node] = true;

    while(!nodes.empty()){
        int current = nodes.front();
        nodes.pop();

        for(int next : graph[current]){
            if(visited[next]){
                if(vertex[next] == vertex[current]){
                    check = false;
                    return;
                }
            }
            else{
                vertex[next] = !vertex[current];
                visited[next] = true;
                nodes.push(next);
            }
        }
    }
}

void initialize(){
    check = true;

    for(int i=0; i<SIZE_V; ++i){
        graph[i].clear();
        visited[i] = false;
        vertex[i] = false;
    }
}

bool check_bipartite_graph(){

    // // method 1 (dfs)
    // for(int node=1; node<=V; ++node){
    //     if(!visited[node]){
    //         vertex[node] = true;
    //         dfs(node);
    //     }
    // }

    // bool ret = true;
    // for(int i=1; i<=E; ++i){
    //     if(vertex[edge[i].first] == vertex[edge[i].second]){
    //         ret = false;
    //         break;
    //     }
    // }

    // return ret;

    // method 2 (dfs)
    for(int node=1; node<=V; ++node){
        if(!visited[node]){
            vertex[node] = true;
            dfs_and_check(node);
        }
    }
    return check;

    // // method 3 (bfs)
    // for(int node=1; node<=V; ++node){
    //     if(!visited[node]){
    //         vertex[node] = true;
    //         bfs_and_check(node);
    //     }
    // }
    // return check;
}

int main(){
    IOS;

    cin >> K;
    while(K--){
        cin >> V >> E;

        for(int i=1; i<=E; ++i){
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
            // edge[i] = {u, v};
        }

        if(check_bipartite_graph()){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }

        initialize();
    }

    return 0;
}
