/*
    https://www.acmicpc.net/problem/13699
    (recurrence relation)

    reference
        https://en.wikipedia.org/wiki/Catalan_number
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    catalan number recurrence relation

*/

const int MAX_NUM = 35;

int n;

ll dp[MAX_NUM + 1];

void solve(){
    dp[0] = 1;
    for(int num=1; num<=n; ++num){
        for(int val=0; val<num; ++val){
            dp[num] += dp[val] * dp[num - val - 1];
        }
    }

    cout << dp[n] << endl;
}

void input(){
    cin >> n;
}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    input();

    solve();

    return 0;
}
