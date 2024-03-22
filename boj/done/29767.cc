/*
    https://www.acmicpc.net/problem/29767
    (maximum score)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int NUM_SCORES = 300'000;     // 3 * 10^5
const int MIN_NUM = -100'000'000;   // -10^8
const int MAX_NUM = 100'000'000;    // 10^8

int N, K;
ll scores[NUM_SCORES + 1];
ll prefix_sum[NUM_SCORES + 1];
void solve(){
    sort(prefix_sum+1, prefix_sum+1+N, greater<ll>());

    ll sum = 0;
    for(int ith=1; ith<=K; ++ith){
        sum += prefix_sum[ith];
    }
    cout << sum << endl;
}

void input(){
    cin >> N >> K;
    for(int i=1; i<=N; ++i){
        cin >> scores[i];
        prefix_sum[i] = prefix_sum[i-1] + scores[i];
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
