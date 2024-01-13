/*
    https://www.acmicpc.net/problem/11660
    (range sum 5)

    solutions
        https://www.acmicpc.net/source/50631282
        (cbkpar, 124 ms)

    fast IOs
        https://www.acmicpc.net/source/54578283
        (ehwlfk2, 40 ms, fast Input)

        https://www.acmicpc.net/source/9513806
        (YunGoon, 32 ms, fast Input)

        https://www.acmicpc.net/source/52310349
        (indo7872, 20 ms, fast Input & Output)

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    1024 = 2^10
    2^20 * 1'000 ~ 2^30
    => int range (O)
*/

const int SIZE_TABLE = 1024;
int N, M;
int table[SIZE_TABLE + 1][SIZE_TABLE + 1];
int x_1, y_1, x_2, y_2;
int prefix_sum_row[SIZE_TABLE + 1][SIZE_TABLE + 1];

pair<int, int> calculate_prev_location(int row, int col){
    if(col <= 1){
        return {row-1, N};
    }
    else{
        return {row, col-1};
    }
}

void solve_1(){
    while(M--){
        cin >> x_1 >> y_1 >> x_2 >> y_2;

        int sum = 0;
        for(int row=x_1; row<=x_2; ++row){
            auto [prev_row, prev_col] = calculate_prev_location(row, y_1);
            sum += prefix_sum_row[row][y_2] - prefix_sum_row[prev_row][prev_col];
        }

        cout << sum << endl;
    }
}

int prefix_sum_table[SIZE_TABLE + 1][SIZE_TABLE + 1];   // prefix sum from (1, 1) to (i, j)
void solve_2(){
    while(M--){
        cin >> x_1 >> y_1 >> x_2 >> y_2;

        cout << (prefix_sum_table[x_2][y_2] - prefix_sum_table[x_2][y_1-1] - prefix_sum_table[x_1-1][y_2] + prefix_sum_table[x_1-1][y_1-1]) << endl;
    }
}

void solve(){
    // solve_1();

    solve_2();
}

void input(){
    cin >> N >> M;
    for(int row=1; row<=N; ++row){
        for(int col=1; col<=N; ++col){
            cin >> table[row][col];
            // auto [prev_row, prev_col] = calculate_prev_location(row, col);
            // prefix_sum_row[row][col] = prefix_sum_row[prev_row][prev_col] + table[row][col];

            prefix_sum_table[row][col] = (
                prefix_sum_table[row][col-1] + prefix_sum_table[row-1][col] -
                prefix_sum_table[row-1][col-1] +
                table[row][col]
            );
        }
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
