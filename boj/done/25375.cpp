/*
    https://www.acmicpc.net/problem/25375
    (very simple problem)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    gcd = a
    x = a s
    y = a t
        where gcd(s, t) = 1
    x + y = a (s + t) = b >= a * (1 + 1)
    take s = 1, t = b/a-1 => always coprime

*/

int Q;
ll a, b;

void solve(){
    if(b % a){
        cout << 0 << endl;
    }
    else{
        if(b / a > 1){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
}

void input(){
    cin >> Q;
    while(Q--){
        cin >> a >> b;

        solve();
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
