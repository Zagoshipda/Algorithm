/*
    https://www.acmicpc.net/problem/2751
    (sort 2)
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
    for(int i=1; i<=N; ++i){
        cout << arr[i] << endl;
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
