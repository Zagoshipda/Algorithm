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
                int cnt2 = 0;
                for(int j=i+2; j<s.size() && s[j]==s[i+2]; ++j){
                    ++cnt2;
                }
                if(i+2+cnt2<s.size() && s[i+2+cnt2] == 'n' && i+2+cnt2+1<s.size() && s[i+2+cnt2+1] == 'e'){
                    int cnt1 = 0;
                    for(int j=i; j<s.size() && s[j]==s[i]; --j){
                        ++cnt1;
                    }
                    int cnt3 = 0;
                    for(int j=i+2+cnt2+1; j<s.size() && s[j]=='e'; ++j){
                        ++cnt3;
                    }
                    if(min(cnt2, (cnt1+cnt3)) > 2){
                        ans.push_back(i+1);
                        ans.push_back(i+2+cnt2);
                        i += (2 + cnt2+1+cnt3-1);
                    }
                    else{
                        if(cnt2 <= cnt1 + cnt3){
                            // middle 'o'
                            for(int k=i+2; k<i+2+cnt2; ++k){
                                ans.push_back(k);
                            }
                            i += (2 + cnt2+1+cnt3-1);
                        }
                        else{
                            // front 't'
                            for(int k=i-cnt1+1; k<=i; ++k){
                                ans.push_back(k);
                            }
                            // back 'e'
                            for(int k=i+2+cnt2+1; k<=i+2+cnt2+1+cnt3-1; ++k){
                                ans.push_back(k);
                            }
                            i += (2 + cnt2+1+cnt3-1);
                        }
                    }
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
