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

        int d;
        vector<int> ans;
        int i=0;
        while(n > 0){
            n -= pow(2, i);
            ans.push_back(pow(2, i));
            ++i;
        }
        if(n < 0){
            n += pow(2, i-1);
            ans.pop_back();
            ans.push_back(n);
        }
        sort(ans.begin(), ans.end());
        
        cout << ans.size()-1 << endl;
        for(int i=1; i<ans.size(); ++i){
            cout << ans[i]-ans[i-1] << ' ';
        }
        cout << endl;       
        
    }
    

    return 0;
}
