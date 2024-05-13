/*
    https://www.acmicpc.net/problem/22115
    (coffee)

    similar problem
        https://www.acmicpc.net/problem/1106
        (hotel)
        https://www.acmicpc.net/problem/7579
        (App)

    solution
        https://www.acmicpc.net/source/53529449
        (jshyun912, 12 ms) : fortran
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    S ubproblem
        dp[k] : max caffeine with k coffee
    R ecurrence relation
    T opological order
    B ase case
    O riginal problem
    T ime complexity

8 100
90 5 4 2 2 2 2 2

// 5

*/

const int NUM_COFFEE = 100;         // 10^2
const int MAX_CAFFEINE = 1'000;     // 10^3
const int MAX_SUM_CAFFEINE = NUM_COFFEE * MAX_CAFFEINE;     // 10^5

int N, K;
int coffee[NUM_COFFEE + 1];

int dp[NUM_COFFEE + 1];
int cnt[NUM_COFFEE + 1];
void solve_dp_wrong(){
    for(int idx=1; idx<=N; ++idx){
        for(int num=N; num; --num){
            dp[num] = max({
                dp[num],
                dp[num - 1] + coffee[idx],
            });
        }
    }

    // WRONG : finding "exactly" K
    for(int num=0; num<=N; ++num){
        if(dp[num] >= K){
            cout << num << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int dp_2[MAX_SUM_CAFFEINE + 1];
void solve_dp_2(){
    for(int i=1; i<=MAX_SUM_CAFFEINE; ++i){
        dp_2[i] = NUM_COFFEE + 1;
    }
    // dp_2[0] = 0;

    for(int idx=1; idx<=N; ++idx){
        for(int caffeine=K; caffeine>=coffee[idx]; --caffeine){
            dp_2[caffeine] = min({
                dp_2[caffeine],
                dp_2[caffeine - coffee[idx]] + 1,
            });
        }
    }

    if(dp_2[K] <= N){
        cout << dp_2[K] << endl;
    }
    else{
        cout << -1 << endl;
    }
}

void solve(){
    // solve_dp_wrong();
    solve_dp_2();
}

void input(){
    cin >> N >> K;
    for(int i=1; i<=N; ++i){
        cin >> coffee[i];
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
