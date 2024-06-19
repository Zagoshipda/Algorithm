/*
    https://www.acmicpc.net/problem/31443
    (maximum happiness)

    similar problem
        https://www.acmicpc.net/problem/1437
        (number decomposition)

    solution
        https://www.acmicpc.net/source/73985417
        (jhuni, 0 ms)
        https://www.acmicpc.net/source/73985654
        (ncy09, 8 ms)

        https://www.acmicpc.net/source/73987552
        (leedongbin, 4 ms)
        https://www.acmicpc.net/source/73984067
        (mickeyjung, 0 ms)

        https://www.acmicpc.net/source/74212835
        (yooshnn, 8 ms) : DP

    reference
        https://oeis.org/A000792
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Algorithm
        (observation) f(n) = n^1/n is maximum when n = 3

        N, M ~ O(10^3)
        DP
        S ubproblem
            dp[a][b] = max value with a x b
        R ecurrence relation
            dp[a][b] = max(dp[x][y] * dp[x][b-y] * dp[a-x][y] * dp[a-x][b-y]) for x=0...a for y=0...b

            => greedy choice ?
            recursive size as close as to the square roots
            => check for sqrt-1, sqrt, sqrt+1 : 3 choices

            1 8 => 2 2 2 2 (X) or 3 3 2 (O)
            1 6 => 3 3 = 9
            2 10
            3 3 3
            3 3 3 2
        T opological order
        B ase case
        O riginal problem
        T ime complexity
            # of subproblems : O(10^6)
            operations per subproblem : O(10^6)
            operations per subproblem : O(3)

*/

const int MAX_ROW = 1'000;  // 10^3
const int MAX_COL = 1'000;  // 10^3
const int MOD = 1'000'000'007;  // 10^9 + 7

int N, M;

ll dp[MAX_ROW + 1][MAX_COL + 1];    // 10^6
void solve_bottom_up(){
    for(int size=1; size<=N; ++size){
        dp[size][0] = 1;
    }
    for(int size=1; size<=M; ++size){
        dp[0][size] = 1;
    }
    dp[1][1] = 1;

    for(int row=1; row<=N; ++row){
        for(int col=1; col<=M; ++col){
            dp[row][col] = row * col;
            if(row == 1 && col == 1){
                continue;
            }
            vector<int> rows;
            vector<int> cols;
            int val_row = sqrt(row);
            int val_col = sqrt(col);
            // int val_row = row / 2;
            // int val_col = col / 2;
            if(val_row > 1){
                rows.push_back(val_row - 1);
            }
            rows.push_back(val_row);
            if(val_row < N-1){
                rows.push_back(val_row + 1);
            }

            if(val_col > 1){
                cols.push_back(val_col - 1);
            }
            cols.push_back(val_col);
            if(val_col < M-1){
                cols.push_back(val_col + 1);
            }

            int len_1 = rows.size();
            int len_2 = cols.size();
            for(int idx=0; idx<len_1; ++idx){
                for(int jdx=0; jdx<len_2; ++jdx){
                    dp[row][col] = max({
                        dp[row][col],
                        dp[rows[idx]][cols[jdx]] * dp[rows[idx]][col - cols[jdx]] % MOD * dp[row - rows[idx]][cols[jdx]] % MOD * dp[row - rows[idx]][col - cols[jdx]] % MOD,
                    });
                }
            }
        }
    }

    cout << dp[N][M] << endl;
}

void solve_2(){
    for(int row=1; row<=N; ++row){
        dp[row][0] = 1;
    }
    for(int col=1; col<=M; ++col){
        dp[0][col] = 1;
    }

    // for(int sum=)
    for(int row=1; row<=N; ++row){
        for(int col=1; col<=M; ++col){
            if(row > col && dp[col][row]){
                dp[row][col] = dp[col][row];
                continue;
            }
            dp[row][col] = row * col;
            for(int middle=1; middle<row; ++middle){
                dp[row][col] = max({
                    dp[row][col],
                    dp[middle][col] * dp[row - middle][col],
                });
            }
            for(int middle=1; middle<col; ++middle){
                dp[row][col] = max({
                    dp[row][col],
                    dp[row][middle] * dp[row][col - middle],
                });
            }
            dp[row][col] %= MOD;
        }
    }

    cout << dp[N][M] << endl;
}

ll recursive_wrong(int big, int small){
    if(small <= 1){
        ll val = 1;
        while(big % 3){
            big -= 2;
            val <<= 1;
            val %= MOD;
        }
        int cnt = big / 3;
        for(int ith=1; ith<=cnt; ++ith){
            val *= 3;
            val %= MOD;
        }
        return val;
    }

    ll val_1 = 1;
    int row = big / 3;
    int cnt_1 = row * small;
    for(int ith=1; ith<=cnt_1; ++ith){
        val_1 *= 3;
        val_1 %= MOD;
    }
    val_1 *= recursive_wrong(max(big % 3, small), min(big % 3, small));
    val_1 %= MOD;

    ll val_2 = 1;
    int col = small / 3;
    int cnt_2 = col * big;
    for(int ith=1; ith<=cnt_2; ++ith){
        val_2 *= 3;
        val_2 %= MOD;
    }
    val_2 *= recursive_wrong(big, small % 3);
    val_2 %= MOD;

    return max(val_1, val_2);   // WRONG
}

// error : naive implementation with TOO many recursive calls
ll recursive(int num){
    cout << num << " ";
    if(num <= 4){
        return num;
    }

    return 3LL * recursive(num - 3) % MOD;
}

void solve_recursive(){
    cout << recursive(N * M) << endl;
}

void solve_greedy_1(){
    int remainder = N * M % 3;
    ll val = 1;
    int cnt;
    if(remainder == 0){
        cnt = N * M / 3;
    }
    else if(remainder == 1){
        if(N * M >= 4){
            cnt = (N * M - 4) / 3;
            val = 4;
        }
        else{
            cnt = 0;
            val = 1;
        }
    }
    else{
        cnt = (N * M - 2) / 3;
        val = 2;
    }

    for(int ith=1; ith<=cnt; ++ith){
        val *= 3;
        val %= MOD;
    }
    cout << val << endl;
}

void solve_greedy_2(){
    int num = N * M;
    ll val = 1;
    while(num > 4){
        num -= 3;
        val *= 3;
        val %= MOD;
    }

    val *= num;
    val %= MOD;
    cout << val << endl;
}

void solve(){
    // solve_greedy_1();
    solve_greedy_2();

    // solve_recursive();
}

void input(){
    cin >> N >> M;
}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    input();

    solve();

    return 0;
}
