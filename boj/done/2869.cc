/*
    https://www.acmicpc.net/problem/2869
    (snail) : puz
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
    - wooden pole with the height of V meters
    - In one day it can climb A meters upwards
    - during each night it sleeps, sliding B meters back down

    Q. the number of days that the snail needs to reach the top ?

    Algorithm
        required days to go V - A, then go up A and finish
        (V-A / A-B) + 1

        ex.
        V=8 A=3 B=1
            5 / 2
            8-3 / 3-1 = 2 ... 1 => 3 + 1 = 4
            2 4 6 9 : 4

        V=9 A=5 B=1
            V-B=8 A-B=4
            4 9 : 2
        V=10 A=5 B=1
            V-B=9 A-B=4
            4 8 13 : 3

*/

const int MAX_NUM = 1'000'000'000;  // 10^9

int V;
int A, B;

void solve_1(){
    int ans = (V - A) / (A - B);
    if((V - A) % (A - B)){
        ans += 1;
    }

    cout << ans + 1 << endl;    // ceil((V - A) / (A - B)) + 1
}

void solve_2(){
    cout << (V - B -1) / (A - B) + 1 << endl;
}

void solve(){
    // solve_1();

    solve_2();
}

void input(){
    cin >> A >> B >> V;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
