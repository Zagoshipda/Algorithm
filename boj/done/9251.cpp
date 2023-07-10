/*
    LCS
    https://www.acmicpc.net/problem/9251
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define SIZE 1000
#define INITIAL_VALUE -1
string str_1, str_2;
int dp[SIZE+1][SIZE+1];

void input(){
    cin >> str_1 >> str_2;
}

void initialize(){
    for(int i=0; i<=SIZE; ++i){
        for(int j=0; j<=SIZE; ++j){
            dp[i][j] = INITIAL_VALUE;
        }
    }
}

int lcs_bottom_up(){

    for(int len_1=0; len_1<=str_1.length(); ++len_1){
        for(int len_2=0; len_2<=str_2.length(); ++len_2){
            if(len_1 <= 0 || len_2 <= 0){
                dp[len_1][len_2] = 0;
            }
            else{
                if(str_1[len_1-1] == str_2[len_2-1]){
                    dp[len_1][len_2] = 1 + dp[len_1-1][len_2-1];
                }
                else{
                    dp[len_1][len_2] = max(dp[len_1-1][len_2], dp[len_1][len_2-1]);
                }
            }

        }
    }

    return dp[str_1.length()][str_2.length()];
}

int lcs_top_down(int len_1, int len_2){

    if(len_1 <= 0 || len_2 <= 0){
        return dp[len_1][len_2] = 0;
    }

    if(dp[len_1][len_2] != INITIAL_VALUE){
        return dp[len_1][len_2];
    }

    if(str_1[len_1-1] == str_2[len_2-1]){
        return dp[len_1][len_2] = 1 + lcs_top_down(len_1-1, len_2-1);
    }
    else{
        return dp[len_1][len_2] = max(lcs_top_down(len_1-1, len_2), lcs_top_down(len_1, len_2-1));
    }
}

void solve(){
    initialize();
    cout << lcs_top_down(str_1.length(), str_2.length()) << endl;

    // cout << lcs_bottom_up() << endl;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
