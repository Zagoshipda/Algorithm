/*
    https://www.acmicpc.net/problem/11401
    (binomial coefficient 3)

    similar problem
        https://www.acmicpc.net/problem/13172
        (fractions sum) : modular inverse
        https://www.acmicpc.net/problem/11051
        (binomial coefficient 2)

    solution
        https://www.acmicpc.net/source/12722132
        (clrmt, 12 ms)
        https://www.acmicpc.net/source/10422857
        (sunhong, 8 ms)
        https://www.acmicpc.net/source/6217626
        (dajinstory, 68 ms) : recursive, implemented in modular_inverse_recursive()
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

    nCk = n (n-1) ... (n-(k-1)) / k (k-1) ... 2 1

    modular inverse
        k^p-1 = 1 (mod p)
        k^p-2 = p^-1 (mod p)

    DP
        nCk = n-1Ck-1 + n-1Ck
        1 2 3 ... N/2 ... 3 2 1 => O(N(1+N)) = O(N^2) = O(10^12)

    int ~ 2^32-1
    MOD ~ 2^31
*/

const int MAX_NUM = 4'000'000;
const ll MOD = 1'000'000'007;   // prime
const int MAX_BIT = 31;

ll N, K;

ll modular_inverse_iterative(ll num){
    ll ans = 1;
    ll base = num;
    int power = MOD - 2;
    for(int shift=0; shift<=MAX_BIT; ++shift){
        if((power >> shift) & 1){
            ans *= base;
            ans %= MOD;
        }
        base *= base;
        base %= MOD;
    }
    return ans;
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

void solve_1(){
    ll comb = 1;
    for(ll ith=1; ith<=K; ++ith){
        // comb *= (N-(ith-1)) * modular_inverse_iterative(K-(ith-1));   // ERROR : overflow (product of 3 numbers : comb, N-x, 1/K-x)
        comb *= ((N-(ith-1)) * modular_inverse_iterative(K-(ith-1)) % MOD);
        comb %= MOD;
    }
    cout << comb << endl;
}

void solve_2(){
    // 16 ms -> 8 ms
    if(K * 2 > N){
        K = N - K;
    }

    ll numerator = 1;
    ll denominator = 1;
    for(int choice=1; choice<=K; ++choice){
        numerator *= (N - choice + 1);
        numerator %= MOD;

        denominator *= choice;
        denominator %= MOD;
    }

    // cout << (numerator * modular_inverse_iterative(denominator)) % MOD << endl;
    cout << (numerator * modular_inverse_recursive(denominator, MOD-2)) % MOD << endl;
}

void solve(){
    // solve_1();  // 460 ms
    solve_2();  // 16 ms
}

void input(){
    cin >> N >> K;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
