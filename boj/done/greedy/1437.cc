/*
    https://www.acmicpc.net/problem/1437
    (number decomposition)

    similar problem
        https://www.acmicpc.net/problem/31443
        (maximum happiness)

    solution
        https://www.acmicpc.net/source/66566149
        (ksoosung77, 0 ms) : implemented in solve_recursive()
        https://www.acmicpc.net/source/44848081
        (sungheeboy, 0 ms) : iterative
        https://www.acmicpc.net/source/1203102
        (chatterboy, 0 ms) : iterative

        https://www.acmicpc.net/source/73989945
        (nflight11, 104 ms) : implemented in solve_1()

    reference
        https://oeis.org/A000792
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Algorithm
        WANT : maximize n^(x/n) = n^(1/n)x for fixed x

        => f(n) = n^(1/n) is maximum when n = 3
        proof
            logf(n) = (logn)/n
            (logf(n))' = (1/n*n - (logn))/n^2 = (1-logn)/n^2
                        or
                       = 1/n*1/n + (logn)(-1/n^2) = (1-logn)/n^2
                       = 0 if logn = 1
                       => n = e = 2.718... : maximum

        => divide into 3 as much as possible
*/

const int MAX_NUM = 1'000'000;  // 10^6
const int MOD = 10'007;

int N;

ll recursive(int num){
    // base case
    if(num <= 4){
        return num;
    }

    return 3 * recursive(num - 3) % MOD;
}

void solve_recursive(){
    cout << recursive(N) << endl;
}

void solve_1(){
    if(N == 0){
        cout << 0 << endl;
        return;
    }

    int remainder = N % 3;
    int cnt;
    int val = 1;
    if(remainder == 1){
        if(N > 1){
            cnt = (N - 4) / 3;
            val = 4;
        }
        else{
            cnt = 0;
            val = 1;
        }
    }
    else if(remainder == 2){
        cnt = (N - 2) / 3;
        val = 2;
    }
    else{
        cnt = N / 3;
    }

    for(int ith=1; ith<=cnt; ++ith){
        val *= 3;
        val %= MOD;
    }
    cout << val << endl;
}

void solve(){
    solve_1();

    solve_recursive();
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
