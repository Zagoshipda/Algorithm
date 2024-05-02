/*
    https://www.acmicpc.net/problem/2775
    (inhabitant)

    solution
        https://www.acmicpc.net/source/2698804
        (yeongsik2065, 0 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    1 ... i
*/

const int MAX_NUM = 14;
int T;
int k, n;

int arr[MAX_NUM + 1][MAX_NUM + 1];
void solve(){
    int num = 0;
    for(int col=0; col<=MAX_NUM; ++col){
        arr[0][col] = col;
    }
    for(int row=1; row<=MAX_NUM; ++row){
        for(int col=1; col<=MAX_NUM; ++col){
            // for(int jdx=1; jdx<=col; ++jdx){
            //     arr[row][col] += arr[row-1][jdx];
            // }
            arr[row][col] = arr[row][col-1] + arr[row-1][col];
        }
    }
}

void input(){
    solve();

    cin >> T;
    while(T--){
        cin >> k >> n;
        cout << arr[k][n] << endl;
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
