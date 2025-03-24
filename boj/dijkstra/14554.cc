/*
    https://www.acmicpc.net/problem/14554
    (the other way)
*/

#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(false); std::cin.tie(nullptr);
#define ll long long
#define endl '\n'

using namespace std;

/*
    Specifiaction
        graph
        - undirected
        - weighted
        - positive weight
*/

using p_ll = pair<ll, ll>;

const ll NUM_VERTEX = 100'000;          // 10^5
const ll NUM_EDGE = 300'000;            // 3 * 10^5
const ll MIN_WEIGHT = 1;
const ll MAX_WEIGHT = 1'000'000'000;    // 10^9
const int MOD = 1'000'000'009;          // 10^9 + 9
const ll INF = MAX_WEIGHT * NUM_VERTEX + 1;     // 10^9 * 10^5 = 10^14

int N, M, S, E;
int A, B, C;

vector<p_ll> graph[NUM_VERTEX + 1];     // (vertex, weight)
bool visited[NUM_VERTEX + 1];
p_ll min_dist[NUM_VERTEX + 1];          // (dist, cnt)
priority_queue<p_ll, vector<p_ll>, greater<p_ll> > pq_min;    // (weight, vertex)

void initialize(){
    for(int vertex=1; vertex<=N; ++vertex){
        min_dist[vertex] = {INF, -1};
    }
}

void solve_dijkstra(){
    initialize();

    pq_min.push({0, S});
    min_dist[S] = {0, 1};

    while(!pq_min.empty()){
        auto [curr_weight, curr] = pq_min.top();
        pq_min.pop();

        if(curr == E){
            cout << min_dist[curr].second << endl;
            break;
        }

        if(visited[curr]){
            continue;
        }

        visited[curr] = true;

        for(auto [next, edge_weight] : graph[curr]){
            ll next_weight = min_dist[curr].first + edge_weight;
            if(next_weight < min_dist[next].first){
                // min_dist[next] = {next_weight, 1};  // WRONG
                min_dist[next] = {next_weight, min_dist[curr].second};
                pq_min.push({next_weight, next});
            }
            else if(next_weight == min_dist[next].first){
                // min_dist[next].second += 1;     // WRONG
                min_dist[next].second += min_dist[curr].second;
                min_dist[next].second %= MOD;
            }
            else{
                // do nothing.
            }
        }
    }
}

void solve(){
    solve_dijkstra();
}

void input(){
    cin >> N >> M >> S >> E;
    for(int ith=1; ith<=M; ++ith){
        cin >> A >> B >> C;
        graph[A].push_back({B, C});
        graph[B].push_back({A, C});
    }
}

int main(){

    input();

    solve();

    return 0;
}
