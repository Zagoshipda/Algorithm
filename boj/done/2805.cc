/*
    https://www.acmicpc.net/problem/2805
    (rod cutting) : EKO

    similar problem
        https://www.acmicpc.net/problem/1654
        (cut the lan cable)

    reference
        https://www.acmicpc.net/blog/view/109
        implementing a binary search
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        - only allowed to cut a single row of trees
        - takes the parts that were cut off
        - set sawblade height as high as possible
        => maximum integer height of the sawblade s.t. cut off at least M wood

4 3
2 2 2 2

// 1

1 1
1

// 0

*/

const int ARR_SIZE = 1'000'000; // 10^6
const int MAX_SUM = 2'000'000'000;  // 2 * 10^9
const int MAX_NUM = 1'000'000'000;  // 10^9

int N, M;
ll arr[ARR_SIZE + 1];

void solve_parametric_search_1(){
    ll height;
    ll middle;
    for(ll left=0, right=MAX_SUM; left<=right; ){
        middle = (left + right) >> 1;

        ll sum = 0;
        for(int idx=1; idx<=N; ++idx){
            sum += arr[idx] - min(arr[idx], middle);
        }

        if(sum < M){
            right = middle - 1;
        }
        else if(sum > M){
            height = middle;
            left = middle + 1;
        }
        else{
            height = middle;
            break;
        }
    }

    for( ; ; ++height){
        ll sum = 0;
        for(int idx=1; idx<=N; ++idx){
            sum += arr[idx] - min(arr[idx], height);
        }

        if(sum < M){
            cout << height - 1 << endl;
            break;
        }
    }
}

void solve_parametric_search_2(){
    ll max_height = 0;
    ll left, right, middle;
    for(left=0, right=MAX_NUM; left<=right; ){
        middle = (left + right) >> 1;
        ll sum = 0;
        for(int idx=1; idx<=N; ++idx){
            sum += arr[idx] - min(arr[idx], middle);
        }

        if(sum >= M){
            max_height = max(max_height, middle);
            left = middle + 1;
        }
        else{
            right = middle - 1;
        }
    }
    // cout << left - 1 << endl;
    cout << max_height << endl;
}

void solve(){
    // solve_parametric_search_1();
    solve_parametric_search_2();
}

void input(){
    cin >> N >> M;
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
