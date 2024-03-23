/*
    https://www.acmicpc.net/problem/11399
    (ATM)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int NUM_TIMES = 1'000;
int N;
int times[NUM_TIMES + 1];
int prefix_time[NUM_TIMES + 1];

void solve_1(){
    sort(times+1, times+1+N, less<int>());

    int sum = 0;
    for(int idx=1; idx<=N; ++idx){
        prefix_time[idx] = prefix_time[idx-1] + times[idx];
        sum += prefix_time[idx];
    }

    cout << sum << endl;
}

void solve_2(){
    sort(times+1, times+1+N, less<int>());

    int sum = 0;
    for(int idx=1; idx<=N; ++idx){
        sum += (N-(idx-1)) * times[idx];
    }
    cout << sum << endl;
}

void solve(){
    // solve_1();
    solve_2();
}

void input(){
    cin >> N;
    for(int i=1; i<=N; ++i){
        cin >> times[i];
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
