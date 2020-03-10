#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // -9*10^18 ~ 9*10^18

int n, m;

int main(void){
    IOS;

    cin >> n >> m;
    vector<int> a(n);
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }
    if(n > m){
        cout << 0 << endl;
    }
    else{
        ll ans = 1;
        for(int i=0; i<n-1; ++i){
            for(int j=i+1; j<n; ++j){
                ans *= abs(a[i] - a[j]);
                ans %= m;
            }
        }
        cout << ans << endl;
    }


    return 0;
}
