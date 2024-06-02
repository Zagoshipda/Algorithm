/*
    https://www.acmicpc.net/problem/19538
    (rumor)

    similar problem
        https://www.acmicpc.net/problem/13463
        (brexit)

    solution
        https://www.acmicpc.net/source/21246425
        (Green55, 348 ms) : using time[] array
        https://www.acmicpc.net/source/21255145
        (YunGoon, 144 ms) : implemented in solve_bfs()
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        graph G
        - no self loops
        - undirected / bidirected

    Algorithm
        bfs with additional condition
*/

const int NUM_VERTEX = 200'000;     // 2 * 10^5
const int NUM_EDGE = 1'000'000;     // 10^6

int N, M;
int x;
vector<int> graph[NUM_VERTEX + 1];  // (destination)
// int degrees[NUM_VERTEX + 1];
bool visited[NUM_VERTEX + 1];
int rumors[NUM_VERTEX + 1];
queue<int> circulators;
int times[NUM_VERTEX + 1];

void initialize(){
    for(int idx=1; idx<=N; ++idx){
        if(!visited[idx]){
            times[idx] = -1;
        }
    }
    // error: no matching function for call to 'begin(std::queue<int>&)'
    // for(int x : circulators){
    //     times[x] = 0;
    //     visited[x] = true;
    // }
}

void print_answer(){
    for(int idx=1; idx<=N; ++idx){
        cout << times[idx] << " ";
    }
    cout << endl;
}

void solve_bfs(){
    initialize();

    int time = 0;
    while(!circulators.empty()){
        int len = circulators.size();
        ++time;
        // unordered_set<int> candidates;
        for(int i=1; i<=len; ++i){
            int curr = circulators.front();
            circulators.pop();

            for(int next : graph[curr]){
                if(!visited[next]){
                    ++rumors[next];
                    // candidates.insert(next);
                    if(graph[next].size() <= 2 * rumors[next]){
                        times[next] = time;
                        visited[next] = true;
                        circulators.push(next);
                    }
                }
            }
        }

        // for(const int& node : candidates){
        // // for(int node=1; node<=N; ++node){   // time exceeded
        //     if(!visited[node] && graph[node].size() && graph[node].size() <= 2 * rumors[node]){
        //         times[node] = time;
        //         visited[node] = true;
        //         circulators.push(node);
        //     }
        // }
    }

    print_answer();
}

void solve(){
    solve_bfs();
}

void input(){
    cin >> N;
    for(int node=1; node<=N; ++node){
        while(true){
            cin >> x;
            if(x == 0){
                break;
            }
            graph[node].push_back(x);
        }
    }
    cin >> M;
    for(int i=1; i<=M; ++i){
        cin >> x;
        circulators.push(x);
        // times[x] = 0;
        visited[x] = true;
    }
    // for(auto &x : circulators){
    //     cin >> x;
    // }
}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    input();

    solve();

    return 0;
}
