/*
    https://www.acmicpc.net/problem/21318
    (piano gymnastics)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int ARR_SIZE = 100'000;   // 10^5
int N;
int arr[ARR_SIZE + 1];
int Q;
int x, y;
int dp[ARR_SIZE + 1];

void solve(){
    for(int ith=1; ith<N; ++ith){
        // dp[ith] = (arr[ith] > arr[ith+1]) ? 1 : 0;
        dp[ith] = (arr[ith] > arr[ith+1]);
    }
    for(int ith=1; ith<=N; ++ith){
        dp[ith] += dp[ith-1];
    }
}

void input(){
    cin >> N;
    for(int ith=1; ith<=N; ++ith){
        cin >> arr[ith];
    }

    solve();

    cin >> Q;
    for(int ith=1; ith<=Q; ++ith){
        cin >> x >> y;
        cout << dp[y-1] - dp[x-1] << endl;
    }
}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    input();

    // solve();

    return 0;
}
