#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

ll gcd(ll a, ll b){
    if(b <= 0){
        return a;
    }
    else{
        return gcd(b, a%b);
    }
}

int n, m;

int main(){
    IOS;

    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> b(m);

    for(int i=0; i<n; ++i){
        cin >> a[i];
    }
    for(int j=0; j<m; ++j){
        cin >> b[j];
    }

    sort(a.begin(), a.end());

    vector<ll> _gcd(m);
    ll val = a[n-1] - a[0];
    for(int i=0; i<n-1; ++i){
        // cout << val << ' ' << a[n-1] - a[i] << endl;
        val = gcd(val, a[n-1] - a[i]);
    }

    for(int k=0; k<m; ++k){
        _gcd[k] = gcd(val, a[n-1] + b[k]);
    }
    for(int k=0; k<m; ++k){
        cout << _gcd[k] << ' ';
    }
    cout << endl;
    
    return 0;
}
