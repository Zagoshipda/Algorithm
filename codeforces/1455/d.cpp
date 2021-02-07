#include <bits/stdc++.h>
using namespace std;
    
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18
    
int t;
int n, x;
    
int main(){
    IOS;
    
    cin >> t;
    while(t--){
        cin >> n >> x;
        // int init = x;
        // string ans_temp = "";
        vector<int> a(n);
        int ans = 0;
        bool is_sorted = true;
        for(int i=0; i<n; ++i){
            cin >> a[i];
            if(i > 0 && is_sorted){
                if(a[i-1] > a[i]){
                    is_sorted = false;
                }
            }
        }
        if(is_sorted){
            cout << 0 << endl;
            continue;
        }
    
        int temp;
        int j = 0;
        for(int i=1; i<n; ++i){
            if(a[i-1] > a[i]){
                // ans_temp += to_string(a[i]);
                for(j=i-1; j>=0; --j){
                    if(a[j] <= x){
                        break;
                    }
                }
                ++j;
                if(j >= i){
                    ans = -1;
                    break;
                }
    
                for(int k=j; k<i; ++k){
                    if(a[k+1] == a[k]){
                        continue;
                    }
                    temp = x;
                    x = a[k];
                    a[k] = temp;
                    ++ans;
                }

                // cout << "j / i / ans / x: " << j << ' ' << i << ' ' << ans << ' ' << x << endl;
                bool flag = false;
                int cnt = 0;
                for(int k=j; k<i; ++k){
                    if(a[k] > a[i]){
                        ans = -1;
                        flag = true;
                        break;
                    }
                }
                if(flag){
                    break;
                }
            }
        }
        cout << ans << endl;
        
    }
    
    return 0;
}
