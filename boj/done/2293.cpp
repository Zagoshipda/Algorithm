// https://debuglog.tistory.com/78

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define SIZE 100001
int n, k;
int cost[SIZE];
int dp[SIZE];   // number of ways for making value k

int main(){
    IOS;

    cin >> n >> k;
    for(int i=0; i<n; ++i){
        cin >> cost[i];
    }

    dp[0] = 1;
    for(int i=0; i<n; ++i){
        for(int j=cost[i]; j<=k; ++j){
            dp[j] += dp[j-cost[i]];
        }
        // for(int i=0; i<=k; ++i){
        //     cout << dp[i] << " ";
        // }
        // cout << endl;
    }

    cout << dp[k] << endl;

    return 0;
}
