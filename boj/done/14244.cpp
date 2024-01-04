/*
    https://www.acmicpc.net/problem/14244
    (build tree)

    solutions
        https://www.acmicpc.net/source/9150728
        (ae04071, 1116 KB) : max(0,i-m), i for i=n-1...1
        https://www.acmicpc.net/source/30236331
        (jinhan814, 1112 KB)

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Tree : graph without a cycle

    1. make m leaf from the root
    2. attach following nodes to existing leaves (# of leaves do not change)
*/

const int ROOT = 0;

int n, m;

void solve_1(){
    int i;
    for(i=1; i<=m; ++i){
        cout << 0 << " " << i << endl;
    }
    for(int j=1; i<=n-1; ++i){
        cout << j << " " << i << endl;
        ++j;
        if(j > m){
            j = (i+1)-m;
        }
    }
}

void solve_2(){
    int i;
    for(i=1; i<=m; ++i){
        cout << ROOT << " " << i << endl;
    }
    int parent = 1;
    while(i<=n-1){
        cout << parent << " " << i << endl;
        parent = i;
        ++i;
    }
}

void solve(){
    // solve_1();

    solve_2();
}

void input(){
    cin >> n >> m;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
