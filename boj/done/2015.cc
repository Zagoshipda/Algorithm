/*
    https://www.acmicpc.net/problem/2015
    (sum of numbers 4)

    similar problem
        https://www.acmicpc.net/problem/1208
        (sum of subarray/subsequence 2) : subset

        https://www.acmicpc.net/problem/2003
        (sum of numbers 2)
        ttps://www.acmicpc.net/problem/19566
        (segment mean)

        https://www.acmicpc.net/problem/2018
        (sum of numbers 5) : herd sums

    solution
        https://www.acmicpc.net/source/26717770
        (yj10516, 40 ms) : upper_bound() - lower_bound()

        implemented in solve_hash_2()
            https://www.acmicpc.net/source/5369784
            (pps789, 28 ms)
            https://www.acmicpc.net/source/5146683
            (aung, 36 ms)
            https://www.acmicpc.net/source/8064963
            (woo960131, 36 ms)

    reference
        https://khu98.tistory.com/262
        prefix_sum[i] - prefix_sum[j] = K (j < i)
        prefix_sum[j] = prefix_sum[i] - K (j < i)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        N ~ 10^5
        - numbers in range -10^4 ~ +10^4

    Algorithm
        dp ? suffix
        dp[i][k] : # of subarray sum == k
        dp[i][k] = dp[i+1][k] + dp[i+1][k-arr[i]]
        => since K ~ 10^9, space overflow

        WANT : prefix_sum[j] - prefix_sum[i] = K
            ai + ... + ak + ... + aj = x
            ai + ... + ak = x - k
            => ak+1 + ... + aj = k
*/

const int ARR_SIZE = 200'000;   // 2 * 10^5
const int MIN_NUM = -10'000;    // - 10^4
const int MAX_NUM = +10'000;    // + 10^4
const int MIN_SUM = ARR_SIZE * MIN_NUM; // - 2 * 10^9
const int MAX_SUM = ARR_SIZE * MAX_NUM; // + 2 * 10^9

int N, K;
int arr[ARR_SIZE + 1];

int prefix_sum[ARR_SIZE + 1];
// map<int, int> hashes;   // (value, cnt)
unordered_map<int, int> hashes;   // (value, cnt)
ll cnt;

// NOTE : only when elements are positive integers
void solve_two_pointer_wrong(){
    int right = 1;
    int sum = arr[1];

    for(int left=1; left<=N; ++left){
        while(right<N && sum < K){
            ++right;
            sum += arr[right];
        }

        if(sum == K){
            ++cnt;
        }
        sum -= arr[left];
    }

    cout << cnt << endl;
}

void solve_hash_1(){
    for(int idx=1; idx<=N; ++idx){
        cnt += hashes[prefix_sum[idx] - K];
        cnt += (prefix_sum[idx] == K);
        ++hashes[prefix_sum[idx]];
    }

    cout << cnt << endl;
}

void solve_hash_2(){
    hashes.insert({0, 1});
    for(int idx=1; idx<=N; ++idx){
        cnt += hashes[prefix_sum[idx] - K];
        ++hashes[prefix_sum[idx]];
    }

    cout << cnt << endl;
}

void review(){
    for(int idx=1; idx<=N; ++idx){
        cnt += hashes[prefix_sum[idx] - K];
        if(prefix_sum[idx] == K){
            ++cnt;
        }
        ++hashes[prefix_sum[idx]];
    }
    cout << cnt << endl;
}

void solve(){
    // solve_two_pointer_wrong();

    // solve_hash_1();
    // solve_hash_2();

    review();
}

void input(){
    cin >> N >> K;
    for(int i=1; i<=N; ++i){
        cin >> arr[i];
        prefix_sum[i] = prefix_sum[i-1] + arr[i];
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
