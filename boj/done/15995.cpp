/*
    https://www.acmicpc.net/problem/15995
    (modular inverse)

    similar problem
        https://www.acmicpc.net/problem/6930
        (mod inverse)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int MIN_NUM = 2;
const int MAX_NUM = 10'000;
int a, m;

void solve_brute_force(){
    // NOTE : modular inverse can be [1...m-1]
    for(int num=1; num<m; ++num){
        if(a * num % m == 1){
            cout << num << endl;
            break;
        }
    }
}

void solve(){
    solve_brute_force();
}

void input(){
    cin >> a >> m;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
