/*
    https://www.acmicpc.net/problem/12176
    (dreary design 2)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

int T;
int cnt;
int K, V;

void solve(){
    cout << "Case #" << cnt << ": ";
    cout << (V+1)*(V+1)*(V+1) * (K-V+1) - V*V*V * (K-V) << endl;
}

void input(){
    cin >> T;
    for(cnt=1; cnt<=T; ++cnt){
        cin >> K >> V;
        solve();
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
