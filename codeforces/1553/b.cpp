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
        cin >> s >> t;
        int s_size = s.size();
        int t_size = t.size();
        int i;
        vector<int> pos;
        for(i=0; i<s_size; ++i){
            if(s[i] == t[0]){
                pos.push_back(i);
            }
        }

        int pos_size = pos.size();
        bool flag = false;
        for(i=0; i<pos_size; ++i){
            int starting = pos[i];
            int j = 0;
            while(s[starting + j] == t[j]){
                ++j;
            }
            // cout << "starting " << starting << endl;
            // cout << "j " << j << endl;
            for(int k=0; k<j; ++k){
                int starting_2 = starting + k;
                int back = 0;
                int forward = k;
                // cout << "starting_2 " << starting_2 << endl;
                while(s[starting_2 - back] == t[forward]){
                    ++back; ++forward;
                }
                if(forward >= t_size){
                    flag = true;
                    break;
                }
            }
            if(flag){
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
