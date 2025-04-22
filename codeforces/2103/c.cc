/*
    https://codeforces.com/contest/2103/problem/C
    (C. Median Splits)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        determine for 1 <= l < r < n
        med(med(arr[1...l]), med(arr[l+1...r]), med(arr[r+1...n])) <= k
        where med := ceil(n / 2)-th smallest element of arr[1...n]

    Algorithm
        two pointer ?
        greedy ?
        dp ?


        asssume arr[1...l]) <= med(arr[l+1...r]) <= med(arr[r+1...n]
        med(arr[1...l]), med(arr[l+1...r]), med(arr[r+1...n]) <= k
        <=> arr[1...l]) <= med(arr[l+1...r]) <= k <= med(arr[r+1...n]

        n ~ O(2 * 10^5)
        brute force
            for fixed l ~ O(n), choice of r ~ O(n) => O(n^2) ~ O(10^10)

        [observation] : prefix - () - suffix


        DP
        S ubproblem
        R ecurrence relation
        T opological order
        B ase case
        O riginal problem
        T ime complexity
*/

const int NUM_TESTCASE = 10'000;    // 10^4
const int ARR_SIZE = 200'000;       // 2 * 10^5
const int MAX_NUM = 1'000'000'000;  // 10^9
const int INF = ARR_SIZE << 1;

int t;
int n, k;
int arr[ARR_SIZE << 1];

int prefix[ARR_SIZE << 1];
int suffix[ARR_SIZE << 1];

// NOTE : O(n^2) -> O(n)
int min_prefix[ARR_SIZE << 1];
int min_suffix[ARR_SIZE << 1];

void initialize(){
    for(int ith=0; ith<=n + 1; ++ith){
        prefix[ith] = 0;
        suffix[ith] = 0;

        min_prefix[ith] = INF;
        min_suffix[ith] = INF;
    }
}

void solve(){
    initialize();

    for(int ith=1; ith<=n; ++ith){
        prefix[ith] = prefix[ith - 1];
        if(arr[ith] <= k){
            prefix[ith] += 1;
        }
        else{
            prefix[ith] -= 1;
        }

        min_prefix[ith] = min(min_prefix[ith - 1], prefix[ith]);
    }
    for(int ith=n; ith>=0; --ith){
        suffix[ith] = suffix[ith + 1];
        if(arr[ith] <= k){
            suffix[ith] += 1;
        }
        else{
            suffix[ith] -= 1;
        }

        min_suffix[ith] = min(min_suffix[ith + 1], suffix[ith]);
    }

    for(int ith=1; ith<=n-2; ++ith){
        if(0 <= prefix[ith]){
            if(suffix[ith + 1] >= min_suffix[ith + 2]){
                cout << "YES" << endl;
                return;
            }
        }
    }
    for(int ith=n; ith>=3; --ith){
        if(0 <= suffix[ith]){
            if(prefix[ith - 1] >= min_prefix[ith - 2]){
                cout << "YES" << endl;
                return;
            }
        }
    }

    int left = INF;
    int right = -1;
    for(int ith=1; ith<=n; ++ith){
        if(0 <= prefix[ith]){
            left = ith;
            break;
        }
    }
    for(int ith=n; ith>=1; --ith){
        if(0 <= suffix[ith]){
            right = ith;
            break;
        }
    }
    if(left + 2 <= right){
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;
}

void input(){
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int ith=1; ith<=n; ++ith){
            cin >> arr[ith];
        }
        solve();
    }
}

void debug(){

}

int main(){

    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    // debug();

    input();

    // solve();

    return 0;
}
