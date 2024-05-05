/*
    https://www.acmicpc.net/problem/2343
    (guitar lesson)

    similar problem
        https://www.acmicpc.net/problem/6236
        (monthly expense)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

6 2
10000 2 4 10000 12 3

// 10015

9 3
9 1 2 3 4 5 6 7 8

// 15

*/

const int ARR_SIZE = 100'000;   // 10^5
const int MAX_NUM = 10'000;     // 10^4
const int MAX_SIZE = ARR_SIZE * MAX_NUM;    // 10^9

int N, M;
int arr[ARR_SIZE + 1];
int max_arr;
int sum_arr;

void solve_parametric_search(){
    ll left, right, middle;
    ll min_size = MAX_SIZE;
    for(left=max_arr, right=sum_arr; left<=right; ){
        middle = (left + right) >> 1;
        int cnt = 1;
        int sum = 0;
        for(int idx=1; idx<=N; ++idx){
            if(sum + arr[idx] <= middle){
                sum += arr[idx];
            }
            else{
                sum = arr[idx];
                ++cnt;
            }
        }

        if(cnt > M){
            left = middle + 1;
        }
        else{
            min_size = min(min_size, middle);
            right = middle - 1;
        }
    }
    cout << min_size << endl;
}

void solve(){
    solve_parametric_search();
}

void input(){
    cin >> N >> M;
    for(int i=1; i<=N; ++i){
        cin >> arr[i];
        max_arr = max(max_arr, arr[i]);
        sum_arr += arr[i];
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
