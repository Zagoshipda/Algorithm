#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int n, m;
int ans;

int main(){
    IOS;

    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> a[i][j];
            --a[i][j];
        }
    }

    for(int j=0; j<m; ++j){
        vector<int> cnt(n);
        for(int i=0; i<n; ++i){
            if(a[i][j] % m == j){
                if(a[i][j] < n*m){
                    ++cnt[(n+i - a[i][j]/m) % n];
                }
            }
        }
        // for(int i=0; i<n; ++i){
        //     cout << cnt[i] << ' ';
        // }
        // cout << endl;

        int cost = n;
        for(int i=0; i<n; ++i){
            cost = min(cost, n-cnt[i] + i);
        }    
        ans += cost;
    }
    
    cout << ans << endl;

    return 0;
}
