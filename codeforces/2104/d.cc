/*
    https://codeforces.com/contest/2104/problem/D
    (D. Array and GCD)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        [Operations]
        - pay one coin and increase any element of the array by 1
            (you must have at least 1 coin to perform this operation)
        - gain one coin and decrease any element of the array by 1

        [observation]
            we can only start by decreasing element and gain one coin
            => the sum of the resulting array must not be greater than the sum of the original one

        = an array is [ideal] if
        - each element of the array is at least 2
        - (coprime / pairwise relatively prime) : GCD of ai and aj is equal to 1 for each pair of indices i and j (1 <= i, j <= n, i != j)
        - If the array has less than 2 elements, this condition is automatically satisfied.

        = an array is [beautiful] if
        - you initially have NO coins.
        - it can be transformed into an ideal array using the aforementioned [Operations].
        - If the array is already ideal, then it is also beautiful.

        You can remove any elements from it (including removing the entire array or not removing anything at all).
        => calculate the minimum number of elements you have to remove (possibly, zero) from the array a to make it [beautiful].


    Algorithm
        n ~ 4 * 10^5
        n^2 ~ 16 * 10^10

        - how can we check coprime subset ?
            brute force ~ n^2 ~ O(10^11) => TLE ?
            n = 2
            how can we know we can make 2 numbers are coprime ?
            if k, k-1 => coprime
            - for any given 2 numbers, we can always make them coprime
            n = 3
            - make 2 numbers coprime
            - if a, b corpime, b, c coprime => a, c coprime ?
                NO 2 5, 5 8 => 2, 8 NOT coprime


        - when it is beautiful ?


        - how can we get max beautiful subset ?
            find max size coprime subset of the given array a ?



        pi(x) ~ x / log(x)
        n ~ 4 * 10^5 ~ 2^2 * 2^7 * 2^10 ~ 2^20
        logn ~ 20
        n logn ~ 8 * 10^6 ~ 10^7

        5
        1000000000 1000000000 1000000000 1000000000 1000000000
*/

const int NUM_TESTCASE = 10'000;    // 10^4
const int ARR_SIZE = 400'000;       // 4 * 10^5
const int MIN_NUM = 2;
const int MAX_NUM = 1'000'000'000;  // 10^9
const int MAX_PRIME = 10'000'000;   // 10^7

int t;
int n;
ll arr[ARR_SIZE + 1];

bool not_prime[MAX_PRIME + 1];
vector<ll> primes;
ll prefix_sum[ARR_SIZE + 1];
void sieve_of_eratosthenes(){
    for(int num=2; num<=MAX_PRIME; ++num){
        if(!not_prime[num]){
            ll prime = num;
            primes.push_back(prime);
            for(ll val=prime*prime; val<=MAX_PRIME; val+=prime){
                not_prime[val] = true;
            }
        }
    }
    // cout << primes.size() << endl;          // 664'579

    for(int ith=1; ith<=ARR_SIZE; ++ith){
        prefix_sum[ith] = prefix_sum[ith - 1] + primes[ith - 1];
    }
    // cout << prefix_sum[ARR_SIZE] << endl;   // 1'116'583'315'953 ~ 10^12
}

void solve_greedy(){
    sort(arr+1, arr+1+n, less<ll>());
    // ll sum_arr = accumulate(arr+1, arr+1+n, 0);     // WRONG : sum as int
    ll sum_arr = accumulate(arr+1, arr+1+n, 0LL);   // AC : sum as long long
    // cout << "sum_arr : " << sum_arr << endl;

    // AC - remove smallest element first
    arr[0] = 0;
    for(int remove=0; remove<n; ++remove){
        sum_arr -= arr[remove];

        if(prefix_sum[n - remove] <= sum_arr){
            cout << remove << endl;
            return;
        }
    }
    // error
    assert(sum_arr == -1 && "error");
    cout << n << endl;

    // WRONG - remove greatest element first
    // for(int jth=n; jth>=1; --jth){
    //     if(prefix_sum[jth] <= sum_arr){
    //         cout << n - jth << endl;
    //         break;
    //     }

    //     sum_arr -= arr[jth];
    // }
}


void solve(){
    solve_greedy();
}

void input(){
    sieve_of_eratosthenes();

    cin >> t;
    while(t--){
        cin >> n;
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
