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
        vector<int> x(n);
        for(int i=0; i<n; ++i){
            cin >> x[i];
        }
        int y = 0;
        cout << y << ' ';
        int z = x[0] ^ y;
        for(int i=1; i<n; ++i){
            y = (z | x[i]) ^ x[i];
            z = x[i] ^ y;
            cout << y << ' ';
        }
        cout << endl;
    }

    return 0;
}