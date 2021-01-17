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
        // vector<int> a(n);
        // vector<int> p(k);
        // vector<int> b(n);
        // for(int i=0; i<k; ++i){
        //     a[i] = i+1;
        // }
        // for(int i=1; i<=n-k; ++i){
        //     a[k+i-1] = k-i;
        // }

        if((n-k)*2 + 1 == n){
            // p[i]
            for(int i=0; i<k; ++i){
                cout << k-i << ' ';
            }
            cout << endl;

            // b[i]
            // for(int i=0; i<k; ++i){
            //     cout << k-i << ' ';
            // }
            // cout << " / ";
            // for(int i=k; i<n; ++i){
            //     cout << i - (n-1-k) << ' ';
            // }
            // cout << endl;
            // cout << endl;
        }
        else{
            // p[i]
            for(int i=0; i<n-(2*(n-k)+1); ++i){
                cout << i+1 << ' ';
            }
            for(int i=n-(2*(n-k)+1); i<k; ++i){
                cout << k-(i-(n-(2*(n-k)+1))) << ' ';
            }
            cout << endl;

            // b[i]
            // for(int i=0; i<n-(2*(n-k)+1); ++i){
            //     cout << i+1 << ' ';
            // }
            // cout << " // ";
            // for(int i=n-(2*(n-k)+1); i<k-1; ++i){
            //     cout << k-(i-(n-(2*(n-k)+1))) << ' ';
            // }
            // cout << " // ";
            // for(int i=k-1; i<n; ++i){
            //     cout << i-(n-1-k) << ' ';
            // }
            // cout << endl;
            // cout << endl;
        }
    }

    return 0;
}
