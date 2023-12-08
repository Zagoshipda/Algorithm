/*
    https://www.acmicpc.net/problem/11066
    (merging files)

    similar problems
        https://www.acmicpc.net/problem/11049
        (matrix multiplication order)

        https://www.acmicpc.net/problem/1715
        (merging cards)

    DP optimization : Knuth optimization (128ms > 8ms)
        https://dl.acm.org/doi/pdf/10.1145/800141.804691
        https://cp-algorithms.com/dynamic_programming/knuth-optimization.html
        https://www.acmicpc.net/board/view/16202

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define NUM_CHAPTER 500
#define SIZE_CHAPTER 10'000
int T;
int K;
int chapters[NUM_CHAPTER + 1];
int prefix_sum[NUM_CHAPTER + 1];

/*
    DP modeling

    S ubproblem
        substring
        dp[i][j] : minimum cost for merging chapters [i:j]

    R ecurrence relation
        local brute force (try all possible choices)
        dp[i][h] = min(dp[i][j] + dp[j+1][h] + chapters[i...h]) for j=i...h-1

    T opological order
        increasing substring size/length
        j-i=0...K-1 for i=1...K

    B ase case
        dp[i][i] = 0 : no cost required for merging a file (or no need to merge)

    O riginal problem
        dp[1][K] : minimum cost for merging all chapters [1:K]

    T ime complexity
        O(K^2) subproblems, O(K) operations for each subproblem,
        total O(K^3) time

*/

int dp[NUM_CHAPTER + 1][NUM_CHAPTER + 1];
void solve_dp(){
    for(int len=2; len<=K; ++len){
        for(int start=1; start + (len-1) <=K; ++start){
            int end = start + (len-1);
            dp[start][end] = INT_MAX;
            for(int mid=start; mid+1<=end; ++mid){
                dp[start][end] = min({
                    dp[start][end],
                    dp[start][mid] + dp[mid+1][end] + (prefix_sum[end] - prefix_sum[start-1])
                });
            }
        }
    }

    cout << dp[1][K] << endl;
}

/*
    S ubproblem
        dp[i][j] : minimum cost for merging chapters[i:j]

    R ecurrence relation
        local brute force : try all possible choices
        let h be a minimum cut position between i...j then we have,
        dp[i][j] = min(dp[i][h] + dp[h+1][j] + chapters[i:j]) for h=i...j-1

    T opological order
        increasing length i...j
        for j-i=1...K-1 (or j-i+1=2...K)

    B ase case
        dp[i][i] = 0 for i=1...K

    O riginal problem
        calculate the minimum cost for merging the files into one final file
        dp[1][K] : minimum cost for merging all chapters[1:K]

    T ime complexity
        operation / subproblem : O(K) choices for position of h
        subproblems : O(K^2) choices for i and j
        total O(K^3)

        can we optimize this?

        Knuth optimization : opt(i,j-1) <= opt(i,j) <= opt(i+1, j)
        assuming opt(i,j) = argmin_h(dp[i][j]) for h=i...j-1
        for each length j-i, total choices for h is sequential sums up to O(K)
        choices for length is up to O(K)
        therefore, total running time O(K^2)
*/

int opt[NUM_CHAPTER + 1][NUM_CHAPTER + 1];  // argmin look-up table for Knuth optimization
void solve_dp_opt(){
    for(int i=1; i<=K; ++i){
        opt[i][i] = i;
    }

    for(int length=2; length<=K; ++length){
        for(int start=1; start+length-1<=K; ++start){
            int end = start+length-1;
            dp[start][end] = INT_MAX;
            for(int mid=opt[start][end-1]; mid+1<=end && mid<=opt[start+1][end]; ++mid){
                int merge_cost = dp[start][mid] + dp[mid+1][end] + (prefix_sum[end] - prefix_sum[start-1]);
                if(merge_cost < dp[start][end]){
                    dp[start][end] = merge_cost;
                    opt[start][end] = mid;
                }
            }
        }
    }

    cout << dp[1][K] << endl;
}

void solve(){
    // solve_dp();

    solve_dp_opt();
}

void input(){
    cin >> T;
    while(T--){
        cin >> K;
        for(int i=1; i<=K; ++i){
            cin >> chapters[i];
            prefix_sum[i] = prefix_sum[i-1] + chapters[i];
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
