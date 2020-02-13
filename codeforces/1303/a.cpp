#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int t;
string s;

int main(){
    IOS;

    cin >> t;
    for(int i=0; i<t; ++i){
        cin >> s;

        int cnt = 0;
        bool check = false;
        for(int j=0; j<s.size(); ++j){
            if(s[j] - '0'){
                check = true;
            }
            else{
                if(check){
                    ++cnt;
                }
            }
        }
        int sub = 0;
        for(int j=s.size()-1; j>=0; --j){
            if(s[j] - '0'){
                break;
            }
            else{
                ++sub;
            }
        }
        int ans = check ? cnt - sub : cnt;
        cout << ans << endl;
    }

    return 0;
}
