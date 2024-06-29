/*
    https://www.acmicpc.net/problem/17427
    (sum of divisors 2)

    similar problem
        https://www.acmicpc.net/problem/17425
        (sum of divisors 1)
        https://www.acmicpc.net/problem/2247
        (real divisor)

    solution
        https://www.acmicpc.net/source/42833105
        (pianop, 0 ms)

    reference
        https://oeis.org/A024916
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int MAX_NUM = 1'000'000;  // 10^6

int N;

ll dp[MAX_NUM + 1];

void solve_1(){
    for(int num=1; num<=N; ++num){
        for(int val=num; val<=N; val+=num){
            dp[val] += num;
        }
        dp[num] += dp[num-1];
    }

    cout << dp[N] << endl;
}

void solve_2(){
    ll ans = 0;
    for(int num=1; num<=N; ++num){
        ans += num * (N / num);
    }
    cout << ans << endl;
}

void solve(){
    // solve_1();

    solve_2();
}

void input(){
    cin >> N;
}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    input();

    solve();

    return 0;
}
