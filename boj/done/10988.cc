/*
    https://www.acmicpc.net/problem/10988
    (check palindrome)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int MAX_LENGTH = 100;
string word;

void solve(){
    int len = word.size();
    for(int start=0, end=len-1; start<=end; ++start, --end){
        if(word[start] != word[end]){
            cout << 0 << endl;
            return;
        }
    }
    cout << 1 << endl;
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
