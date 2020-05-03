#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int t;
int n, k;
string s;

int main(){
    IOS;

    cin >> t;
    while(t--){
        cin >> n >> k;
        cin >> s;
        vector<string> ans(k);
        sort(s.begin(), s.end());
        if(k == 1){
            cout << s << endl;
        }
        else{
            for(int i=0; i<k; ++i){
                ans[i] += s[i];
            }
            if(ans[0] == ans[k-1]){
                if(s[k] == s[n-1]){
                    for(int i=0; (n-k)>0 && i<(n-k-1)/k+1; ++i){
                        ans[0] += s[k];
                    }
                }
                else{
                    for(int i=k; i<n; ++i){
                        ans[0] += s[i];
                    }
                }
                cout << ans[0] << endl;
            }
            else{
                cout << ans[k-1] << endl;
            }
        }
    }
    

    return 0;
}
