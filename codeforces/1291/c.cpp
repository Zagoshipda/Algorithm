#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int t;
int n, m, k;

int main(){
    IOS;
    
    cin >> t;
    for(int i=0; i<t; ++i){
        cin >> n >> m >> k;
        int a[n];
        fill_n(a, n, 0);
        for(int j=0; j<n; ++j){
            cin >> a[j];
        }
        k = min(m-1, k);
        
        int ans = 0;
        for(int j=0; j<=k; ++j){
            int temp = INT_MAX;
            for(int l=0; l<= m-1 - k; ++l){
                int cal = max(a[j + l], a[j + l + n-m]);
                temp = min(temp, cal);
            }
            ans = max(ans, temp);
        }
        cout << ans << endl;
    }
    


    return 0;
}
