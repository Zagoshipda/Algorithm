#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int q;
string s;
string t;

int main(){
    IOS;

    cin >> q;
    while(q--){
        cin >> s;
        cin >> t;
        if(t.size() > s.size()){
            cout << "NO" << endl;
            continue;
        }
        int i = s.size()-1;
        int j = t.size()-1;
        // from the back.
        for(; i>=0 && j>=0; ){
            if(s[i] == t[j]){
                --i;
                --j;
            }
            else{
                i -= 2;
            }
        }

        if(j < 0){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    

    return 0;
}
