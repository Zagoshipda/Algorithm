/*
    https://www.acmicpc.net/problem/14430
    (mining)

    solutions
        https://www.acmicpc.net/source/38308841
        (cozyyg, 4 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

enum TYPES{
    EMPTY = 0,
    MINERAL = 1,
};
const int MAX_SIZE = 300;
const int NUM_MOVES = 2;
int N, M;
int map_matrix[MAX_SIZE + 1][MAX_SIZE + 1];
pair<int, int> moves[] = { {-1, 0}, {0, -1} };

bool check_range(int row, int col){
    return (1 <= row && row <= N) && (1 <= col && col <= M);
}

int dp[MAX_SIZE + 1][MAX_SIZE + 1];
void solve_dp(){
    for(int row=1; row<=N; ++row){
        for(int col=1; col<=M; ++col){
            int val = 0;
            for(int ith=0; ith<NUM_MOVES; ++ith){
                int prev_row = row + moves[ith].first;
                int prev_col = col + moves[ith].second;
                // if(check_range(prev_row, prev_col)){
                    val = max(val, dp[prev_row][prev_col]);
                // }
            }
            dp[row][col] = val + map_matrix[row][col];
        }
    }

    cout << dp[N][M] << endl;
}
void solve(){
    solve_dp();
}

void input(){
    cin >> N >> M;
    for(int row=1; row<=N; ++row){
        for(int col=1; col<=M; ++col){
            cin >> map_matrix[row][col];
        }
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
