#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int n;
string s;
int res;
string ans;

int main(){
    IOS;

    cin >> n;
    cin >> s;
    char c[n];
    fill_n(c, n, 'a');
    int used[n];
    fill_n(used, n, 0);

    // for(int i=0; i<n; ++i){
    //     cout << c[i] << ' ';
    // }
    // cout << endl;

    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(s[i] >= c[j]){
                if(!used[j]){
                    used[j] = 1;
                    ++res;
                }
                c[j] = s[i];
                ans += to_string(j+1) + ' ';
                break;
            }
        }
    }

    cout << res << endl;
    cout << ans << endl;


    return 0;
}
