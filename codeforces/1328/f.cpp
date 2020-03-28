#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18)

int n, k;

int main(){
    IOS;

    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(int i=0; i+k-1<n; ++i){
        if(a[i] == a[i+k-1]){
            cout << 0 << endl;
            return 0;
        }
    }
    int val1 = a[k-1], val2 = a[n-1-(k-1)];
    ll cnt1 = 0, cnt2 = 0;
    for(int i=0; i<k; ++i){
        cnt1 += val1-a[i];
    }
    for(int i=k; i<n; ++i){
        if(a[i] == val1){
            cnt1--;
        }
    }
    for(int i=n-1-(k-1); i<n; ++i){
        cnt2 += a[i]-val2;
    }
    for(int i=n-1-k; i>-1; --i){
        if(a[i] == val2){
            cnt2--;
        }
    }

    ll cnt3 = 0;
    for(int i=0; i<n-1-i; ++i){
        cnt3 += a[n-1-i] - a[i];
    }
    cnt3 -= n-k;

    // cout << "cnt1 cnt2 cnt3 : " << cnt1 << ' ' << cnt2 << ' ' << cnt3 << endl;
    cout << min(min(cnt1, cnt2), cnt3) << endl;
    

    return 0;
}
