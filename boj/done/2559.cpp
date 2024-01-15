/*
    https://www.acmicpc.net/problem/2559
    (sequence)

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    temperatures range from -100 ~ 100

*/

const int MAX_DAYS = 100'000;
int N, K;
int temperatures[MAX_DAYS + 1];
int prefix_sum[MAX_DAYS + 1];

void solve_prefix_sum(){
    int max_sum = INT_MIN;
    for(int start=1, end=start+K-1; end<=N; ++start, ++end){
        int sum = prefix_sum[end] - prefix_sum[start-1];
        max_sum = max(max_sum, sum);
    }

    cout << max_sum << endl;
}

void solve_sliding_window_with_two_pointers(){
    int max_sum = INT_MIN;
    int sum = 0;
    for(int idx=1; idx<=K; ++idx){
        sum += temperatures[idx];
    }
    max_sum = max(max_sum, sum);

    for(int pos=K+1; pos<=N; ++pos){
        sum += (- temperatures[pos-K] + temperatures[pos]);
        max_sum = max(max_sum, sum);
    }

    cout << max_sum << endl;
}

void solve(){
    // solve_prefix_sum();

    solve_sliding_window_with_two_pointers();
}

void input(){
    cin >> N >> K;
    for(int i=1; i<=N; ++i){
        cin >> temperatures[i];
        prefix_sum[i] = prefix_sum[i-1] + temperatures[i];
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
