/*
    https://www.acmicpc.net/problem/12015
    (lis 2)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int ARR_SIZE = 1'000'000;
int N;
int arr[ARR_SIZE + 1];

void solve_binary_search(){
    vector<int> lis;
    lis.push_back(arr[1]);
    for(int idx=2; idx<=N; ++idx){
        if(lis.back() < arr[idx]){
            lis.push_back(arr[idx]);
        }
        else{
            auto it = lower_bound(lis.begin(), lis.end(), arr[idx]);
            *it = arr[idx];
        }
    }
    cout << lis.size() << endl;
}

void solve(){
    solve_binary_search();
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
