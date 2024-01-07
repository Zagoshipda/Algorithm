/*
    https://www.acmicpc.net/problem/10829
    (binary translation)

    solutions
        https://www.acmicpc.net/source/3028263
        (dotorya, ll vector)

        https://www.acmicpc.net/source/643057
        (koosaga, recursion)
        https://www.acmicpc.net/source/3845500
        (rohtax, recursion)
        https://www.acmicpc.net/source/3028296
        (hxgn0221, recursion)

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    1010101010_(2)
        1 for 2^n, 0 for not
        X...X0 for even-number
        X...X1 or odd-number

    recursion check
        10^3 ~ 2^10
        10^14 ~ 2^40 * 10^2 ~ 2^40 * 2*7 ~ 2*47
        => at most 50 recursion depth
        => affordable !

*/

#define MAX_NUM 100'000'000'000'000 // 1e14
ll N;

void solve_string(){
    string binary;
    while(N){
        if(N&1){
            binary += "1";
        }
        else{
            binary += "0";
        }
        N = N >> 1;
    }

    reverse(binary.begin(), binary.end());
    cout << binary << endl;
}

void solve_vector(){
    vector<int> ans;

    while(N){
        if(N&1){
            ans.push_back(1);
        }
        else{
            ans.push_back(0);
        }
        N = N >> 1;
        // N /= 2;
    }

    reverse(ans.begin(), ans.end());

    for(int bit : ans){
        cout << bit;
    }
    cout << endl;
}

void solve_recursion(ll num){
    if(num <= 0){
        return;
    }

    solve_recursion(num >> 1);

    // if(num & 1){
    //     cout << 1;
    // }
    // else{
    //     cout << 0;
    // }

    cout << (num & 1);
    // cout << (num % 2);

    return;
}

void solve(){
    // solve_string();

    // solve_vector();

    solve_recursion(N);

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
