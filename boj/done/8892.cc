/*
    https://www.acmicpc.net/problem/8892
    (palindrome)

    solutions
        https://www.acmicpc.net/source/1093051
        (wowoto9772, 12 ms) : implemented in solve_brute_force_2()
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    palindrome is a word which can be read the same way in either direction
    password
        concatenation of "two different" strings out of the k words
        it is a palindrome
    => find the password from k given words

    k ~ 10^2
    k^2 ~ 10^4

1
2
abc
ba

// abcba

*/

const int NUM_WORD = 100;       // 10^2
const int MAX_LENGTH = 10'000;  // 10^4
int T;
int k;
string words[NUM_WORD + 1];

bool is_palindrome(string str){
    int len = str.size();
    for(int start=0, end=len-1; start<=end; ++start, --end){
        if(str[start] != str[end]){
            return false;
        }
    }
    return true;
}

void solve_brute_force_1(){
    string word_1, word_2;
    for(int idx=1; idx<=k; ++idx){
        word_1 = words[idx];
        for(int jdx=idx+1; jdx<=k; ++jdx){
            word_2 = words[jdx];
            if(is_palindrome(word_1 + word_2)){
                cout << word_1 + word_2 << endl;
                return;
            }
            if(is_palindrome(word_2 + word_1)){
                cout << word_2 + word_1 << endl;
                return;
            }
        }
    }
    cout << 0 << endl;
}

void solve_brute_force_2(){
    string word_1, word_2;
    for(int idx=1; idx<=k; ++idx){
        word_1 = words[idx];
        for(int jdx=1; jdx<=k; ++jdx){
            if(idx == jdx){
                continue;
            }

            word_2 = words[jdx];
            if(is_palindrome(word_1 + word_2)){
                cout << word_1 + word_2 << endl;
                return;
            }
        }
    }
    cout << 0 << endl;
}

void solve(){
    // solve_brute_force_1();
    solve_brute_force_2();
}

void input(){
    cin >> T;
    while(T--){
        cin >> k;
        for(int i=1; i<=k; ++i){
            cin >> words[i];
        }
        solve();
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
