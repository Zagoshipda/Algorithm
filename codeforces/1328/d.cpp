#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18)

int q;
int n;

int main(){
    IOS;

    cin >> q;
    while(q--){
        cin >> n;
        vector<int> t(n);
        for(int i=0; i<n; ++i){
            cin >> t[i];
        }
        int k = 0;
        vector<int> c(n);
        c[0] = 1;
        bool flag = false;
        int pos = -1;
        for(int i=0; i<n; ++i){
            if(i<n-1){
                if(t[i+1] != t[i]){
                    if(c[i] == 1){
                        c[i+1] = 2;
                    }
                    else{
                        c[i+1] = 1;
                    }
                    flag = true;
                }
                else{
                    c[i+1] = c[i];
                    pos = i+1;
                }
            }
            else{
                if(t[0] != t[i]){
                    if(t[i-1] == t[i]){
                        k = 2;
                        c[i] = 2;
                    }
                    else{
                        if(c[i-1] == 1){
                            k = 2;
                            c[i] = 2;
                        }
                        else{
                            if(pos < 0){
                                k = 3;
                                c[i] = 3;
                            }
                            else{
                                k = 2;
                                c[n-1] = 2;
                                for(int j=n-2; j>=pos; --j){
                                    if(c[j] == 1){
                                        c[j] = 2;
                                    }
                                    else{
                                        c[j] = 1;
                                    }
                                }
                            }
                        }
                    }
                }
                else{   // t[0] == t[i]
                    if(flag){
                        k = 2;
                    }
                    else{
                        k = 1;
                    }
                    c[i] = (c[i-1] == 1 && t[i-1] != t[i])? 2 : 1;
                    if(c[i] == 2){
                        k = 2;
                    }
                }
            }
        }

        cout << k << endl;
        for(int i=0; i<n; ++i){
            cout << c[i] << ' '; 
        }
        
        cout << endl;

    }
    

    return 0;
}
