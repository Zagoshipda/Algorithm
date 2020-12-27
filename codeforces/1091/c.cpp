#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int n;

int main(){
    IOS;

    cin >> n;

    vector<int> divisors;

    divisors.push_back(1);
    for(int i=2; i*i<=n; ++i){
        if(n % i == 0){
            if(i*i != n){
                divisors.push_back(i);
            }
            divisors.push_back(n/i);
        }
    }
    divisors.push_back(n);

    // for(int i=0; i<divisors.size(); ++i){
    //     cout << divisors[i] << ' ';
    // }
    // cout << endl;

    vector<ll> ans(divisors.size());
    // Time limit exceeded
    // for(int i=0; i<divisors.size(); ++i){
    //     for(int j=1; j<=n; j += divisors[i]){
    //         ans[i] += j;
    //     }
    // }
    for(int i=0; i<divisors.size(); ++i){
        ll num = n / divisors[i];
        ans[i] = (divisors[i] * (num - 1) + 2) * num / 2;
    }

    sort(ans.begin(), ans.end());

    for(int i=0; i<ans.size(); ++i){
        cout << ans[i] << ' ';
    }
    cout << endl;
    

    return 0;
}
