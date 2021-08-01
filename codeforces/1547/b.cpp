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
        int s_size = s.size();
        if(s_size <= 1){
            if(s[0] == 'a'){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
            continue;
        }
        vector<bool> checker(s_size, false);
        bool found_a = false;
        bool flag = true;
        for(int i=0; i<s_size-1; ++i){
            checker[s[i] - 'a'] = true;
            checker[s[i+1] - 'a'] = true;
            if(!(s[i] - 'a')){
                found_a = true;
            }
            if(found_a){
                if(s[i] >= s[i+1]){
                    flag = false;
                    break;
                }
            }
            else{
                if(s[i] <= s[i+1]){
                    flag = false;
                    break;
                }
            }
        }
        for(int i=0; i<s_size; ++i){
            if(!checker[i]){
                flag = false;
                break;
            }
        }
        if(flag){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }

    }


    return 0;
}
