#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int t;
ll n;
const int MOD = 1e9+7;

ll gcd(ll a, ll b){
    return a%b ? gcd(b, a%b) : b;
}

ll lcm(ll a, ll b){
    // ll _gcd = gcd(a, b);
    // return _gcd * (a/_gcd) * (b/_gcd);
    return a/gcd(a, b)*b;
}

int main(){
    IOS;

    // cout << gcd(18, 12) << endl;
    // cout << gcd(315, 648) << endl;


    cin >> t;
    while(t--){
        cin >> n;

        int ans = 0;
        ll _lcm = 1;

        ll val;
        for(int i=2; _lcm <= n; ++i){
            val = 0;
            val += n/_lcm;
            _lcm = lcm(_lcm, i); 
            val -= n/_lcm;
            val *= i;
            val %= MOD;
            ans += val;
            ans %= MOD;
        }

        cout << ans << endl;
    }
    

    return 0;
}
