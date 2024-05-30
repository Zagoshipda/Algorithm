/*
    https://www.acmicpc.net/problem/11051
    (binomial coefficient 2)

    similar problem
        https://www.acmicpc.net/problem/11401
        (binomial coefficient 3)

    solution
        https://www.acmicpc.net/source/5212265
        (dajinstory, 0 ms) : brute forcing modular inverse, implemented in modular_inverse_2()

        https://www.acmicpc.net/source/8773437
        (piri007, 0 ms) : (N + x * MOD) / K (mod p)

        implemented in solve_dp_2()
            https://www.acmicpc.net/source/7305579
            (rdd6584, 0 ms) : using array[]
            https://www.acmicpc.net/source/7049292
            (kim1246, 0 ms) : using array[]
            https://www.acmicpc.net/source/4451079
            (goooora, 0 ms) : using array[2][]
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Algorithm
        (Fermat's little theorem)
        for prime p,
            x^p-2 * x = x^p-1 = 1 (mod p)
            x^p-2 = x^-1 = 1/x (mod p)

        (operation)
        x^-1 * y^-2 = (xy)^-1
            i.e. g(f(x), f(y)) = f(g(x, y)) for f(x) = x^-1, g(x, y) = x * y
        proof
            x^-1 = a => ax = 1 (mod p)
            y^-1 = b => by = 1 (mod p)
                        abxy = 1 (mod p)
                        ab = (xy)^-1 = x^-1 * y^-1

*/

const int MAX_NUM = 1'000;  // 10^3
const int MOD = 10'007;     // 10^4 + 7 : prime

int N, K;

ll modular_inverse(int num){
    ll inv = 1;
    for(int power=MOD-2, base=num; power; power>>=1, base=(base*base)%MOD){
        if(power & 1){
            inv = (inv * base) % MOD;
        }
    }
    return inv;
}

ll modular_inverse_2(int num){
    ll inv = 1;
    for(int power=1; power<=MOD-2; ++power){
        inv *= num;
        inv %= MOD;
    }
    return inv;
}

void solve_modular(){
    // preprocessing
    if(2 * K > N){
        K = N - K;
    }

    // calculate each part
    ll numerator = 1;
    ll denominator = 1;
    for(int choice=1; choice<=K; ++choice){
        numerator *= (N - choice + 1);
        numerator %= MOD;

        denominator *= choice;
        denominator %= MOD;
    }

    // take modular inverse
    // cout << (numerator * modular_inverse(denominator)) % MOD << endl;
    cout << (numerator * modular_inverse_2(denominator)) % MOD << endl;
}

int dp[MAX_NUM + 1][MAX_NUM + 1];
void solve_dp(){
    for(int num=1; num<=N; ++num){
        dp[num][0] = 1;
        for(int choice=1; choice<num; ++choice){
            dp[num][choice] = dp[num-1][choice-1] + dp[num-1][choice];
            dp[num][choice] %= MOD;
        }
        dp[num][num] = 1;
    }
    cout << dp[N][K] << endl;
}

int dp_2[MAX_NUM + 1];
void solve_dp_2(){
    dp_2[0] = 1;
    for(int num=1; num<=N; ++num){
        // for(int choice=1; choice<num; ++choice){    // WRONG
        for(int choice=num-1; choice>=1; --choice){ // AC
            dp_2[choice] += dp_2[choice - 1];
            dp_2[choice] %= MOD;
        }
        dp_2[num] = 1;
    }
    cout << dp_2[K] << endl;
}

void solve(){
    solve_modular();
    // solve_dp();
    // solve_dp_2();
}

void input(){
    cin >> N >> K;
}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    input();

    solve();

    return 0;
}
