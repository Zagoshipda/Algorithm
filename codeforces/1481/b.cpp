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
        vector<int> h(n);
        for(int i=0; i<n; ++i){
            cin >> h[i];
        }
        int ans = -2;
        for(int i=0; i<k; ++i){
            bool is_set = true;
            for(int j=0; j<n-1; ++j){
                if(h[j] < h[j+1]){
                    ++h[j];
                    is_set = false;
                    if(i == k-1){
                        ans = j;
                    }
                    break;
                }
            }
            if(is_set){
                ans = -2;
                break;
            }
        }
        cout << ans + 1 << endl;
    }

    return 0;
}
