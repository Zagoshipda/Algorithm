#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int t, n;

int main(){
    IOS;

    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        int a[n];
        fill_n(a, n, 0);
        ll asum = 0, axor = 0;
        for(int j=0; j<n; j++){
            cin >> a[j];
            asum += a[j];
            axor = (axor xor a[j]);
        }
        cout << 2 << endl;
        cout << axor << ' ' << asum + axor << endl;

    }
    

    return 0;
}
