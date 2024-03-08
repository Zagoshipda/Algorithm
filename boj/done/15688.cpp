/*
    https://www.acmicpc.net/problem/15688
    (sort 5)

    solution
        https://www.acmicpc.net/source/38123963
        (syoh0708, 4356 ms) : counting sort
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int NUM = 1'000'000;
int N;
int arr[NUM + 1];

void solve(){
    sort(arr+1, arr+1+N, less<int>());
    for(int idx=1; idx<=N; ++idx){
        cout << arr[idx] << endl;
    }
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
