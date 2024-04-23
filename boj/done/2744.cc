/*
    https://www.acmicpc.net/problem/2744
    (lowercase and uppercase switch)

    solution
        implemented in solve_1()
            https://www.acmicpc.net/source/2144018
            (kipa00, 0 ms)
        implemented in solve_2()
            https://www.acmicpc.net/source/69024608
            (junhyung9985, 0 ms)
            https://www.acmicpc.net/source/3579356
            (Juno, 0 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

string word;

void solve_1(){
    int len = word.size();
    for(int idx=0; idx<len; ++idx){
        if('a' <= word[idx] && word[idx] <= 'z'){
            // word[idx] = word[idx] - 'a' + 'A';
            word[idx] -= 32;
        }
        else if('A' <= word[idx] && word[idx] <= 'Z'){
            // word[idx] = word[idx] - 'A' + 'a';
            word[idx] += 32;
        }
    }
    cout << word << endl;
}

void solve_2(){
    for(int ch : word){
        // cout << static_cast<char>(ch ^ (0x20));
        cout << static_cast<char>(ch ^ 32);
    }
    cout << endl;
}

void solve(){
    // solve_1();
    solve_2();
}

void input(){
    cin >> word;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
