#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int t;
int m;

int main(){
    IOS;

    cin >> t;
    while(t--){
        cin >> m;
        int a[2][m];
        int val;
        for(int i=0; i<m; ++i){
            cin >> a[0][i];
        }
        for(int i=0; i<m; ++i){
            cin >> a[1][i];
        }
        if(m == 1){
            cout << 0 << endl;
            continue;
        }

        int sufa0[m] = { 0, };
        int prefa1[m] = { 0, };
        int height[m] = { 0, };
        sufa0[m-1] = a[0][m-1];
        prefa1[0] = a[1][0];
        height[0] = a[0][0] + a[1][0];
        for(int i=1; i<m; ++i){
            sufa0[m-1-i] = sufa0[m-i] + a[0][m-1-i];
            prefa1[i] = prefa1[i-1] + a[1][i];
            height[i] = a[0][i] + a[1][i];
        }

        int min_val = sufa0[1];
        // int max_sum_idx = 0;
        int cur_val;
        for(int i=1; i<m-1; ++i){
            cur_val = max(sufa0[i+1] , prefa1[i-1]);
            if(min_val > cur_val){
                min_val = cur_val;
                // max_sum_idx = i;
            }
        }
        cur_val = prefa1[m-2];
        if(min_val > cur_val){
            min_val = cur_val;
            // max_sum_idx = i;
        }

        cout << min_val << endl;

    }

    return 0;
}
