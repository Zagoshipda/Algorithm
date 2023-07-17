/*
    GCD of numbers with only 1's
    https://www.acmicpc.net/problem/1850
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

ll A, B;

ll gcd(ll a, ll b){
    if(b <= 0){
        return a;
    }

    return gcd(b, a%b);
}

void input(){
    cin >> A >> B;
}

void solve(){
    ll _gcd = gcd(max(A, B), min(A, B));

    // 1. wrong answer
    // ll ans = 0;
    // for(ll i=0; i<_gcd; ++i){
    //     ans *= 10;
    //     ans += 1;
    // }
    // cout << ans << endl;

    // 2. (180ms)
    // for(int i=0; i<_gcd; ++i){
    //     cout << 1;
    // }
    // cout << endl;

    // 3. (20ms)
    // string str;
    // for(int i=0; i<_gcd; ++i){
    //     // += : Appends additional characters to the string.
    //     str += '1';
    //     // + : string containing characters from lhs followed by the characters from rhs.
    //     // str = str + '1';    // time exceeded at 19%
    // }
    // cout << str << endl;

    // 4. (8ms)
    cout << string(_gcd, '1') << endl;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
