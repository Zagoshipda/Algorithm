/*
    https://www.acmicpc.net/problem/14040
    (hidden palindrome)

    solutions
        https://www.acmicpc.net/source/34707901
        (YunGoon, 0 ms) : reverse()
        https://www.acmicpc.net/source/22404867
        (dotorya, 0 ms) : string() constructor

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    - palindrome is a word which is the same when read forwards as it is when read backwards
    - what is the longest palindrome that is contained in the word
*/

string word;
bool is_palindrome(string str){
    int len = str.size();
    for(int left=0, right=len-1; left<right; ++left, --right){
        if(str[left] != str[right]){
            return false;
        }
    }
    return true;
}

void solve_substring(){
    int len = word.size();
    int cnt = 0;
    for(int left=0; left<len; ++left){
        for(int right=left; right<len; ++right){
            // if(is_palindrome(word.substr(left, right-left+1))){
            if(is_palindrome(string(word, left, right-left+1))){
                cnt = max(cnt, right-left+1);
            }
        }
    }
    cout << cnt << endl;
}

void solve_wrong(){
    string reversed = word;
    reverse(reversed.begin(), reversed.end());

    int len = word.size();
    int cnt = 0;
    for(int left=0; left<len; ++left){
        for(int right=left; right<len; ++right){
            bool is_palindrome = true;
            for(int idx=left; idx<=right; ++idx){
                if(word[idx] != reversed[idx]){
                    is_palindrome = false;
                    break;
                }
            }
            if(is_palindrome){
                cnt = max(cnt, right-left+1);
            }
        }
    }
    cout << cnt << endl;
}

void solve(){
    solve_substring();
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
