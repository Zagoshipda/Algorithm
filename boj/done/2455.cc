/*
    https://www.acmicpc.net/problem/2455
    (train)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

int x, y;

void solve(){

}

void input(){
    int num = 0;
    int max_num = 0;
    for(int ith=1; ith<=4; ++ith){
        cin >> x >> y;
        num += (- x + y);
        max_num = max(max_num, num);
    }
    cout << max_num << endl;
}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    input();

    // solve();

    return 0;
}
