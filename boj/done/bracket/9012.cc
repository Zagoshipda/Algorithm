/*
    https://www.acmicpc.net/problem/9012
    (parenthesis)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

int T;
string paren;

void solve(){
    int cnt = 0;
    int len = paren.size();
    for(int idx=0; idx<len; ++idx){
        if(paren[idx] == '('){
            ++cnt;
        }
        else{
            --cnt;
        }

        if(cnt < 0){
            // cout << "NO" << endl;
            // return;

            break;
        }
    }

    if(cnt){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }
}

void input(){
    cin >> T;
    while(T--){
        cin >> paren;

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
