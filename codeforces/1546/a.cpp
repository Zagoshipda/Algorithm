#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int t;
int n;

int main(){
    IOS;

    cin >> t;
    while(t--){
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for(int i=0; i<n; ++i){
            cin >> a[i];
        }
        for(int i=0; i<n; ++i){
            cin >> b[i];
        }

        int big = 0;
        int small = 0;
        for(int i=0; i<n; ++i){
            if(a[i] > b[i]){
                big += a[i] - b[i];
            }
            else if(a[i] < b[i]){
                small += b[i] - a[i];
            }
        }
        
        if(big != small){
            cout << -1 << endl;
        }
        else{
            int ans_size = big;
            vector<pair<int, int>> ans(ans_size);
            for(int i=0; i<ans_size; ++i){
                ans[i] = make_pair(1, 1);
            }
            
            int idx_1=0, idx_2=0;
            for(int i=0; i<n; ++i){
                if(a[i] > b[i]){
                    for(int j=0; j<a[i]-b[i]; ++j){
                        ans[idx_1+j].first = i+1;
                    }
                    idx_1 += a[i]-b[i];
                }
                else if(a[i] < b[i]){
                    for(int j=0; j<b[i]-a[i]; ++j){
                        ans[idx_2+j].second = i+1;
                    }
                    idx_2 += b[i]-a[i];
                }
            }

            cout << ans_size << endl;
            for(int i=0; i<ans_size; ++i){
                cout << ans[i].first << ' ' << ans[i].second << endl;
            }
        }
    }

    return 0;
}
