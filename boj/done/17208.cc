/*
    https://www.acmicpc.net/problem/17208
    (arbeit)

    solution
        https://www.acmicpc.net/source/62275150
        (smjun04, 36 ms) : 3-dim solution with index information added
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    DP
        2-dimensional knapsack problem
    S ubproblem
        (subproblem expansion)
        dp[i][j] : max # of orders with i burgers and j chips
    R
    T
    B
    O
    T
*/

const int NUM_QUERY = 100;  // 10^2
const int INF = NUM_QUERY + 1;
const int MIN_NUM = 1;
const int MAX_NUM = 300;    // 10^2

struct Order{
    int burger;
    int chips;
};

int N, M, K;
Order orders[NUM_QUERY + 1];

int dp[MAX_NUM + 1][MAX_NUM + 1];
void solve_dp(){
    for(int idx=1; idx<=N; ++idx){
        for(int cnt_1=MAX_NUM; cnt_1>=orders[idx].burger; --cnt_1){
            for(int cnt_2=MAX_NUM; cnt_2>=orders[idx].chips; --cnt_2){
                dp[cnt_1][cnt_2] = max({
                    dp[cnt_1][cnt_2],
                    dp[cnt_1 - orders[idx].burger][cnt_2 - orders[idx].chips] + 1,
                });
            }
        }
    }
    cout << dp[M][K] << endl;
}

void solve(){
    solve_dp();
}

void input(){
    cin >> N >> M >> K;
    for(int i=1; i<=N; ++i){
        cin >> orders[i].burger >> orders[i].chips;
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
