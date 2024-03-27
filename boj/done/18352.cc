/*
    https://www.acmicpc.net/problem/18352
    (find K-distance)

    solutions
        https://www.acmicpc.net/source/25728100
        (gyeolse, 348 ms) : bfs, find distances to all vertices

        implemented in solve_bfs()
            https://www.acmicpc.net/source/34692292
            (1231js, 324 ms)
            https://www.acmicpc.net/source/40163700
            (alsidnf, 320 ms)

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int NUM_VERTEX = 300'000;         // 3 * 10^5
const int NUM_EDGE = 1'000'000;         // 10^6
const int MAX_DISTANCE = NUM_VERTEX;    // 3 * 10^5
const int INITIAL_DISTANCE = MAX_DISTANCE << 1;
int N, M, K, X;
int A, B;
vector<pair<int, int> > graph[NUM_VERTEX + 1];  // (destination, weight)

priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq_min;  // (distance, destination)
int min_dist[NUM_VERTEX + 1];
set<int> cities;
void solve_dijkstra(){
    for(int i=0; i<=NUM_VERTEX; ++i){
        min_dist[i] = INITIAL_DISTANCE;
    }
    min_dist[X] = 0;

    pq_min.push({0, X});
    while(!pq_min.empty()){
        auto [curr_dist, curr_pos] = pq_min.top();
        pq_min.pop();

        if(curr_dist == K){
            cities.insert(curr_pos);
        }

        if(min_dist[curr_pos] < curr_dist){
            continue;
        }

        for(auto [next_pos, edge_weight] : graph[curr_pos]){
            // relax
            if(min_dist[curr_pos] + edge_weight < min_dist[next_pos]){
                min_dist[next_pos] = min_dist[curr_pos] + edge_weight;
                pq_min.push({min_dist[next_pos], next_pos});
            }
        }
    }

    if(cities.empty()){
        cout << -1 << endl;
    }
    else{
        for(int city : cities){
            cout << city << endl;
        }
    }
}

void solve_bfs(){
    for(int idx=0; idx<=NUM_VERTEX; ++idx){
        min_dist[idx] = INITIAL_DISTANCE;
    }
    min_dist[X] = 0;

    queue<int> nodes;
    nodes.push(X);
    int cnt = -1;
    while(!nodes.empty()){
        ++cnt;
        if(cnt == K){
            set<int> cities;
            while(!nodes.empty()){
                cities.insert(nodes.front());
                nodes.pop();
            }
            for(int city : cities){
                cout << city << endl;
            }
            return;
        }
        int len = nodes.size();
        for(int ith=1; ith<=len; ++ith){
            int curr = nodes.front();
            for(auto [next, edge_weight] : graph[curr]){
                if(min_dist[curr] + edge_weight < min_dist[next]){
                    min_dist[next] = min_dist[curr] + edge_weight;
                    nodes.push(next);
                }
            }
            nodes.pop();
        }
    }
    cout << -1 << endl;
}

void solve(){
    // solve_dijkstra();

    solve_bfs();
}

void input(){
    cin >> N >> M >> K >> X;
    for(int i=1; i<=M; ++i){
        cin >> A >> B;
        graph[A].push_back({B, 1});
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
