/*
    https://www.acmicpc.net/problem/23758
    (change the median)

    solutions
        https://www.acmicpc.net/source/35820654
        (kimjihoon, 364 ms)

        https://www.acmicpc.net/source/36040221
        (cheetose, 392 ms) : __builtin_clz() count the leading zeros in 32 bits
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        median / 2 until zero appears

    Algorithm
        input size N ~ 10^7
        1's time limit ~ 10^9
        => at most 10^2 operations required per input size N

        median / 2 only decreases number
        => median number = largest among a_1...a_(N+1)/2
        => maximum priority queue?

        in order to make 0, must get 1, 2, 2^2, 2^3, ...
        => if a_(N+1)/2 = 1 then we get 0 after the operation
        => count (# of operations required to make a_k = 1) + 1 (last operation to make 0)

        10^9 ~ 2^32 => at most 32 operations

        1 2 3
        0 1
        // 2

        1 2 2 5 6 6 6
        0 1 1 2
        // 5
*/

const int ARR_SIZE = 2'000'000;  // 2* 10^6
const int MIN_NUM = 1;
const int MAX_NUM = 1'000'000'000;  // 10^9
const int TARGET = 1;

int N;
int arr[ARR_SIZE + 1];
map<int, int> hashes;   // (number, cnt)

void solve(){
    sort(arr+1, arr+1+N, less<int>());

    int len = (N+1) >> 1;
    int ops = 1;
    int median = arr[len];
    for(int idx=1; idx<=len; ++idx){
        int val, cnt;
        for(val=arr[idx], cnt=0; TARGET < val; val >>= 1, ++cnt){

        }
        ops += cnt;
    }

    cout << ops << endl;
}

void input(){
    cin >> N;
    for(int i=1; i<=N; ++i){
        cin >> arr[i];
        // ++hashes[arr[i]];
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
