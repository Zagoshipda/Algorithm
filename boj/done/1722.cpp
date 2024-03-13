/*
    https://www.acmicpc.net/problem/1722
    (permutation order)

    solutions
        https://www.acmicpc.net/source/3918260
        (kcm1700, 0 ms) : using vector

        https://www.acmicpc.net/source/3708177
        (kazel, 0 ms)

        https://www.acmicpc.net/source/62485782
        (lighter, 0 ms) : recursive solution

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    1 ... N ~ 20
    N! ~ 20! ~ 3 * 10^18

        1 2 ... N   => (N-1)!
        2 1 ... N   => (N-1)!
        X 1 ... N   => (N-2)!
        X 2 ... N   => (N-2)!
        X X 1 ... N => (N-3)!
        ... 1 ... N => (N-k)!
    suppose kth number is m = permutation[k]
    here we have passed permutations up to kth number (permutation[k])
        = # of number smaller than permutation[k],
            excluding 1...k-1th numbers that have already appeared before
    which means we have passed the order by (N-k)! * (# of numbers smaller than permutation[k])
    => sum( (N-k)! * (# of numbers smaller than permutation[k]) for k=1...N )
        + 1 (for itself-th order)

*/

const int MIN_NUM = 1;
const int MAX_NUM = 20;
ll N;
int type;
ll order;
ll permutation[MAX_NUM + 1];

ll factorial[MAX_NUM + 1];

ll calculate_factorial(){
    factorial[1] = 1;
    for(int n=2; n<=MAX_NUM; ++n){
        factorial[n] = factorial[n-1] * n;
    }
}

ll get_factorial(ll num){
    // if(factorial[num]){
    //     return factorial[num];
    // }

    // ll ans = 1;
    // for(ll n=2; n<=num; ++n){
    //     ans *= n;
    // }
    // return factorial[num] = ans;

    return factorial[num];
}

void solve(){
    set<int> numbers;
    for(int i=1; i<=N; ++i){
        numbers.insert(i);
    }
    calculate_factorial();

    if(order){
        for(int idx=1; idx<=N; ++idx){
            // ll cnt = tgamma(N-idx+1);   // ERROR : double precision
            ll cnt = get_factorial(N-idx);
            for(auto it=numbers.begin(); it!=numbers.end(); ++it){
                if(order > cnt){
                    order -= cnt;
                }
                else{
                    cout << *it << " ";
                    numbers.erase(it);
                    break;
                }
            }
        }
        cout << endl;
    }
    else{
        // calculate # of previous permutations
        for(int idx=1; idx<=N; ++idx){
            ll ith = 0;
            for(auto it=numbers.begin(); it!=numbers.end(); ++it){
                if(*it < permutation[idx]){
                    ++ith;
                }
                else{
                    break;
                }
            }
            // order += (tgamma(N-idx+1) * (permutation[idx]-1));  // WRONG
            // order += (tgamma(N-idx+1) * ith);   // ERROR : double precision
            order += (get_factorial(N-idx) * ith);
            numbers.erase(permutation[idx]);
        }
        cout << order + 1 << endl;  // NOTE : + 1 for current order
    }
}

void input(){
    cin >> N;
    cin >> type;
    if(type == 1){
        cin >> order;
    }
    else{
        for(int i=1; i<=N; ++i){
            cin >> permutation[i];
        }
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
