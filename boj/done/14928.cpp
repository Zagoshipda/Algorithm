/*
    https://www.acmicpc.net/problem/14928
    (big number)

    references
        https://www.acmicpc.net/board/view/41060
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int MOD = 2000'0303;
const int MAX_LENGTH = 1'000'000;
string N;

void solve(){
    int len = N.size();
    int remainder = 0;
    for(int idx=0; idx<len; ++idx){
        remainder *= 10;
        remainder += (N[idx] - '0');
        remainder %= MOD;
    }
    cout << remainder << endl;
}

void input(){
    cin >> N;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
