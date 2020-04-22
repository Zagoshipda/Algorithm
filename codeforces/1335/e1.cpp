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
        vector<int> a(n+1);
        // int cnt[26][n];
        vector<vector<int>> cnt(26, vector<int>(n+1));
        for(int i=1; i<=n; ++i){
            cin >> a[i];
            for(int j=0; j<cnt.size(); ++j){
                cnt[j][i] = cnt[j][i-1];
            }
            ++cnt[a[i]-1][i];
        }

        int ans = 0;
        for(int l=1; l<=n; ++l){
            for(int r=l; r<=n; ++r){
                int mid = 0;
                int side = 0;
                for(int k=0; k<cnt.size(); ++k){
                    mid = max(mid, cnt[k][r] - cnt[k][l-1]);
                    side = max(side, min(cnt[k][l-1], cnt[k][n] - cnt[k][r]));
                }
                ans = max(ans, mid + 2 * side);
            }
        }

        cout << ans << endl;
    }
    

    return 0;
}
