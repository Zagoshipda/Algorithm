/*
    https://www.acmicpc.net/problem/1916
    (minimum cost 1) : dijkstra

    similar problem
        https://www.acmicpc.net/problem/1753
        (shortest path)
        https://www.acmicpc.net/problem/11779
        (minimum cost 2)

    solutions
        https://www.acmicpc.net/source/9524683
        (zsx160, 24 ms) : using struct, instead of pair<>

        modified bellman-ford : O(N^2) dijkstra, not using a priority queue
        https://www.acmicpc.net/source/13556576
        (yeongjae8066, 24 ms)
        https://www.acmicpc.net/source/17605577
        (kwan765, 20 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int NUM_VERTEX = 1'000;   // 10^3
const int NUM_EDGE = 100'000;   // 10^5
const int MAX_WEIGHT = 100'000; // 10^5
const int INITIAL_COST = INT_MAX - 1;   // max cost ~ 10^3 * 10^5 ~ 10^8

using p_ll = pair<ll, ll>;
int N;
int M;
ll s, e, w;
int START_CITY, END_CITY;
vector<p_ll> graph[NUM_VERTEX + 1];   // (destination, weight)

priority_queue<p_ll, vector<p_ll>, greater<p_ll> > pq_min;  // (weight, destination)
ll min_cost[NUM_VERTEX + 1];
void solve_dijkstra(){
    for(int idx=0; idx<=NUM_VERTEX; ++idx){
        min_cost[idx] = INITIAL_COST;
    }
    min_cost[START_CITY] = 0;

    pq_min.push({0, START_CITY});
    while(!pq_min.empty()){
        auto [curr_cost, curr_pos] = pq_min.top();
        pq_min.pop();

        // early termination
        if(curr_pos == END_CITY){
            cout << min_cost[curr_pos] << endl;
            return;
        }
        if(min_cost[curr_pos] < curr_cost){
            continue;
        }

        for(auto [next_pos, edge_weight] : graph[curr_pos]){
            // relax
            int next_cost = min_cost[curr_pos] + edge_weight;
            if(next_cost < min_cost[next_pos]){
                min_cost[next_pos] = next_cost;
                pq_min.push({next_cost, next_pos});
            }
        }
    }
}

void solve(){
    solve_dijkstra();
}

void input(){
    cin >> N;
    cin >> M;
    for(int i=1; i<=M; ++i){
        cin >> s >> e >> w;
        graph[s].push_back({e, w});
    }
    cin >> START_CITY >> END_CITY;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
