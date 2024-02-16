/*
    https://www.acmicpc.net/problem/2463
    (cost)

    similar problem
        https://www.acmicpc.net/problem/17398
        (connection network division)

    solutions
        (parent[root] = -(# of descendants))
        https://mapocodingpark.blogspot.com/2020/02/BOJ-2463.html
        https://www.acmicpc.net/source/17942625
        (YunGoon, 36 ms)

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        cost(u, v) for all (u < v) pairs
        remove edge with smallest weight first

    1. sort the edge by their weight in descending order
    2. along the edge order, merge vertices
        if vertices (u < v) merged, calculate cost(u, v)
        NOTE : how to figure with (u < v) pair has combined ?
            => vertices in group(u) are all newly become connected with vertices in group(v)
            since we don't merge vertices in the same group,
            i.e. we only merge distinct groups of vertices,
            we only have to calculate cost(u < v) when union() happens
    3. sums up all cost(u, v) until all (u < v) pairs merged
        => until the last edge in descending order (edge with the smallest weight)

    NOTE : (u < v) pairs exist as much as O(N (N-1)) = O(N^2) = O(10^10)
        so naive search might not work within 1s

*/

// NOTE : use struct/class with meaningful member variables rather than meaningless tuples
struct Edge{
    int weight;
    int vertex_1;
    int vertex_2;

    // NOTE : all weights are different, sort in descending order
    bool operator<(const Edge& edge) const{
        // if(weight == edge.weight){
        //     return vertex_1 < edge.vertex_1;
        // }
        // else{
        return weight > edge.weight;
        // }
    }
};
using t_iii = tuple<int, int, int>;

const int MAX_VERTEX = 100'000;
const int MAX_EDGE = 100'000;
const int MAX_WEIGHT = 100'000;
const int MOD = 1'000'000'000;

int N, M;
int x, y, w;
// vector<t_iii> edges;    // (weight, vertex_1, vertex_2)
vector<Edge> edges;    // (weight, vertex_1, vertex_2)
ll path_cost;

class Disjoint_Set{
    private:
        int parent[MAX_VERTEX + 1];
        int sizes[MAX_VERTEX + 1];
    public:
        Disjoint_Set(){
            for(int i=0; i<=MAX_VERTEX; ++i){
                parent[i] = i;
                sizes[i] = 1;
            }
        }

        int get_size(int node){
            return sizes[node];
        }

        int find_set(int node){
            // optimization : path halving
            while(node != parent[node]){
                node = parent[node] = parent[parent[node]];
            }

            return node;
        }

        void union_set(int node_1, int node_2){
            int rep_1 = find_set(node_1);
            int size_1 = sizes[rep_1];

            int rep_2 = find_set(node_2);
            int size_2 = sizes[rep_2];

            // NOTE : considering the change of a group size
            if(rep_1 != rep_2){
                parent[rep_2] = rep_1;
                sizes[rep_1] += sizes[rep_2];
            }
        }
};

Disjoint_Set disjoint_set;
ll weights_sum;

void solve_disjoint_set(){
    // sort(edges.begin(), edges.end(), greater<t_iii>());
    sort(edges.begin(), edges.end());

    for(auto it=edges.begin(); it!=edges.end(); ++it){
        auto [w, x, y] = *it;
        int rep_x = disjoint_set.find_set(x);
        int rep_y = disjoint_set.find_set(y);

        if(rep_x != rep_y){
            int size_x = disjoint_set.get_size(rep_x);
            int size_y = disjoint_set.get_size(rep_y);

            // # of newly broken connections = choices from group(x) * choices from group(y)
            path_cost += (weights_sum * size_x * size_y);
            path_cost %= MOD;

            disjoint_set.union_set(x, y);
        }
        // NOTE : weight change should be applied after the calculation above
        weights_sum -= w;
        // ERROR : modular operation can affect the following weight_sum to be negative
        // weights_sum %= MOD;

        // cout << "   " << path_cost << endl;
    }

    cout << path_cost << endl;
}

void solve(){
    solve_disjoint_set();
}

void input(){
    cin >> N >> M;
    for(int i=0; i<M; ++i){
        cin >> x >> y >> w;
        edges.push_back({w, x, y});
        weights_sum += w;
        // ERROR : modular operation can affect the following weight_sum to be negative
        // weights_sum %= MOD;
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
