/*
    https://www.acmicpc.net/problem/7579
    App (knapsack problem)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    DP methodology

    S ubproblem
        suffix dp[a][b] : max memory for (app a...N), with (sum of cost b)

    R ecurrence relation
    T opological order
    B ase case
    O riginal problem
    T ime complexity

*/

#define SIZE 100
#define RANGE 10'000'000
#define MAX_SUM_COST 10'000
int N, M;
pair<int, int> app[SIZE + 1];   // (bytes, cost)

int dp[SIZE + 2][MAX_SUM_COST + 1];

void dp_suffix(){
    for(int ith=N; ith>=1; --ith){
        for(int cost=0; cost<=MAX_SUM_COST; ++cost){
            // NOTE : current cost - cost of ith app
            if(cost - app[ith].second >= 0){
                dp[ith][cost] = max(
                    dp[ith+1][cost - app[ith].second] + app[ith].first,
                    dp[ith+1][cost]
                );
            }
            else{
                dp[ith][cost] = dp[ith+1][cost];
            }
        }
    }

    for(int cost=0; cost<=MAX_SUM_COST; ++cost){
        if(dp[1][cost] >= M){
            cout << cost << endl;
            break;
        }
    }
}

void dp_prefix(){
    // TODO
}

void solve(){
    dp_suffix();

    // dp_prefix();
}

void input(){
    cin >> N >> M;
    for(int i=1; i<=N; ++i){
        cin >> app[i].first;
    }
    for(int i=1; i<=N; ++i){
        cin >> app[i].second;
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
