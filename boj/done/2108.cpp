/*
    https://www.acmicpc.net/problem/2108
    (statistics)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

5
-1
-1
-1
-1
0

// -1 -1 -1 1

*/

const int ARR_SIZE = 500'000;
const int MIN_NUM = -4000;
const int MAX_NUM = 4000;
int N;
int arr[ARR_SIZE + 1];
int occurred[MAX_NUM << 2 + 1];
int sum;
int avg;
int max_occurred;
set<int> max_occurred_num;

void solve(){
    // 1
    int avg = sum / N;
    if(sum > 0){
        if(sum % N > N/2){
            ++avg;
        }
    }
    else{
        sum = -sum;
        if(sum % N > N/2){
            --avg;
        }
    }

    // 2 4
    sort(arr+1, arr+1+N, less<int>());

    // 3
    for(int num=0; num<=MAX_NUM << 2; ++num){
        max_occurred = max(max_occurred, occurred[num]);
    }
    for(int num=0; num<=MAX_NUM << 2; ++num){
        if(occurred[num] == max_occurred){
            max_occurred_num.insert(num-MAX_NUM);
        }
    }
    auto it = max_occurred_num.begin();
    if(max_occurred_num.size() > 1){
        ++it;
    }

    // cout << (int)round(sum / (double)N) << endl;
    cout << avg << endl;
    cout << arr[N/2+1] << endl;
    cout << *it << endl;
    cout << arr[N] - arr[1] << endl;
}

void input(){
    cin >> N;
    for(int i=1; i<=N; ++i){
        cin >> arr[i];
        sum += arr[i];
        ++occurred[arr[i] + MAX_NUM];
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
