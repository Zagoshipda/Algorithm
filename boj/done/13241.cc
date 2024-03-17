/*
    https://www.acmicpc.net/problem/13241
    (LCM)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

ll A, B;

void solve(){
    cout << lcm(A, B) << endl;
}

void input(){
    cin >> A >> B;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
