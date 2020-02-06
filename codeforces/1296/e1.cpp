#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int n;
string s;
string ans;

int main(){
    IOS;

    cin >> n;
    cin >> s;
    char high = 'a', low = 'a';
    bool flag = true;
    for(int i=0; i<n; ++i){
        if(s[i] >= high){
            high = s[i];
            ans += '0';
        } 
        else if(s[i] >= low){
            low = s[i];
            ans += '1';
        }
        else{
            cout << "NO" << endl;
            flag = false;
            break;
        }
    }
    if(flag){
        cout << "YES" << endl;
        cout << ans << endl;
    }

    return 0;
}
