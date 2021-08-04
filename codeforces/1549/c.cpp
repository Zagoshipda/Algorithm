#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Idea : A noble can survive iff a noble's all friends are weaker.

    Solution : Keep track of degree of vertices that has the lower power than at least one of its friends. If it's connected to other stronger noble, then it will be killed, if it's disconnected to any other nobles then it will survive.
*/

int n, m;
int u, v;
int q;

int main(){
    IOS;

    cin >> n >> m;
    int ans = n;
    vector<int> degree(n+1, 0);
    for(int i=0; i<m; ++i){
        cin >> u >> v;
        if(u > v){
            swap(u, v);
        }
        ++degree[u];
        if(degree[u] == 1){
            --ans;
        }
    }

    cin >> q;
    int type;
    for(int i=0; i<q; ++i){
        cin >> type;
        if(type == 1){
            cin >> u >> v;
            if(u > v){
                swap(u, v);
            }
            ++degree[u];    // ++degree[v];
            if(degree[u] == 1){
                --ans;
            }
        }
        else if(type == 2){
            cin >> u >> v;
            if(u > v){
                swap(u, v);
            }
            --degree[u];
            if(degree[u] <= 0){
                ++ans;
            }
        }
        else if(type == 3){
            cout << ans << endl;
        }
    }

    return 0;
}
