/*
    https://www.acmicpc.net/problem/2563
    (colored paper)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int MAX_PAPER = 100;
const int SIZE_COLORED = 10;
int n;
pair<int, int> papers[MAX_PAPER + 1];
int x, y;
bool colored[MAX_PAPER + 1][MAX_PAPER + 1];

void solve(){
    for(int idx=1; idx<=n; ++idx){
        auto [start_row, start_col] = papers[idx];
        for(int row=start_row; row<start_row+SIZE_COLORED; ++row){
            for(int col=start_col; col<start_col+SIZE_COLORED; ++col){
                colored[row][col] = true;
            }

        }
    }

    int area = 0;
    for(int row=1; row<=MAX_PAPER; ++row){
        for(int col=1; col<=MAX_PAPER; ++col){
            if(colored[row][col]){
                ++area;
            }
        }
    }
    cout << area << endl;
}

void input(){
    cin >> n;
    for(int idx=1; idx<=n; ++idx){
        cin >> x >> y;
        papers[idx] = {x, y};
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
