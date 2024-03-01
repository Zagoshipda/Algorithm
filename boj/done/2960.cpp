/*
    https://www.acmicpc.net/problem/2960
    (reseto)

    similar problem
        https://www.acmicpc.net/problem/1929
        (find prime numbers) : find all primes within a range

        https://www.acmicpc.net/problem/1837
        (The Embarrassed Cryptographer) : calculate modular with a big number
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
      2   4   6   8   10    12    14
        3     6     9       12        15
            5
*/

const int MAX_NUM = 1'000;
int N, K;
bool not_primes[MAX_NUM + 1];

void sieve_of_eratosthenes(){
    int cnt = 0;
    for(int num=2; num<=N; ++num){
        if(!not_primes[num]){
            ++cnt;
            if(cnt >= K){
                cout << num << endl;
                return;
            }
            int prime = num;
            for(int val=prime*prime; val<=N; val+=prime){
                if(!not_primes[val]){   // NOTE : no duplicate counting
                    not_primes[val] = true;
                    ++cnt;
                    if(cnt >= K){
                        cout << val << endl;
                        return;
                    }
                }
            }
        }
    }
}

void solve(){
    sieve_of_eratosthenes();
}

void input(){
    cin >> N >> K;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
