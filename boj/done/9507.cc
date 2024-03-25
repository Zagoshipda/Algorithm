/*
    https://www.acmicpc.net/problem/9507
    (generations of tribbles)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int MAX_NUM = 67;
int t;
int n;

ll dp[MAX_NUM + 1];
void initialize(){
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int idx=4; idx<=MAX_NUM; ++idx){
        dp[idx] = dp[idx-1] + dp[idx-2] + dp[idx-3] + dp[idx-4];
    }
}

void solve(){
    cout << dp[n] << endl;
}

void input(){
    initialize();

    cin >> t;
    while(t--){
        cin >> n;
        solve();
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
