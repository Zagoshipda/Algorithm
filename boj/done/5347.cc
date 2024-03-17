/*
    https://www.acmicpc.net/problem/5347
    (lcm)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

int n;
ll a, b;

void solve(){
    cout << lcm(a, b) << endl;
}

void input(){
    cin >> n;
    while(n--){
        cin >> a >> b;
        solve();
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
