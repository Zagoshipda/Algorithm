/*
    https://www.acmicpc.net/problem/10211
    (maximum subarray)

    similar problem
        https://www.acmicpc.net/problem/16512
        (maximum subarrays)
        https://www.acmicpc.net/problem/2670
        (largest consecutive product)

    solutions
        https://www.acmicpc.net/source/4431816
        (goooora, 0 ms)
        https://www.acmicpc.net/source/314024
        (kcm1700, 0 ms)

        implemented in solve_prefix_sum()
            https://www.acmicpc.net/source/21004689
            (kdr06006, 0 ms) : maximum of (prefix sum - negative prefix sum)
            https://www.acmicpc.net/source/14222609
            (harinboy, 0 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    arr length ~ 10^3
        => N^2 ~ 10^6 also works
    value range ~ 10^3
    max sum range ~ 10^6

*/

const int ARR_SIZE = 1'000; // 10^3
const int MIN_NUM = -1'000; // - 10^3
const int MAX_NUM = +1'000; // + 10^3
int T;
int N;
int arr[ARR_SIZE + 1];

// int dp_sum[ARR_SIZE + 1];   // dp_sum[k] = max sum that ends with arr[k]
void solve_dp(){
    // need to initialize array, so not use it

    int sum = arr[1];
    int max_sum = sum;
    for(int idx=2; idx<=N; ++idx){
        if(sum + arr[idx] > arr[idx]){
            sum += arr[idx];
        }
        else{
            sum = arr[idx];
        }
        max_sum = max(max_sum, sum);
    }
    cout << max_sum << endl;
}

void solve_prefix_sum(){
    int prefix_sum = 0;
    // int negative_prefix_sum = MAX_NUM;   // WRONG
    int negative_prefix_sum = 0;
    int max_sum = MIN_NUM;
    for(int idx=1; idx<=N; ++idx){
        prefix_sum += arr[idx];
        max_sum = max(max_sum, prefix_sum - negative_prefix_sum);
        negative_prefix_sum = min(negative_prefix_sum, prefix_sum);
    }
    cout << max_sum << endl;
}

void solve(){
    // solve_dp();

    solve_prefix_sum();
}

void input(){
    cin >> T;
    while(T--){
        cin >> N;
        for(int i=1; i<=N; ++i){
            cin >> arr[i];
        }
        solve();
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
