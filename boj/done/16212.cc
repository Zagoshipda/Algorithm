/*
    https://www.acmicpc.net/problem/16212
    (sorting)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int MIN_NUM = -2'000'000; // -2 * 10^6
const int MAX_NUM = +2'000'000; // +2 * 10^6
const int ARR_SIZE = 500'000;
int N;
int arr[ARR_SIZE + 1];

void solve(){
    sort(arr+1, arr+1+N, less<int>());
    for(int idx=1; idx<=N; ++idx){
        cout << arr[idx] << " ";
    }
    cout << endl;
}

void input(){
    cin >> N;
    for(int i=1; i<=N; ++i){
        cin >> arr[i];
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
