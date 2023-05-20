#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define MOD 1'000'000'000
#define CHECK 0b1'111'111'111
#define SIZE 1<<10
int N;
int dp[101][10][SIZE];  // dp[position][last number][bitmask]

void calculate_number_of_stair_numbers_dp(){
    for(int i=1; i<=9; ++i){
        dp[1][i][1<<i] = 1;
    }

    for(int pos=2; pos<=N; ++pos){
        for(int num=0; num<=9; ++num){
            for(int bit=0; bit<=CHECK; ++bit){
                if(num >= 1){
                    dp[pos][num][bit | 1<<num] += dp[pos-1][num-1][bit];
                    dp[pos][num][bit | 1<<num] %= MOD;
                }
                if(num <= 8){
                    dp[pos][num][bit | 1<<num] += dp[pos-1][num+1][bit];
                    dp[pos][num][bit | 1<<num] %= MOD;
                }
            }
        }
    }

    int ans = 0;
    for(int num=0; num<=9; ++num){
        ans += dp[N][num][CHECK];
        ans %= MOD;
    }
    cout << ans << endl;
}

int cnt[101][10][SIZE];
int calculate_number_of_stair_numbers_dfs(int pos, int last_number, int bit){
    if(pos >= N){
        return bit == CHECK ? 1 : 0;
    }

    // CHECK : cnt[pos][last_number][bit] mod === 0 possible ?
    if(cnt[pos][last_number][bit] > 0){
        return cnt[pos][last_number][bit];
    }

    int value = 0;
    if(last_number >= 1){
        value += calculate_number_of_stair_numbers_dfs(pos+1, last_number-1, 1<<last_number-1 | bit);
        value %= MOD;
    }
    if(last_number <= 8){
        value += calculate_number_of_stair_numbers_dfs(pos+1, last_number+1, 1<<last_number+1 | bit);
        value %= MOD;
    }
    // memoization
    cnt[pos][last_number][bit] = value;

    return value;
}

int main(){
    IOS;

    cin >> N;

    // 1. dp (bfs)
    // calculate_number_of_stair_numbers_dp();

    // 2. dfs
    int ans = 0;
    for(int num=1; num<=9; ++num){
        ans += calculate_number_of_stair_numbers_dfs(1, num, 1<<num);
        ans %= MOD;
    }
    cout << ans << endl;


    return 0;
}
