#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define SIZE 10'000
int N;
bool not_primes[SIZE];

void get_primes(){
    for(int i=2; i<SIZE; ++i){
        if(!not_primes[i]){
            for(int j=i*i; j<SIZE; j+=i){
                not_primes[j] = true;
            }
        }
    }
}

void solve(){
    if(N == 1){
        return;
    }

    get_primes();

    for(int i=2; i*i<=N; ++i){
        if(!not_primes[i]){
            while(N % i == 0){
                cout << i << endl;
                N /= i;
            }
        }
        if(N == 1){
            break;
        }
    }
    if(N > 1){
        cout << N << endl;
    }
}

void solve_2(){
    for(int i=2; i*i<=N; ++i){
        while(N % i == 0){
            cout << i << endl;
            N /= i;
        }
    }
    if(N > 1){
        cout << N << endl;
    }
}

int main(){
    IOS;

    cin >> N;

    // solve();

    solve_2();

    return 0;
}
