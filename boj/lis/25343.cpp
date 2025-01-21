/*
    https://www.acmicpc.net/problem/25343
    (maximum lis) : 2-D lis

    similar problem
        https://www.acmicpc.net/problem/11053
        (lis 1)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

    Algorithm
        # paths = choose N-1 row, N-1 col = (2N-2)! / (N-1)! (N-1)!
        N=2 : 2
        N=3 : 6
        N=4 : 20
        ...

        WRONG : consider numbers in diagonal order ?
            => optimal lis can NOT be represented as a connected path

3
1 2 3
1 1 3
1 4 5

*/

const int SIZE = 100;           // 10^2
const int MAX_NUM = 10'000;     // 10^4

int N;
int matrix[SIZE + 1][SIZE + 1];

// void initialize(){
//     for(int i=0; i<=(N<<1); ++i){
//         dp[i] = (INT_MAX >> 1);
//     }
// }

int dp[(SIZE<<1)+1];
void solve_lis_wrong(){
    int start_row, start_col, cnt;
    for(int step=1; step<=N; ++step){
        start_row = step;
        start_col = 1;
        cnt = step;
        vector<int> numbers;
        for(int row=start_row, col=start_col; cnt; --row, ++col, --cnt){
            // int val = matrix[row][col];
            // int pos = lower_bound(dp+1, dp+1+(N<<1), val) - dp;
            // dp[pos] = val;
            numbers.push_back(matrix[row][col]);
        }
        sort(numbers.begin(), numbers.end(), less<int>());
        auto it = upper_bound(numbers.begin(), numbers.end(), dp[step-1]);
        dp[step] = *it;
    }

    for(int step=2; step<=N; ++step){
        start_row = N;
        start_col = step;
        cnt = N - step + 1;
        vector<int> numbers;
        for(int row=start_row, col=start_col; cnt; --row, ++col, --cnt){
            // int val = matrix[row][col];
            // int pos = lower_bound(dp+1, dp+1+(N<<1), val) - dp;
            // dp[pos] = val;
            numbers.push_back(matrix[row][col]);
        }
        sort(numbers.begin(), numbers.end(), less<int>());
        auto it = upper_bound(numbers.begin(), numbers.end(), dp[step-1 + N -1]);
        dp[step-1 + N] = *it;
    }

    int pos;
    for(int idx=(N<<1); idx>0; --idx){
        if(dp[idx]){
            pos = idx;
            cout << idx << endl;
            break;
        }
    }
    for(int idx=1; idx<=pos; ++idx){
        cout << dp[idx] << " ";
    }
    cout << endl;
}


int dp_2[SIZE + 1][SIZE + 1];
void solve_lis_2(){
    int max_lis = -1;
    // brute force
    for(int row=1; row<=N; ++row){
        for(int col=1; col<=N; ++col){
            // NOTE : include matrix[0?][0?] = 0 as a base case
            for(int ith=0; ith<=row; ++ith){
                for(int jth=0; jth<=col; ++jth){
                    // lis condition
                    if(matrix[ith][jth] < matrix[row][col]){
                        dp_2[row][col] = max({
                            dp_2[row][col],
                            1 + dp_2[ith][jth],
                        });
                    }
                }
            }
            max_lis = max(max_lis, dp_2[row][col]);
        }
    }

    cout << max_lis << endl;
}

void solve(){
    // solve_lis_wrong();

    solve_lis_2();
}

void input(){
    cin >> N;
    for(int row=1; row<=N; ++row){
        for(int col=1; col<=N; ++col){
            cin >> matrix[row][col];
        }
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
