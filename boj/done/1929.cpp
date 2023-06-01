/*
    find prime numbers
    https://www.acmicpc.net/problem/1929

    solutions
    (8ms)
    https://www.acmicpc.net/source/57200804
    https://www.acmicpc.net/source/41233552
    https://www.acmicpc.net/source/55676793

    (bitset)
    https://www.acmicpc.net/source/8800845
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define SIZE 1'000'001
int M, N;
bool not_primes[SIZE];

bool is_prime(int n){
    if(n < 2){
        return false;
    }
    for(int i=2; i*i<=n; ++i){
        if(n % i == 0){
            return false;
        }
    }

    return true;
}

void solve_1(){
    for(int i=M; i<=N; ++i){
        if(is_prime(i)){
            cout << i << endl;
        }
    }
}

void solve_2(){
    not_primes[1] = true;

    for(int i=2; i*i<=N; ++i){
        if(!not_primes[i]){
            for(int j=i*i; j<=N; j+=i){
                not_primes[j] = true;
            }
        }
    }

    for(int i=M; i<=N; ++i){
        if(!not_primes[i]){
            cout << i << endl;
        }
    }
}

int main(){
    IOS;

    cin >> M >> N;

    // solve_1();

    // about 10 times faster
    solve_2();

    return 0;
}
