#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int N;
int DP[1000001];
const int MOD = 15746;

int main(){
    IOS;

    cin >> N;

    DP[0] = 1;
    DP[1] = 1;

    for(int i=2; i<=N; ++i){
        DP[i] = (DP[i-1] + DP[i-2]) % MOD;
    }

    cout << DP[N] << endl;

    return 0;
}
