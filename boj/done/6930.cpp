/*
    https://www.acmicpc.net/problem/6930
    (mod inverse)

    similar problem
        https://www.acmicpc.net/problem/15995
        (modular inverse)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

int x, m;

void solve(){
    for(int num=1; num<m; ++num){
        if(x * num % m == 1){
            cout << num << endl;
            return;
        }
    }
    cout << "No such integer exists." << endl;
}

void input(){
    cin >> x >> m;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
