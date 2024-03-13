/*
    https://www.acmicpc.net/problem/15489
    (pascal triangle)

    similar problem
        https://www.acmicpc.net/problem/16395
        (pascal triangle)

    solutions
        https://www.acmicpc.net/source/50275244
        (faang12594, 108 ms) : brute force using python comb(n, r) library

        https://www.acmicpc.net/source/32858365
        (4011hjs, 0 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int MAX_ROW = 30;
const int MAX_COL = 30;

int R, C, W;

int dp[MAX_ROW + 1][MAX_COL + 1];   // dp[row][col] = row-1Ccol-1

void calculate_combination(){
    dp[0][0] = 1;
    for(int row=1; row<=MAX_ROW; ++row){
        for(int col=1; col<=row; ++col){
            dp[row][col] = dp[row-1][col-1] + dp[row-1][col];
        }
    }
}

void solve(){
    calculate_combination();

    int sum = 0;
    for(int row=R; row<=R+(W-1); ++row){
        for(int col=C; col<C+(row-R+1); ++col){
            sum += dp[row][col];
        }
    }
    cout << sum << endl;
}

void input(){
    cin >> R >> C >> W;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
