/*
    https://www.acmicpc.net/problem/2475
    (verification number)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

int num;
int sum;

void solve(){
    cout << sum % 10 << endl;
}

void input(){
    for(int ith=1; ith<=5; ++ith){
        cin >> num;
        sum += num * num;
    }
}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    input();

    solve();

    return 0;
}
