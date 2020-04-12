#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int T;
int n, k;

int main(){
    IOS;

    cin >> T;
    while(T--){
        cin >> n >> k;
        vector<ll> a(n);
        for(int i=0; i<n; ++i){
            cin >> a[i];
        }

        vector<int> cnt(60);
        for(int i=0; i<n; ++i){
            ll val = a[i];
            for(int j=0; j<cnt.size(); ++j){
                if(val <= 0){
                    break;
                }
                cnt[j] += val % k;
                val /= k;
            }
        }

        string ans;
        bool flag = true;
        for(int i=0; i<cnt.size(); ++i){
            if(cnt[i] > 1){
                ans = "NO";
                flag = false;
                break;
            }
        }
        if(flag){
            ans = "YES";
        }

        cout << ans << endl;

    }
    

    return 0;
}
