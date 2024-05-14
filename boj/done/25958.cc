/*
    https://www.acmicpc.net/problem/25958
    (beautiful number)

    similar problem
        https://www.acmicpc.net/problem/2293
        (coin 1)

    solution
        https://www.acmicpc.net/source/54982851
        (wider93, 4 ms) : dp when calculating digit sums
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        beautiful number
            digit sum is a divisor
            a1...an / a1+...+an
        1...9
        1X : 10+x / x+1
            10 12
        2X : 20+x / x+1
            20 21 24 27
        3X : 30+x / x+3
            30 36
        4X : 40+x / x+4
            40 42 45 48
        5X : 50+x / x+5
            50 54
            60 61 62 63 64 65 66 67 68 69
            ...
        => just brute force to find beautiful numbers

*/

const int MAX_NUM = 5000;   // 10^4
const int BASE = 10;

int M, K;

vector<int> beautifuls;
void find_beautiful_numbers(){
    for(int num=1; num<=M; ++num){
        int digit_sum = 0;
        int val = num;
        while(val){
            digit_sum += val % BASE;
            val /= BASE;
        }
        if(num % digit_sum == 0){
            beautifuls.push_back(num);
        }
    }
}

ll dp[MAX_NUM + 1];
void solve_dp_1(){
    int len = beautifuls.size();
    dp[0] = 1;
    for(int idx=0; idx<len; ++idx){
        for(int num=M; num>=beautifuls[idx]; --num){
            for(int cnt=1; cnt * beautifuls[idx] <= num; ++cnt){
                dp[num] += dp[num - cnt * beautifuls[idx]];
                // modular 1. 152 ms
                // if(dp[num] >= K){
                //     dp[num] -= K;
                // }
            }
            // modular 2. 52 ms
            while(dp[num] >= K){
                dp[num] -= K;
            }

            // modular 3. 56 ms
            // dp[num] %= K;
        }
    }
    cout << dp[M] << endl;
}

void solve_dp_2(){
    // accumulate counting bottom-up
    int len = beautifuls.size();
    dp[0] = 1;
    for(int idx=0; idx<len; ++idx){
        for(int num=beautifuls[idx]; num<=M; ++num){
            dp[num] += dp[num - beautifuls[idx]];
            // method 1. 28 ms
            // dp[num] %= K;

            // method 2. 4 ms
            if(dp[num] >= K){
                dp[num] -= K;
            }
        }
    }
    cout << dp[M] << endl;
}

void solve(){
    find_beautiful_numbers();

    // solve_dp_1();
    solve_dp_2();
}

void input(){
    cin >> M >> K;
}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    input();

    solve();

    return 0;
}
