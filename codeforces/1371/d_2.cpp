#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int t;
int n, k;
// n, 2*(n-1), 2*(n-2)

int main(){
	IOS;

    cin >> t;
    while(t--){
        cin >> n >> k;
        vector<vector<int>> A (n, vector<int> (n, 0));

        int fa = 0;
        int cnt = 0;
        int val1;
        int val2;
        while(k > 0 && cnt < n){
            if(cnt > 0){
                val1 = n-cnt;
                val2 = n-cnt;
                if(k < val1){
                    for(int i=0; i<k; ++i){
                        A[i][i + cnt] = 1;
                    }
                    fa = 2;
                    k = 0;
                }
                else if(k == val1){
                    for(int i=0; i<val1; ++i){
                        A[i][i + cnt] = 1;
                    }
                    fa = 2;
                    k = 0;
                }
                else if(k < val1 + val2){
                    for(int i=0; i<val1; ++i){
                        A[i][i + cnt] = 1;
                    }
                    for(int i=0; i<k - val1; ++i){
                        A[i + cnt][i] = 1;
                    }
                    fa = 4;
                    k = 0;
                }
                else if(k == val1 + val2){
                    for(int i=0; i<val1; ++i){
                        A[i][i + cnt] = 1;
                    }
                    for(int i=0; i<val2; ++i){
                        A[i + cnt][i] = 1;
                    }
                    fa = 0;
                    k = 0;
                }
                else{
                    for(int i=0; i<val1; ++i){
                        A[i][i + cnt] = 1;
                    }
                    for(int i=0; i<val2; ++i){
                        A[i + cnt][i] = 1;
                    }
                    k -= (val1 + val2);
                }
            } 
            else{
                val1 = n;
                if(k < val1){
                    for(int i=0; i<k; ++i){
                        A[i][i] = 1;
                    }
                    fa = 2;
                    k = 0;
                }
                else if(k == val1){
                    for(int i=0; i<val1; ++i){
                        A[i][i] = 1;
                    }
                    fa = 0;
                    k = 0;
                }
                else{
                    for(int i=0; i<val1; ++i){
                        A[i][i] = 1;
                    }
                    k -= val1;
                }
            }
            ++cnt;
        }

        cout << fa << endl;
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                cout << A[i][j];
            }
            cout << endl;
        }
    }
    
    return 0;
}
