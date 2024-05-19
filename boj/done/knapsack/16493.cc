/*
    https://www.acmicpc.net/problem/16493
    (maximum page)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int NUM_DAY = 200;    // 10^3
const int NUM_CHAPTER = 20; // 10^2

int N, M;
pair<int, int> chapters[NUM_CHAPTER + 1];

int dp[NUM_DAY + 1];
void solve_dp(){
    for(int idx=1; idx<=M; ++idx){
        for(int day=N; day>=chapters[idx].first; --day){
            dp[day] = max({
                dp[day],
                dp[day - chapters[idx].first] + chapters[idx].second,
            });
        }
    }
    cout << dp[N] << endl;
}

void solve(){
    solve_dp();
}

void input(){
    cin >> N >> M;
    for(int i=1; i<=M; ++i){
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
