#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int t;
int n, m;

int main(){
    IOS;

    cin >> t;
    while(t--){
        ll sum = 0;
        cin >> n >> m;
        vector<int> k(n);
        for(int i=0; i<n; ++i){
            cin >> k[i], k[i] -= 1;
        }
        vector<int> c(m);
        for(int i=0; i<m; ++i){
            cin >> c[i];
        }

        sort(k.begin(), k.end(), greater<int>());

        for(int i=0, j=0; i<n; ++i){
            if(c[k[i]] <= c[j]){
                sum += c[k[i]];
            }
            else{
                sum += c[j++];
            }
        }

        cout << sum << endl; 

    }
    

    return 0;
}
