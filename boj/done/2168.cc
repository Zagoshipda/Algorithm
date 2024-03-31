/*
    https://www.acmicpc.net/problem/2168
    (tiles with diagonal)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    for every integer line, diagonal passes
    when gcd(x, y) = 1, diagonal do not pass the vertices other than starting or the finishing vertex, hence x+y-1 (think of it as the # of blocks along the path from s to t)
    if gcd(x, y) > 1, then (x/gcd + y/gcd - 1) * gcd
    => x + y - gcd(x, y)

*/

const int MAX_NUM = 1'000'000'000;  // 10^9

int x, y;

void solve(){
    int _gcd = gcd(x, y);
    cout << (x/_gcd + y/_gcd - 1) * _gcd << endl;
}

void input(){
    cin >> x >> y;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
