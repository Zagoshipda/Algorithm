#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    value = i*j - k*(a[i] | a[j])
    min value > i*j - k*(2*n) (since 0 <= a[k] <= n, a[i] | a[j] < 2*n)
    max value = i*j (when a[i] = a[j] = 0)

    min value of i=n-1, j=n > n*(n-1) - k*(2*n) = n*(n-(2k+1))
    => only have to check indices >= n-2k
*/

int t;
int n, k;

int main(){
    IOS;

    cin >> t;
    while(t--){
        cin >> n >> k;
        vector<ll> a(n+1);
        for(int i=1; i<=n; ++i){
            cin >> a[i];
        }

        ll ans = LLONG_MIN;
        ll val;
        ll idx = max(1, n-2*k);
        // cout << "idx " << idx << endl;
        for(ll i=idx; i<n; ++i){
            for(ll j=i+1; j<=n; ++j){
                val = i*j - k*(a[i] | a[j]);
                if(ans < val){
                    ans = val;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
