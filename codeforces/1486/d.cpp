#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int n, k;
int m;  // maximum median

int main(){
    IOS;

    cin >> n >> k;
    vector<int> a(n);
    // for(int i=0; i<n; ++i){
    //     cin >> a[i];
    // }
    for(auto &i : a){
        cin >> i;
    }

    // binary search on the answer m
    int l = 1;
    int r = n+1;
    while(l + 1 < r){
        m = (l + r) / 2;
        // cout << "l / m / r : " << l << ' ' << m << ' ' << r << endl;
        vector<int> b(n);
        for(int i=0; i<n; ++i){
            if(a[i] < m){
                b[i] = -1;
            }
            else{
                b[i] = 1;
            }
        }
        for(int i=1; i<n; ++i){
            b[i] += b[i-1];
        }

        int val = b[k-1];
        int pref = 0;
        for(int i=k; i<n; ++i){
            pref = min(pref, b[i-k]);
            val = max(val, b[i] - pref);
        }
        if(val > 0){
            l = m;
        }
        else{
            r = m;
        }
    }
    
    cout << l << endl;

    return 0;
}
