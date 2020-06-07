#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int t;
int n, x;
int u, v;

int main(){
    IOS;

    cin >> t;
    while(t--){
        cin >> n >> x;
        vector<int> node[n];

        for(int i=0; i<n-1; ++i){
            cin >> u >> v;
            node[u-1].push_back(v);
            node[v-1].push_back(u);
        }

        if(node[x-1].size() <= 1){
            cout << "Ayush" << endl;
        }
        else{
            if(n%2 == 0){
                cout << "Ayush" << endl;
            }
            else{
                cout << "Ashish" << endl;
            }
        }
    }
    

    return 0;
}
