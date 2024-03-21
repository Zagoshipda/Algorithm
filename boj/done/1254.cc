/*
    https://www.acmicpc.net/problem/1254
    (make a palindrome)

    solutions
        https://www.acmicpc.net/source/6657793
        (BaaaaaaaaaaarkingDog, 0 ms) : implemented in solve_brute_force_3()

        https://www.acmicpc.net/source/3363436
        (danielee99, 0 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    length <= 50 ~ 10^2
    => brute force ?

    since result should be a palindrome and always add a character at the end of the input, the result should be symmetric from the start of the input
    => try all from the beginning of the input, brute force

*/

const int MAX_SIZE = 50;
string S;

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
    string prefix, suffix;
    int len = S.size();
    int idx = 0;
    while(!is_palindrome(S + suffix)){
        prefix += S[idx];
        suffix = prefix;
        reverse(suffix.begin(), suffix.end());
        ++idx;
    }
    cout << (S+suffix).size() << endl;
}

void solve_brute_force_2(){
    string suffix;
    int cnt = 1;
    while(!is_palindrome(S + suffix)){
        suffix = S.substr(0, cnt);
        reverse(suffix.begin(), suffix.end());
        ++cnt;
    }
    cout << (S + suffix).size() << endl;
}

void solve_brute_force_3(){
    int len = S.size();
    for(int idx=0; idx<len; ++idx){
        if(is_palindrome(S.substr(idx, len-idx))){
            cout << len + idx << endl;
            break;
        }
    }
}

void solve(){
    // solve_brute_force_1();

    // solve_brute_force_2();

    solve_brute_force_3();
}

void input(){
    cin >> S;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
