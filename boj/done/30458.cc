/*
    https://www.acmicpc.net/problem/30458
    (palindrome anagram)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int MIN_LENGTH = 3;
const int MAX_LENGTH = 200'000;

int N;
string S;
map<char, int> letters;

void solve(){
    for(int left=0, right=N-1; left<right; ++left, --right){
        ++letters[S[left]];
        // --letters[S[right]];
        ++letters[S[right]];
    }
    for(auto it=letters.begin(); it!=letters.end(); ++it){
        if(it->second & 1){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

void input(){
    cin >> N;
    cin >> S;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
