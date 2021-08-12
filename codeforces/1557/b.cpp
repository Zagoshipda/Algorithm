#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int t;
int n, k;

int main(){
    IOS;

    cin >> t;
    while(t--){
        cin >> n >> k;
        vector<pair<int, int>> a(n);
        int input;
        for(int i=0; i<n; ++i){
            cin >> input;
            a[i] = make_pair(input, i);
        }
        if(k >= n){
            cout << "YES" << endl;
            continue;
        }
        sort(a.begin(), a.end());
        // for(int i=0; i<n; ++i){
        //     cout << a[i].first << ' ' << a[i].second << endl;
        // }

        int cnt = 0;
        for(int i=0; i<n-1; ++i){
            // cout << a[i+1].second - a[i].second << endl;
            if(a[i+1].second - a[i].second != 1){
                ++cnt;
            }
        }
        if(cnt > 0){
            ++cnt;
        }
        // cout << "cnt " << cnt << endl;
        if(cnt <= k){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }

    }

    return 0;
}
