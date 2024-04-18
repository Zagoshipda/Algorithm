/*
    https://www.acmicpc.net/problem/16504
    (origami)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const ll MAX_SIZE = 1 << 10;    // 2^10 ~ 10^3
const ll MAX_NUM = 100'000;     // 10^5
const ll MAX_SUM = MAX_SIZE * MAX_SIZE * MAX_NUM;   // 10^11

int N;
ll num;

ll sum;

void solve(){
    cout << sum << endl;
}

void input(){
    cin >> N;
    for(int row=1; row<=N; ++row){
        for(int col=1; col<=N; ++col){
            cin >> num;
            sum += num;
        }
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
