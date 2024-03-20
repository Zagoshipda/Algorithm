/*
    https://www.acmicpc.net/problem/1259
    (palindrome numbers)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    A word is a palindrome if it reads the same backwards as it does forwards
    numbers written in the normal decimal way, with no leading zeros
*/

const int MIN_NUM = 1;
const int MAX_NUM = 99'999;
int N;
string N_str;

void solve(){
    // N_str = to_string(N);
    int len = N_str.size();

    for(int start=0, end=len-1; start<=end; ++start, --end){
        if(N_str[start] != N_str[end]){
            cout << "no" << endl;
            return;
        }
    }
    cout << "yes" << endl;
}

void input(){
    // while(cin >> N){
    while(cin >> N_str){
        // if(N == 0){
        if(N_str == "0"){
            break;
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
