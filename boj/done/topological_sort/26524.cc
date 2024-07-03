/*
    https://www.acmicpc.net/problem/26524
    (edge direction)

    reference
        https://u.acmicpc.net/2d5038ac-5b76-4cd2-8092-443a75ac4a2f/2022_mijeok_hwaktong_editorial.pdf
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int MOD = 1'000'000'007;  // 10^9 + 7
int n;

void solve(){
    ll ans = 1;
    for(int num=1; num<=n; ++num){
        ans *= num;
        ans %= MOD;
    }
    cout << ans << endl;
}

void input(){
    cin >> n;
}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    input();

    solve();

    return 0;
}
