/*
    https://www.acmicpc.net/problem/1009
    (distributed processing)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

int T;
int a, b;

void solve(){
    a %= 10;
    int num = 1;
    for(int power=1; power<=b; ++power){
        num *= a;
        num %= 10;
    }
    if(num == 0){
        cout << 10 << endl;
    }
    else{
        cout << num << endl;
    }
}

void input(){
    cin >> T;
    while(T--){
        cin >> a >> b;
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
