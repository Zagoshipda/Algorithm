/*
    https://www.acmicpc.net/problem/13900
    (sum of pair products)

    solutions
        https://www.acmicpc.net/source/4705619
        (deneb2016, 8 ms) : process as input comes, implemented in solve_2()

        https://www.acmicpc.net/source/4758841
        (sukusuku, 0 ms) : polynomial product with inclusion-exclusion, implemented in solve_3()
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    N ~ 10^5
    N^2 ~ 10^10
    1s ~ 10^9
    sum of products with numbers of different positions
        a[1]*a[2] + ... + a[N-1]*a[N]
*/

const int ARR_SIZE = 100'000;   // 10^5
const int MIN_NUM = 0;
const int MAX_NUM = 10'000;     // 10^4

int N;
ll arr[ARR_SIZE + 1];
ll sum;    // NOTE : check range ~ 10^9

void solve_1(){
    ll product_sum = 0;     // NOTE : check range
    for(int idx=1; idx<=N; ++idx){
        product_sum += arr[idx] * (sum - arr[idx]);
    }
    // NOTE : counted twice for each product
    cout << (product_sum >> 1) << endl;
}

void solve_2(){
    ll sum = arr[1];
    ll product_sum = 0;
    for(int idx=2; idx<=N; ++idx){
        product_sum += sum * arr[idx];
        sum += arr[idx];
    }
    cout << product_sum << endl;
}

ll squares;
void solve_3(){
    cout << ((sum * sum - squares) >> 1) << endl;
}

void solve(){
    // solve_1();
    // solve_2();

    solve_3();
}

void input(){
    cin >> N;
    for(int i=1; i<=N; ++i){
        cin >> arr[i];
        sum += arr[i];
        squares += arr[i] * arr[i];
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
