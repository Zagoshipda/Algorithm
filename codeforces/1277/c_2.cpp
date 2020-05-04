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
    while(t--){
        cin >> s;

        if(s.size() < 3){
            cout << 0 << endl;
            cout << endl;
            continue;
        }
        vector<int> ans;
        for(int i=0; i<s.size()-2; ++i){
            string sub;
            for(int j=i; j<i+3; ++j){
                sub += s[j];
            }
            if(sub == "one"){
                ans.push_back(i+1);
                i += 2;
            }
            else if(sub == "two"){
                // 'twone'
                if(i+3 < s.size() && s[i+3] == 'n' && i+4 < s.size() && s[i+4] == 'e'){
                    ans.push_back(i+2);
                    i += 4;
                }
                else{
                    ans.push_back(i+1);
                    i += 2;
                }
            }
        }

        cout << ans.size() << endl;
        for(int i=0; i<ans.size(); ++i){
            cout << ans[i]+1 << ' ';
        }
        cout << endl;
    }


    return 0;
}
