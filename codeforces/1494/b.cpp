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
        // cin >> n >> U >> R >> D >> L;
        cin >> n >> pos[0] >> pos[1] >> pos[2] >> pos[3];

        bool flag = false;
        for(int i=0; i<2; ++i){
            for(int j=0; j<2; ++j){
                for(int k=0; k<2; ++k){
                    for(int l=0; l<2; ++l){
                        U = pos[0], R = pos[1], D = pos[2], L = pos[3];
                        if(i > 0 && U > 0 && R > 0){
                            --U;
                            --R;
                        }
                        if(j > 0 && R > 0 && D > 0){
                            --R;
                            --D;
                        }
                        if(k > 0 && D > 0 && L > 0){
                            --D;
                            --L;
                        }
                        if(l > 0 && L > 0 && U > 0){
                            --L;
                            --U;
                        }
                        if(U <= n-2 && R <= n-2 && D <= n-2 && L <= n-2){
                            flag = true;
                        }
                    }
                }
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
