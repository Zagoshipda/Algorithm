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
        for(int i=0; i<n; ++i){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        for(int i=n-1; i>=0; --i){
            cout << a[i] << ' ';
        }
        cout << endl;
    }
    

    return 0;
}
