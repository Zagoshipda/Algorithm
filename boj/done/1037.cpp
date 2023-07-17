/*
    divisor / factor
    https://www.acmicpc.net/problem/1037
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define NUM 50
#define RANGE 1'000'000
int N;
int divisor_max = 0, divisor_min = RANGE;
int divisor;

void input(){
    cin >> N;
    for(int i=0; i<N; ++i){
        cin >> divisor;
        divisor_max = max(divisor_max, divisor);
        divisor_min = min(divisor_min, divisor);
    }
}

void solve(){
    cout << divisor_min * divisor_max << endl;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
