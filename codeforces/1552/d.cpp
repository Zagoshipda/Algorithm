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
        int cnt = 1;
        for(int i=0; i<n; ++i){
            cin >> a[i];
            cnt *= 3;
        }
        
        bool flag = false;
        int val;
        int sum;
        int temp;
        for(int i=1; i<cnt; ++i){   // except i == 0 (NOT choosing anyone)
            sum = 0;
            val = i;
            for(int j=0; j<n; ++j){
                // cout << "val " << val << endl;
                temp = val % 3;
                if(temp == 1){
                    sum += a[j];
                }
                if(temp == 2){
                    sum -= a[j];
                }
                val /= 3;
            }
            if(sum == 0){
                flag = true;
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
