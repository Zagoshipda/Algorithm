/*
    https://www.acmicpc.net/problem/2739
    (times table)

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

int N;

void solve(){
    for(int i=1; i<=9; ++i){
        cout << N << " * " << i  << " = " << N*i << endl;
    }
}

void input(){
    cin >> N;

}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
