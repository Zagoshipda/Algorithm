/*
    https://www.acmicpc.net/problem/10430
    (modular preserves under addition or multiplication)

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

int A, B, C;

void solve(){
    cout << (A+B)%C << endl;
    cout << ((A%C) + (B%C))%C << endl;
    cout << (A*B)%C << endl;
    cout << ((A%C) * (B%C))%C << endl;
}

void input(){
    cin >> A >> B >> C;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
