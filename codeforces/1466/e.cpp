#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

const ll MODULO = pow(10, 9) + 7;
const int _size = 60;

int t;
int n;

int main(){
    IOS;

    cin >> t;
    while(t--){
        ll ans = 0;
        vector<int> bits(_size, 0);

        cin >> n;
        vector<ll> x(n);
        for(int i=0; i<n; ++i){
            cin >> x[i];
            for(int j=0; j<_size; ++j){
                bits[j] += x[i] >> j & 1;
            }
        }

        for(int i=0; i<n; ++i){
            ll and_value = 0, or_value = 0;
            for(int j=0; j<_size; ++j){
                ll value = x[i] >> j & 1;
                if(value){
                    // and_value += (bits[j] << j) % MODULO;
                    // or_value += (n << j) % MODULO;
                    // and_value += ((1ll << j) * bits[j]) % MODULO;
                    // or_value += ((1ll << j) * n) % MODULO;
                    and_value += (1ll << j) % MODULO * bits[j];
                    or_value += (1ll << j) % MODULO * n;
                }
                else{
                    // or_value += (bits[j] << j) % MODULO;
                    // or_value += ((1ll << j) * bits[j]) % MODULO;
                    or_value += (1ll << j) % MODULO * bits[j];
                }
            }
            ans += (and_value % MODULO) * (or_value % MODULO);
            ans %= MODULO;
        }
        cout << ans << endl;
    }

    return 0;
}
