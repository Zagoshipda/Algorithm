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
        int cnt_a = 0, cnt_b =0;
        int either_a = 0, either_b = 0;
        int diff = 0;
        bool flag = false;
        for(int i=0; i<10; ++i){

            // cout << s[i] << ' ';
            if(i&1){
                if(s[i] == '0'){
                    // do nothing.
                }
                else if(s[i] == '1'){
                    cnt_b += 1;
                }
                else{   // s[i] == ?
                    either_b += 1;
                }
            }
            else{
                if(s[i] == '0'){
                    // do nothing.
                }
                else if(s[i] == '1'){
                    cnt_a += 1;
                }
                else{   // s[i] == ?
                    either_a += 1;
                }
            }
                        
            if((cnt_a + either_a) - cnt_b > (cnt_b + either_b) - cnt_a){
                flag = true;
                diff = (cnt_a + either_a) - cnt_b;
            }
            else{
                flag = false;
                diff = (cnt_b + either_b) - cnt_a;
            }

            // cout << boolalpha << " ;; " << cnt_a << ' ' << cnt_b << ' ' << either_a << ' ' << either_b << ' ' << diff << ' ' << flag << endl;

            if(flag){
                int val = 5 - (i/2 + 1) + (1 & (i+1));
                
                // cout << "diff / value = " << diff << ' ' << val << ' ' << endl << flush;
                
                if(diff > val){
                    cout << i+1 << endl;
                    break;
                }
            }
            else{
                if(diff > 5 - (i/2 + 1)){
                    cout << i+1 << endl;
                    break;
                }
            }
            
            if(i >= 9){
                cout << 10 << endl;
            }
        }
        
        // cout << " t : " << t << endl;
    }

    return 0;
}
