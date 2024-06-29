/*
    https://www.acmicpc.net/problem/17425
    (sum of divisors 1)

    similar problem
        https://www.acmicpc.net/problem/2247
        (real divisor)
        https://www.acmicpc.net/problem/17427
        (sum of divisors 2)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define NUM_TESTCASE 100'000
#define MAX_INPUT 1'000'000

int T;
vector<ll> inputs;
ll N;

/*
    sum of divisors
    sum of (sum of divisors) for number less or equal

*/

// ERROR : time exceeded
void solve_brute_force(){
    ll ans = 0;
    for(ll div=1; div<=N; ++div){
        ans += div * (N/div);
    }
    cout << ans << endl;
}


ll dp[MAX_INPUT + 1];
void solve_dp_1(){
    for(int num=1; num<=MAX_INPUT; ++num){
        ll divisor_sum = 0;
        for(int divisor=1; divisor * divisor<=num; ++divisor){
            if(num % divisor == 0){
                ll val_1 = divisor;
                ll val_2 = num / divisor;
                divisor_sum += (val_1 == val_2 ? val_1 : val_1 + val_2);
            }
        }
        dp[num] = dp[num-1] + divisor_sum;
    }

    for(int input : inputs){
        cout << dp[input] << endl;
    }
}

void solve_2(){
    for(int num=1; num<=MAX_INPUT; ++num){
        for(int val=num; val<=MAX_INPUT; val+=num){
            dp[val] += num;
        }
        dp[num] += dp[num-1];
    }

    // for(int e : inputs){
    //     cout << dp[e] << endl;
    // }
}

void solve(){
    // solve_brute_force();

    // solve_dp_1();

    solve_2();
}

void input(){
    cin >> T;

    solve();

    while(T--){
        cin >> N;

        cout << dp[N] << endl;
        // inputs.push_back(N);
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
