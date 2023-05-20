#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define SIZE_COIN 101
#define SIZE_TARGET 10'001
int n, k;
int coin[SIZE_COIN];
int dp[SIZE_TARGET];

void calculate_minimum_number_of_coin(){

    // initialize
    for(int i=1; i<=k; ++i){
        dp[i] = SIZE_TARGET;
    }
    dp[0] = 0;

    // calculate dp
    for(int i=0; i<n; ++i){
        for(int sum=coin[i]; sum<=k; ++sum){
            dp[sum] = min(dp[sum], dp[sum - coin[i]] + 1);
        }
    }

    if(dp[k] >= SIZE_TARGET){
        cout << -1 << endl;
    }
    else{
        cout << dp[k] << endl;
    }
}

int main(){
    IOS;

    cin >> n >> k;
    for(int i=0; i<n; ++i){
        cin >> coin[i];
    }

    calculate_minimum_number_of_coin();

    return 0;
}
