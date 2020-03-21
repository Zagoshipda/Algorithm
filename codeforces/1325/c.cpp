#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18)

// https://en.cppreference.com/w/cpp/types/size_t

int n;
int u, v;

int main(){
    IOS;

    cin >> n;
    vector<int> ans(n-1);
    vector<int> edge[n];

    for(int i=0; i<n-1; ++i){
        cin >> u >> v;
        edge[u-1].push_back(i);
        edge[v-1].push_back(i);
        ans[i] = -1;
    }

    int cnt = 0;
    for(int i=0; i<n; ++i){
        if((int)(edge[i].size()) >= 3){
            for(int j : edge[i]){
                ans[j] = cnt++;
            }
            break;
        }
    }
    // cout << "ans[] ===> " << endl;
    // for(int i=0; i<n-1; ++i){
    //     cout << ans[i] << ' ';
    // }

    for(int i=0; i<n-1; ++i){
        if(ans[i] < 0){
            ans[i] = cnt++;
        }
    }

    for(int i=0; i<n-1; ++i){
        cout << ans[i] << endl;
    }


    return 0;
}
