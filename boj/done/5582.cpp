/*
    Longest Common-[Substring]
    https://www.acmicpc.net/problem/5582

    NOTE : similar but [NOT the same] problem as LC-[Subsequence]
    https://www.acmicpc.net/problem/9251

    references
    https://www.geeksforgeeks.org/longest-common-substring-dp-29/
    (TODO) https://www.geeksforgeeks.org/find-the-longest-common-substring-using-binary-search-and-rolling-hash/
    (TODO) https://www.geeksforgeeks.org/suffix-tree-application-5-longest-common-substring-2/

    optimize space complexity of bottom-up DP
    https://www.acmicpc.net/source/568146   (24ms)
    https://www.acmicpc.net/source/106693   (24ms)

    suffix array
    https://www.acmicpc.net/source/50704549 (4ms)

    iterate recursion
    https://www.acmicpc.net/source/25505546 (120ms)

    brute-force
    https://www.acmicpc.net/source/3898960  (16ms)

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define SIZE 4000
#define INITIAL_VALUE -1
string str_1, str_2;
int dp_lcs_length[SIZE + 1][SIZE + 1];
int dp_lcs_length_2[2][SIZE + 1];
int ans = 0;

void input(){
    cin >> str_1 >> str_2;
}

void initialize(int len_1, int len_2){
    // for(int row=0; row<=len_1; ++row){
    //     for(int col=0; col<=len_2; ++col){
    //         dp_lcs_length[row][col] = INITIAL_VALUE;
    //     }
    // }

    // memset(dp_lcs_length, INITIAL_VALUE, sizeof(int) * (SIZE+1));
    memset(dp_lcs_length, INITIAL_VALUE, sizeof dp_lcs_length);
    // memset(dp_lcs_length_2, INITIAL_VALUE, sizeof dp_lcs_length_2);
}

// find LC-Substring that ends with str_1[len_1-1] and str_2[len_2-1]
int lcs_top_down_1(int len_1, int len_2){

    if(len_1 <= 0 || len_2 <= 0){
        return dp_lcs_length[len_1][len_2] = 0;
    }

    if(dp_lcs_length[len_1][len_2] != INITIAL_VALUE){
        return dp_lcs_length[len_1][len_2];
    }

    // CHECK : much faster when recursive call on ahead
    lcs_top_down_1(len_1-1, len_2);
    lcs_top_down_1(len_1, len_2-1);

    if(str_1[len_1-1] == str_2[len_2-1]){
        dp_lcs_length[len_1][len_2] = 1 + lcs_top_down_1(len_1-1, len_2-1);
        ans = max(ans, dp_lcs_length[len_1][len_2]);
    }
    else{
        dp_lcs_length[len_1][len_2] = 0;
    }

    // lcs_top_down_1(len_1-1, len_2);
    // lcs_top_down_1(len_1, len_2-1);

    return dp_lcs_length[len_1][len_2];
}

int lcs_top_down_2(int len_1, int len_2){

    if(len_1 <= 0 || len_2 <= 0){
        return dp_lcs_length[len_1][len_2] = 0;
    }

    if(dp_lcs_length[len_1][len_2] != INITIAL_VALUE){
        return dp_lcs_length[len_1][len_2];
    }

    if(str_1[len_1-1] == str_2[len_2-1]){
        return dp_lcs_length[len_1][len_2] = 1 + lcs_top_down_2(len_1-1, len_2-1);
    }
    else{
        return dp_lcs_length[len_1][len_2] = 0;
    }
}

// find LC-Substring that ends with str_1[len_1-1] and str_2[len_2-1]
void lcs_bottom_up_1(){

    for(int len_1=1; len_1<=str_1.length(); ++len_1){
        for(int len_2=1; len_2<=str_2.length(); ++len_2){
            if(str_1[len_1-1] == str_2[len_2-1]){
                // dp_lcs_length[len_1][len_2] = max({1 + dp_lcs_length[len_1-1][len_2-1], dp_lcs_length[len_1-1][len_2], dp_lcs_length[len_1][len_2-1]});

                dp_lcs_length[len_1][len_2] = 1 + dp_lcs_length[len_1-1][len_2-1];

                ans = max(ans, dp_lcs_length[len_1][len_2]);
            }
        }
    }
}

// NOTE : only need to store the previous state (optimizing space complexity)
void lcs_bottom_up_2(){

    int index = 0;
    for(int len_1=1; len_1<=str_1.length(); ++len_1){
        // NOTE : flip the state every iteration.
        index = 1 - index;
        for(int len_2=1; len_2<=str_2.length(); ++len_2){
            if(str_1[len_1-1] == str_2[len_2-1]){
                // NOTE : current state only depends on previous state.
                // dp_lcs_length_2[len_1&1][len_2] = 1 + dp_lcs_length_2[1-(len_1&1)][len_2-1];
                dp_lcs_length_2[index][len_2] = 1 + dp_lcs_length_2[1-index][len_2-1];
            }
            // NOTE : else condition necessary, initialize the state for the next iteration.
            else{
                // dp_lcs_length_2[len_1&1][len_2] = 0;
                dp_lcs_length_2[index][len_2] = 0;
            }
            // ans = max(ans, dp_lcs_length_2[len_1&1][len_2]);
            ans = max(ans, dp_lcs_length_2[index][len_2]);
        }
    }
}

void lcs_brute_force(){

    int lcs_length;
    for(int offset_1=1; offset_1<=str_1.length(); ++offset_1){
        lcs_length = 0;
        for(int pos_1=offset_1, pos_2=1; pos_1<=str_1.length() && pos_2<=str_2.length(); ++pos_1, ++pos_2){
            if(str_1[pos_1-1] == str_2[pos_2-1]){
                ans = max(ans, ++lcs_length);
            }
            else{
                lcs_length = 0;
            }
        }
    }

    for(int offset_2=1; offset_2<=str_2.length(); ++offset_2){
        lcs_length = 0;
        for(int pos_1=1, pos_2=offset_2; pos_1<=str_1.length() && pos_2<=str_2.length(); ++pos_1, ++pos_2){
            if(str_1[pos_1-1] == str_2[pos_2-1]){
                ans = max(ans, ++lcs_length);
            }
            else{
                lcs_length = 0;
            }
        }
    }
}

void solve(){

    // initialize(str_1.length(), str_2.length());

    // lcs_top_down_1(str_1.length(), str_2.length());

    // for(int len_1=1; len_1<=str_1.length(); ++len_1){
    //     for(int len_2=1; len_2<=str_2.length(); ++len_2){
    //         ans = max(ans, lcs_top_down_2(len_1, len_2));
    //     }
    // }


    // lcs_bottom_up_1();

    // lcs_bottom_up_2();


    lcs_brute_force();

    cout << ans << endl;



    // for(int row=0; row<=str_1.length(); ++row){
    //     for(int col=0; col<=str_2.length(); ++col){
    //         cout << dp_lcs_length[row][col] << " ";
    //     }
    //     cout << endl;
    // }

    // for(int row=0; row<=1; ++row){
    //     for(int col=0; col<=str_2.length(); ++col){
    //         cout << dp_lcs_length_2[row][col] << " ";
    //     }
    //     cout << endl;
    // }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
