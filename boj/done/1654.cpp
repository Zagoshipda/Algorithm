/*
    https://www.acmicpc.net/problem/1654
    (cut the lan cable)

    sample input
        https://www.acmicpc.net/board/view/112075

    similar problem
        https://www.acmicpc.net/problem/2805
        (rod cutting) : EKO
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    K <= N
    assume solution always exists
    NOTE : can throw away some useless parts

1 1
2147483647

// 2147483647

3 4
1 2147483647 2147483647

// 1

3 5
2 2147483647 2147483647

// 2

3 4
2 6 19

// 6

*/

const int ARR_SIZE = 10'000;
const int NUM_TARGET = 1'000'000;
const ll MAX_NUM = INT_MAX;
int K, N;
ll lans[ARR_SIZE + 1];

void solve_1(){
    sort(lans+1, lans+1+K, less<int>());

    ll max_len = 0; // NOTE : int range
    for(ll left=1, right=lans[K]; left<=right; ){   // NOTE : int range
        ll len = (left + right) >> 1;   // NOTE : int range
        ll sum = 0;                     // NOTE : int range
        for(int idx=1; idx<=K; ++idx){
            sum += lans[idx] / len;
        }
        if(N <= sum){
            max_len = max(max_len, len);
            left = len + 1;
        }
        else if(sum < N){
            right = len - 1;
        }
    }

    cout << max_len << endl;
}

void solve_parametric_search(){
    ll max_length = 0;
    ll left, right, middle;
    for(left=1, right=MAX_NUM; left<=right; ){
        middle = (left + right) >> 1;
        int cnt = 0;
        for(int idx=1; idx<=K; ++idx){
            cnt += lans[idx] / middle;
        }
        // cout << middle << " " << cnt << endl;
        if(cnt < N){
            right = middle - 1;
        }
        else{
            max_length = max(max_length, middle);
            left = middle + 1;
        }
    }
    // cout << max_length << endl;
    cout << left - 1 << endl;
}

void solve(){
    // solve_1();
    solve_parametric_search();
}

void input(){
    cin >> K >> N;
    for(int i=1; i<=K; ++i){
        cin >> lans[i];
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
