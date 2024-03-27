/*
    https://www.acmicpc.net/problem/14429
    (baskin robbins 31)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    winning strategy
    - total number j
    - can take 1...m numbers at the same time
    - winning number : starting from j-1 % m+1, add up the multiples of m+1
        => j-1 % m+1 + (m+1) * k, for k=0, 1, 2, ...

    ex. j=20 m=6
        19 % 7 = 2...5
        5(1) 12(3) 19(5) | 20(6)

        => (j-1 / m+1) * 2 + 2
*/

const int NUM_GAME = 1'000;
const int MAX_NUM = 10'000;

int n;
int j, m;
int cnt;
int min_length = MAX_NUM;
int min_cnt;

void solve(){
    int length = (j-1)/(m+1) * 2 + 2;
    if(length < min_length){
        min_length = length;
        min_cnt = cnt;
    }
}

void input(){
    cin >> n;
    for(cnt=1; cnt<=n; ++cnt){
        cin >> j >> m;
        solve();
    }
    cout << min_cnt << " " << min_length << endl;
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
