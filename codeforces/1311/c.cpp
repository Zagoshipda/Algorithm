#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // -9*10^18 ~ 9*10^18

int t;
int n, m;
string s;

int main(void){
    IOS;

    cin >> t;
    while(t--){
        int ans[26];
        fill_n(ans, 26, 0);

        cin >> n >> m;
        cin >> s;

        // int p[m];
        int p;  // 1 <= p < n
        int num[n];
        fill_n(num, n, 0);
        for(int i=0; i<m; ++i){
            // cin >> p[i];
            // ++num[p[i]-1];
            cin >> p;
            ++num[p-1];
        }
        
        num[n-1] = 1;
        for(int i=n-2; i>=0; --i){
            num[i] += num[i+1];
        }

        for(int i=0; i<n; ++i){
            ans[s[i] - 'a'] += num[i];
        }

        for(int i=0; i<26; ++i){
            cout << ans[i] << ' ';
        }
        cout << endl;


    }

    return 0;
}
