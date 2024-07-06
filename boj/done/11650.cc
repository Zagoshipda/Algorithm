/*
    https://www.acmicpc.net/problem/11650
    (coordinate sorting)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int ARR_SIZE = 100'000;   // 10^5

int N;
pair<int, int> arr[ARR_SIZE + 1];

void solve(){
    sort(arr+1, arr+1+N, less<pair<int, int> >());
    for(int idx=1; idx<=N; ++idx){
        cout << arr[idx].first << " " << arr[idx].second << endl;
    }
}

void input(){
    cin >> N;
    for(int idx=1; idx<=N; ++idx){
        cin >> arr[idx].first >> arr[idx].second;
    }
}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    input();

    solve();

    return 0;
}
