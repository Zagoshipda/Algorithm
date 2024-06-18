/*
    https://www.acmicpc.net/problem/1744
    (number together)

    similar problem
        https://www.acmicpc.net/problem/2036
        (score of array)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

#define NUM 50

int N;
int arr[NUM + 1];

void solve_arr(){
    sort(arr+1, arr+1+N, less<int>());

    int pos_zero = -1;
    int pos_right = -1;
    for(int idx=1; idx<=N; ++idx){
        if(pos_zero < 0 && arr[idx] == 0){
            pos_zero = idx;
        }
        else if(arr[idx] > 0){
            pos_right = idx;
            break;
        }
    }
    if(pos_right < 0){
        pos_right = N+1;
    }
    // no zeros
    if(pos_zero < 0){
        pos_zero = pos_right;
    }

    int max_sum = 0;
    int idx_left;
    for(idx_left=1; idx_left<pos_zero-1; ){
        max_sum += arr[idx_left] * arr[idx_left+1];
        idx_left += 2;
    }
    if(idx_left == pos_zero-1){
        if(idx_left+1 > N || arr[idx_left+1] != 0){   // arr[idx_left+1] > 0
            max_sum += arr[idx_left];
        }
    }

    int idx_right;
    for(idx_right=N; idx_right>pos_right; ){
        if(arr[idx_right] == 1 || arr[idx_right-1] == 1){
            max_sum += arr[idx_right] + arr[idx_right-1];
        }
        else{
            max_sum += arr[idx_right] * arr[idx_right-1];
        }
        idx_right -= 2;
    }
    if(idx_right == pos_right){
        max_sum += arr[idx_right];
    }

    cout << max_sum << endl;
}

void solve_vector(){

}

void solve_pq(){

}

void solve(){
    solve_arr();

    // solve_vector();

    // solve_pq();
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
