/*
    https://www.acmicpc.net/problem/22858
    (recovery small)

    similar problem
        https://www.acmicpc.net/problem/22863
        (recovery large)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    d_i -> i (index)
    i   : 1 2 3 4 5   cycle
    d_i : 4 3 1 2 5 : (1 4 2 3) (5)
          2 1 4 3 5
          3 4 2 1 5
          1 2 3 4 5 (1-cycle : 4-steps)

*/

const int NUM_CARD = 10'000;    // 10^4
const int MAX_NUM = 1'000'000;  // 10^6
const int MAX_SHUFFLE = 1'000;  // 10^3

int N, K;
int arr_s[NUM_CARD + 1];
int arr_d[NUM_CARD + 1];
int arr_p[NUM_CARD + 1];

bool visited[NUM_CARD + 1];
vector<int> graph_idx[NUM_CARD + 1];
void dfs(int root, int pos){
    if(visited[pos]){
        return;
    }

    visited[pos] = true;
    graph_idx[root].push_back(pos);
    dfs(root, arr_d[pos]);
}

void solve_1(){
    // find permutation cycles
    for(int idx=1; idx<=N; ++idx){
        if(!visited[idx]){
            dfs(idx, idx);
        }
    }

    for(int idx=1; idx<=N; ++idx){
        int len = graph_idx[idx].size();
        if(len){
            int remainder = K % len;
            if(len == 1){
                remainder = 1;
            }

            if(remainder){
                int shuffle = len - remainder;
                for(int jdx=0; jdx<len; ++jdx){
                    arr_p[graph_idx[idx][jdx]] = arr_s[graph_idx[idx][(jdx + shuffle) % len]];
                }
            }
            else{
                for(int jdx=0; jdx<len; ++jdx){
                    arr_p[graph_idx[idx][jdx]] = arr_s[graph_idx[idx][jdx]];
                }
            }
        }
    }

    for(int idx=1; idx<=N; ++idx){
        cout << arr_p[idx] << " ";
    }
    cout << endl;
}

void solve_2(){
    // find permutation cycles
    for(int idx=1; idx<=N; ++idx){
        if(!visited[idx]){
            dfs(idx, idx);
        }
    }

    for(int idx=1; idx<=N; ++idx){
        int len = graph_idx[idx].size();
        if(len){
            int remainder = K % len;
            // if(len == 1){
            //     remainder = 1;
            // }

            for(int jdx=0; jdx<len; ++jdx){
                arr_p[graph_idx[idx][(jdx + remainder) % len]] = arr_s[graph_idx[idx][jdx]];
            }
        }
    }

    for(int idx=1; idx<=N; ++idx){
        cout << arr_p[idx] << " ";
    }
    cout << endl;
}

void solve(){
    // solve_1();

    solve_2();
}

void input(){
    cin >> N >> K;
    for(int i=1; i<=N; ++i){
        cin >> arr_s[i];
    }
    for(int i=1; i<=N; ++i){
        cin >> arr_d[i];
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
