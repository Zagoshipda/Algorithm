/*
    almost prime number
    https://www.acmicpc.net/problem/1456
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define SIZE 10'000'001
ll lower, upper;
bool not_primes[SIZE];

void get_primes(){
    // NOTE : since i*i can overflow the range of int, declare as long long
    for(ll i=2; i<SIZE; ++i){
        if(!not_primes[i]){
            for(ll j=i*i; j<SIZE; j+=i){
                not_primes[j] = true;
            }
        }
    }
}

void solve(){
    // 1 2 3 (4) 5 6 7 (8) (9) 10
    // 11 12 13 14 15 (16) 17 18 19 20
    // 21 22 23 24 (25) 26 (27) 28 29 30
    // (32)
    // (49) // 8
    // (64)
    // (81) // 10

    get_primes();

    ll cnt = 0;
    for(ll i=2; i<SIZE; ++i){
        if(!not_primes[i]){
            for(ll j=i*i; j<=upper; ){
                if(lower <= j){
                    ++cnt;
                }
                // NOTE : j*=i can overflow the range of long long
                if(j <= LONG_LONG_MAX/i){
                    j*=i;
                }
                else{
                    break;
                }
            }
        }
    }

    cout << cnt << endl;
}

int main(){
    IOS;

    cin >> lower >> upper;

    solve();

    return 0;
}
