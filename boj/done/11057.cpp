/*
    ascent (non-strictly increasing digit) number
    https://www.acmicpc.net/problem/11057

    different subproblem definition
        dp[i][k] : number of ascent number with (length i, last number [at most] k)
        original problem : dp[N][9]
    https://www.acmicpc.net/source/3654688

    optimization 1.
    https://www.acmicpc.net/source/3526415
    https://www.acmicpc.net/source/2945237


    optimization 2.
    https://www.acmicpc.net/source/3532414

    optimization 3. (solve by calculation)
    https://www.acmicpc.net/source/2739760
    https://www.acmicpc.net/source/2328905

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define SIZE 1'000
#define MOD 10'007
int N;
int dp[SIZE + 1][10];
int ans = 0;

/*
    SUBPROBLEMS
        dp[i][k] : number of ascent number with (length i, last number k), number can start with 0
    RELATION
        regard as DAG path from dp[1][0] to dp[N][9],
        dp[i][k] = sum(dp[i-1][j] for j=0...k)

        optimization 2.
            (think of 2-dim dp array, length i as column, number k as row)
            dp[i][k] = sum(dp[i-1][j] for j=0...k) : [(i)th col (k)th row] made from [(i-1)th col (0...k)th row]
            dp[i][k-1] = sum(dp[i-1][j] for j=0...k-1)

            => dp[i][k] = dp[i][k-1] + dp[i-1][k]

        optimization 3. (solve by calculation)
            use only dp[10]
            accumulate as 1 + (1+2) + (1+2+3) + ...

    TOPOLOGICAL ORDER
        i = 1, 2, ... , n-1, n
    BASE CASE
        dp[1][0...9] = 1 (ascent number can start with 0)
    ORIGINAL PROBLEM
        sum(dp[N][j] for j=0...9)
    TIME COMPLEXITY
        length (n) * digit (0...9 possible, 10 total) subproblems,
        O(1) time (sum up to 10 numbers for dp[i-1][j] for j=0...k<10) for each subproblem,
        O(n) total
*/

void dp_1(){
    for(int i=0; i<10; ++i){
        dp[1][i] = 1;
    }

    for(int len=2; len<=N; ++len){
        for(int last=0; last<=9; ++last){
            for(int prev=0; prev<=last; ++prev){
                dp[len][last] += dp[len-1][prev];
                dp[len][last] %= MOD;
            }
        }
    }

    for(int i=0; i<=9; ++i){
        ans += dp[N][i];
        ans %= MOD;
    }
    cout << ans << endl;
}

void dp_2(){
    for(int i=0; i<=9; ++i){
        dp[1][i] = 1;
    }

    for(int len=2; len<=N; ++len){
        dp[len][0] = dp[len-1][0];
        for(int last=1; last<=9; ++last){
            dp[len][last] = dp[len][last-1] + dp[len-1][last];
            dp[len][last] %= MOD;
        }
    }

    for(int last=0; last<=9; ++last){
        ans += dp[N][last];
        ans %= MOD;
    }
    cout << ans << endl;
}

int cnt[10];
void dp_3(){
    cnt[0] = 1;
    for(int len=1; len<=N; ++len){
        for(int last=1; last<=9; ++last){
            cnt[last] += cnt[last-1];
            cnt[last] %= MOD;
        }
    }

    for(int i=0; i<=9; ++i){
        ans += cnt[i];
        ans %= MOD;
    }
    cout << ans << endl;
}

void solve(){
    // dp_1();

    dp_2();

    // dp_3();
}

void input(){
    cin >> N;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
