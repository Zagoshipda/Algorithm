/*
    https://www.acmicpc.net/problem/16510
    (predictable queue)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int MAX_NUM = 200'000;                // 2 * 10^5
const int MAX_TIME = 10'000;                // 10^4
const int MAX_TOTAL = MAX_NUM * MAX_TIME;   // 2 * 10^9

int N, M;
int works[MAX_NUM + 1];
int times[MAX_NUM + 1];

int prefix_sum[MAX_NUM + 2];
void solve_prefix_sum(){
    for(int idx=1; idx<=M; ++idx){
        auto it = upper_bound(prefix_sum+1, prefix_sum+1+N, times[idx]);
        cout << distance(prefix_sum, it-1) << endl;
    }
}

void solve(){
    solve_prefix_sum();
}

void input(){
    cin >> N >> M;
    for(int i=1; i<=N; ++i){
        cin >> works[i];
        prefix_sum[i] = prefix_sum[i-1] + works[i];
    }

    for(int idx=1; idx<=M; ++idx){
        cin >> times[idx];
        auto it = upper_bound(prefix_sum+1, prefix_sum+1+N, times[idx]);
        cout << distance(prefix_sum, it-1) << endl;
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
