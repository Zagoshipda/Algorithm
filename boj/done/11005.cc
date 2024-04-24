/*
    https://www.acmicpc.net/problem/11005
    (base conversion 2)

    similar problem
        https://www.acmicpc.net/problem/2745
        (base conversion 1)
        https://www.acmicpc.net/problem/1112
        (base conversion)
        https://www.acmicpc.net/problem/5720
        (bases)
        https://www.acmicpc.net/problem/6757
        (all your base belong to palindromes)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int MAX_BASE = 36;

int N, B;

void solve_1(){
    vector<char> base_B;
    int remainder;
    while(N){
        remainder = N % B;
        if(remainder > 9){
            base_B.push_back('A' + remainder - 10);
        }
        else{
            base_B.push_back('0' + remainder);
        }
        N /= B;
    }

    for(auto it = base_B.rbegin(); it != base_B.rend(); ++it){
        cout << *it;
    }
    cout << endl;
}

void solve(){
    solve_1();
}

void input(){
    cin >> N >> B;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
