/*
    https://www.acmicpc.net/problem/18783
    (swapity swapity swap)

    similar problem
        https://www.acmicpc.net/problem/22863
        (recovery large)

        https://www.acmicpc.net/problem/3117
        (youtube)

    solutions
        https://www.acmicpc.net/source/20916682
        (alex9801, 16 ms)

        https://www.acmicpc.net/source/23969869
        (palilo, 16 ms) : ???
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

    Algorithm
        reverse the order ?

        IDEA : do M-step 1-time, find same rule for (repeating M-step) K-times

        - find (permutation) cycles,
        - take K modular the length of a cycle (remainder r = K % cycle),
        - place each item in each cycle using remainder r (process cycle r times)

    ex.
    1 2 3 4 5 6 7 (initial)

    1 5 4 3 2 6 7
    1 5 7 6 2 3 4 (M-step, 1-time)

    1 2 6 7 5 3 4
    1 2 4 3 5 7 6 (M-step, 2-time)

    ... (repetitive process)

*/

const int ARR_SIZE = 100'000;   // 10^5
const int MAX_PROCESS = 1'000'000'000;  // 10^9
const int NUM_RANGES = 100;  // 10^2
int N, M, K;
int L, R;

pair<int, int> ranges[NUM_RANGES + 1];  // (L_i, R_i)
int arr_1[ARR_SIZE + 1];
int arr_2[ARR_SIZE + 1];

void initialize(){
    for(int idx=1; idx<=N; ++idx){
        arr_1[idx] = idx;
        arr_2[idx] = idx;
    }
}

bool visited[ARR_SIZE + 1];
vector<int> graph[ARR_SIZE + 1];    // cycles graph
void dfs(int root, int pos){
    if(visited[pos]){
        return;
    }

    visited[pos] = true;
    graph[root].push_back(pos);
    dfs(root, arr_2[pos]);
}

void solve_1(){
    initialize();

    // 1-step simulation
    for(int idx=1; idx<=M; ++idx){
        // NOTE : [start, end)
        // reverse(arr_2 + ranges[idx].first, arr_2 + ranges[idx].second);     // WRONG
        reverse(arr_2 + ranges[idx].first, arr_2 + ranges[idx].second + 1); // AC
    }

    // dfs to find cycles
    for(int idx=1; idx<=N; ++idx){
        if(!visited[idx]){
            dfs(idx, idx);
        }
    }

    // apply (K % cycle - step) simulation (= K-step simulation) to each cycle
    for(int idx=1; idx<=N; ++idx){
        int len = graph[idx].size();
        if(len){
            int remainder = K % len;
            if(remainder){
                for(int jdx=0; jdx<len; ++jdx){
                    arr_1[graph[idx][jdx]] = graph[idx][(jdx + remainder) % len];
                }
            }
        }
    }

    for(int idx=1; idx<=N; ++idx){
        cout << arr_1[idx] << endl;
    }
}

void solve(){
    solve_1();
}

void input(){
    cin >> N >> M >> K;
    for(int i=1; i<=M; ++i){
        cin >> L >> R;
        ranges[i] = {L, R};
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
