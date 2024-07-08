/*
    https://www.acmicpc.net/problem/20152
    (game addiction)

    solution
        https://www.acmicpc.net/source/23862331
        (pichulia, 0 ms) : comb(2n, n)/n+1
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    (H, H) ~ (N, N)

    (N-H, N-H) (grid / lattice cells)
    Catalan number C(N-H)
    NOTE : assume H < N, or take abs()

    C(n) = comb(2n, n)/n+1
*/

const int MAX_NUM = 30;

int H, N;

ll dp[MAX_NUM + 1];

void solve_dp(){
    dp[0] = 1;
    // dp[1] = 1;
    for(int num=1; num<=abs(N-H); ++num){
        for(int choice=0; choice<=num-1; ++choice){
            dp[num] += dp[choice] * dp[num-1 - choice];
        }
    }

    cout << dp[abs(N-H)] << endl;
}

void solve_2(){
    int num = abs(N-H);
    ll ans = 1;
    for(int choice=1; choice<=num; ++choice){
        ans *= (num + choice);
        ans /= choice;
    }

    cout << ans / (num+1) << endl;
}

void solve(){
    // solve_dp();

    solve_2();
}

void input(){
    cin >> H >> N;
}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    input();

    solve();

    return 0;
}
