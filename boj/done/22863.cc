/*
    https://www.acmicpc.net/problem/22863
    (recovery large)

    similar problem
        https://www.acmicpc.net/problem/18783
        (swapity swapity swap)

        https://www.acmicpc.net/problem/22858
        (recovery small)

    solutions
        implemented in solve_2()
            https://www.acmicpc.net/source/35569748
            (cozyyg, 340 ms)
            https://www.acmicpc.net/source/35320302
            (kth990303, 336 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    ex.
    1 2 3 4 5
    arr_d       index graph
    4 3 1 2 5 : (1 4 2 3) (5) : permutation cycles
                index
    1 4 5 3 2   (1 2 3 4) (5) : arr_p
    3 5 1 4 2   (4 3 1 2) (5)
    4 1 3 5 2   (2 1 4 3) (5) : arr_s
    5 3 4 1 2   (3 4 2 1) (5)
    1 4 5 3 2   (1 2 3 4) (5) (1-cycle : 4-step)

    2 1 4 3 : (1 2) (3 4)

    1 1 2 2 : (1 1) (2 2)
    1 1 2 2 (1-cycle)

    1 2 2 2 (1 2) (2 2)
    2 1 2 2
    1 2 2 2 (1-cycle)


5 1
3 5 1 4 2
4 3 1 2 5

5 2
4 1 3 5 2
4 3 1 2 5

5 3
5 3 4 1 2
4 3 1 2 5

// 1 4 5 3 2

4 3
1 2 3 4
1 2 3 4

// 1 2 3 4


4 2
1 2 2 2
2 1 4 3

// 1 2 2 2

*/

const ll NUM_CARD = 1'000'000;                  // 10^6
const ll MAX_NUM = 1'000'000;                   // 10^6
const ll MAX_SHUFFLE = 1'000'000'000'000'000;   // 10^15

ll N, K;
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
    for(int idx=1; idx<=N; ++idx){
        if(!visited[idx]){
            dfs(idx, idx);
        }
    }

    for(int idx=1; idx<=N; ++idx){
        ll len = graph_idx[idx].size();
        if(len){
            ll remainder = K % len;
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
    for(int idx=1; idx<=N; ++idx){
        if(!visited[idx]){
            dfs(idx, idx);
        }
    }

    for(int idx=1; idx<=N; ++idx){
        ll len = graph_idx[idx].size();
        if(len){
            ll remainder = K % len;
            if(len == 1){
                remainder = 1;
            }

            // if(remainder){
                for(int jdx=0; jdx<len; ++jdx){
                    arr_p[graph_idx[idx][(jdx + remainder) % len]] = arr_s[graph_idx[idx][jdx]];
                }
            // }
            // else{
            //     for(int jdx=0; jdx<len; ++jdx){
            //         arr_p[graph_idx[idx][jdx]] = arr_s[graph_idx[idx][jdx]];
            //     }
            // }
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
