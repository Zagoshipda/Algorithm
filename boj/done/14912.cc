/*
    https://www.acmicpc.net/problem/14912
    (digit frequency)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    n ~ 10^5
    5 digits each => 10^6 => brute force
*/

const int MIN_NUM = 1;
const int MAX_NUM = 100'000;    // 10^5

int n, d;
int digits[10];
void solve_brute_force(){
    for(int num=1; num<=n; ++num){
        int val = num;
        while(val){
            ++digits[val % 10];
            val /= 10;
        }
    }
    cout << digits[d] << endl;
}

void solve(){
    solve_brute_force();
}

void input(){
    cin >> n >> d;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
