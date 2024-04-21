/*
    https://www.acmicpc.net/problem/28323
    (unstable array)

    solution
        https://www.acmicpc.net/source/63862685
        (index, 56 ms) : implemented in solve_greedy_2()
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Algorithm
        add up to odd : different parity
        add up to even : same parity
            => can think of it as a substitution with the later element
*/

const int ARR_SIZE = 300'000;
const int MAX_NUM = 100'000;

int N;
int arr[ARR_SIZE + 1];

void solve_greedy_1(){
    int cnt = 1;
    for(int prev=1, idx=2; idx<=N; ++idx){
        // if((arr[prev] + arr[idx]) & 1){
        if((arr[prev] ^ arr[idx]) & 1){
            ++cnt;
            prev = idx;
        }
    }
    cout << cnt << endl;
}

void solve_greedy_2(){
    int cnt = 1;
    for(int idx=1; idx<N; ++idx){
        if((arr[idx] ^ arr[idx+1]) & 1){
            ++cnt;
        }
    }
    cout << cnt << endl;
}

void solve(){
    // solve_greedy_1();

    solve_greedy_2();
}

void input(){
    int cnt = 1;
    cin >> N;
    for(int i=1; i<=N; ++i){
        cin >> arr[i];
        if(i>1 && (arr[i] ^ arr[i-1]) & 1){
            ++cnt;
        }
    }
    cout << cnt << endl;
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
