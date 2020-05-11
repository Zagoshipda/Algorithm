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
        if(n <= 3){
            cout << -1 << endl;
        }
        else{
            deque<int> ans = {3, 1, 4, 2};
            for(int i=5; i<=n; ++i){
                if(i % 2){
                    ans.push_front(i);
                }
                else{
                    ans.push_back(i);
                }
            }
            for(int i=0; i<ans.size(); ++i){
                cout << ans[i] << ' ';
            }
            cout << endl;
        }
    }
    

    return 0;
}
