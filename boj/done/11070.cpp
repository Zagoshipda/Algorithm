/*
    https://www.acmicpc.net/problem/11070
    Pythagorean Expectation

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define NUM_TEAMS 1'000
#define NUM_GAMES 1'000
#define SIZE_RUNS 20
int T;
int n, m;
int a, b, p, q;
pair<int, int> runs[NUM_TEAMS + 1]; // (scored, allowed)
ll expectations[NUM_TEAMS + 1];

void initialize(){
    for(int i=0; i<=NUM_TEAMS; ++i){
        runs[i] = {0, 0};
    }
}

void solve(){
    ll max_expectation = 0;
    ll min_expectation = INT_MAX;
    for(int team=1; team<=n; ++team){
        // If a team has no scored and allowed runs, then its expectation value becomes zero
        if(runs[team].first <= 0){
            expectations[team] = 0;
        }
        else{
            expectations[team] = pow(runs[team].first, 2) * 1000 / (pow(runs[team].first, 2) + pow(runs[team].second, 2));
        }
        max_expectation = max(max_expectation, expectations[team]);
        min_expectation = min(min_expectation, expectations[team]);
    }
    cout << max_expectation << endl;
    cout << min_expectation << endl;
}

void input(){
    cin >> T;
    while(T--){
        cin >> n >> m;
        for(int i=0; i<m; ++i){
            cin >> a >> b >> p >> q;
            runs[a].first += p;
            runs[a].second += q;
            runs[b].first += q;
            runs[b].second += p;
        }

        solve();

        initialize();
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
