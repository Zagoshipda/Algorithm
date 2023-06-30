/*
    two weights
    https://www.acmicpc.net/problem/12930
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define SIZE_N 20   // vertex range from 0...N-1
#define SIZE_WEIGHT 9
#define NODE_START 0
#define NODE_FINISH 1
#define NO_EDGE '.'
#define MAX_VALUE (INT_MAX / 2)
using t_iii = tuple<int, int,int>;          // graph
using t_iiii = tuple<int, int, int,int>;    // pq for dijkstra

int N;
string weight1, weight2;
vector<int> weight_matrix[SIZE_N][SIZE_N];
// vector<t_iii> graph[SIZE_N];    // <vertex, weight1, weight2>, can be regarded as undirected
vector<int> graph[SIZE_N];    // <vertex>, can be regarded as undirected
int shortest_path_cost = MAX_VALUE;

pair<int, int> shortest_path_weights[SIZE_N];
int min_cost[SIZE_N];
int min_diff[SIZE_N];

void initialize(){
    for(int i=0; i<N; ++i){
        shortest_path_weights[i] = {MAX_VALUE, MAX_VALUE};
        min_cost[i] = MAX_VALUE;
        min_diff[i] = MAX_VALUE;
    }
}

// TODO
void dp(){

}

priority_queue<t_iiii, vector<t_iiii>, greater<t_iiii> > pq_min;    // <cost, vertex, wegith1, weight2>
void dijkstra_pq_min(){
    shortest_path_weights[NODE_START] = {0, 0};
    pq_min.push({0, NODE_START, 0, 0});

    while(!pq_min.empty()){
        t_iiii current = pq_min.top();
        pq_min.pop();
        int current_vertex = get<1>(current);
        int current_cost = get<0>(current);

        if(current_vertex == NODE_FINISH){
            shortest_path_cost = current_cost;
            break;
        }

        int current_weight1 = get<2>(current);
        int current_weight2 = get<3>(current);

        // NOTE : running time may differ on the input
        if(current_weight1 > shortest_path_weights[current_vertex].first &&
            current_weight2 > shortest_path_weights[current_vertex].second){
            continue;
        }

        // for(t_iii next : graph[current_vertex]){
        for(int next : graph[current_vertex]){
            // int next_vertex = get<0>(next);
            // int edge_weight1 = get<1>(next);
            // int edge_weight2 = get<2>(next);
            int next_vertex = next;
            int edge_weight1 = weight_matrix[current_vertex][next_vertex].front();
            int edge_weight2 = weight_matrix[current_vertex][next_vertex].back();

            int old_weight1 = shortest_path_weights[next_vertex].first;
            int old_weight2 = shortest_path_weights[next_vertex].second;
            // int old_cost = old_weight1 * old_weight2;

            int new_weight1 = current_weight1 + edge_weight1;
            int new_weight2 = current_weight2 + edge_weight2;
            int new_cost = new_weight1 * new_weight2;

            // NOTE : condition for storing least (weight1 or weight2)
            if(new_weight1 < old_weight1 || new_weight2 < old_weight2){
                shortest_path_weights[next_vertex] = {min(old_weight1, new_weight1), min(old_weight2, new_weight2)};
                pq_min.push({new_cost, next_vertex, new_weight1, new_weight2});
            }
        }
    }
}

// NOTE : WRONG answer
priority_queue<t_iiii, vector<t_iiii>, less<t_iiii> > pq_max;
void dijkstra_pq_max(){
    min_cost[NODE_START] = 0;
    min_diff[NODE_START] = 0;
    pq_max.push({0, NODE_START, 0, 0});

    while(!pq_max.empty()){
        t_iiii current = pq_max.top();
        pq_max.pop();

        int current_vertex = get<1>(current);
        int current_cost = get<0>(current);
        int current_weight1 = get<2>(current);
        int current_weight2 = get<3>(current);
        int current_diff = abs(current_weight1 - current_weight2);

        // if(/*current_cost > min_cost[current_vertex] &&*/ current_diff > min_diff[current_vertex]){
        //     continue;
        // }

        for(int next_vertex : graph[current_vertex]){
            int edge_weight1 = weight_matrix[current_vertex][next_vertex].front();
            int edge_weight2 = weight_matrix[current_vertex][next_vertex].back();

            int next_weight1 = current_weight1 + edge_weight1;
            int next_weight2 = current_weight2 + edge_weight2;
            int next_cost = next_weight1 * next_weight2;
            int next_diff = abs(next_weight1 - next_weight2);

            if(next_cost < min_cost[next_vertex] || next_diff < min_diff[next_vertex]){
                min_cost[next_vertex] = min(next_cost, min_cost[next_vertex]);
                min_diff[next_vertex] = min(next_diff, min_diff[next_vertex]);
                pq_max.push({next_cost, next_vertex, next_weight1, next_weight2});
            }

        }
    }

    shortest_path_cost = min_cost[NODE_FINISH];
}

void print_minimum_cost(){
    if(shortest_path_cost >= MAX_VALUE){
        cout << -1 << endl;
    }
    else{
        cout << shortest_path_cost << endl;
    }
}

void solve(){
    initialize();

    // dp();

    dijkstra_pq_min();

    print_minimum_cost();
}

int main(){
    IOS;

    cin >> N;
    for(int i=0; i<N; ++i){
        cin >> weight1;
        for(int j=0; j<N; ++j){
            if(weight1[j] != NO_EDGE){
                graph[i].push_back(j);
                weight_matrix[i][j].push_back(weight1[j]-'0');
            }
        }
    }
    for(int i=0; i<N; ++i){
        cin >> weight2;
        for(int j=0; j<N; ++j){
            if(weight2[j] != NO_EDGE){
                weight_matrix[i][j].push_back(weight2[j]-'0');
            }
        }
    }
    // for(int from=0; from<N; ++from){
    //     for(int to=0; to<N; ++to){
    //         if(weight_matrix[from][to].size() > 0){
    //             int weight1 = weight_matrix[from][to].front();
    //             int weight2 = weight_matrix[from][to].back();
    //             graph[from].push_back({to, weight1, weight2});
    //         }
    //     }
    // }

    solve();

    return 0;
}
