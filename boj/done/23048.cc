/*
    https://www.acmicpc.net/problem/23048
    (color the numbers)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Algorithm
        find all primes ( + 1) and color its multiples
*/

const int MAX_NUM = 500'000;    // 5 * 10^5
int N;

int not_prime[MAX_NUM + 1];
int colors[MAX_NUM + 1];
int cnt = 1;
void sieve_of_eratosthenes(){
    colors[1] = cnt;

    for(int num=2; num<=N; ++num){
        if(!colors[num]){
            ++cnt;
            ll prime = num;
            for(ll val=prime; val<=N; val+=prime){
                colors[val] = cnt;
            }
        }
    }
}

void solve(){
    sieve_of_eratosthenes();

    cout << cnt << endl;
    for(int idx=1; idx<=N; ++idx){
        cout << colors[idx] << " ";
    }
    cout << endl;
}

void input(){
    cin >> N;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
