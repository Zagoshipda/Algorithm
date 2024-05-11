/*
    https://www.acmicpc.net/problem/9084
    (Coin) : count the number of ways to make certain value k

    similar problem
        https://www.acmicpc.net/problem/3067
        (Coins) : same problem
        https://www.acmicpc.net/problem/2293
        (coin 1)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    2
    1 2
    2
    // 1+1 or 2
    0 1 2 dp
    1 0 0

*/

#define SIZE 20
#define SIZE_PRICE 10'000
#define SIZE_TARGET 10'000
int T;
int N;
int coin[SIZE];
int M;
int dp[SIZE_TARGET + 1];    // number of ways to make value k

void initialize(){
    memset(dp, 0, sizeof dp);
}

void calculate_number_of_ways_to_make_target_price(){
    dp[0] = 1;
    for(int i=0; i<N; ++i){
        // NOTE : accumulating result from the past, in ascending value order
        for(int value=coin[i]; value<=M; ++value){
            dp[value] += dp[value-coin[i]];
        }
    }

    cout << dp[M] << endl;
}

void input(){
    cin >> T;

    while(T--){
        cin >> N;
        for(int i=0; i<N; ++i){
            cin >> coin[i];
        }
        cin >> M;

        calculate_number_of_ways_to_make_target_price();

        initialize();
    }
}

int main(){
    IOS;

    input();

    return 0;
}
