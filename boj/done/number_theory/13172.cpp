/*
    https://www.acmicpc.net/problem/13172
    (fractions sum)

    similar problem
        https://www.acmicpc.net/problem/11401
        (binomial coefficient 3)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Algorithm
        sum(Si / Ni) for i=1...M

        for prime p,
            x^p-2 * x = x^p-1 = 1 (mod p)
            x^p-2 = x^-1 (mod p)
*/

const int NUM_DICE = 10'000;
const int MOD = 1'000'000'007;
int M;
pair<ll, ll> dice[NUM_DICE + 1];    // (N-sided, S-sum)
ll N, S;

ll mod_inverse_iterative(ll val){
    ll ans = 1;
    ll base = val;
    for(ll power=MOD-2; power; power>>=1){
        if(power & 1){
            ans *= base;
            ans %= MOD;
        }
        base *= base;
        base %= MOD;
    }
    return ans;
}

void solve_mod_inverse(){
    ll sum = 0;
    for(int idx=1; idx<=M; ++idx){
        auto [denominator, numerator] = dice[idx];
        sum += (numerator * mod_inverse_iterative(denominator) % MOD);
        sum %= MOD;
    }

    cout << sum << endl;
}

void solve(){
    solve_mod_inverse();
}

void input(){
    cin >> M;
    for(int i=1; i<=M; ++i){
        cin >> N >> S;
        dice[i] = {N, S};
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
