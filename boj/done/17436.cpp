#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define SIZE 10
int N;
ll M;
ll primes[SIZE];

int main(){
    IOS;

    cin >> N >> M;
    for(int i=0; i<N; ++i){
        cin >> primes[i];
    }

    ll cnt = 0;
    for(int mask=1<<0; mask<1<<N; ++mask){
        ll val = 1;
        int ones = 0;
        for(int i=0; i<N; ++i){
            if(mask>>i & 1){
                ++ones;
                val *= primes[i];
            }
        }

        cnt += ones & 1 ? M / val : -(M / val);
    }

    cout << cnt << endl;

    return 0;
}
