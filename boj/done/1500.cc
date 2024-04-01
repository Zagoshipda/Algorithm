/*
    https://www.acmicpc.net/problem/1500
    (maximum product)

    solutions
        https://www.acmicpc.net/source/3865032
        (acebroad, 0 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

    Algorithm
        evenly distribute numbers
        a+b=k, ab=a(k-a) = -a^2+ka => think of it as graph

*/

int S, K;

void solve_greedy(){
    ll min_num = S / K;
    ll max_num = S / K + 1;
    int cnt_max_num = S % K;
    ll ans = 1;
    int ith;
    for(ith=1; ith<=cnt_max_num; ++ith){
        ans *= max_num;
    }
    for( ; ith<=K; ++ith){
        ans *= min_num;
    }
    cout << ans << endl;
}

void solve(){
    solve_greedy();
}

void input(){
    cin >> S >> K;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
