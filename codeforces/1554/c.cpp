#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int t;
int n, m;

int main(){
    IOS;

    cin >> t;
    while(t--){
        cin >> n >> m;
        int ans = 0;
        int target = m+1;
        bool flag = false;
        for(int i=30; i>=0; --i){
            ans <<= 1;
            if(flag){
                continue;
            }
            else{
                if((target >> i) & 1){
                    if((n >> i) & 1){
                        continue;
                    }
                    else{
                        ans += 1;
                    }
                }
                else{
                    if((n >> i) & 1){
                        // ans += 1;    // n ^ ans >= target (= m+1)
                        flag = true;
                        continue;   // stop the loop
                    }
                    else{
                        continue;
                    }
                }
            }
            
        }

        cout << ans << endl;
    }


    return 0;
}
