/*
    https://www.acmicpc.net/problem/6005
    (cow pinball)

    similar problem
        https://www.acmicpc.net/problem/1932
        (the triangle)

    solution
        https://www.acmicpc.net/source/2134436
        (functionx, 0 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int NUM_ROW = 25;
const int MAX_POINT = 3'000;    // 3 * 10^3

int R;
int pinball[NUM_ROW + 2][NUM_ROW + 2];

int dp[NUM_ROW + 1][NUM_ROW + 1];   // dp[a][b] max score starting from pinball[a][b]
void solve_dp(){
    for(int row=R; row>=1; --row){
        for(int col=1; col<=row; ++col){
            dp[row][col] = max(dp[row+1][col], dp[row+1][col+1]) + pinball[row][col];
        }
    }
    cout << dp[1][1] << endl;
}

void solve(){
    solve_dp();
}

void input(){
    cin >> R;
    for(int row=1; row<=R; ++row){
        for(int col=1; col<=row; ++col){
            cin >> pinball[row][col];
        }
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
