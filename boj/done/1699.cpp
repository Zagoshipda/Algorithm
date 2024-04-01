/*
    https://www.acmicpc.net/problem/1699
    (squares sum)

    similar problem
        https://www.acmicpc.net/problem/2057
        (factorial factorization)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Observation : since 1 = 1^2, all positive integers can be expressed as sum of squares

        greedy ? (X)
            (n-1)^2 = n^2 -2n + 1
            n^2
            (n+1)^2 = n^2 + 2*n + 1

            16 25 36
            41 = 16 + 25

        brute force ? => DP

        sqrt(100000) = 316.228...

        DP solution
            S ubproblem
                dp[k] : minimum # of squares that sums up to k
            R ecurrence relation
                local brute force, optimal substructure property
                dp[k] = min(dp[x] + dp[k-x]) for x=1...k-1
            T opological order
                k=1...N
            B ase case
                dp[0] = 0
                dp[k^2] = 1 for k^2 <= N
                dp[i] = i for i=1...N
            O riginal problem
                dp[N]
            T ime complexity
                O(N) subproblems
                O(N) comparisons for each subproblem
                => total O(N^2) ~ O(10^10) => time overflow
                => optimization ?
*/

const int MAX_NUM = 100'000;    //   10^5
int N;

int dp_squares_sum[MAX_NUM + 1];
void solve_dp_1(){
    // initialize
    for(int i=1; i<=N; ++i){
        dp_squares_sum[i] = i;
    }

    for(int i=1; i*i<=N; ++i){
        dp_squares_sum[i*i] = 1;
    }

    // DP(bottom-up)
    for(int i=2; i<=N; ++i){
        for(int j=1; j<=i-j; ++j){
            dp_squares_sum[i] = min(dp_squares_sum[i], dp_squares_sum[j] + dp_squares_sum[i-j]);
        }
    }

    cout << dp_squares_sum[N] << endl;
}

void solve_dp_2(){
    // initialize
    for(int i=1; i<=N; ++i){
        dp_squares_sum[i] = i;
    }

    for(int i=1; i*i<=N; ++i){
        dp_squares_sum[i*i] = 1;
    }

    // DP(bottom-up)
    for(int i=2; i<=N; ++i){
        for(int j=1; j*j<=i; ++j){
            dp_squares_sum[i] = min({
                dp_squares_sum[i],
                dp_squares_sum[i-j*j] + dp_squares_sum[j*j]
            });
        }
    }

    cout << dp_squares_sum[N] << endl;
}

void solve_dp_3(){
    // initialize
    for(int i=1; i<=N; ++i){
        dp_squares_sum[i] = i;
    }

    // duplicate in DP
    // for(int i=1; i*i<=N; ++i){
    //     dp_squares_sum[i*i] = 1;
    // }

    // DP(bottom-up)
    for(int i=2; i<=N; ++i){
        for(int j=1; j*j<=i; ++j){
            dp_squares_sum[i] = min({
                dp_squares_sum[i],
                dp_squares_sum[i-j*j] + 1
            });
        }
    }

    cout << dp_squares_sum[N] << endl;
}

vector<int> squares;
void solve_greedy_wrong(){
    for(int num=1; num*num<=N; ++num){
        squares.push_back(num * num);
    }

    int cnt = 0;
    int square;
    for(auto it=squares.begin(); it!=squares.end(); ++it){
        square = *it;
        if(N >= square){
            N -= square;
            ++cnt;
        }
        else{
            break;
        }
    }

    cout << cnt + N << endl;
}

void solve(){
    // solve_dp_1();   // time exceeded
    solve_dp_2();
    // solve_dp_3();

    // solve_greedy_wrong();
}

void input(){
    cin >> N;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
