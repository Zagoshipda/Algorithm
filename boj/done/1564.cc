/*
    https://www.acmicpc.net/problem/1564
    (factorial 5)

    similar problem
        https://www.acmicpc.net/problem/2553
        (last factorial number)

        https://www.acmicpc.net/problem/1676
        (trailing zeros on factorial)

    solutions
        https://www.acmicpc.net/source/42489231
        (dongwondavid, 4 ms)

        divide by 2's and 5's
            https://www.acmicpc.net/source/8816608
            (dotorya, 4 ms)
            https://www.acmicpc.net/source/7775756
            (ntopia, 4 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    ~ 10^6
    multiples of 5 : 10^6
*/

const int MIN_NUM = 9;
const int MAX_NUM = 1'000'000;      // 10^6
const ll DIV = 1'000'000'000'000;   // 10^12
const int MOD = 100'000;            // 10^5 : factorial "5"
int N;

void solve(){
    ll fact = 1;
    for(ll ith=1; ith<=N; ++ith){
        fact *= ith;

        // remove trailing zeros
        while(fact % 10 == 0){
            fact /= 10;
        }

        // remove leading bits
        // fact -= DIV * (fact / DIV);
        fact %= DIV;
    }

    // cout << fact % MOD << endl;  // leading zero problem
    // method 1. bit by bit
    fact %= MOD;
    for(int pos=1, val=10'000; pos<=5; ++pos, val/=10){
        cout << fact / val % 10;
    }
    cout << endl;

    // method 2. using string
    // string ans = to_string(fact);
    // int len = ans.size();
    // cout << ans.substr(len-5, len) << endl;
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
