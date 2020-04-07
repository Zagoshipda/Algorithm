#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long

int t;
int d, m;
ll num;

int main(void){
    IOS;

    cin >> t;
    while(t--){
        cin >> d >> m;
        if(m == 1){
            cout << 0 << endl;
            continue;
        }

        num = 1;
        int val[30];
        fill_n(val, 30, -1);
        int cnt = 0;
        for(int i=0; i<30; ++i){
            if(d < pow(2, i+1)){
                val[i] = d - pow(2, i) + 1;
                ++cnt;
                break;
            }
            val[i] = pow(2, i);
            ++cnt;
        }

        if(cnt > 1){
            for(int i=0; i<cnt; ++i){
                num *= (val[i]+1);
                num %= m;
            }
            --num;
            if(num < 0){
                num += m;
            }
        }
        else{
            for(int i=0; i<cnt; ++i){
                num *= val[i];
                num %= m;
            }
        }

        cout << num << endl;
        
    }

    return 0;
}
