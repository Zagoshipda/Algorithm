/*
    https://www.acmicpc.net/problem/11729
    (hanoi tower)

    similar problem
        https://www.acmicpc.net/problem/1914
        (hanoi tower)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    2^20 ~ 10^6
*/

const int MAX_NUM = 20;

int N;

void recursive(int src, int dest, int extra, int plate){
    if(plate <= 1){
        cout << src << " " << dest << endl;
        return;
    }

    recursive(src, extra, dest, plate-1);
    recursive(src, dest, extra, 1);
    recursive(extra, dest, src, plate-1);
}

void solve_hanoi(){
    cout << (1<<N) - 1 << endl;

    recursive(1, 3, 2, N);
}

void solve(){
    solve_hanoi();
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
