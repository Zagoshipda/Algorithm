/*
    https://www.acmicpc.net/problem/2057
    (factorial factorization)

    similar prblem
        https://www.acmicpc.net/problem/1699
        (squares sum)

    solutions
        https://www.acmicpc.net/source/303139
        (wwiiiii, 0 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        N = a_1 ! + ... + a_M ! ? where a_i != a_j for all 1 <= i < j <= M

        NOTE : M is "NOT GIVEN" as a fixed number

    Algorithm
    Suppose N = 1...a_1 + 1...a_2 + ... + 1...a_M, for a_1 < a_2 < ... < a_M
            N = 1...a_1(1 + a_1+1....a_2 + ... + a_1+1...  a_M)

    observation : 1! + ... + n! < n * n! < (n+1)!
    => can use greedy ?
    => use each factorial numbers as bits

    DP ? greedy ?
    brute force
        20! > 1e18 => 2^20 brute force

    ex.
        5 = 1 + 2 ... (X)
        1! 1
        2! 2
        3! 6
        4! 24
        5! 120

        1
        2 3(1,2)
        6 7(1,6) 8(6,2)
        24 25(24,1) 26(24,2) 27(24,1,2) 30(24,6) ...
        120 120+(1,2,6,24) ...

*/

const ll MAX_NUM = 1'000'000'000'000'000'000;   // 10^18
ll N;

void solve_greedy(){
    vector<ll> factorials;
    factorials.push_back(1);    // 0!
    ll fact = 1;
    for(ll num=2; 0<fact && fact<=N; ++num){
        factorials.push_back(fact);
        fact *= num;
    }

    int len = factorials.size();
    int cnt = 0;
    for(int idx=len-1; N>0 && idx>=0; --idx){
        if(factorials[idx] <= N){
            N -= factorials[idx];
            ++cnt;
        }
    }

    if(N==0 && cnt){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}

void solve(){
    solve_greedy();
}

void input(){
    cin >> N;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
