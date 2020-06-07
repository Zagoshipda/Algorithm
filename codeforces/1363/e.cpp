#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

const int N = 202020;
vector<int> g[N+1];
vector<int> a(N+1);
vector<int> b(N+1);
vector<int> c(N+1);
int n;
ll cost;

pair<int, int> dfs(int u, int p, int minCost){
    pair<int, int> type = {0, 0};
    if(b[u] != c[u]){
        if(b[u]){
            type.first++;
        }
        else{
            type.second++;
        }
    }

    for(auto &it:g[u]){
        if(it == p){
            continue;
        }
        pair<int, int> result = dfs(it, u, min(minCost, a[u]));
        type.first += result.first;
        type.second += result.second;
    }

    if(a[u] < minCost){
        // int cnt = min(type.first, type.second);
        // cost += 2 * (ll)cnt * (ll)a[u];

        ll cnt = min(type.first, type.second);  // why NOT int?
        cost += 2 * cnt * a[u];
        
        type.first -= cnt;
        type.second -= cnt;
    }

    return type;
}

int main(){
    IOS;

    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> a[i] >> b[i] >> c[i];
    }
    int u, v;
    for(int i=0; i<n-1; ++i){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u); 
    }

    pair<int, int> output = dfs(1, 0, INT_MAX);
    if(output.first || output.second){
        cout << -1 << endl;
    }
    else{
        cout << cost << endl;
    }

    return 0;
}
