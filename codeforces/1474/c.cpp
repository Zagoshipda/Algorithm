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
        vector<int> _a(2*n);
        int input;
        for(int i=0; i<2*n; ++i){
            cin >> _a[i];
        }
        sort(_a.begin(), _a.end());
        // for(auto it=a.begin(); it!=a.end(); ++it){
        //     cout << ' ' << *it;
        // }
        // cout << endl;
        
        int x, a1, a2;
        bool flag = true;
        for(auto it=_a.begin(); it!=_a.end(); ++it){
            vector<pair<int, int>> ans;
            multiset<int> a;
            for(int i=0; i<2*n; ++i){
                a.insert(_a[i]);
            }
            a1 = *(--a.end());
            x = *it + a1;
            for(int i=0; i<n; ++i){
                auto diff = a.find(x - a1);
                a2 = *diff;
                if(diff == a.end()){
                    break;
                }
                else if(a2 == a1 && a.count(a2) <= 1){
                    break;
                }
                else{
                    a.erase(--a.end());
                    a.erase(diff);
                    ans.push_back(make_pair(a1, a2));
                    x = max(a1, a2);
                    if(a.size() <= 0){
                        break;
                    }
                    a1 = *(--a.end());
                }
            }
            if(ans.size() == n){
                cout << "YES" << endl;
                cout << ans[0].first + ans[0].second << endl;
                for(int i=0; i<n; ++i){
                    cout << ans[i].first << ' ' << ans[i].second << endl;
                }
                flag = false;
                break;
            }
        }
        if(flag){
            cout << "NO" << endl;
        }

    }


    return 0;
}
