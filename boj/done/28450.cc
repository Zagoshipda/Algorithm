/*
    https://www.acmicpc.net/problem/28450
    (conventional deadlift)

    solutions
        https://www.acmicpc.net/source/65027539
        (Green55, 96 ms) : prefix DP
        https://www.acmicpc.net/source/65107573
        (	djs100201, 92 ms) : prefix DP
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Algorithm
        take minimum cost from the start (1, 1) to the end (N, M) and compare it with the current value H
*/

const ll MAX_SIZE = 1'000;         // 10^3
const ll MAX_NUM = 100'000'000;    // 10^8
const ll INF = MAX_SIZE * MAX_SIZE * MAX_NUM + 1;   // 10^14
int N, M;
ll gym[MAX_SIZE + 1][MAX_SIZE + 1];
ll H;

ll dp[MAX_SIZE + 2][MAX_SIZE + 2];  // suffix
void solve_dp(){
    dp[N][M] = gym[N][M];   // base case

    ll val_1, val_2;
    for(int row=N; row>=1; --row){
        for(int col=M; col>=1; --col){
            if(row == N && col == M){
                continue;
            }

            val_1 = INF;
            val_2 = INF;
            if(row+1<=N){
                val_1 = dp[row+1][col];
            }
            if(col+1<=M){
                val_2 = dp[row][col+1];
            }

            dp[row][col] = min({
                val_1,
                val_2,
            }) + gym[row][col];
        }
    }

    if(H >= dp[1][1]){
        cout << "YES" << endl;
        cout << dp[1][1] << endl;
    }
    else{
        cout << "NO" << endl;
    }
}

void solve_bfs(){

}

void solve(){
    solve_dp();

    // solve_bfs();
}

void input(){
    cin >> N >> M;
    for(int row=1; row<=N; ++row){
        for(int col=1; col<=M; ++col){
            cin >> gym[row][col];
        }
    }
    cin >> H;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
