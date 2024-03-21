/*
    https://www.acmicpc.net/problem/31460
    (11 multiple palindrome)

    solutions
        https://www.acmicpc.net/source/74229184
        (ruykun, 4 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

    multiples of 11 : using modular 10 = -1 (mod 11)
        11 * k

    11 1001 100001
    0 121 12221 1222221
*/

int T;
int N;

void solve_1(){
    if(N == 1){
        cout << 0 << endl;
    }
    else{
        if(N & 1){
            if(N == 3){
                cout << 121 << endl;
            }
            else{
                cout << 11 << string(N-4, '0') << 11 << endl;
            }
        }
        else{
            cout << string(N, '1') << endl;
        }
    }
}

void solve_2(){
    if(N <= 1){
        cout << 0 << endl;
    }
    else{
        // if(N & 1){
        //     cout << 1 << string(N-2, '2') << 1 << endl;
        // }
        // else{
        //     cout << string(N, '1') << endl;
        // }

        cout << 1 << string(N-2, '2') << 1 << endl;
    }
}

void solve(){
    // solve_1();

    solve_2();
}

void input(){
    cin >> T;
    while(T--){
        cin >> N;
        solve();
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
