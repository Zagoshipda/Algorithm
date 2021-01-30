#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int t;
int n;
ll k;

int main(){
    IOS;

    cin >> t;
    while(t--){
        cin >> n >> k;
        vector<ll> x(n);
        ll min_val = __LONG_LONG_MAX__;
        for(int i=0; i<n; ++i){
            cin >> x[i];
            if(x[i] < min_val){
                min_val = x[i];
            }
        }
        ll _gcd = 0;
        for(int i=0; i<n-1; ++i){
            _gcd = __gcd(_gcd, x[i+1] - x[i]);
        }

        if((k - min_val) % _gcd){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
        // bool flag = true;
        // for(int i=0; i<n; ++i){
        //     if(((k - x[i]) % _gcd) == 0){
        //         flag = false;
        //         cout << "YES" << endl;
        //         break;
        //     }
        // }
        // if(flag){            
        //     cout << "NO" << endl;
        // }
    }

    return 0;
}
