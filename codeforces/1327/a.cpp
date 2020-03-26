#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18)

int t;
ll n, k;

int main(){
    IOS;

    cin >> t;
    while(t--){
        cin >> n >> k;

        if(n >= k*k && (n - k*k) % 2 == 0){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }

    }
    

    return 0;
}
