/*
    k-th shortest path distance
    https://www.acmicpc.net/problem/1854

    k-th dijkstra
    https://everenew.tistory.com/159
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define SIZE_N 1'001
#define SIZE_M 2'000'000
#define SIZE_K 100
#define SIZE_C 1'000
#define START_CITY 1

int n, m, k;
vector<pair<int, int>> graph[SIZE_N];   // pair<destination, positive edge weight>
int a, b, c;
priority_queue<int> shortest_distance_pq_max[SIZE_N];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq_min;
void dijkstra_kth(){
    shortest_distance_pq_max[START_CITY].push(0);
    pq_min.push({0, START_CITY});

    while(!pq_min.empty()){
        pair<int, int> current = pq_min.top();
        pq_min.pop();

        int current_vertex = current.second;
        int current_distance = current.first;

        // NOTE : check condition for faster implementation
        if(shortest_distance_pq_max[current_vertex].top() < current_distance){
            continue;
        }

        for(pair<int, int> next : graph[current_vertex]){
            int next_vertex = next.first;
            int edge_weight = next.second;
            int new_distance = current_distance + edge_weight;

            if(shortest_distance_pq_max[next_vertex].size() < k){
                shortest_distance_pq_max[next_vertex].push(new_distance);
                pq_min.push({new_distance, next_vertex});
            }
            else{
                int kth_distance = shortest_distance_pq_max[next_vertex].top();
                if(new_distance < kth_distance){
                    shortest_distance_pq_max[next_vertex].pop();
                    shortest_distance_pq_max[next_vertex].push(new_distance);
                    pq_min.push({new_distance, next_vertex});
                }
            }
        }
    }
}

void print_kth_shortest_distance(){
    for(int i=1; i<=n; ++i){
        if(shortest_distance_pq_max[i].size() < k){
            cout << -1 << endl;
        }
        else{
            cout << shortest_distance_pq_max[i].top() << endl;
        }
    }
}

void solve(){
    dijkstra_kth();

    print_kth_shortest_distance();
}

int main(){
    IOS;

    cin >> n >> m >> k;
    for(int i=0; i<m; ++i){
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    solve();

    return 0;
}
