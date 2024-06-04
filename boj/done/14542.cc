/*
    https://www.acmicpc.net/problem/14542
    (outer triangle sum)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

int n;
int cnt;
int x;
int sum;

void solve(){
    cout << "Case #" << cnt << ":" << sum << endl;
}

void input(){
    while(true){
        cin >> n;
        if(n == 0){
            break;
        }

        ++cnt;
        sum = 0;
        for(int row=1; row<=n; ++row){
            for(int col=1; col<=row; ++col){
                cin >> x;
                if(col == 1 || col == row || row == n){
                    sum += x;
                }
            }
        }

        solve();
    }
}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    input();

    // solve();

    return 0;
}
