#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int t;
int n;

int main(){
    IOS;

    cin >> t;
    while(t--){
        cin >> n;
        vector<int> a(n);
        vector<int> intimidation(n);
        int ans = 0;
        int dec = 0;
        for(int i=0; i<n; ++i){
            cin >> a[i];
        }

        for(int i=1; i<n-1; ++i){
            if(a[i-1] > a[i] && a[i] < a[i+1]){
                intimidation[i] = -1;
                ++ans;
            }
            else if(a[i-1] < a[i] && a[i] > a[i+1]){
                intimidation[i] = 1;
                ++ans;
            }
        }

        for(int i=1; i<n-1; ++i){
            if(intimidation[i] != 0){
                int val = abs(intimidation[i-1]) + abs(intimidation[i]) + abs(intimidation[i+1]);
                int new_val_1 = 0;
                int new_val_2 = 0;
                // a[i] = a[i-1]
                if(a[i-1] > a[i+1] && (i+2 < n && a[i+1] < a[i+2])){
                    ++new_val_1;
                    // cout << "!" << endl;
                }
                else if(a[i-1] < a[i+1] && (i+2 < n && a[i+1] > a[i+2])){
                    ++new_val_1;
                    // cout << "!!" << endl;
                }
                // a[i] = a[i+1]
                if((i-2 >= 0 && a[i-2] > a[i-1]) && a[i-1] < a[i+1]){
                    ++new_val_2;
                    // cout << "!!!" << endl;
                }
                else if((i-2 >= 0 && a[i-2] < a[i-1]) && a[i-1] > a[i+1]){
                    ++new_val_2;
                    // cout << "!!!!" << endl;
                }
                // cout << dec << ' ' << val << ' ' << new_val_1 << ' ' << new_val_2 << endl;
                dec = max(dec, val - min(new_val_1, new_val_2));
            }
        }
        // cout << ans << ' ' << dec << endl;
        cout << ans - dec << endl;

    }
    

    return 0;
}
