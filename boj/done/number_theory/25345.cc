/*
    https://www.acmicpc.net/problem/25345
    (game setting)

    similar problem
        https://www.acmicpc.net/problem/11051
        (binomial coefficient 2)
        https://www.acmicpc.net/problem/11401
        (binomial coefficient 3)

    solution
        https://www.acmicpc.net/source/45791758
        (dlalswp25, 0 ms) : N! / K! (N-K)! * 2^K-1 (mod p)

        https://www.acmicpc.net/source/45786052
        (jjang36524, 0 ms) : recursive

        custom struct
            https://www.acmicpc.net/source/49064492
            (xiaowuc1, 0 ms)
            https://www.acmicpc.net/source/45780907
            (ainta, 0 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Algorithm
        all numbers are distinct

        ex.
            1 6 7
            1 7 6
            6 7 1
            7 6 1
            6 1 7 (X)
            7 1 6 (X)
            5C3 * 4 = 10 * 4 = 40

        when impossible ?
            (condition A) if ai-1 > ai < ai+1 exists
        counting ?
            comb(N, K) * 2^(K-1)
            2 choices for each K-1...1

            [WRONG]
                    all - not(condition A)
                    k! - if ai-1 > ai > ai+1 or ai-1 < ai < ai+1 or ai-1 < ai > ai+1
                    k! - if sorted in decreasing or sorted in increasing or symmetric(condition A)
                    (condition A) = k! - 2 - (condition A)
                    => (condition A) = (k! - 2) / 2

                => comb(N, K) * (K! - (K! - 2) / 2)
                = comb(N, K) * (K...321 - (K...3 - 1))
                = comb(N, K) * (K...3 + 1) if K >= 3

                what if K <= 2
                    always possible so
                    comb(N, K) * K!
*/

const int MOD = 1'000'000'007;  // 10^9 + 7
const int MAX_NUM = 1'000'000'000;  // 10^9
const int ARR_SIZE = 2'000; // 2 * 10^3

int N, K;
int A;
// int arr[ARR_SIZE + 1];

ll modular_inverse_iterative(ll base){
    ll inv = 1;
    for(int power=MOD-2; power; power>>=1){
        if(power & 1){
            inv *= base;
            inv %= MOD;
        }
        base *= base;
        base %= MOD;
    }

    return inv;
}

ll modular_inverse_recursive(ll base, int power){
    if(power <= 1){
        return base;
    }

    ll inv = modular_inverse_recursive(base, power >> 1);
    inv *= inv;
    inv %= MOD;
    if(power & 1){
        inv *= base;
        inv %= MOD;
    }

    return inv;
}

void solve_combinatorics(){
    ll numerator = 1;
    ll denominator = 1;
    for(ll choice=1; choice<=K; ++choice){
        // numerator *= (N - K + choice);
        numerator *= (N - choice + 1);
        // numerator /= choice;    // WRONG
        numerator %= MOD;

        denominator *= choice;
        denominator %= MOD;
    }

    ll ans = (numerator * modular_inverse_iterative(denominator)) % MOD;
    // ll ans = (numerator * modular_inverse_recursive(denominator, MOD-2)) % MOD;

    for(int power=1; power<K; ++power){
        ans <<= 1;
        ans %= MOD;
    }

    cout << ans << endl;
}

void solve_dp(){
    // N ~ 10^3 is small so we can use DP to calculate
    // comb(N, K) : dp[n][k] = (dp[n-1][k-1] + dp[n-1][k]) % MOD
}

void solve(){
    solve_combinatorics();

    // solve_dp();
}

void input(){
    cin >> N >> K;
    for(int i=1; i<=N; ++i){
        // cin >> arr[i];
        cin >> A;
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
