/*
    https://www.acmicpc.net/problem/11441
    (range sum)

    similar problem
        https://www.acmicpc.net/problem/11659
        (range sum 4)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int ARR_SIZE = 100'000;

int N;
int arr[ARR_SIZE + 1];  // 32 ms
int M;
int dp[ARR_SIZE + 1];   // 36 ms

void solve(){
    for(int idx=1; idx<=N; ++idx){
        // dp[idx] = dp[idx-1] + arr[idx];
        arr[idx] += arr[idx-1];
    }
}

void input(){
    cin >> N;
    for(int idx=1; idx<=N; ++idx){
        cin >> arr[idx];
    }

    solve();

    cin >> M;
    for(int ith=1; ith<=M; ++ith){
        int i, j;
        cin >> i >> j;
        // cout << dp[j] - dp[i-1] << endl;
        cout << arr[j] - arr[i-1] << endl;
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
