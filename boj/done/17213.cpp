/*
    https://www.acmicpc.net/problem/17213
    (fruit)

    solutions
        https://www.acmicpc.net/source/54138998
        (imax, 0 ms) : multi-combination property, implemented in solve_dp_1()
            from nCr = n-1Cr-1 + n-1Cr
            nHr = n+r-1Cr = n+r-2Cr-1 + n+r-2Cr = nHr-1 + n-1Hr
            among n take r = (not taking nth) or (take at least one nth)
                = (among n-1 take r) or (assuming one take from nth, among n take r-1)

            WANT : answers with (n,m) pairs, nHm-n where n<=m
            1,1 2,2 3,3 4,4 5,5 6,6 ...
                1 1 1 1 1 ...
            1,2 2,3 3,4 4,5 5,6 6,7
                1 2 3 4 5 ...
            1,3 2,4 3,5 4,6 5,7 6,8
                1 3 6 10 15 21 ...
            1,4 2,5 3,6 4,7 5,8 6,9
                1 4 10 20 35 56 ...
            1,5 2,6 3,7 4,8 5,9 6H10
                1 5 15 35 70 ...
            ...
            1,m-n ... n,m

            dp[n][m] = dp[n][m-1]+dp[n-1][m] since nHr = nHr-1 + n-1Hr

            can be done in 1-D by
            1. base case
            1,0 2,1 3,2 4,3 ...
                1 0 0 0 ...
            2. iteration
            for i=1...m
                dp[k] += dp[k-1] for k=2...n
            3. answer
                dp[n]


            N=n, M=n-1 => n-2Cn-1
                but impossible for the condition that at least take one from each
            n=1 2 3
            1C2 2C3 3C4 ...
            nCn+1 = n(n-1)...(n-(n-1))(n-n) / (n+1)...1 = 0

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Combinatorics
        1 ... N
        take M, at least 1 for each
        <=>
        1 ... N
        take M-N,
        choice N N ... N ? (X, duplicate)
        since multi-combination nHr = r+n-1Cr => NH(M-N) = M-1CM-N=M-1CN-1
        range : 30C15 = 30 ... 16 / 15 ... 1 ~ 10^8 ~ 10^15

    DP : (local) brute force + memoization
        suffix
            among 1...N take M
            for k take 1...x-(N-k) since k+1...N have to take at least 1
            k take 1 : k+1...N take x-1
            k take 2 : k+1...N take x-2
            ...
            k take x-(N-k) : k+1...N take x-(x-(N-k))=(N-k)

            S ubproblem
                dp[k][x] : # with among k...N choose x (<= M-(k-1) from 1...k-1)
            R ecurrence relation
                dp[k][x] = sum( dp[k+1][y] for y=x-1 > ... > N-k=x-(x-(N-k)) )
                    actually available range : for x=N-(k-1)...M-(k-1)
                        min when k...N can take 1 each
                        max when 1...k-1 took 1 each
            T opological order
                for among k=N...1 (suffix) take x=1...M
                local brute force : try all, check available conditions
            B ase case
                dp[N][1...M] = 1 : among Nth only, take 1...M, only one case
            O riginal problem
                dp[1][M] : among 1...N, take M
            T ime complexity
                for each subproblem iterate takes O(M) for the size of max choice
                O(NM) subproblems
                => total O(NM^2)
                since N~10, M~10^2 => O(10^5)
*/

const int MIN_TYPE = 1;
const int MAX_TYPE = 10;
const int MAX_NUM = 30;
ll N;
ll M;

void solve_multi_combination(){
    // NOTE : overflow long long on N=16, M=31
    ll numerator = 1;
    ll denominator = 1;
    for(ll ith=1; ith<=N-1; ++ith){
        numerator *= (M-1-(ith-1));
        denominator *= (N-1-(ith-1));
    }
    cout << numerator / denominator << endl;
}

ll dp[MAX_TYPE + 2][MAX_NUM + 2];
void solve_dp_suffix_1(){
    for(int num=1; num<=M; ++num){
        dp[N][num] = 1;
    }

    for(int ith=N-1; ith>=1; --ith){
        for(int num=N-(ith-1); num<=M-(ith-1); ++num){
            for(int next=num-1; next>=N-ith; --next){
                dp[ith][num] += dp[ith+1][next];
            }
        }
    }
    cout << dp[1][M] << endl;
}

void solve_dp_suffix_2(){
    for(int num=1; num<=M; ++num){
        dp[N][num] = 1;
    }

    for(int ith=N-1; ith>=1; --ith){
        for(int num=N-(ith-1); num<=M-(ith-1); ++num){
            for(int take=1; num-take>=N-ith; ++take){
                dp[ith][num] += dp[ith+1][num-take];
            }
        }
    }
    cout << dp[1][M] << endl;
}

void solve_dp_1(){

}

int dp_2[MAX_NUM + 1];
void solve_dp_2(){
    dp_2[1] = 1;
    for(int row=0; row<=M-N; ++row){
        for(int type=2; type<=N; ++type){
            dp_2[type] += dp_2[type-1];
        }
    }
    cout << dp_2[N] << endl;
}

void solve(){
    // solve_multi_combination();

    // solve_dp_suffix_1();
    // solve_dp_suffix_2();

    solve_dp_2();
}

void input(){
    cin >> N >> M;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
