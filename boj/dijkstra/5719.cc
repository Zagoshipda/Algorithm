/*
    https://www.acmicpc.net/problem/5719
    (almost shortest path)

    reference
        https://www.acmicpc.net/board/view/65679 : TLE, memory exceeded
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define endl '\n'


/*
    Specification
        graph
        - directed
        - weighted
        - simple

    Algorithm
        - find all shortest paths
        - modified graph = remove edges in those shortest paths
        - find shortest path on the modified graph

        V ~ 5 * 10^2
            V^2 ~ 25 * 10^4 > E
        E ~ 10^4 ~ 2^4 * 2^10 ~ 2^14

        dijkstra ~ ElogE ~ 10^4 * 14 ~ 10^5


        memory 256 MB ~ 256 * 10^6 ~ 3 * 10^8
*/

const int NUM_VERTEX = 500;
const int NUM_EDGE = 10'000;    // 10^4
const int MAX_WEIGHT = 1'000;   // 10^3
const int INF = INT_MAX >> 1;

using p_ii = std::pair<int, int>;
struct Edge{
    int start;
    int end;
    int weight;
};

int N, M;
int S, D;
int U, V, P;

std::vector<p_ii> graph_1[NUM_VERTEX << 1];       // (vertex, weight)
std::vector<p_ii> graph_2[NUM_VERTEX << 1];     // (vertex, weight)
Edge edges[NUM_EDGE << 1];
int edges_matrix[NUM_VERTEX << 1][NUM_VERTEX << 1];   //
bool is_removed[NUM_EDGE << 1];

std::vector<int> parents[NUM_VERTEX << 1];      // NOTE : can have multiple parents
// bool parents[NUM_VERTEX << 1][NUM_VERTEX << 1];      // 25 * 10^4, parents[from][to] : parent[to] == from ?
int min_dist_1[NUM_VERTEX << 1];
int min_dist_2[NUM_VERTEX << 1];

std::priority_queue<p_ii, std::vector<p_ii>, std::greater<p_ii> > pq_min_1; // (distance, vertex)
std::priority_queue<p_ii, std::vector<p_ii>, std::greater<p_ii> > pq_min_2; // (distance, vertex)

bool visited[NUM_VERTEX << 1];

void initialize(){
    for(int vertex=0; vertex<N; ++vertex){
        graph_1[vertex].clear();
        graph_2[vertex].clear();

        parents[vertex].clear();

        min_dist_1[vertex] = INF;
        min_dist_2[vertex] = INF;

        visited[vertex] = false;

        for(int to=1; to<=N; ++to){
            edges_matrix[vertex][to] = 0;
        }
    }
    for(int edge=1; edge<=M; ++edge){
        is_removed[edge] = false;
    }

    pq_min_1 = std::priority_queue<p_ii, std::vector<p_ii>, std::greater<p_ii> > ();
    pq_min_2 = std::priority_queue<p_ii, std::vector<p_ii>, std::greater<p_ii> > ();
}

void bfs(){
    std::queue<int> que;
    que.push(D);
    visited[D] = true;
    while(!que.empty()){
        int curr = que.front();
        que.pop();

        // WRONG
        // for(int parent : parents[curr]){
        //     if(!visited[parent]){
        //         is_removed[edges_matrix[parent][curr]] = true;
        //         que.push(parent);
        //         visited[parent] = true;
        //     }
        // }

        // AC
        for(int parent : parents[curr]){
            is_removed[edges_matrix[parent][curr]] = true;
            if(!visited[parent]){
                que.push(parent);
                visited[parent] = true;
            }
        }
    }
}


void dfs(int curr){
    if(curr == S){
        return;
    }

    if(visited[curr]){
        return;
    }

    visited[curr] = true;

    for(int parent : parents[curr]){
        is_removed[edges_matrix[parent][curr]] = true;
        dfs(parent);
    }
}

void solve_dijkstra(){
    // run dijkstra
    min_dist_1[S] = 0;
    pq_min_1.push({0, S});
    while(!pq_min_1.empty()){
        auto [curr_d, curr_v] = pq_min_1.top();
        pq_min_1.pop();

        if(min_dist_1[curr_v] < curr_d){
            continue;
        }

        if(curr_v == D){
            break;
        }

        for(p_ii next : graph_1[curr_v]){
            auto [next_v, edge_weight] = next;
            if(min_dist_1[curr_v] + edge_weight < min_dist_1[next_v]){
                min_dist_1[next_v] = min_dist_1[curr_v] + edge_weight;
                parents[next_v].clear();
                parents[next_v].push_back(curr_v);
                pq_min_1.push({min_dist_1[next_v], next_v});
            }
            else if(min_dist_1[curr_v] + edge_weight == min_dist_1[next_v]){
                parents[next_v].push_back(curr_v);
            }
        }
    }

    // remove shortest path
    bfs();
    // dfs(D);

    // build new graph
    for(int ith=1; ith<=M; ++ith){
        if(!is_removed[ith]){
            auto [from, to, weight] = edges[ith];
            graph_2[from].push_back({to, weight});
        }
    }

    // run dijkstra
    min_dist_2[S] = 0;
    pq_min_2.push({0, S});
    while(!pq_min_2.empty()){
        auto [curr_d, curr_v] = pq_min_2.top();
        pq_min_2.pop();

        if(min_dist_2[curr_v] < curr_d){
            continue;
        }

        if(curr_v == D){
            std::cout << curr_d << endl;
            return;
        }

        for(p_ii next : graph_2[curr_v]){
            auto [next_v, edge_weight] = next;
            if(min_dist_2[curr_v] + edge_weight < min_dist_2[next_v]){
                min_dist_2[next_v] = min_dist_2[curr_v] + edge_weight;
                pq_min_2.push({min_dist_2[next_v], next_v});
            }
        }
    }

    // impossible
    std::cout << -1 << endl;
}

void solve(){
    solve_dijkstra();
}

void input(){
    while(true){
        std::cin >> N >> M;
        if(N == 0 && M == 0){
            break;
        }

        initialize();

        std::cin >> S >> D;
        for(int ith=1; ith<=M; ++ith){
            std::cin >> U >> V >> P;
            edges[ith] = {U, V, P};
            edges_matrix[U][V] = ith;
            graph_1[U].push_back({V, P});
        }

        solve();
    }
}

int main(){
    input();

    // solve();

    return 0;
}
