/*
    https://www.acmicpc.net/problem/19946
    (power of 2)

    solution
        https://www.acmicpc.net/source/29862655
        (dranger97, 0 ms)
        https://www.acmicpc.net/source/22927642
        (starboard, 0 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

string N_str;
unsigned long long N;
const int MAX_POWER = 64;
int answers[MAX_POWER + 1];

void solve_1(){
    if(N_str == "18446744073709551615"){
        cout << 64 << endl;
    }
    else{
        N = stoull(N_str);
        for(int mistake=1; mistake<MAX_POWER; ++mistake){
            unsigned long long ans = 1;
            for(int power=1; power<=MAX_POWER; ++power){
                ans = ans << 1;
                if(power == mistake){
                    ans -= 1;
                }
            }
            if(ans == N){
                cout << mistake << endl;
                break;
            }
        }
    }
}

void solve_2(){
    cout << __popcount(N) << endl;
}

void solve(){
    // solve_1();

    solve_2();
}

void input(){
    // cin >> N_str;
    cin >> N;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
