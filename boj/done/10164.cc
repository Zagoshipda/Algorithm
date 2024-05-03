/*
    https://www.acmicpc.net/problem/10164
    (grid path)

    solution
        https://www.acmicpc.net/source/25973323
        (dngnogu, 0 ms) : DP except (row, col) where row + col == (K-1)/M + (K-1)%M
        https://www.acmicpc.net/source/4687159
        (jygkim, 0 ms) : product of # of paths, implemented in solve_dp_2()
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        - move right / down
        - must pass marked (O) block
*/

const int MAX_ROW = 15;
const int MAX_COL = 15;

int N, M, K;

int dp[MAX_ROW + 1][MAX_COL + 1];
void solve_dp_1(){
    dp[1][1] = 1;
    if(K){
        int target_row = (K-1) / M + 1;
        int target_col = (K-1) % M + 1;
        for(int row=1; row<=target_row; ++row){
            for(int col=1; col<=target_col; ++col){
                if(row == 1 && col == 1){
                    continue;
                }
                dp[row][col] = dp[row][col-1] + dp[row-1][col];
            }
        }
        for(int row=target_row; row<=N; ++row){
            for(int col=target_col; col<=M; ++col){
                if(row == target_row && col == target_col){
                    continue;
                }
                dp[row][col] = dp[row][col-1] + dp[row-1][col];
            }
        }
    }
    else{
        for(int row=1; row<=N; ++row){
            for(int col=1; col<=M; ++col){
                if(row == 1 && col == 1){
                    continue;
                }
                dp[row][col] = dp[row][col-1] + dp[row-1][col];
            }
        }
    }
    cout << dp[N][M] << endl;
}

void solve_dp_2(){
    dp[1][1] = 1;
    for(int row=1; row<=N; ++row){
        for(int col=1; col<=M; ++col){
            if(row == 1 && col == 1){
                continue;
            }
            dp[row][col] = dp[row][col-1] + dp[row-1][col];
        }
    }

    int target_row = K ? (K-1) / M + 1 : 1;
    int target_col = K ? (K-1) % M + 1 : 1;
    // int target_row = K ? (K-1) / M + 1 : N;
    // int target_col = K ? (K-1) % M + 1 : M;

    cout << dp[target_row][target_col] * dp[1 + N - target_row][1 + M - target_col] << endl;
}

void solve(){
    // solve_dp_1();
    solve_dp_2();
}

void input(){
    cin >> N >> M >> K;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
