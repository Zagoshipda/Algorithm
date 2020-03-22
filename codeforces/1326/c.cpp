#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18)

int n, k;
ll ans1 = 0, ans2 = 1;

int main(){
    IOS;

    cin >> n >> k;
    vector<int> p(n);
    // vector<int> pos(k);
    bool flag = false;
    int pos = 0;
    for(int i=0; i<n; ++i){
        cin >> p[i];
        if(flag){
            if(p[i] > n-k){
                ans2 *= (i-pos);
                ans2 = ans2 % 998244353;
                pos = i;
            }
            else{
                continue;
            }
        }
        else{
            if(p[i] > n-k){
                flag = true;
                pos = i;
            }
        }
    }

    for(int i=n; i>n-k; --i){
        ans1 += i;
    }
    cout << ans1 << ' ' << ans2 << endl;


    return 0;
}
