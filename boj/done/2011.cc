/*
    https://www.acmicpc.net/problem/2011
    (alphacode)

    similar problem
        https://www.acmicpc.net/problem/2591
        (number card)

    solution
        https://www.acmicpc.net/source/19914616
        (palilo, 0 ms)
        https://www.acmicpc.net/source/4442115
        (goooora, 0 ms)
        https://www.acmicpc.net/source/4524172
        (helloneo, 0 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int MAX_DIGIT = 5000; // 10^4
const int MOD = 1'000'000;  // 10^6
const int NUM_A = 1;
const int NUM_Z = 26;

string cipher;
int dp[MAX_DIGIT + 1];
bool check_range(int num){
    return (NUM_A <= num && num <= NUM_Z);
}
void solve_dp(){
    int len = cipher.size();
    // if(cipher[0] - '0' == 0){
    //     cout << 0 << endl;
    //     return;
    // }

    dp[0] = 1;
    // dp[1] = 1;                  // WRONG
    dp[1] = cipher[0]-'0' > 0;  // AC
    int prev;
    int curr;
    for(int idx=1; idx<len; ++idx){
        prev = cipher[idx-1] - '0';
        curr = cipher[idx] - '0';
        if(!check_range(curr) && !check_range(prev * 10 + curr)){
            cout << 0 << endl;
            return;
        }

        if(check_range(curr)){
            dp[idx+1] += dp[idx];
        }
        if(prev && check_range(prev * 10 + curr)){
            dp[idx+1] += dp[idx-1];
        }
        dp[idx+1] %= MOD;
    }
    cout << dp[len] << endl;
}

void solve(){
    solve_dp();
}

void input(){
    cin >> cipher;
}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    input();

    solve();

    return 0;
}
