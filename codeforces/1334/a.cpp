#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int T;
int n;

int main(){
    IOS;

    cin >> T;
    while(T--){
        cin >> n;
        vector<int> p(n);
        vector<int> c(n);
        for(int i=0; i<n; ++i){
            cin >> p[i] >> c[i];
        }

        string ans;
        if(p[0] - c[0] < 0){
            ans = "NO";
            cout << ans << endl;
            continue;
        }
        
        bool wrong = false;
        for(int i=1; i<n; ++i){
            if(p[i-1] <= p[i] && c[i-1] <= c[i] && p[i-1]-c[i-1] <= p[i]-c[i]){
                continue;
            }
            else{
                wrong = true;
                break;
            }
        }
        if(wrong){
            ans = "NO";
            cout << ans << endl;
            continue;
        }

        ans = "YES";
        cout << ans << endl;

    }
    

    return 0;
}
