/*
    https://www.acmicpc.net/problem/1322
    (bitwise or euqals to addition)

    solution
        https://www.acmicpc.net/source/6478345
        (wonmo, 0 ms)
        https://www.acmicpc.net/source/24094813
        (wider93, 0 ms)
        https://www.acmicpc.net/source/11972617
        (shiftpsh, 0 ms)
        https://www.acmicpc.net/source/817223
        (koosaga, 0 ms)
        https://www.acmicpc.net/source/5073129
        (kipa00, 0 ms) : using bitwise operations, x & (-x)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    X + Y = X | Y
    (observation) can both X and Y be the 1 on some bit ?
        <=> can Y be 1 on X's 1 bit ?
        => (X)

    Y can have 1 only on X's 0 bit
    Y set to 0 on X's 1 bit

    10^18 ~ 2^10^6 ~ 2^60

    bitwise or distributive over operations (+, -, *, /) ?
        (a + b) | c = a | c + b | c ? (X)
        11 + 1 = 100
        (11 | 1 + 1 | 1 = 11 + 1 = 100) != (101 = 100 | 1)


2000000000 2000000000

// 16383165351936

1073741823 2000000000

// 2147483648000000000

*/

const int MAX_NUM = 2'000'000'000;  // 2 * 10^9
// const int MAX_BIT = 60; // WRONG (oooops...)
const int MAX_BIT = 63; // AC

ll X, K;
ll Y;

void solve_bitset(){
    bitset<MAX_BIT> bs_x(X);
    bitset<MAX_BIT> bs_k(K);
    bitset<MAX_BIT> bs_y;
    for(int idx=0, jdx=0; K; ++idx){
        if(bs_x.test(idx)){
            bs_y.reset(idx);
        }
        else{
            bs_y[idx] = bs_k[jdx];
            ++jdx;
            K >>= 1;
        }
    }
    cout << bs_y.to_ullong() << endl;
}

void solve(){
    solve_bitset();
}

void input(){
    cin >> X >> K;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
