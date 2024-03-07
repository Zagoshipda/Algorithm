/*
    https://www.acmicpc.net/problem/13171
    (logarithmic exponential)

    solutions
        recursive solution, implemented in solve_recursive()
            https://www.acmicpc.net/source/14635882
            (lktgt, 0 ms)
            https://www.acmicpc.net/source/5750145
            (Juno, 0 ms)

        64 bit counting (sign-bit : 63 | 62...0), implemented in solve_3()
            https://www.acmicpc.net/source/7738832
            (peter1201, 0 ms)
            https://www.acmicpc.net/source/9374495
            (movie_jo, 0 ms)

        implemented in solve_4()
            https://www.acmicpc.net/source/16780887
            (namespace, 0 ms)
            https://www.acmicpc.net/source/8075564
            (anjupiter, 0 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    2^10 ~ 10^3
    10^18 ~ 2^60
*/

const int MOD = 1'000'000'007;
const int LEN = 70;
ll A;
ll X;
vector<int> powers;

void solve_1(){
    A %= MOD;

    ll val = A;
    powers.push_back(val);
    ll power = 2;
    // ll cnt = 1;

    while(power <= X){
        // NOTE : time exceeded
        // for(; cnt<=power; ++cnt){
        //     val *= A;
        //     val %= MOD;
        // }
        val *= val;
        val %= MOD;

        powers.push_back(val);
        power *= 2;
    }

    ll ans = 1;
    ll cur_idx;
    while(X){
        cur_idx = pow(2, powers.size()-1);
        if(cur_idx <= X){
            ans *= powers.back();
            ans %= MOD;
            X -= cur_idx;
        }

        powers.pop_back();
    }
    cout << ans << endl;
}

void solve_2(){
    bitset<LEN> binary(X);

    ll ans = 1;
    for(int i=0; i<LEN; ++i){
        A %= MOD;
        if(binary[i]){
            ans *= A;
            ans %= MOD;
        }
        A *= A;
    }

    cout << ans << endl;
}

void solve_3(){
    int MAX_BIT = 62;
    ll ans = 1;
    for(int bit=0; bit<=MAX_BIT; ++bit){
        A %= MOD;
        if((X >> bit) & 1){
        // if(X & ((ll)1 << bit)){
            ans *= A;
            ans %= MOD;
        }
        A *= A;
    }

    cout << ans << endl;
}

void solve_4(){
    ll ans = 1;
    for(ll power=X; power; power = power >> 1){ // bit shift-right
        A %= MOD;
        // if(power % 2){  // taking current (k-th) bit
        if(power & 1){  // taking current (k-th) bit
            ans *= A;
            ans %= MOD;
        }
        A *= A;
    }
    cout << ans << endl;
}

ll solve_recursive(ll power){
    if(power == 1){
        return A % MOD;
    }

    // if(power % 2){
    if(power & 1){
        return (A % MOD * solve_recursive(power-1)) % MOD;
    }
    else{
        ll val = solve_recursive(power >> 1);
        return (val % MOD * val) % MOD;
    }
}

void solve(){
    // solve_1();
    // solve_2();
    solve_3();
    // solve_4();

    // cout << solve_recursive(X) << endl;
}

void input(){
    cin >> A;
    cin >> X;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
