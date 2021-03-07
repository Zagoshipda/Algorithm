#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int t;
int n, U, R, D, L;
int pos[4];

int main(){
    IOS;

    cin >> t;
    while(t--){
        cin >> n >> U >> R >> D >> L;
        bool flag = true;
        for(int i=0; i<16; ++i){
            pos[0] = U, pos[1] = R, pos[2] = D, pos[3] = L;
            for(int j=0; j<4; ++j){
                if(i & 1<<j){
                    --pos[j];
                    --pos[(j+1)%4];
                }
            }
            // cout << pos[0] << pos[1] << pos[2] << pos[3] << endl;
            if(0 <= *min_element(pos, pos+4) && *max_element(pos, pos+4) <= n-2){
                cout << "YES" << endl;
                flag = false;
                break;
            }
        }
        if(flag){
            cout << "NO" << endl;
        }
    }
    

    return 0;
}
