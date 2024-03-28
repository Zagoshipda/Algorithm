/*
    https://www.acmicpc.net/problem/16208
    (polynomial product)

    solutions
        https://www.acmicpc.net/source/10631651
        (jung2381187, 28 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    polynomial product
    a b c d
    a (b (c d))
        ab ac ad + bc bd + cd
    ((a b) c) d
        ad bd cd + ac bc + ab
    (a b) (c d)
        ac ad bc bd + ab + cd

    3 5 4 2
    48 + 15 + 8 = 71
*/

const int ARR_SIZE = 500'000;   // 5 * 10^5
const int MAX_LENGTH = 101;
int n;
ll arr[ARR_SIZE + 1];
ll sum;
ll cost;

void solve_1(){
    for(int idx=1; idx<=n; ++idx){
        cost += (sum - arr[idx]) * arr[idx];
    }
    cout << (cost >> 1) << endl;
}

void solve(){
    // solve_1();
}

void input(){
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> arr[i];
        cost += (sum * arr[i]);
        sum += arr[i];
    }
    cout << cost << endl;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
