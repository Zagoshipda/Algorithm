/*
    https://www.acmicpc.net/problem/2154
    (consecutive number digit 3)

    simiar problem
        https://www.acmicpc.net/problem/1748
        (consecutive number digit 1)

        https://www.acmicpc.net/problem/1790
        (consecutive number digit 2)

    solutions
        https://www.acmicpc.net/source/2906602
        (hist0613, 4 ms) : string.find()
        https://www.acmicpc.net/source/21369897
        (YunGoon, 8 ms) : strstr()

        int manipulation
            https://www.acmicpc.net/source/5800704
            (kajebiii, 0 ms)
            https://www.acmicpc.net/source/323164
            (wateret, 0 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    N ~ 10^5
    assume each 6 digit => 10^5 * 6 ~ 10^6
    => brute force

    check 6 digits for 10^6 ~ O(10^7)
*/

const int MIN_NUM = 1;
const int MAX_NUM = 100'000;    // 10^5

int N;

string digits;
void solve_brute_force(){

    for(int num=1; num<=MAX_NUM; ++num){
        digits += to_string(num);
    }

    string N_str = to_string(N);
    // int len = N_str.size();
    // for(int idx=0; ; ++idx){
    //     if(digits.substr(idx, len) == N_str){
    //         cout << idx+1 <<endl;
    //         break;
    //     }
    // }

    // cout << digits.find(N) + 1 << endl;     // WRONG
    cout << digits.find(N_str) + 1 << endl;
}

void solve(){
    solve_brute_force();
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
