/*
    directed weighted shortest path
    https://www.acmicpc.net/problem/1753

    Dijkstra
    greedy approach on graph with non-negative edge weights

    time complexity (depends on data structures that implements) a changeable priority queue CPQ
    CPQ : data structure that [normal priority queue + can modify/update the shortest path value]

    operation 1. build(X) - build priority queue with given set of vertices X
    operation 2. delete_min() - pop vertex with minimum shortest distance from the source s
                                only the vertex with the minimum shortest distance required
                                (we can sort vertices by the shortest distance from source s)
    operation 3. decrease_key(id, k) - update shortest distance(k) with id(indicates vertex in CPQ)

    implementations with time complexity, assuming n=V=O(E)
    1. array O(V + V^2 + E)
    2. binary heap O(V + VlogV + ElogV)
    3. fibonacci heap O(V + VlogV + E)
        data structure is much more difficult to implement compared to array or binary heap
    4. (special case) dial's algorithm, when weights are NOT big
        https://www.geeksforgeeks.org/dials-algorithm-optimized-dijkstra-for-small-range-weights/
        https://www.codingninjas.com/codestudio/library/dials-algorithm
        https://blog.naver.com/jinhan814/222511581119
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define SIZE_V 20'001
#define SIZE_E 300'000
#define SIZE_W 10
#define MAX_PATH_VALUE (INT_MAX / 2)
int V, E;
int K;
int u, v, w;

// NOTE : may NOT be a simple graph, multiple (directed) edges can exist between two vertices
vector<pair<int, int>> graph[SIZE_V];   // pair<outgoing vertex, weight>
int shortest_path_value[SIZE_V];        // shortest distance from source, changeable look-up table

// TODO : since weight <= 10,
// can apply bfs by converting weighted edges into unweighted edges
// with the following equation weight(n) = n * weight(1)


// method 1(BST, map). implement decrease_min() by update elements in map
    // since keys are shortest distances, and keys cannot be updated
    // (keys can only be inserted or removed)
    // we have to do the following 2 steps (order does not matter)
    // 1-1. remove the original key-value pair (vertex-old shortest distance)
    // 1-2. add the new key-value pair (vertex-updated shortest distance)
// method 2(HEAP, PQ). just push elements into priority queue, handle it later
    // conditional check required inside while loop


// NOTE : time complexity may vary on different data structures
    // PQ - based on heap
    // map - red-black tree, based on BST


void initialize(){
    for(int i=1; i<=V; ++i){
        shortest_path_value[i] = MAX_PATH_VALUE;
    }
}

void relax(int from, int to, int weight){
    shortest_path_value[to] = shortest_path_value[from] + weight;
}

// time exceeded
// naive implementation with direct access array, have to find the minimum shortest distance on each cycle
// int arr[SIZE_V];
bool visited[SIZE_V];

// pair<int, int> get_vertex_with_shortest_distance(){
int get_vertex_with_shortest_distance(){
    int distance = MAX_PATH_VALUE;
    int vertex = -1;
    for(int i=1; i<=V; ++i){
        if(!visited[i] && shortest_path_value[i] < distance){
            distance = shortest_path_value[i];
            vertex = i;
        }
    }

    // return {vertex, distance};
    return vertex;
}

void dijkstra_array(){

    shortest_path_value[K] = 0;

    while(true){
        int current_vertex, current_distance;
        // tie(current_vertex, current_distance) = get_vertex_with_shortest_distance();
        current_vertex = get_vertex_with_shortest_distance();
        if(current_vertex < 0){
            break;
        }
        current_distance = shortest_path_value[current_vertex];

        visited[current_vertex] = true;

        for(pair<int, int> next : graph[current_vertex]){
            int next_vertex = next.first;
            int edge_weight = next.second;
            int old_distance = shortest_path_value[next_vertex];
            int new_distance = shortest_path_value[current_vertex] + edge_weight;

            if(new_distance < old_distance){
                relax(current_vertex, next_vertex, edge_weight);
            }
        }
    }
}

// NOTE : normal priority queue cannot update shortest distances
// NOTE : need a data structure of min-heap (default cpp PQ STL : max-heap)
// 1. use custom comparison function compare with default PQ
// 2. use negative shortest distance (-distance) with defualt PQ


// it is NOT possible to update shortest distance using a normal priority queue (binary heap)
// priority queue with descending order, get last (smallest) element : min-heap
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq_min;
// pair<distance, vertex> sorted by distance(key)
void dijkstra_pq_min(){

    pq_min.push({0, K});
    shortest_path_value[K] = 0;

    while(!pq_min.empty()){
        pair<int, int> current = pq_min.top();
        pq_min.pop();

        int current_vertex = current.second;
        int current_distance = current.first;

        // handle cases such that vertex has already been processed (optional)
            // NOTE : algorithm correctness still holds without this condition,
            // just for efficient running time
        // NOTE : different path with the same shortest distance can be added to PQ
            // and this will pass the condition below
            // which will go through the for loop and and increase the running time
        if(shortest_path_value[current_vertex] < current_distance){
            continue;
        }

        for(pair<int, int> next : graph[current_vertex]){
            int next_vertex = next.first;
            int edge_weight = next.second;
            int distance = current_distance + edge_weight;
            if(shortest_path_value[next_vertex] > distance){
                relax(current_vertex, next_vertex, edge_weight);
                // NOTE : just push into priority queue
                pq_min.push({distance, next_vertex});
            }
        }
    }
}

// priority queue with ascending order, get last (largest) element : max-heap (defulat PQ)
priority_queue<pair<int, int>, vector<pair<int,int>>, less<pair<int, int>> > pq_max;
void dijkstra_pq_max(){
    pq_max.push({0, K});
    shortest_path_value[K] = 0;

    while(!pq_max.empty()){
        pair<int, int> current = pq_max.top();
        pq_max.pop();

        int current_vertex = current.second;
        int current_distance = -current.first;

        if(shortest_path_value[current_vertex] < current_distance){
            continue;
        }

        for(pair<int, int> next : graph[current_vertex]){
            int next_vertex = next.first;
            int edge_weight = next.second;
            int old_distance = shortest_path_value[next_vertex];
            int new_distance = shortest_path_value[current_vertex] + edge_weight;
            if(new_distance < old_distance){
                relax(current_vertex, next_vertex, edge_weight);
                pq_max.push({-new_distance, next_vertex});
            }
        }
    }
}


// NOTE : use map/set stl ---> consider time complexity
    // based on red-black tree (basically BST)
    // build : O(n * logn)
    // insert, find/search, remove : O(log n)
// map<int, int> pq_map;   // pair<distance, vertex> sorted by distance(key)
    // impossible since map is an associative container with unique keys
    // where here multiple vertices can have same shortest distance from the source s
    // i.e. multiple keys(shortest distances) can have the same value
// we can do similar approach of priority queue implementation by set STL
    // somewhat similar to a map with key as pair<shortest distance, vertex>
    // map<pair<vertex, path_value[vertex]>, path_value[vertex]>
// set STL : [sorted] set of [unique] objects, implemented as a red-black tree (basically BST)
set<pair<int, int>> pq_set; // pair<distance, vertex>

// pair<int, int> find_pair_with_shortest_distance(){
//     int distance = INT_MAX;
//     pair<int, int> ret;
//     // NOTE : const
//     // error: binding reference of type 'std::pair<int, int>&' to 'const std::pair<int, int>' discards qualifiers
//     for(const pair<int, int>& element : pq_set){
//         if(element.first < distance){
//             distance = element.first;
//             ret = element;
//         }
//     }
//     return ret;
// }

void dijkstra_pq_set(){

    pq_set.insert({0, K});
    shortest_path_value[K] = 0;

    while(!pq_set.empty()){
        // time exceeded
        // pair<int, int> current = find_pair_with_shortest_distance();
        pair<int, int> current = *(pq_set.begin());
        pq_set.erase(current);

        int current_vertex = current.second;
        int current_distance = current.first;

        for(pair<int, int> next : graph[current_vertex]){
            int next_vertex = next.first;
            int edge_weight = next.second;
            int new_distance = current_distance + edge_weight;
            int old_distance = shortest_path_value[next_vertex];
            if(old_distance > new_distance){
                relax(current_vertex, next_vertex, edge_weight);
                // update priority queue
                pq_set.erase({old_distance, next_vertex});
                pq_set.insert({new_distance, next_vertex});
            }
        }
    }
}

const int SIZE_BUCKET = SIZE_W*(SIZE_V-1)+1;
vector<int> bucket_queue_vector[SIZE_BUCKET];  // bucket[i] : list of vertices at a distance i from the source s
// bool visited[SIZE_V];

void dijkstra_dials_algorithm_vector(){

    int pos = 0;
    bucket_queue_vector[pos].push_back(K);
    shortest_path_value[K] = pos;

    // longest path can have at most V-1 edges, and each edge can be of weight SIZE_W
    const int MAX_POS = SIZE_W*(V-1)+1;
    // const int MAX_POS = SIZE_W*V+1;
    int current_vertex;
    while(true){
        while(pos < MAX_POS){
            if(!bucket_queue_vector[pos].empty()){
                current_vertex = *(bucket_queue_vector[pos].rbegin());
                bucket_queue_vector[pos].pop_back();
                // NOTE : algorithm still works without checking visited[] condition
                if(!visited[current_vertex]){
                    visited[current_vertex] = true;
                    break;
                }
            }
            else{
                ++pos;
            }
        }

        if(pos >= MAX_POS){
            break;
        }

        for(pair<int, int> next : graph[current_vertex]){
            int next_vertex = next.first;
            int edge_weight = next.second;
            int new_distance = shortest_path_value[current_vertex] + edge_weight;
            if(new_distance < shortest_path_value[next_vertex]){
                relax(current_vertex, next_vertex, edge_weight);
                bucket_queue_vector[new_distance].push_back(next_vertex);
            }
        }
    }
}


unordered_set<int> bucket_queue_set[SIZE_BUCKET];   // unordered set of unique objects of key, with average constant-time [search, insertion, and removal]
void dijkstra_dials_algorithm_set(){

    int pos = 0;
    bucket_queue_set[pos].insert(K);
    shortest_path_value[K] = pos;

    int current_vertex;
    const int MAX_POS = SIZE_W * (V-1) + 1;
    while(true){
        while(pos < MAX_POS){
            if(!bucket_queue_set[pos].empty()){
                auto iter = bucket_queue_set[pos].begin();
                current_vertex = *(iter);
                bucket_queue_set[pos].erase(iter);
                break;
            }
            ++pos;
        }

        if(pos >= MAX_POS){
            break;
        }

        for(pair<int, int> next : graph[current_vertex]){
            int next_vertex = next.first;
            int edge_weight = next.second;
            int new_distance = shortest_path_value[current_vertex] + edge_weight;
            if(new_distance < shortest_path_value[next_vertex]){
                relax(current_vertex, next_vertex, edge_weight);
                bucket_queue_set[new_distance].insert(next_vertex);
            }
        }
    }
}

// TODO : dijkstra implementation with fibonacci heap
void dijkstra_pq_fib(){

}

void print_shortest_path_value(){
    for(int i=1; i<=V; ++i){
        int value = shortest_path_value[i];
        if(value >= MAX_PATH_VALUE){
            cout << "INF" << endl;
        }
        else{
            cout << value <<endl;
        }
    }
}

void solve(){
    initialize();

    // dijkstra_array();

    // dijkstra_pq_min();

    // dijkstra_pq_max();

    // dijkstra_pq_set();

    // dijkstra_dials_algorithm_vector();
    dijkstra_dials_algorithm_set();

    // TODO
    // dijkstra_pq_fib();

    print_shortest_path_value();
}

int main(){
    IOS;

    cin >> V >> E;
    cin >> K;

    for(int i=0; i<E; ++i){
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    solve();

    return 0;
}
