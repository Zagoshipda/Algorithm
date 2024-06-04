/*
    https://www.acmicpc.net/problem/14534
    (string permutation)

    solution
        https://www.acmicpc.net/source/9035589
        (YunGoon, 0 ms) : backtracking + bitmasking (mask - or, unmask - xor)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int MAX_LEN = 10;

int T;
string L;
int len;

bool is_used[MAX_LEN + 1];
void backtracking(int nth, string str){
    if(nth >= len){
        cout << str << endl;
        return;
    }

    for(int idx=0; idx<len; ++idx){
        if(!is_used[idx]){
            is_used[idx] = true;
            backtracking(nth + 1, str + L[idx]);
            is_used[idx] = false;
        }
    }
}

void solve_backtracking(){
    backtracking(0, "");
}

void solve(){
    solve_backtracking();
}

void input(){
    cin >> T;
    for(int ith=1; ith<=T; ++ith){
        cin >> L;
        len = L.size();
        cout << "Case # " << ith << ":" << endl;
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
