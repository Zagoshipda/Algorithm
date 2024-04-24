/*
    https://www.acmicpc.net/problem/2745
    (base conversion 1)

    similar problem
        https://www.acmicpc.net/problem/11005
        (base conversion 2)
        https://www.acmicpc.net/problem/5720
        (bases)
        https://www.acmicpc.net/problem/6757
        (all your base belong to palindromes)

    solution
        https://www.acmicpc.net/source/26865495
        (index, 4 ms) : implemented in solve_2()
        https://www.acmicpc.net/source/36769009
        (ai4youej, 68 ms) : python, print(int(a, int(b)))
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int MIN_BASE = 2;
const int MAX_BASE = 36;

string N_str;
int B;

void solve_1(){
    int sum = 0;
    int len = N_str.size();
    for(int idx=0; idx<len; ++idx){
        sum *= B;
        if(N_str[idx] - '0' > 9){
            sum += 10 + N_str[idx] - 'A';
        }
        else{
            sum += N_str[idx] - '0';
        }
    }
    cout << sum << endl;
}

void solve_2(){
    // size_t pos;
    // int ans = stoi(N_str, &pos, B);
    // cout << ans << " " << pos << endl;

    cout << stoi(N_str, nullptr, B) << endl;
}

void solve(){
    // solve_1();

    solve_2();
}

void input(){
    cin >> N_str >> B;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
