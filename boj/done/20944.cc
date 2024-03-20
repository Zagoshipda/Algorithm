/*
    https://www.acmicpc.net/problem/20944
    (palindrome and repetitive)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    palindrome (symmetry)
    repetitive
*/

const int MAX_NUM = 1'000'000;

int N;
void solve(){
    for(int i=0; i<N; ++i){
        cout << 'a';
    }
    cout << endl;
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
