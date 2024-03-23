/*
    https://www.acmicpc.net/problem/1439
    (bit flip)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

string word;

void solve(){
    int len = word.size();
    int changes = 0;
    char prev = word[0];
    for(int idx=1; idx<len; ++idx){
        if(word[idx] != prev){
            ++changes;
        }
        prev = word[idx];
    }

    cout << ((changes + 1) >> 1) << endl;
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
