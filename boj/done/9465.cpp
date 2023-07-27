/*
    stickers
    https://www.acmicpc.net/problem/9465

    https://www.acmicpc.net/source/29143362         (prefix, 76ms)
    https://blog.naver.com/occidere/220786307316    (explanation)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define SIZE 100'000
#define RANGE 100
int T;
int n;
int stickers[2][SIZE + 1];
int dp[2][SIZE + 1];

void initialize(){
    for(int row=0; row<2; ++row){
        for(int col=0; col<=SIZE; ++col){
            dp[row][col] = 0;
        }
    }
}

/*
    SUBPROBLEMS
        [suffix] / prefix / substring (/ subsequence)
        dp[i][j] : maximum total score, for sheet of (stickers[i][j:], stickers[1-i][j+1:])
    RELATION
        1. tear off sticker[i][j] with its score
            only one choice for the next column dp[1-i][j+1]
        2. not tear off sticker[i][j]
            two choices for the next column dp[1-i][j+1], dp[i][j+1]
        dp[i][j] = max(stickers[i][j] + dp[1-i][j+1], dp[1-i][j+1], dp[i][j+1])
    TOPOLOGICAL ORDER
        j = n, n-1, n-2, ... , 2, 1, 0 (start from n for easier base case)
    BASE CASE
        dp[0][n] = 0, dp[1][n] = 0 (no stickers)
    ORIGINAL PROBLEM
        max(dp[0][0], dp[1][0]) : 2 choices (1st row or 2nd row) for the 1st element
    TIME COMPLEXITY
        2n subproblems, O(1) time (+, max) for each subproblem, O(n) total
*/
void solve(){
    // NOTE : calculate alternately
    for(int col=n-1; col>=0; --col){
        // NOTE : scores are non-negative [0...100] so we can optimize comparison
        // dp[0][col] = max({stickers[0][col] + dp[1][col+1], dp[0][col+1], dp[1][col+1]});
        dp[0][col] = max(stickers[0][col] + dp[1][col+1], dp[0][col+1]);
        // dp[1][col] = max({stickers[1][col] + dp[0][col+1], dp[0][col+1], dp[1][col+1]});
        dp[1][col] = max(stickers[1][col] + dp[0][col+1], dp[1][col+1]);
    }

    cout << max(dp[0][0], dp[1][0]) << endl;
}

/*
    SUBPROBLEMS
        suffix / [prefix] / substring (/ subsequence)
        dp[i][j] : maximum total score, by choosing sticker[i][j], for sheet of (stickers[i][j:], stickers[1-i][j:])
    RELATION
        tear off sticker[i][j] with its score, and move forward to next column diagonally
        possible next choices can be
            1. next column dp[1-i][j+1]
            2. next next column dp[1-i][j+2]
            (3. next next next column can be obtained from 1, by moving 3 times diagonally)
        dp[i][j] = max(stickers[i][j] + dp[1-i][j-1], stickers[i][j] + dp[1-i][j-2])
    TOPOLOGICAL ORDER
        j = 1, 2, ... , n-2, n-1, n
    BASE CASE
        j = 1 : dp[0][1] = stickers[0][1], dp[1][1] = stickers[1][1]
        j = 2 : dp[0][2] = dp[1][1] + stickers[0][2], dp[1][2] = dp[0][1] + stickers[1][2]
    ORIGINAL PROBLEM
        max(dp[0][n], dp[1][n]) : 2 choices (1st row or 2nd row) for the last(n-th) element
    TIME COMPLEXITY
        2n subproblems, O(1) time (+, max) for each subproblem, O(n) total
*/
void solve_2(){
    dp[0][0] = stickers[0][0];
    dp[1][0] = stickers[1][0];

    dp[0][1] = dp[1][0] + stickers[0][1];
    dp[1][1] = dp[0][0] + stickers[1][1];

    for(int col=2; col<n; ++col){
        dp[0][col] = stickers[0][col] + max(dp[1][col-1], dp[1][col-2]);
        dp[1][col] = stickers[1][col] + max(dp[0][col-1], dp[0][col-2]);
    }

    cout << max(dp[0][n-1], dp[1][n-1]) << endl;
}

void input(){
    cin >> T;
    while(T--){
        cin >> n;
        for(int row=0; row<2; ++row){
            for(int col=0; col<n; ++col){
                cin >> stickers[row][col];
            }
        }

        // solve();
        solve_2();
        initialize();
    }
}

int main(){
    IOS;

    input();

    return 0;
}
