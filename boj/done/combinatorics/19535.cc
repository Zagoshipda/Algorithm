/*
    https://www.acmicpc.net/problem/19535
    (size 4 tree)

    solution
        vertex degree & edges, implemented in solve_2()
            https://www.acmicpc.net/source/21246471
            (kdh9949, 80 ms) : author
            https://www.acmicpc.net/source/65458998
            (kep1er07, 68 ms) : only using vertex degree, edges from 2 vertices
            https://www.acmicpc.net/source/21246524
            (koosaga, 100 ms)
            https://www.acmicpc.net/source/31577259
            (jhwest2, 84 ms)
        dfs
            https://www.acmicpc.net/source/45351219
            (promis9, 208 ms) : visited[]
            https://www.acmicpc.net/source/21589262
            (jaeung95, 156 ms) : dfs(curr, prev), without visited[]

        dfs + tree DP, implemented in solve_dp()
            https://www.acmicpc.net/source/21297111
            (ploffer11, 200 ms) : visited[]
            https://www.acmicpc.net/source/21234737
            (YunGoon, 204 ms) : dfs(curr, prev), without visited[]
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Algorithm
        D-tree : from the center edge, choose 1 vertex from each end, then multiply
        G-tree : from the center vertex, choose 3 vertices among neighbors
*/

const int NUM_VERTEX = 300'000; // 3 * 10^5
const int NUM_EDGE = 300'000;   // 3 * 10^5
const int TREE_SIZE = 4;        // # of nodes

// struct Node{
//     int val;
//     vector<Node*> children;
// };

int N;
int u, v;
vector<int> graph[NUM_VERTEX + 1];
ll degrees[NUM_VERTEX + 1];

ll num_d = 0;
ll num_g = 0;
// ll comb[NUM_VERTEX + 1][TREE_SIZE];

void print_answer(){
    if(num_d > 3 * num_g){
        cout << 'D' << endl;
    }
    else if(num_d < 3 * num_g){
        cout << 'G' << endl;
    }
    else{
        cout << "DUDUDUNGA" << endl;
    }
}

void solve_1(){
    // for(int num=0; num<=N; ++num){
    //     comb[num][0] = 1;
    //     for(int choice=1; choice<=min(TREE_SIZE - 1, num); ++choice){
    //         comb[num][choice] = comb[num-1][choice-1] + comb[num-1][choice];
    //     }
    // }

    // calculate
    ll size_1, size_2;
    for(int node_1=1; node_1<=N; ++node_1){
        size_1 = graph[node_1].size();
        if(size_1 >= TREE_SIZE - 1){
            // num_g += comb[size_1][TREE_SIZE - 1];
            num_g += size_1 * (size_1-1) * (size_1-2) / 6;
        }

        // NOTE : choice of edge duplicated by the choice of 2 vertices
        for(int node_2 : graph[node_1]){
            // method 1. count by the vertex id
            // if(node_1 < node_2){
                // 192 ms
                // num_d += static_cast<ll>(graph[node_1].size() - 1) * (graph[node_2].size() - 1);

                // 168 ms
                size_2 = graph[node_2].size();
                num_d += (size_1 - 1) * (size_2 - 1);
            // }
        }
    }
    // method 2. just divide by 2
    num_d >>= 1;

    print_answer();
}

vector<pair<int, int> > edges;
void solve_2(){
    ll size_1, size_2;
    for(int node_1=1; node_1<=N; ++node_1){
        // size_1 = graph[node_1].size();  // 180 ms
        size_1 = degrees[node_1];       // 76 ms
        if(size_1 >= TREE_SIZE - 1){
            num_g += size_1 * (size_1 - 1) * (size_1 - 2) / 6;
            // num_g += size_1 * (size_1 - 1) * (size_1 - 2);
        }
    }
    // num_g /= 6;

    for(auto nodes : edges){
        auto [node_1, node_2] = nodes;
        // num_d += (graph[node_1].size() - 1) * (graph[node_2].size() - 1);
        num_d += (degrees[node_1] - 1) * (degrees[node_2] - 1);
    }

    print_answer();
}

ll dp[NUM_VERTEX + 1][TREE_SIZE];
bool visited[NUM_VERTEX];
void dfs(int node){
    dp[node][0] = 1;    // length 0 path : to itself

    ll len = graph[node].size();
    if(len >= TREE_SIZE - 1){
        num_g += len * (len - 1) * (len - 2) / 6;
    }

    for(int next : graph[node]){
        if(!visited[next]){
            // NOTE : dfs() visit first, calculate dp[] values later
            visited[next] = true;
            dfs(next);

            // num_d += dp[node][1] * dp[next][1];
            // num_d += dp[node][2] * dp[next][0];
            dp[node][1] += dp[next][0];
            dp[node][2] += dp[next][1];
            dp[node][3] += dp[next][2];
        }
    }

    // num_d += dp[node][3] + dp[node][2] * dp[node][1];   // WRONG : duplicated selection of vertices
    num_d += dp[node][3] + dp[node][2] * (dp[node][1] - 1);   // AC
    // num_d += dp[node][3];
}

void solve_dp(){
    visited[1] = true;
    dfs(1);

    print_answer();
}

void solve(){
    // solve_1();
    // solve_2();

    solve_dp();
}

void input(){
    cin >> N;
    for(int i=1; i<N; ++i){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);

        // ++degrees[u];
        // ++degrees[v];
        // // edges.push_back({u, v});    // 76 ms
        // edges.emplace_back(u, v);   // 72 ms
    }
}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    input();

    solve();

    return 0;
}
