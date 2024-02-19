/*
    https://www.acmicpc.net/problem/2591
    (number card)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int MIN_NUM = 1;
const int MAX_NUM = 34;
const int MAX_LENGTH = 40;
string card_number;

int dp[MAX_LENGTH + 2];


void solve_dp_suffix(){
    int len = card_number.size();

    dp[len+1] = 1;
    dp[len] = 1;
    for(int idx=len-1; idx>=1; --idx){
        int curr_num = card_number[idx-1] - '0';
        int next_num = card_number[idx] - '0';

        if(1<= curr_num && curr_num <= 9){
            dp[idx] += dp[idx+1];
        }

        if(10*curr_num + next_num <= MAX_NUM){
            dp[idx] += dp[idx+2];
        }
    }

    cout << dp[1] << endl;
}

void solve_dp_prefix(){
    int len = card_number.size();

    dp[0] = 1;
    dp[1] = 1;
    for(int idx=2; idx<=len; ++idx){
        int prev_num = card_number[idx-2] - '0';
        int curr_num = card_number[idx-1] - '0';

        assert(prev_num != 0 && curr_num != 0);

        if(1 <= curr_num && curr_num <= 9){
            dp[idx] += dp[idx-1];
        }
        if(0 < prev_num && 10*prev_num + curr_num <= MAX_NUM){
            dp[idx] += dp[idx-2];
        }
    }

    cout << dp[len] << endl;
}

void solve_dp_prefix_2(){
    int len = card_number.size();

    dp[0] = 1;
    dp[1] = 1;
    for(int idx=2; idx<=len; ++idx){
        int prev_num = card_number[idx-2] - '0';
        int curr_num = card_number[idx-1] - '0';

        dp[idx] += dp[idx-1];

        if(10*prev_num + curr_num <= MAX_NUM){
            dp[idx] += dp[idx-2];
        }
    }

    cout << dp[len] << endl;
}

void solve(){
    // solve_dp_suffix();
    // solve_dp_prefix();
    solve_dp_prefix_2();
}

void input(){
    cin >> card_number;
    for(int i=0; i<card_number.size(); ++i){
        assert((card_number[i] - '0') != 0);
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
