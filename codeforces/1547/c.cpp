#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int t;
int k, n, m;

int main(){
    IOS;

    cin >> t;
    while(t--){
        cin >> k >> n >> m;
        vector<int> a(n);
        vector<int> b(m);
        for(int i=0; i<n; ++i){
            cin >> a[i];
        }
        for(int i=0; i<m; ++i){
            cin >> b[i];
        }
        
        bool flag = true;
        string ans = "";
        for(int i=0, j=0; i<n || j<m; ){
            // cout << "K " << k << endl;
            if(i == n){
                if(b[j] > k){
                    flag = false;
                    break;
                }
                else{
                    if(b[j] == 0){
                        ++k;
                    }
                    ans += to_string(b[j++]);
                }
            }
            else if(j == m){
                if(a[i] > k){
                    flag = false;
                    break;
                }
                else{
                    if(a[i] == 0){
                        ++k;
                    }
                    ans += to_string(a[i++]);
                }
            }
            else{
                if(a[i] <= k){
                    if(a[i] == 0){
                        ++k;
                    }
                    ans += to_string(a[i++]);
                }
                else if(b[j] <= k){
                    if(b[j] == 0){
                        ++k;
                    }
                    ans += to_string(b[j++]);
                }
                else{
                    flag = false;
                    break;
                }
            }
            ans += ' ';
        }

        if(flag){
            cout << ans << endl;
        }
        else{
            cout << -1 << endl;
        }

    }

    return 0;
}
