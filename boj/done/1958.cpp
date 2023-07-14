/*
    LCS 3 : LC-Subsequence of 3 strings
    https://www.acmicpc.net/problem/1958

    optimizing space complexity
    https://www.acmicpc.net/source/20164195 (0ms)
    https://www.acmicpc.net/source/3044536  (0ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define SIZE 100
string str_1, str_2, str_3;
int dp[SIZE+1][SIZE+1][SIZE+1];
int dp_2[2][SIZE+1][SIZE+1];
// int lcs_length;

void input(){
    cin >> str_1 >> str_2 >> str_3;
}

void lcs_top_down(){

}

void lcs_bottom_up(){

    for(int len_1=1; len_1<=str_1.length(); ++len_1){
        for(int len_2=1; len_2<=str_2.length(); ++len_2){
            for(int len_3=1; len_3<=str_3.length(); ++len_3){
                if(str_1[len_1-1] == str_2[len_2-1] && str_2[len_2-1] == str_3[len_3-1]){
                    dp[len_1][len_2][len_3] = 1 + dp[len_1-1][len_2-1][len_3-1];

                }
                else{
                    int val_1 = dp[len_1-1][len_2][len_3];
                    int val_2 = dp[len_1][len_2-1][len_3];
                    int val_3 = dp[len_1][len_2][len_3-1];
                    // int val_4 = dp[len_1-1][len_2-1][len_3];
                    // int val_5 = dp[len_1-1][len_2][len_3-1];
                    // int val_6 = dp[len_1][len_2-1][len_3-1];
                    // dp[len_1][len_2][len_3] = max({val_1, val_2, val_3, val_4, val_5, val_6});
                    dp[len_1][len_2][len_3] = max({val_1, val_2, val_3});
                }
                // lcs_length = max(lcs_length, dp[len_1][len_2][len_3]);
            }
        }
    }

    // cout << lcs_length << endl;
    cout << dp[str_1.length()][str_2.length()][str_3.length()] << endl;
}

// NOTE : optimizing space complexity results faster running time (0ms)
void lcs_bottom_up_2(){
    int index = 0;
    for(int len_1=1; len_1<=str_1.length(); ++len_1){
        index = 1 - index;
        for(int len_2=1; len_2<=str_2.length(); ++len_2){
            for(int len_3=1; len_3<=str_3.length(); ++len_3){
                if(str_1[len_1-1] == str_2[len_2-1] && str_2[len_2-1] == str_3[len_3-1]){
                    dp_2[index][len_2][len_3] = 1 + dp_2[1-index][len_2-1][len_3-1];
                }
                else{
                    int val_1 = dp_2[1-index][len_2][len_3];
                    int val_2 = dp_2[index][len_2-1][len_3];
                    int val_3 = dp_2[index][len_2][len_3-1];
                    dp_2[index][len_2][len_3] = max({val_1, val_2, val_3});
                }
            }
        }
    }

    cout << dp_2[index][str_2.length()][str_3.length()] << endl;
}

void solve(){
    // lcs_bottom_up();

    lcs_bottom_up_2();
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
