/*
    https://www.acmicpc.net/problem/13463
    (brexit)

    similar problem
        https://www.acmicpc.net/problem/19538
        (rumor)

    solution
        https://www.acmicpc.net/source/45968756
        (imax, 120 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        - If "at least half" of the trading partners of any given country Y leave the union, country Y will soon follow

        graph G
        - connected
        - undirected / bidirected
        - simple graph, with no self loops
*/

const int NUM_VERTEX = 200'000; // 2 * 10^5
const int NUM_EDGE = 300'000;   // 3 * 10^5

int C, P, X, L;
int A, B;
vector<int> graph[NUM_VERTEX + 1];
bool visited[NUM_VERTEX + 1];
int degrees[NUM_VERTEX + 1];

queue<int> nodes;
void solve_bfs(){
    nodes.push(L);
    visited[L] = true;

    while(!nodes.empty()){
        // int len = nodes.size();
        // while(len--){
            int curr = nodes.front();
            nodes.pop();

            if(curr == X){
                cout << "leave" << endl;
                return;
            }

            for(int next : graph[curr]){
                if(!visited[next]){
                    ++degrees[next];
                    if(graph[next].size() <= 2 * degrees[next]){
                        nodes.push(next);
                        visited[next] = true;
                    }
                }
            }
        // }
    }

    cout << "stay" << endl;
}

void solve(){
    solve_bfs();
}

void input(){
    cin >> C >> P >> X >> L;
    for(int i=1; i<=P; ++i){
        cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
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
