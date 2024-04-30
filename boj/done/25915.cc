/*
    https://www.acmicpc.net/problem/25915
    (yonsei)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

string password = "ILOVEYONSEI";

char c;

void solve_greedy(){
    int len = password.size();
    int dist = abs(c - password[0]);;
    for(int idx=1; idx<len; ++idx){
        dist += abs(password[idx] - password[idx-1]);
    }
    cout << dist << endl;
}

void solve(){
    solve_greedy();
}

void input(){
    cin >> c;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
