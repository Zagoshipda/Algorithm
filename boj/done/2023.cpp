/*
    amazing prime
    https://www.acmicpc.net/problem/2023
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

// ERROR : memory exceeded
// #define SIZE 100'000'000
int N;
// NOTE : 9 possible, 2 only possible for the left-most digit
// int primes[4] = {2, 3, 5, 7};
// bool not_prime[SIZE];

// void get_primes(){
//     not_prime[1] = true;
//     for(ll i=2; i<SIZE; ++i){
//         if(!not_prime[i]){
//             for(ll j=i*i; j<SIZE; j+=i){
//                 not_prime[j] = true;
//             }
//         }
//     }
// }

bool check_prime(int n){
    if(n < 2){
        return false;
    }
    for(int i=2; i*i<=n; ++i){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

void get_amazing_prime(int digit, int amazing_prime){
    if(digit > N){
        cout << amazing_prime << endl;
        // NOTE : if not return, move to next for loop and stack overflow
        // (with array index out of bounds - Segmentation fault)
        return;
    }

    for(int num=1; num<=9; ++num){
        // if(!not_prime[amazing_prime*10 + num]){
        if(check_prime(amazing_prime*10 + num)){
            get_amazing_prime(digit + 1, amazing_prime*10 + num);
        }
    }
}

void solve(){
    // get_primes();

    get_amazing_prime(1, 0);
}

int main(){
    IOS;

    cin >> N;

    solve();

    return 0;
}
