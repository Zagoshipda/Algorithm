#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int t;
int n, a, b;

int main(){
    IOS;

    cin >> t;
    while(t--){
        string sub;
        string ans;
        cin >> n >> a >> b;
        for(int i=0; i<b; ++i){
            sub += (char)(i+97);
        }
        for(int i=0; i<a-b; ++i){
            sub += 'a';
        }

        for(int i=0; i<n; ++i){
            int val = i % a;
            ans += sub[val];
        }

        
        cout << ans << endl;
    }

    return 0;
}
