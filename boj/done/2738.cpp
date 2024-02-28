/*
    https://www.acmicpc.net/problem/2738
    (matrix addition)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int ROW_SIZE = 100;
const int COL_SIZE = 100;
int N, M;
int matrix_A[ROW_SIZE + 1][COL_SIZE + 1];
int matrix_B[ROW_SIZE + 1][COL_SIZE + 1];

void solve(){
    for(int row=1; row<=N; ++row){
        for(int col=1; col<=M; ++col){
            cout << matrix_A[row][col] + matrix_B[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void input(){
    cin >> N >> M;
    for(int row=1; row<=N; ++row){
        for(int col=1; col<=M; ++col){
            cin >> matrix_A[row][col];
        }
    }

    for(int row=1; row<=N; ++row){
        for(int col=1; col<=M; ++col){
            cin >> matrix_B[row][col];
        }
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
