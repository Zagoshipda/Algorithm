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
        vector<pair<int, int>> cnt(100010);
        int input;
        for(int i=0; i<n; ++i){
            cin >> input;
            a[i] = input;
            if(i & 1){
                ++cnt[input-1].first;
            }
            else{
                ++cnt[input-1].second;
            }
        }

        sort(a.begin(), a.end());
        // for(int i=0; i<n; ++i){
        //     cout << cnt[i].first << ' ' << cnt[i].second << endl;
        // }
        // cout << endl;
        
        for(int i=0; i<n; ++i){
            input = a[i];
            if(i & 1){
                --cnt[input-1].first;
            }
            else{
                --cnt[input-1].second;
            }
        }

        bool flag = true;
        for(int i=0; i<n; ++i){
            if(cnt[a[i]-1].first != 0 || cnt[a[i]-1].second != 0){
                flag = false;
                break;
            }
        }
        if(flag){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }

    }


    return 0;
}
