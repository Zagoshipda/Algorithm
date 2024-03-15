/*
    https://www.acmicpc.net/problem/16483
    (two circles)

    solutions
        https://www.acmicpc.net/source/38748936
        (minggyul, 0 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    (T/2)^2 = T * T / 4
    if T is even, T/2 is an integer
    if T is odd, T/2 = (n+1/2) * (n+1/2) = n^2 + n + 1/4
        here n^2, n are integers, only decimal 1/4 can be floored
        => only have to care on integers
        => only using int is sufficient

*/

const int MAX_NUM = 10'000;
int T;

void solve_1(){
    // cout << (int)round(T * T / 4.0) << endl;
    cout << (int)(T * T / 4.0 + 0.5) << endl;
}

void solve_2(){
    int div = T * T / 4;
    // NOTE : never happens
    // if(T * T % 4 >= 4/2){
    //     ++div;
    // }
    cout << div << endl;
}

void solve(){
    // solve_1();

    solve_2();
}

void input(){
    cin >> T;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
