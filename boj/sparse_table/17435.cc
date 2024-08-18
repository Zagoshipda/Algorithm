/*
    https://www.acmicpc.net/problem/17435
    (function composition and query)

    similar problem
        https://www.acmicpc.net/problem/13171
        (logarithmic exponential)

        https://www.acmicpc.net/problem/3117
        (youtube)

    solution
        https://www.acmicpc.net/source/18154260
        (snowflake, 92 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        NOTE : NOT a permutation

    Algorithm
        sparse table
        NOTE : check whether the given function satisfies the condition for composition
            f(g(x)) = (fg)(x) ?

        function parameter ~ O(10^6)
        # of composition n ~ 5 * 10^5 ~ 5 * (10^2 * 10^3) ~ 2^3 * (2^7 * 2^10) ~ 2^20
        => using binary encoding, at most log(n) ~ log(2^20) = 20 steps

ex.
2
2 1
6
1 1
2 1
100000 1
200001 1
499999 1
500000 1

// 2
// 1
// 1
// 2
// 2
// 1

*/

const int ARR_SIZE = 200'000;
const int MAX_COMPOSITION = 500'000;
const int MAX_POWER = 20;

int m;
// int arr[ARR_SIZE + 1];
int Q;
int n, x;

// NOTE : k starts from 0 (2^0 = 1)
int functions[MAX_POWER + 1][ARR_SIZE + 1];     // functions[k][x] = f_2^k(x), 148 ms
// int functions_2[ARR_SIZE + 1][MAX_POWER + 1];   // functions_2[x][k] = f_2^k(x), 188 ms

void solve(){
    // int power = 1;   // WRONG
    int power = 0;      // AC
    int output = x;

    // NOTE : while loop much faster than for loop ?
    while(n){
    // for(int power=0; n; ++power, n >>= 1){
        if(n & 1){
            output = functions[power][output];
            // output = functions_2[output][power];
        }
        n >>= 1;
        // power <<= 1;    // WRONG
        power += 1;     // AC
    }

    cout << output << endl;
}

void initialize(){
    // bottom up DP
    // f_2^k(x) = (f_2^k-1 * f_2^k-1)(x) = f_2^k-1(f_2^k-1(x)) for k=1...20

    for(int power=1; power<=MAX_POWER; ++power){
        for(int val=1; val<=m; ++val){
            functions[power][val] = functions[power-1][functions[power-1][val]];

            // functions_2[val][power] = functions_2[functions_2[val][power - 1]][power - 1];
        }
    }
}

void input(){
    cin >> m;
    for(int ith=1; ith<=m; ++ith){
        // cin >> arr[ith];
        // functions[0][ith] = arr[ith];

        cin >> functions[0][ith];
        // cin >> functions_2[ith][0];
    }

    initialize();

    cin >> Q;
    for(int ith=1; ith<=Q; ++ith){
        cin >> n >> x;

        solve();
    }
}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    input();

    // solve();

    return 0;
}
