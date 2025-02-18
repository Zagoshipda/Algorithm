/*
    https://www.acmicpc.net/problem/1167
    (diameter of tree)

    similar problem
        https://www.acmicpc.net/problem/1967
        (diameter of tree)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Algorithm
        max path distance ~ max distancee 10^5 * # of vertices 10^4 ~ 10^9
*/

const int NUM_VERTEX = 100'000;     // 10^5
const int MAX_DISTANCE = 10'000;    // 10^4

const int ROOT = 1;

using p_ii = pair<int, int>;

int V;
int src, dest, weight;

vector<p_ii> graph[NUM_VERTEX + 1]; // (node, weight)
bool visited[NUM_VERTEX + 1];
int diameter;

int dfs_1(int curr){
    // base case : leaf
    // if(graph[curr].size() == 1 && visited[graph[curr].front().first]){
    if(graph[curr].size() == 1 && curr != ROOT){
        return 0;
    }

    visited[curr] = true;

    priority_queue<int, vector<int>, less<int> > pq_max;
    pq_max.push(0);
    pq_max.push(0);

    for(auto [next, next_weight] : graph[curr]){
        if(!visited[next]){
            pq_max.push(dfs_1(next) + next_weight);
        }
    }

    int dist_1 = pq_max.top();
    pq_max.pop();
    int dist_2 = pq_max.top();
    diameter = max(diameter, dist_1 + dist_2);

    visited[curr] = false;

    return max(dist_1, dist_2);
}

int target_root;
void dfs_2(int curr, int dist){

    visited[curr] = true;
    if(diameter < dist){
        diameter = dist;
        target_root = curr;
    }

    for(auto [next, edge_weight] : graph[curr]){
        if(!visited[next]){
            dfs_2(next, dist + edge_weight);
        }
    }
}

void initialize(){
    diameter = 0;
    for(int node=1; node<=V; ++node){
        visited[node] = false;
    }
}

void solve_dfs(){
    // NOTE : can start from any node
    // bottom-up DP
    // dfs_1(ROOT);

    // 2-pass
    dfs_2(ROOT, 0);
    initialize();
    dfs_2(target_root, 0);

    cout << diameter << endl;
}

void bfs(int start){
    queue<p_ii> que;    // (node, dist)
    que.push({ start, 0 });

    while(!que.empty()){
        auto [curr, curr_dist] = que.front();
        que.pop();

        visited[curr] = true;
        if(diameter < curr_dist){
            diameter = curr_dist;
            target_root = curr;
        }

        for(auto [next, edge_weight] : graph[curr]){
            if(!visited[next]){
                que.push({ next, curr_dist + edge_weight });
            }
        }
    }

}

void solve_bfs(){
    bfs(ROOT);
    initialize();
    bfs(target_root);

    cout << diameter << endl;
}

void solve(){
    // solve_dfs();

    solve_bfs();
}

void input(){
    cin >> V;
    for(int ith=1; ith<=V; ++ith){
        cin >> src;
        while(true){
            cin >> dest;
            if(dest == -1){
                break;
            }
            cin >> weight;

            graph[src].push_back({dest, weight});
            // graph[dest].push_back({src, weight});
        }
    }
}

void debug(){

}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    // debug();

    input();

    solve();

    return 0;
}
