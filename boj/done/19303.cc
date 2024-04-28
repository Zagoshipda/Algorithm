/*
    https://www.acmicpc.net/problem/19303
    (aftermath)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    3 numbers
        (a + b + c) / 3
        3 abc / ab + bc + ca = 3 / 1/a + 1/b + 1/c

    Specification
        (1) a1 + ... + ak / k = a
        (2) k / 1/a1 + ... + 1/ak = h

    Algorithm
        (1) k = a1 + ... ak / a
        (2) k = h (1/a1 + ... + 1/ak)
        => (a1 + ... + ak) / a = h (1/a1 + ... + 1/ak)
        a1 + ... + ak = a*h (1/a1 + ... + 1/ak)
        left : integer => right : integer
        => a*h is a multiple of lcm(a1 ... ak), a1 ... ak are divisors of n
        => a*h is a multiple of n
        => choice of divisors a1 ... ak of n, can be found from a*h
        ah = n, 2n, ...
*/

const ll MAX_NUM = 1'000'000'000'000'000;   // 10^15

ll mean_a, mean_h;

void solve(){
    cout << mean_a * mean_h << endl;
}

void input(){
    cin >> mean_a >> mean_h;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
