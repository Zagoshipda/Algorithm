/*
    https://www.acmicpc.net/problem/17197
    (fence planning)

        similar problem
            https://www.acmicpc.net/problem/11724
            (number of connected components)

        solution
            disjoint set
                https://www.acmicpc.net/source/28010637
                (p_ce1052, 56 ms)
                https://www.acmicpc.net/source/16048302
                (YunGoon, 48 ms)

                https://www.acmicpc.net/source/52939787
                (cko301, 44 ms) : only considering representatives
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        - communicate within their group but not with other groups
        - Two cows that moo at each-other belong to the same moo network
        - at least one moo network is "completely enclosed" by the fence
            - on the boundary of the rectangle count as being enclosed
        - smallest "perimeter" rectangle s.t. edges parallel to x-axis, y-axis

    Algorithm
        build group
        take (min, max) of x, y coordinates
        calculate perimeter of a group
        take min of perimeters

        => graph search (bfs / dfs) or disjoint set with (min, max)

*/

const int NUM_VERTEX = 100'000;     // 10^5
const int NUM_EDGE = 100'000;       // 10^5
const int MAX_POS = 100'000'000;    // 10^8

using p_ii = pair<int, int>;

int N, M;
p_ii arr[NUM_VERTEX + 1];
int a, b;

vector<int> graph[NUM_VERTEX + 1];
bool visited[NUM_VERTEX + 1];

void solve_bfs(){
    int min_perimeter = INT_MAX;
    for(int vertex=1; vertex<=N; ++vertex){
        if(!visited[vertex]){
            queue<int> nodes;
            nodes.push(vertex);
            int x_min = INT_MAX;
            int x_max = INT_MIN;
            int y_min = INT_MAX;
            int y_max = INT_MIN;

            while(!nodes.empty()){
                int curr = nodes.front();
                nodes.pop();

                x_min = min(x_min, arr[curr].first);
                x_max = max(x_max, arr[curr].first);
                y_min = min(y_min, arr[curr].second);
                y_max = max(y_max, arr[curr].second);

                for(int next : graph[curr]){
                    if(!visited[next]){
                        visited[next] = true;
                        nodes.push(next);
                    }
                }
            }

            // min_perimeter = min(min_perimeter, ((x_max - x_min) + (y_max - y_min)) << 1);
            min_perimeter = min(min_perimeter, (x_max - x_min) + (y_max - y_min));
        }
    }
    // cout << min_perimeter << endl;
    cout << (min_perimeter << 1) << endl;
}

void solve(){
    solve_bfs();
}

void input(){
    cin >> N >> M;
    for(int ith=1; ith<=N; ++ith){
        cin >> arr[ith].first >> arr[ith].second;
    }

    for(int ith=1; ith<=M; ++ith){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
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
