/*
    https://www.acmicpc.net/problem/9693
    (trailing zeros on factorial)

    similar problem
        https://www.acmicpc.net/problem/1676
        (trailing zeros on factorial)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int MAX_NUM = 1'000'000;

int N;
int testcase;
int cnt;

void solve(){
    cnt = 0;
    int div = 5;
    for( ; div<=N; div *= 5){
        cnt += N / div;
    }

    cout << "Case #" << ++testcase << ": " << cnt << endl;
}

void input(){
    while(true){
        cin >> N;
        if(N == 0){
            break;
        }

        solve();
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
