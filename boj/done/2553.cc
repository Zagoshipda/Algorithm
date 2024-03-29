/*
    https://www.acmicpc.net/problem/2553
    (last factorial number)

    similar problem
        https://www.acmicpc.net/problem/1564
        (factorial 5)

        https://www.acmicpc.net/problem/1676
        (trailing zeros on factorial)

    solutions
        https://www.acmicpc.net/source/11160574
        (kth, 0 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    => just keep track of the last non-zero digit ?
    5's in ~20'000
        = 4000 + ... zeros in the last digits

    1! 1
    2! 2
    3! 6
    4! 4 24
    5! 2 120
    6! 2 720
    7! 4
    8! 2
    9! 8
    10! 8 3628800

    11! 8 39916800
    12! 6 479001600
    13! 8 6227020800
    14! 2 87178291200
    15! 8 1307674368000
    16! 8 20922789888000
    17! 6 355687428096000
    18! 8 6402373705728000
    19! 2 121645100408832000
    20! 4 2432902008176640000
*/

const int MIN_NUM = 1;
const int MAX_NUM = 20'000; // 2 * 10^4
// const int DIV = 100'000;    // WRONG : 10^5
const int DIV = 1'000'000;  // AC : 10^6
const int MOD = 10;

int N;

void solve(){
    // int num = 1; // error : int range : MAX_NUM * DIV ~ 2 * 10^9
    ll num = 1;
    for(ll ith=1; ith<=N; ++ith){
        num *= ith;
        while(num % 10 == 0){
            num /= 10;
        }

        // cout << DIV * (num/DIV) << " " << (DIV * num / DIV) << endl;
        // num -= (DIV * num / DIV);   // WRONG
        // num -= DIV * (num/DIV);     // AC

        num %= DIV;
    }

    // while(num % 10 == 0){
    //     num /= 10;
    // }
    cout << num % MOD << endl;
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
