/*
    https://www.acmicpc.net/problem/19576
    (mineral water)

    similar problem
        https://www.acmicpc.net/problem/11053
        (lis 1)

    solution
        https://www.acmicpc.net/source/42195114
        (pjshwa, 48 ms)
        https://www.acmicpc.net/source/21825459
        (cheetose, 40 ms) : recursive
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Algorithm
        N ~ 5 * 10^3
        N^2 ~ 10^8

        at most N conversion will work : all numbers to 1

        24 10 4 6 3
        24 : X O O O
        10 : X X X
        4 : X X
        6 : O

        WANT : find the largest set with mutual divisors
        brute force : 2^N

        DP
        S ubproblem
            suppose arr[1...N] is sorted in ascending order
            dp[k] : largest set including arr[k]
        R ecurrence relation
            2 choices : include arr[k] or not
            dp[k] = dp[k-1] + 1 if arr[k] is a multiple of arr[k-1]
                  = dp[k-2] + 1 if arr[k] is a multiple of arr[k-2]
                  ...
                  = dp[1] + 1 if arr[k] is a multiple of arr[1]
                  = dp[0] (= 0) + 1 if arr[k] is a multiple of arr[0] = 0

                  = max(dp[j] + 1) if arr[k] is a multiple of arr[j] for j=0...k-1
        T opological order
            for k=1...N
                for j=0...k-1
        B ase case
            dp[0] = 0
            arr[0] = 0
        O riginal problem
            (WRONG) dp[N]
            (AC) max(dp[1...N])
        T ime complexity
            N ~ O(10^4)
            # of subproblems : O(N)
            operations per subproblem : O(K) ~ O(N)
            total : O(N^2) ~ O(10^8)
*/

const int ARR_SIZE = 5'000;         // 5 * 10^3
const int MAX_NUM = 1'000'000'000;  // 10^9

int N;
int arr[ARR_SIZE + 1];

int dp[ARR_SIZE + 1];
void solve_dp(){
    sort(arr+1, arr+1+N, less<int>());

    for(int idx=1; idx<=N; ++idx){
        dp[idx] = 1;
        for(int jdx=1; jdx<idx; ++jdx){
            if(arr[idx] % arr[jdx] == 0){
                dp[idx] = max({
                    dp[idx],
                    dp[jdx] + 1,
                });
            }
        }
    }

    // cout << N - dp[N] << endl;                      // WRONG
    cout << N - *max_element(dp+1, dp+1+N) << endl; // AC
}

void solve(){
    solve_dp();
}

void input(){
    cin >> N;
    for(int idx=1; idx<=N; ++idx){
        cin >> arr[idx];
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
