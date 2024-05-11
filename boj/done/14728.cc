/*
    https://www.acmicpc.net/problem/14728
    (cramming)

    solution
        https://www.acmicpc.net/source/18015149
        (ywywyw, 0 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int NUM_CHAPTER = 100;    // 10^2
const int MAX_NUM = 1'000;      // 10^3
const int MAX_TOTAL = NUM_CHAPTER * MAX_NUM;    // 10^5
int N, T;
pair<int, int> chapters[NUM_CHAPTER + 1];   // (time, score)

int dp[NUM_CHAPTER + 2][MAX_TOTAL + 1];
void solve_knapsack(){
    for(int idx=N; idx>=1; --idx){
        for(int time=0; time<=T; ++time){
            dp[idx][time] = dp[idx+1][time];
            if(chapters[idx].first <= time){
                dp[idx][time] = max({
                    dp[idx][time],
                    dp[idx+1][time - chapters[idx].first] + chapters[idx].second,
                });
            }
        }
    }
    cout << dp[1][T] << endl;
}

void solve(){
    solve_knapsack();
}

void input(){
    cin >> N >> T;
    for(int i=1; i<=N; ++i){
        cin >> chapters[i].first >> chapters[i].second;
    }
}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    input();

    solve();

    return 0;
}
