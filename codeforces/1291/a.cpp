#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int t, n;
string s;

int main(){
    IOS;

    cin >> t;
    for(int i=0; i<t; ++i){
        cin >> n;
        cin >> s;
        int odd = 0;
        bool flag = false;
        string ans;
        for(int j=0; j<n; ++j){
            if(s[j] % 2 == 1){
                ++odd;
                ans += s[j];
                // cout << ans << endl << flush;
                if(odd > 1){
                    flag = true;
                    break;
                }
            }
        }
        if(flag){
            cout << ans << endl;
        }
        else{
            cout << -1 << endl;
        }
    }


    return 0;
}
