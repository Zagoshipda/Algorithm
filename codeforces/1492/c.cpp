#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int n, m;
string s, t;

int main(){
    IOS;

    cin >> n >> m;
    cin >> s >> t;
    vector<int> pref(m);
    vector<int> suf(m);
    int pos = 0;
    for(int i=0; i<n; ++i){
        if(s[i] == t[pos]){
            pref[pos++] = i;
            if(pos == m){
                break;
            }
        }
    }
    --pos;
    for(int i=n-1; i>=0; --i){
        if(s[i] == t[pos]){
            suf[pos--] = i;
            if(pos < 0){
                break;
            }
        }
    }
    vector<int> diff(m-1);
    int width = -1;
    for(int i=0; i<m-1; ++i){
        diff[i] = suf[i+1] - pref[i];
        width = max(width, diff[i]);
    }

    cout << width << endl;

    return 0;
}
