#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int N;
int cost[1001][3];

int main(){
    IOS;

    cin >> N;
    for(int i=1; i<=N; ++i){
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
        cost[i][0] += min(cost[i-1][1], cost[i-1][2]);
        cost[i][1] += min(cost[i-1][0], cost[i-1][2]);
        cost[i][2] += min(cost[i-1][0], cost[i-1][1]);
    }

    cout << min(min(cost[N][0], cost[N][1]), cost[N][2]);

    return 0;
}
