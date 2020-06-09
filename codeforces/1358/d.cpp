#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

ll n, x;
ll val;
ll ans;

int main(){
    IOS;

    cin >> n >> x;
    vector<ll> d;
    vector<ll> e;
    vector<ll> sum;

    ll input;
    for(int i=0; i<n; ++i){
        cin >> input;
        d.push_back(input);
        if(i > 0){
            e.push_back(e[i-1] + input);
            sum.push_back(sum[i-1] + input*(input+1)/2);
        }
        else{
            e.push_back(input);
            sum.push_back(input*(input+1)/2);
        }
    }

    int length = d.size();
    for(int i=0; i<length; ++i){
        d.push_back(d[i]);
        e.push_back(e[length + i-1] + d[i]);
        sum.push_back(sum[length + i-1] + d[i]*(d[i]+1)/2);
    }
    // cout << endl;
    // cout << "d : ";
    // for(int i=0; i<d.size(); ++i){
    //     cout << d[i] << ' ';
    // }
    // cout << endl;
    // cout << "e : ";
    // for(int i=0; i<e.size(); ++i){
    //     cout << e[i] << ' ';
    // }
    // cout << endl;
    // cout << "sum : ";
    // for(int i=0; i<sum.size(); ++i){
    //     cout << sum[i] << ' ';
    // }
    // cout << endl;
    
    for(int i=0; i<e.size(); ++i){
        if(e[i] >= x){
            auto boundary = upper_bound(e.begin(), e.end(), e[i] - x);
            int pos = boundary - e.begin();
            // cout << i << ' ' << pos << ' ';
            int left = x - (e[i] - e[pos]);
            ll val1 = (sum[i] - sum[pos]);
            ll val2 = (d[pos]*(d[pos] + 1)/2 - (d[pos]-left)*(d[pos]-left+1)/2);
            // cout << "vals : " << val1 << ' ' << val2 << endl;
            val = val1 + val2;
            if(val > ans){
                ans = val;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
