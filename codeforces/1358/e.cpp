#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int n;
int x;
int k;

int main(){
    IOS;

    cin >> n;
    int half = (n+1)/2;
    k = n/2+1;
    vector<int> a(n);
    vector<ll> s(n);
    for(int i=0; i<half; ++i){
        cin >> a[i];
        if(i > 0){
            s[i] = s[i-1] + a[i];
        }
        else{
            s[i] = a[i];
        }
    }
    cin >> x;
    for(int i=half; i<n; ++i){
        a[i] = x;
        s[i] = s[i-1] + a[i];
    }

    // n == 2
    // if(n-k == 0){
    //     if(a[0] + a[1] > 0){
    //         cout << 2 << endl;
    //         return 0;
    //     }
    // }

    vector<ll> p(n);
    vector<ll> minVal(n);
    p[k-1] = 0;
    minVal[k-1] = 0;
    for(int i=0; i<n-k; ++i){
        p[k+i] = p[k+i-1] + (x - a[i]);
        minVal[k+i] = min(minVal[k+i-1], p[k+i]);
    }

    // for(int i=0; i<n; ++i){
    //     cout << p[i] << ' ' << minVal[i] << endl;
    // }

    for(int i=k; i<=n; ++i){
        // ll minVal = 0;
        // for(int j=0; j<n-i; ++j){
        //     if(minVal == 0 || p[j] < minVal){
        //         minVal = p[j];
        //     }
        // }
        if(s[i-1] + minVal[n+k-1-i] > 0){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;


    return 0;
}
