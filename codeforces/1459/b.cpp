#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int n;

int cal(int n){
    return ((2*((n+1)/2)+1)*(2*((n+1)/2)+1))/2;
}

int main(){
    IOS;

    cin >> n;
    vector<int> out(n);
    out[0] = out[1] = 4;
    for(int i=2; i<n; ++i){
        if(i % 2){
            out[i] = cal(i+1) + 1 - out[i - 2];
        }
        else{
            out[i] = cal(i+1);
        }
    }

    // for(int i=0; i<n; ++i){
    //     cout << out[i] << ' ';
    // }
    // cout << endl;
    cout << out[n-1] << endl;

    return 0;
}
