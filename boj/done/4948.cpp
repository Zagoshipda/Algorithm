/*
    https://www.acmicpc.net/problem/4948
    (Chebyshev theorem)

    solutions
        https://www.acmicpc.net/source/4554119
        (dreammusic23, 0 ms)

        dp solution : implemented in solve_dp()
            https://www.acmicpc.net/source/10786261
            (harryhajinchung, 0 ms)
            https://www.acmicpc.net/source/133318
            (WeissBlume, 0 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Chebyshev theorem
        If n is a positive integer,
        there exists at least one prime number p
        greater than n and less than or equal to 2n
        i.e. n < p <= 2n
*/

const int MAX_NUM = (123456 << 1) + 1;

int n;

bool not_prime[MAX_NUM + 1];
vector<int> primes;
int dp[MAX_NUM + 1];
void sieve_of_eratosthenes(){
    for(int num=2; num<=MAX_NUM; ++num){
        dp[num] = dp[num-1];
        if(!not_prime[num]){
            ++dp[num];
            ll prime = num;
            primes.push_back(prime);
            for(ll val=prime*prime; val<=MAX_NUM; val+=prime){
                not_prime[val] = true;
            }
        }
    }
}

void solve_1(){
    int cnt = 0;
    for(int num=n+1; num<=(n<<1); ++num){
        if(!not_prime[num]){
            ++cnt;
        }
    }
    cout << cnt << endl;
}

void solve_2(){
    auto it_left = upper_bound(primes.begin(), primes.end(), n);
    auto it_right = upper_bound(primes.begin(), primes.end(), n<<1);

    // [it_left ... it_right) = [it_left ... it_right-1] => including left, excluding right
    cout << distance(it_left, it_right) << endl;
}

void solve_3(){
    auto it_left = lower_bound(primes.begin(), primes.end(), n+1);
    auto it_right = upper_bound(primes.begin(), primes.end(), n<<1);

    cout << distance(it_left, it_right) << endl;
}

void solve_dp(){
    cout << dp[n<<1] - dp[n] << endl;
}

void solve(){
    // solve_1();
    // solve_2();
    solve_3();

    // solve_dp();
}

void input(){
    sieve_of_eratosthenes();

    while(true){
        cin >> n;
        if(n <= 0){
            break;
        }
        solve();
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
