/*
    https://www.acmicpc.net/problem/11050
    (binomial coefficient 1)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

int N, K;

void solve(){
    ll val = 1;
    for(int i=0; i<K; ++i){
        val *= (N-i);
    }
    for(int i=1; i<=K; ++i){
        val /= i;
    }
    cout << val << endl;
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
