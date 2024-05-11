/*
    https://www.acmicpc.net/problem/3067
    (Coins)

    similar problem
        https://www.acmicpc.net/problem/9084
        (Coin) : same problem
        https://www.acmicpc.net/problem/2293
        (coin 1)

    solution
        https://www.acmicpc.net/source/78937
        (WeissBlume, 0 ms) : implemented in solve_dp_3()
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

const int NUM_COINS = 20;
const int MAX_COST = 10'000;

int T;
int N;
int coins[NUM_COINS + 1];
int M;

int dp[NUM_COINS + 2][MAX_COST + 1];
void initialize(){
    for(int i=0; i<=NUM_COINS+1; ++i){
        for(int j=0; j<=MAX_COST; ++j){
            dp[i][j] = 0;
        }
    }
}

void solve_dp_knapsack(){
    initialize();

    dp[N+1][0] = 1;
    for(int idx=N; idx>=1; --idx){
        for(int cost=0; cost<=M; ++cost){
            dp[idx][cost] = dp[idx+1][cost];
            for(int cnt=1; cost - cnt * coins[idx] >= 0; ++cnt){
                dp[idx][cost] += dp[idx+1][cost - cnt * coins[idx]];
            }
        }
    }
    cout << dp[1][M] << endl;
}

int dp_2[MAX_COST + 1];

void initialize_2(){
    for(int i=0; i<=MAX_COST; ++i){
        dp_2[i] = 0;
    }
}

void solve_dp_2(){
    initialize_2();

    dp_2[0] = 1;
    for(int idx=N; idx>=1; --idx){
        // NOTE : accumulating value in ascending value order
        for(int cost=coins[idx]; cost<=M; ++cost){
            dp_2[cost] += dp_2[cost - coins[idx]];
        }
    }
    cout << dp_2[M] << endl;
}

void solve_dp_3(){
    initialize_2();

    dp_2[0] = 1;
    for(int idx=N; idx>=1; --idx){
        for(int cost=0; cost<=M-coins[idx]; ++cost){
            dp_2[cost + coins[idx]] += dp_2[cost];
        }
    }
    cout << dp_2[M] << endl;
}

void solve(){
    // solve_dp_knapsack();
    // solve_dp_2();
    solve_dp_3();
}

void input(){
    cin >> T;
    while(T--){
        cin >> N;
        for(int i=1; i<=N; ++i){
            cin >> coins[i];
        }
        cin >> M;
        solve();
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
