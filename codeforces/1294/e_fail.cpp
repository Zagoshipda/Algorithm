#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18



// time limit exceeded... -> O(n^2*m)
int n, m;
int ans;

int main(){
    IOS;

    cin >> n >> m;
    vector<vector<int>> a (n, vector<int> (m));

    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> a[i][j];
        }
    }

    // for(int i=0; i<n; ++i){
    //     for(int j=0; j<m; ++j){
    //         cout << a[i][j] << ' ';
    //     }
    //     cout << endl;
    // }


    for(int j=0; j<m; ++j){
        int diff = n;
        for(int i=0; i<n; ++i){
            int cnt = 0;
            int cost = 0;
            for(int k=i; cnt<n; ++k){
                if(k >= n){
                    k -= n;
                }
                if(a[k][j] != (cnt*m + j+1)){
                    ++cost;
                }
                ++cnt;
            }
            // cout << cost << ' ';
            cost += i;
            diff = min(diff, cost);
            // cout << "diff : " << diff << endl;
        }
        // cout << endl;
        ans += diff;
    }

    cout << ans << endl;



    return 0;
}
