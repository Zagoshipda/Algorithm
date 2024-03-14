/*
    https://www.acmicpc.net/problem/1342
    (lucky string)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    time complexity
        10! ~ 10^5 * 120 ~ 10^7
        => brute force
*/

const int MAX_LEN = 10;
const int MIN_LETTER = 'a';
const int MAX_LETTER = 'z';

string S_str;

bool is_lucky(string str){
    for(int idx=1; idx<str.size(); ++idx){
        if(str[idx-1] == str[idx]){
            return false;
        }
    }
    return true;
}

void solve_brute_force(){
    int cnt = 0;
    sort(S_str.begin(), S_str.end(), less<char>());
    do{
        if(is_lucky(S_str)){
            ++cnt;
        }
    }
    while(next_permutation(S_str.begin(), S_str.end()));
    cout << cnt << endl;
}

void solve(){
    solve_brute_force();
}

void input(){
    cin >> S_str;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
