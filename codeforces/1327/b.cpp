#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18)

int t;
int n;
int k;

int main(){
    IOS;

    cin >> t;
    while(t--){
        cin >> n;
        vector<int> g[n];
        int ans[n+1];
        fill_n(ans, n+1, -1);

        vector<int> out;
        for(int i=0; i<n; ++i){
            cin >> k;
            int input;
            for(int j=0; j<k; ++j){
                cin >> input;
                g[i].push_back(input);
            }
            // sort(g[i].begin(), g[i].end());
            bool flag = true;
            for(auto it=g[i].begin(); it!=g[i].end(); it++){
                if(ans[*it] < 0){
                    ans[*it] = 0;
                    flag = false;
                    break;
                }
            }
            if(flag){
                out.push_back(i);
            }
        }
        if(out.size() > 0){
            int out2;
            for(int j=1; j<=n; ++j){
                if(ans[j] < 0){
                    out2 = j;
                    break;
                }
            }
            cout << "IMPROVE" << endl;
            cout << out[0]+1 << ' ' << out2 << endl;
        }
        else{
            cout << "OPTIMAL" << endl;
        }
        
    }
    

    return 0;
}
