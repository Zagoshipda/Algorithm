#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

// Runtime error

int n, x;
int input;
ll length;
ll sum;
ll ans;

int main(){
    IOS;

    cin >> n >> x;
    vector<int> d(n);
    vector<int> e;
    for(int i=0; i<n; ++i){
        cin >> input;
        d[i] = input;
        for(int j=1; j<=input; ++j){
            e.push_back(j);
        }
    }
    length = e.size();
    for(int i=0; i<length; ++i){
        e.push_back(e[i]);
    }
    for(int i=0; i<x; ++i){
        sum += e[i];
    }
    ans = sum;
    // cout << " ans : " << ans << endl;

    for(int i=0; i+x<e.size(); ++i){
        sum -= e[i];
        sum += e[i+x];
        if(sum > ans){
            ans = sum;
        }
    }

    cout << ans << endl;

    return 0;
}
