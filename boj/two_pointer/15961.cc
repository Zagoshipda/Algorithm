/*
    https://www.acmicpc.net/problem/15961
    (rotating kimbob)

    solution
        https://www.acmicpc.net/source/22056616
        (YunGoon, 228 ms) : if condition -> deterministic boolean
*/

#include <bits/stdc++.h>

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'
#define ll long long

using namespace std;

/*

*/

const int ARR_SIZE = 3'000'000;     // 3 * 10^6
const int MIN_NUM = 2;
const int MAX_NUM = 3'000;          // 3 * 10^6
const int MAX_CHOICE = 3'000;       // 3 * 10^3

int N, d, k, c;
int arr[ARR_SIZE + 1];

// int get_index(int idx){
inline int get_index(int idx){
    return idx % N;
}

// map<int, int> hashes;               // (type, cnt), TLE
// unordered_map<int, int> hashes;     // (type, cnt), 392 ms
int hashes[MAX_NUM + 1];            // (type, cnt), 240 ms
void solve_sliding_window(){
    int max_cnt = 0;
    for(int ith=0; ith<k; ++ith){
        // if(hashes.count(arr[ith]) <= 0){
        if(hashes[arr[ith]] <= 0){
            ++max_cnt;
        }
        ++hashes[arr[ith]];
    }

    int cnt = max_cnt;
    for(int left=0, right=k; left<N; ++left, ++right){
        --hashes[arr[get_index(left)]];
        if(hashes[arr[get_index(left)]] <= 0){
            --cnt;
        }

        if(hashes[arr[get_index(right)]] <= 0){
            ++cnt;
        }
        ++hashes[arr[get_index(right)]];

        // coupon
        if(hashes[c] <= 0){
            max_cnt = max(max_cnt, cnt + 1);
        }
        else{
            max_cnt = max(max_cnt, cnt);
        }
    }

    cout << max_cnt << endl;
}

void solve(){
    solve_sliding_window();
}

void input(){
    cin >> N >> d >> k >> c;
    for(int ith=0; ith<N; ++ith){
        cin >> arr[ith];
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
