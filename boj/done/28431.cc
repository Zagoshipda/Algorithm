/*
    https://www.acmicpc.net/problem/28431
    (socks)

    solution
        https://www.acmicpc.net/source/64640771
        (imtore, 0 ms) : implemented in solve_bit()
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

int a, b, c, d, e;
int arr[15];

void solve_bit(){
    cout << (a ^ b ^ c ^ d ^ e) << endl;
}

void solve_hash(){
    ++arr[a];
    ++arr[b];
    ++arr[c];
    ++arr[d];
    ++arr[e];
    for(int num=0; num<=9; ++num){
        if(arr[num] & 1){
            cout << num << endl;
            break;
        }
    }
}

void solve(){
    // solve_hash();

    solve_bit();
}

void input(){
    cin >> a >> b >> c >> d >> e;
}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    input();

    solve();

    return 0;
}
